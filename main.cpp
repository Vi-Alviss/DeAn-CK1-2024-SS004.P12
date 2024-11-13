#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include "mylib.h"
#include "Food.h"

#define Width 50
#define Height 25

using namespace std;

int Dir = 0;

class Point
{
public:
    int x, y;
    Point() : x(0), y(0) {}
    Point(int p_x, int p_y) : x(p_x), y(p_y) {}
};

bool Get_Key(Snake &p_snake)
{
    if (_kbhit())
    {
        char key = _getch();

        switch (key)
        {
        case 72:
            p_snake.Change_dir(0 , -1);
            break;
        case 80:
            p_snake.Change_dir(0 , 1);
            break;
        case 75:
            p_snake.Change_dir(-1 , 0);
            break;
        case 77:
            p_snake.Change_dir(1 , 0);
            break;
        case 'e' : return false;
        }
    }
    return true;
}

int main()
{
    return 0;
}
