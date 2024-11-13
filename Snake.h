#pragma once
#include "mylib.h"
#include "Food.h"



class Snake
{
public:
    vector<COORD> object;
    int dx, dy;

    void Draw();
    void Erase();
    Snake();
    void Move_Snake(bool grow);
    void Change_dir(int new_dx, int new_dy);
    bool CollisionBody();
    bool Eat_food(Food &p_food,int &mark);
};