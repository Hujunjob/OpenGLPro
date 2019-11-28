//
// Created by JUN HU on 2019-11-26.
//

#ifndef OPENGLDEMO_OPENGL_H
#define OPENGLDEMO_OPENGL_H
#pragma once

#include "utils/utils.h"
#include <sys/time.h>
#include <tgmath.h>
#include "native-lib.h"
#include "utils/Shader.h"

void onSurfaceChanged(int width, int height);

void onSurfaceCreated();

void onDrawFrame();

void onPressUp(int value);

void onPressDown(int value);

void onPressLeft(int value);

void onPressRight(int value);

void onTouchEvent(float x,float y,int action);

void yaw(int value);

void pitch(int value);

void roll(int value);

void scroll(float value);

#endif //OPENGLDEMO_OPENGL_H
