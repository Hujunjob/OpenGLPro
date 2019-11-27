//
// Created by hu jun on 2019-11-27.
//

#include "Camera.h"

Camera::Camera() {
    //相机在屏幕正上方
    pose = glm::vec3(0.0f,0.0f,3.0f);

    vec3 cameraTarget = glm::vec3(0.0f,0.0f,0.0f);
    //相机方向，并不是相机面朝的方向，而是相机背对的方向
    direction = glm::normalize(pose - cameraTarget);

    vec3 tUp = glm::vec3(0.0f,1.0f,0.0f);
    right = glm::normalize(glm::cross(tUp,direction));

    up = glm::cross(direction,right);
}

Camera::~Camera() {

}
