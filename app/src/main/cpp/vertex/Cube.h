//
// Created by JUN HU on 2019-11-27.
//

#ifndef OPENGLDEMO_CUBE_H
#define OPENGLDEMO_CUBE_H

#pragma once
#include "../utils/utils.h"

class Cube {
private:
    uint VBO;
    uint VAO;
    void generateVBO();

public:
    Cube();
    ~Cube();
    void create();
    void draw();
};


#endif //OPENGLDEMO_CUBE_H
