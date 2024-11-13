#include "Snake.h"


void Snake::Erase()
{
    // Xóa toàn bộ con rắn (để vẽ lại sau)
    for (const auto &pos : object)
    {
        GetXY(pos.X, pos.Y);
        cout << " ";
    }
}
bool Snake::CollisionBody()
{
    for (int i = 1; i < object.size(); i++)
    {
        if (object[0].X == object[i].X && object[0].Y == object[i].Y)
        {
            return true;
        }
    }
    return false;
}