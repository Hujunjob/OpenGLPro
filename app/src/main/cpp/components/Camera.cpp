//
// Created by hu jun on 2019-11-27.
//

#include "Camera.h"

Camera::Camera() {
    //相机在屏幕正上方
    pose = glm::vec3(0.0f, 0.0f, 3.0f);

    cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
    //相机方向，并不是相机面朝的方向，而是相机背对的方向
    direction = glm::normalize(pose - cameraTarget);

    vec3 tUp = glm::vec3(0.0f, 1.0f, 0.0f);
    right = glm::normalize(glm::cross(tUp, direction));

    up = glm::cross(direction, right);
}


Camera::~Camera() {

}

void Camera::setPose(vec3 pose) {
    this->pose = pose;
}

void Camera::setTarget(vec3 target) {
    this->cameraTarget = target;
}

void Camera::setUp(vec3 up) {
    this->up = up;
}

mat4 Camera::lookAt() {
    return lookAt(pose, cameraTarget, up);
}

mat4 Camera::lookAt(vec3 pose, vec3 target, vec3 up) {
    return glm::lookAt(pose, target, up);
}
