#include "Food.h"
<<<<<<< HEAD

=======
>>>>>>> main
Food::Food()
{
    point = 10;
    Food::Respawn_food();
}

void Food::Respawn_food()
{
    Pos_food.X = (rand() % Width) + 1;
    Pos_food.Y = (rand() % Height) + 1;
}

void Food::Draw_Food()
{
    GetXY(Pos_food.X, Pos_food.Y);
    cout << "O";
}