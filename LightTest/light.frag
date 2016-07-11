#version 330 core

struct Material
{
    vec3 ambient;//环境光照下的颜色
    vec3 diffuse;//漫反射光照下的颜色。
    vec3 specular;//镜面光照下的颜色
    float shininess;
};
uniform Material material;

struct Light
{
    vec3 position;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};
uniform Light light;

out vec4 color;

uniform vec3 objectColor;
uniform vec3 lightColor;
uniform vec3 lightPos;
uniform vec3 viewPos;

in vec3 Normal;
in vec3 FragPos;


void main()
{
    
//    float ambientStrength = 0.1f;
//    vec3 ambient = ambientStrength * lightColor;
//    
//    vec3 norm = normalize(Normal);
//    vec3 lightDir = normalize(lightPos - FragPos);
//    //计算散射值
//    float diff = max(dot(norm, lightDir), 0.0);
//    vec3 diffuse = diff * lightColor;
//
//    // Specular
//    float specularStrength = 10.0f;
//    vec3 viewDir = normalize(viewPos - FragPos);
//    vec3 reflectDir = reflect(-lightDir, norm);
//    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
//    vec3 specular = specularStrength * spec * lightColor;
//    
//    vec3 result = (ambient + diffuse + specular) * objectColor;
//    color = vec4(result, 1.0f);
    
    // 环境光
//    vec3 ambient = lightColor * material.ambient;
    vec3 ambient = light.ambient*material.ambient;
    // 漫反射光
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
//    vec3 diffuse = lightColor * (diff * material.diffuse);
    vec3 diffuse = light.diffuse*(diff*material.diffuse);
    // 镜面高光
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
//    vec3 specular = lightColor * (spec * material.specular);
    vec3 specular = light.specular*(spec*material.specular);
    
    vec3 result = ambient + diffuse + specular;
    color = vec4(result, 1.0f);
}