//
// Created by JUN HU on 2019-11-26.
//

#include <android/log.h>
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include "opengl.h"


void onSurfaceChanged(int width, int height){
    glViewport(0,0,width,height);
    LOGD("OpenGL","onSurfaceChanged %d,%d",width,height);
}

void onSurfaceCreated(){
    glClearColor(1,0,0,1.0);

    LOGD("OpenGL","onSurfaceCreated");
}

void onDrawFrame(){
    glClear(GL_COLOR_BUFFER_BIT);
    LOGD("OpenGL","onDrawFrame");
}
