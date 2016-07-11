#include "LightTest.h"

void LightTest::init(){
    _shaderLight = new Shader("/Users/xiaolei/Develop/GitHub/LearnOpenGL/LightTest/light.vert",
                              "/Users/xiaolei/Develop/GitHub/LearnOpenGL/LightTest/light.frag");
    _shaderLamp = new Shader("/Users/xiaolei/Develop/GitHub/LearnOpenGL/LightTest/lamp.vert",
                             "/Users/xiaolei/Develop/GitHub/LearnOpenGL/LightTest/lamp.frag");
    
    camera = new Camera(glm::vec3(0.0f, 0.0f, 3.0f));
    
    cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
    cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
    
    lightPos = glm::vec3(1.2f, 1.0f, 2.0f);
    
    lastX  =  WIDTH  / 2.0;
    lastY  =  HEIGHT / 2.0;

    
    
    GLfloat vertices[] = {
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
        0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
        0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
        0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
        
        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
        0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
        0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
        0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
        
        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
        
        0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
        0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
        0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
        0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
        0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
        0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
        
        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
        0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
        0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
        0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
        
        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
        0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
        0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
        0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
    };
    
    // First, set the container's VAO (and VBO)
    glGenVertexArrays(1, &containerVAO);
    glGenBuffers(1, &VBO);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    glBindVertexArray(containerVAO);
    // Position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6* sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);
    glBindVertexArray(0);
    
    // Then, we set the light's VAO (VBO stays the same. After all, the vertices are the same for the light object (also a 3D cube))
    glGenVertexArrays(1, &lightVAO);
    glBindVertexArray(lightVAO);

    // We only need to bind to the VBO (to link it with glVertexAttribPointer), no need to fill it; the VBO's data already contains all we need.
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    // Set the vertex attributes (only position data for the lamp))
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);}

