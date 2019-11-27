//
// Created by JUN HU on 2019-11-27.
//

#include "Texture.h"


//纹理坐标
float texCoords[] = {
        0.0f, 0.0f, // 左下角
        1.0f, 0.0f, // 右下角
        0.5f, 1.0f // 上中
};

void setTexture() {
    //设置超出范围后的填充方式
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);


}

uint loadTexture() {
    //宽度、高度和颜色通道的个数
    int width, height, nrChannels;
    unsigned char *data = stbi_load("/sdcard/container.jpg", &width, &height, &nrChannels, 0);

    if (!data) {
        LOGE("Texture", "加载纹理图像失败");
        return 0;
    }
    uint texture;
    glGenTextures(1, &texture);

    glBindTexture(GL_TEXTURE_2D, texture);

    // 为当前绑定的纹理对象设置环绕、过滤方式
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    //纹理过滤
    //如何将纹理像素映射到纹理坐标
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

/**
    glTexImage2D (GLenum target, GLint level, GLint internalformat,
                GLsizei width, GLsizei height, GLint border,
                GLenum format, GLenum type, const void *pixels);
    */
    //参数说明
    //target : 纹理目标，GL_TEXTURE_1D，GL_TEXTURE_2D，GL_TEXTURE_3D
    //level : 指定多级渐远纹理的级别
    //internalformat : 告诉OpenGL把纹理保存为何种格式，我们的图片只有RGB，则保存为RGB格式
    //width、height : 纹理的宽高
    //border : 总是设为0
    //format 、type ： 源图片的格式和数据类型，原图是RGB格式，且加载为byte数组
    //pixels : 图像数据
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

    //为当前绑定的纹理，自动生成多级渐远纹理
    glGenerateMipmap(GL_TEXTURE_2D);

    //释放图片数据
    stbi_image_free(data);

    return texture;
}