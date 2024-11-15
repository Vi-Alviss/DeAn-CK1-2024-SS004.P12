#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <fstream>
#include <string>
#include <limits>
#include "Snake.h"
#include "mylib.h"
#include "Food.h"

#define Width 53
#define Height 25
bool isPaused = false;

int Score = 0;
int speed = 0;

using namespace std;
void DisplaySnakeArt()
{
    std::cout << R"(



         /^\/^\
       _|__|  O|
\/     /~     \_/ \
 \____|__________/  \
        \_______      \
                `\     \                 \
                  |     |                  \
                 /      /                    \
                /     /                       \\ 
              /      /                         \ \
             /     /                            \  \
           /     /             _----_            \   \
          /     /           _-~      ~-_         |   |
         (      (        _-~    _--_    ~-_     _/   |
          \      ~-____-~    _-~    ~-_    ~-_-~    /
            ~-_           _-~          ~-_       _-~
               ~--______-~                ~-___-~
    )" << std::endl;
}
void Title()
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
    cout << "  GREEDY SNAKE ";
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

    SetColor(14);
}

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
bool Get_Key(Snake &p_snake)
{
    if (_kbhit())
    {
        char key = _getch();

        switch (key)
        {
        case 72: // Arrow Up
            if (!isPaused)
                p_snake.Change_dir(0, -1);
            break;
        case 80: // Arrow Down
            if (!isPaused)
                p_snake.Change_dir(0, 1);
            break;
        case 75: // Arrow Left
            if (!isPaused)
                p_snake.Change_dir(-1, 0);
            break;
        case 77: // Arrow Right
            if (!isPaused)
                p_snake.Change_dir(1, 0);
            break;
        case 'p':                 // Toggle pause
            isPaused = !isPaused; // Toggle the pause state
            if (isPaused)
            {
                // Show a pause message
                while (true)
                {
                    GetXY(50 / 2 - 16, 25 / 2 + 1);
                    SetColor(14);
                    cout << "Game paused, press 'P' to continue.... ";
                    Sleep(400);
                    GetXY(50 / 2 - 16, 25 / 2 + 1);
                    cout << "                                       ";
                    Sleep(400);

                    if (_kbhit())
                    {
                        char key = _getch();
                        if (key == 'p')
                        {
                            isPaused = !isPaused;
                            break;
                        }
                    }
                }
            }
        }
    }
    return true;
}

void Choosing_Difficulty()
{
    int diff;
    GetXY(50 / 2 - 9, 25 / 2 + 1);
    SetColor(14);
    cout << "*****  Difficulty *****  ";
    GetXY(50 / 2 - 14, 25 / 2 + 2);
    SetColor(15);
    cout << "______________________________";
    GetXY(50 / 2 - 6, 25 / 2 + 3);
    SetColor(12);
    cout << "Hard: 1";
    GetXY(50 / 2 - 6, 25 / 2 + 4);
    SetColor(6);
    cout << "Normal: 2";
    GetXY(50 / 2 - 6, 25 / 2 + 5);
    SetColor(2);
    cout << "Easy: 3";
}

int main()
{
    return 0;
}
