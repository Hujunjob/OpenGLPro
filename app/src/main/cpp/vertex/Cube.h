//
// Created by JUN HU on 2019-11-27.
//

#ifndef OPENGLDEMO_CUBE_H
#define OPENGLDEMO_CUBE_H


#include "../utils/utils.h"

class Cube {
private:
    float cubeVertices[];
    uint VBO;
public:
    void create();
};


#endif //OPENGLDEMO_CUBE_H
