#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include "mylib.h"
#include "Food.h"
#include <fstream>
#include <string>
#include "Snake.h"

#define Width 50
#define Height 25

using namespace std;

int Score = 0;


bool Get_Key(Snake &p_snake)
{
    if (_kbhit())
    {
        char key = _getch();

        switch (key)
        {
        case 72:
            p_snake.Change_dir(0, -1);
            break;
        case 80:
            p_snake.Change_dir(0, 1);
            break;
        case 75:
            p_snake.Change_dir(-1, 0);
            break;
        case 77:
            p_snake.Change_dir(1, 0);
            break;
        case 'e':
            cout << Score;
            return false;
        }
    }
    return true;
}

int main()
{
    return 0;
}
