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

void UpdateBXH(const string fileName, int p_score, string p_PlayerName)
{
    int high_score = 0;
    string HighgPlayerName;
    ifstream infile(fileName);
    if (infile.is_open())
    {
        infile >> high_score;
        infile >> HighgPlayerName;
        infile.close();
    }

    Result(); 
    if (p_score > high_score)
    {
        HighgPlayerName = p_PlayerName;
        ofstream outfile(fileName);
        if (outfile.is_open())
        {
            outfile << p_score;
            outfile << HighgPlayerName;
            outfile.close();
            GetXY(50 / 2 - 13, 25 / 2 + 1);
            SetColor(2);
            cout << "New Record: ";
            SetColor(15);
            cout << p_score;
            SetColor(10);
            cout << " $";

            GetXY(50 / 2 - 13, 25 / 2 + 3);
            SetColor(9);
            cout << "Congrats Ur Highest Player: ";
            SetColor(15);
            cout << HighgPlayerName;
        }
        else
        {
            cerr << "Can not write in file." << endl;
        }
    }
    else
    {

        GetXY(50 / 2 - 13, 25 / 2 + 1);
        SetColor(15);
        cout << "Highest Record: " << high_score;
        SetColor(10);
        cout << " $";
        SetColor(15);
        GetXY(50 / 2 - 13, 25 / 2 + 2);
        cout << "Highest Player name: " << HighgPlayerName;
        GetXY(50 / 2 - 13, 25 / 2 + 4);
        cout << "Your total money: " << p_score;
        SetColor(10);
        cout << " $";
    }
}

int main()
{
    return 0;
}
