#version 330 core
in vec3 ourColor;
in vec2 TexCoord;
out vec4 color;
uniform sampler2D ourTexture1;
uniform sampler2D ourTexture2;
void main(){
    //	color = texture(ourTexture, TexCoord);
    //mix函数需要两个参数将根据第三个参数为前两者作为输入
    //并在之间进行线性插值。如果第三个值是0.0， 她返回第一个输入；如果是1.0， 返回第二个输入。0.2返回
    //80%的第一个输入和20%的第二个输入颜色，返回两个纹理的混合
    color = mix(texture(ourTexture1, TexCoord), texture(ourTexture2, TexCoord), 0.5);
}
