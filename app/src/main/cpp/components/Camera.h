//
// Created by hu jun on 2019-11-27.
//

#ifndef OPENGLDEMO_CAMERA_H
#define OPENGLDEMO_CAMERA_H

#include "../utils/utils.h"

class Camera {
private:
    //相机位置
    vec3 pose;
    //相机朝向（实际是相机背向）
    vec3 direction;
    //相机右轴
    vec3 right;
    //相机上轴
    vec3 up;

public:
    Camera();

    ~Camera();
};


#endif //OPENGLDEMO_CAMERA_H