void LightTest::update(){
    
    
    // Clear the colorbuffer
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    do_movement();
    
    // Change the light's position values over time (can be done anywhere in the game loop actually, but try to do it at least before using the light source positions)
    lightPos.x = 1.0f + sin(glfwGetTime()) * 2.0f;
    lightPos.y = sin(glfwGetTime() / 2.0f) * 1.0f;
    
    
    // Use cooresponding shader when setting uniforms/drawing objects
    _shaderLight->Use();
    GLint objectColorLoc = glGetUniformLocation(_shaderLight->Program, "objectColor");
    GLint lightColorLoc  = glGetUniformLocation(_shaderLight->Program, "lightColor");
    GLint lightPosLoc = glGetUniformLocation(_shaderLight->Program, "lightPos");
    GLint viewPosLoc = glGetUniformLocation(_shaderLight->Program, "viewPos");
    glUniform3f(objectColorLoc, 1.0f, 0.5f, 0.31f);
    glUniform3f(lightColorLoc,  1.0f, 0.5f, 1.0f);
    glUniform3f(lightPosLoc, lightPos.x, lightPos.y, lightPos.z);
    glUniform3f(viewPosLoc, camera->Position.x, camera->Position.y, camera->Position.y);
    
    GLint matAmbientLoc = glGetUniformLocation(_shaderLight->Program, "material.ambient");
    GLint matDiffuseLoc = glGetUniformLocation(_shaderLight->Program, "material.diffuse");
    GLint matSpecularLoc = glGetUniformLocation(_shaderLight->Program, "material.specular");
    GLint matShineLoc = glGetUniformLocation(_shaderLight->Program, "material.shininess");
    
    glUniform3f(matAmbientLoc, 1.0f, 0.5f, 0.31f);
    glUniform3f(matDiffuseLoc, 1.0f, 0.5f, 0.31f);
    glUniform3f(matSpecularLoc, 0.5f, 0.5f, 0.5f);
    glUniform1f(matShineLoc, 32.0f);
    
    GLint lightAmbientLoc = glGetUniformLocation(_shaderLight->Program, "light.ambient");
    GLint lightDiffuseLoc = glGetUniformLocation(_shaderLight->Program, "light.diffuse");
    GLint lightSpecularLoc = glGetUniformLocation(_shaderLight->Program, "light.specular");
    
    glUniform3f(lightAmbientLoc, 0.2f, 0.2f, 0.2f);
    glUniform3f(lightDiffuseLoc, 0.5f, 0.5f, 0.5f);// 让我们把这个光调暗一点，这样会看起来更自然
    glUniform3f(lightSpecularLoc, 1.0f, 1.0f, 1.0f);
    
    glm::vec3 lightColor; lightColor.x = sin(glfwGetTime() * 2.0f);
    lightColor.y = sin(glfwGetTime() * 0.7f);
    lightColor.z = sin(glfwGetTime() * 1.3f);
    
    glm::vec3 diffuseColor = lightColor * glm::vec3(0.5f);
    glm::vec3 ambientColor = diffuseColor * glm::vec3(0.2f);
    
    glUniform3f(lightAmbientLoc, ambientColor.x, ambientColor.y, ambientColor.z);
    glUniform3f(lightDiffuseLoc, diffuseColor.x, diffuseColor.y, diffuseColor.z);

    
    // Create camera transformations
    glm::mat4 view;
    view = camera->GetViewMatrix();
    glm::mat4 projection = glm::perspective(camera->Zoom, (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f, 100.0f);
    // Get the uniform locations
    GLint modelLoc = glGetUniformLocation(_shaderLight->Program, "model");
    GLint viewLoc  = glGetUniformLocation(_shaderLight->Program,  "view");
    GLint projLoc  = glGetUniformLocation(_shaderLight->Program,  "projection");
    
    // Pass the matrices to the shader
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
    
    
    // Draw the container (using container's vertex attributes)
    glBindVertexArray(containerVAO);
    glm::mat4 model;
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);
    
    // Also draw the lamp object, again binding the appropriate shader
    _shaderLamp->Use();
    // Get location objects for the matrices on the lamp shader (these could be different on a different shader)
    modelLoc = glGetUniformLocation(_shaderLamp->Program, "model");
    viewLoc  = glGetUniformLocation(_shaderLamp->Program, "view");
    projLoc  = glGetUniformLocation(_shaderLamp->Program, "projection");
    // Set matrices
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
    model = glm::mat4();
    model = glm::translate(model, lightPos);
    model = glm::scale(model, glm::vec3(0.2f)); // Make it a smaller cube
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
    // Draw the light object (using light's vertex attributes)
    glBindVertexArray(lightVAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);

}

void LightTest::updateTime(){
    // Calculate deltatime of current frame
    GLfloat currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;
}

void LightTest::do_movement(){
    // Camera controls
    if (keys[GLFW_KEY_W])
        camera->ProcessKeyboard(FORWARD, deltaTime);
    if (keys[GLFW_KEY_S])
        camera->ProcessKeyboard(BACKWARD, deltaTime);
    if (keys[GLFW_KEY_A])
        camera->ProcessKeyboard(LEFT, deltaTime);
    if (keys[GLFW_KEY_D])
        camera->ProcessKeyboard(RIGHT, deltaTime);
}

void LightTest::keyCallBack(GLFWwindow *window, int key, int scancode, int action, int mode){
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
    if(action == GLFW_PRESS)
        keys[key] = true;
    else if (action == GLFW_RELEASE)
        keys[key] = false;
    
}

void LightTest::mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }
    
    GLfloat xoffset = xpos - lastX;
    GLfloat yoffset = lastY - ypos;  // Reversed since y-coordinates go from bottom to left
    
    lastX = xpos;
    lastY = ypos;
    
    camera->ProcessMouseMovement(xoffset, yoffset);
}

void LightTest::scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    camera->ProcessMouseScroll(yoffset);
}