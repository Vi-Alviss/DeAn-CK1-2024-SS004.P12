#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <fstream>
#include <string>

#include "Snake.h"
#include "mylib.h"
#include "Food.h"

#define Width 53
#define Height 25

using namespace std;

void Result()
{
    SetColor(8);
    DisplaySnakeArt();

    SetColor(3);
    DrawWall();
    GetXY(50 / 2 - 13, 25 / 2 - 1);
    for (int i = 11; i < 15; i++)
    {
        SetColor(i);
        if (i == 14)
        {
            cout << "O";
        }
        else
        {
            cout << "o";
        }
    }

    SetColor(10);
    std::cout << " $$";

    SetColor(15);
    cout << "  YOUR RESULT  ";
    SetColor(10);
    std::cout << "$$ ";

    for (int i = 14; i >= 11; i--)
    {
        SetColor(i);
        if (i == 14)
        {
            cout << "O";
        }
        else
        {
            cout << "o";
        }
    }
}


int main()
{
    return 0;
}
