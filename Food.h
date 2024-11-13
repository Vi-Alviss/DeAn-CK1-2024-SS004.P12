#pragma once
#include "mylib.h"

class Food
{
public:
    COORD Pos_food;
    int point;
    Food();
    void Respawn_food();
    void Draw_Food();
};