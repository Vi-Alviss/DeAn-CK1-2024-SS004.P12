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
bool isPaused = false;


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

int main()
{
    return 0;
}
