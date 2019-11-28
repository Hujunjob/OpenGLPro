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
    //相机看的目标
    vec3 cameraTarget;

public:
    Camera();
    /**
     * 设置相机的位置
     * @param pose 相机位置
     */
    void setPose(vec3 pose);
    vec3 getPose(){
        return pose;
    }
    /**
     * 设置相机看的目标
     * @param target 目标位置
     */
    void setTarget(vec3 target);
    vec3 getTarget(){ return cameraTarget;}
    /**
     * 设置相机的上向量
     * @param up
     */
    void setUp(vec3 up);
    vec3 getUp(){
        return up;
    }
    /**
     * 得到相机的观察矩阵
     * @return 观察矩阵
     */
    mat4 lookAt();
    mat4 lookAt(vec3 pose,vec3 target,vec3 up);
    ~Camera();
};


#endif //OPENGLDEMO_CAMERA_H
