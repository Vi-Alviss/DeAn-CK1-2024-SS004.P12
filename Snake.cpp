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
void Snake::Change_dir(int new_dx, int new_dy)
{
    if (new_dx != -dx || new_dy != -dy)
    {
        dx = new_dx;
        dy = new_dy;
    }
}
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


Snake::Snake() : dx(1), dy(0)
{
    object.push_back({50 / 2, 25 / 2});
    object.push_back({50 / 2 - 1, 25 / 2});
    object.push_back({50 / 2 - 2, 25 / 2});
}
bool Snake:: Eat_food(Food &p_food, int &mark)
{
    if (object[0].X == p_food.Pos_food.X && object[0].Y == p_food.Pos_food.Y)
    {
        p_food.Respawn_food();
        mark += p_food.point;
        return true;
    }
    return false;
}
void Snake::Draw()
{
    for (const auto &pos : object)
    {
        GetXY(pos.X, pos.Y);
        cout << "X";
    }

}