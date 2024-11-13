#include "Snake.h"
void Snake::Move_Snake(bool grow = false)
{
    COORD newhead = {(SHORT)(object[0].X + (SHORT)dx), (SHORT)(object[0].Y + (SHORT)dy)};

    // Check Collision with wall
    if (newhead.X < 1)
        newhead.X = Width;
    else if (newhead.X > Width)
        newhead.X = 1;
    if (newhead.Y < 1)
        newhead.Y = Height;
    else if (newhead.Y > Height)
        newhead.Y = 1;
    object.insert(object.begin(), newhead);
    if (!grow)
    {
        object.pop_back();
    }
}