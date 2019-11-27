#version 300 es

precision lowp float;

out vec4 FragColor;

//in vec3 ourColor; // 从顶点着色器传来的输入变量（名称相同、类型相同）
in vec2 TexCoord;

//默认为第一个纹理
uniform sampler2D ourTexture;
//设置第二个纹理
uniform sampler2D ourTexture2;

//在程序里设定该值，从CPU传递给GPU
//uniform vec4 ourColor;

void main() {
    //    FragColor = vec4(1.0f,0.5f,0.2f,1.0f);
//    FragColor = vertexColor;
//    FragColor = ourColor;
//    FragColor = vec4(ourColor,1.0);

    //设置纹理和纹理坐标，输出颜色为纹理和坐标采样的值
//    FragColor = texture(ourTexture,TexCoord);

    //设置两个纹理混合采样
    FragColor = mix(texture(ourTexture,TexCoord),texture(ourTexture2,TexCoord),0.2);
}
