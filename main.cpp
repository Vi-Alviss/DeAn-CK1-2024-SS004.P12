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
#include <ctime>

#define Width 53
#define Height 25

using namespace std;
int Score = 0;
int color_Score = 15;
int color_Food = 2;
int color = 1;
int speed = 0;
bool check_play_again = false;

//
bool isPaused = false;
//

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
        
        case 'w':
        case 'W':
        case 72: // Arrow Up
            if (!isPaused)
                p_snake.Change_dir(0, -1);
            break;
        case 's':
        case 'S':
        case 80: // Arrow Down
            if (!isPaused)
                p_snake.Change_dir(0, 1);
            break;
        case 'a':
        case 'A':
        case 75: // Arrow Left
            if (!isPaused)
                p_snake.Change_dir(-1, 0);
            break;
        case 'd':
        case 'D':
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
        cout << "Highest Player's name: " << HighgPlayerName;
        GetXY(50 / 2 - 13, 25 / 2 + 4);
        cout << "Your total money: " << p_score;
        SetColor(10);
        cout << " $";
    }
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

    GetXY(50 / 2 - 6, 25 / 2 + 7);
    SetColor(13);
    cout << "Select difficulty: ";
    do
    {
        SetColor(13);

        cin >> diff;
        if (diff < 1 || diff > 3)
        {
            GetXY(50 / 2 - 10, 25 / 2 + 8);
            SetColor(4);
            cout << "Wrong difficulty, select again !";
            GetXY(50 / 2 + 13, 25 / 2 + 7);
        }
    } while (diff < 1 || diff > 3);

    switch (diff)
    {
    case 1:
        speed = 60;
        break;
    case 2:
        speed = 100;
        break;
    default:
        speed = 160;
    }
}

void Setup(Snake s, string player_name = "")
{

    ofstream BXH("BXH.txt");
    GetXY(50 / 2 - 8, 25 / 2 + 1);
    SetColor(14);
    cout << "Enter Player's name: \n";
    ShowCur(true);
    GetXY(50 / 2 - 3, 25 / 2 + 2);
    SetColor(15);
    getline(cin, player_name);

    Choosing_Difficulty();

    system("cls");
    ShowCur(false);
    std::cout << endl;
    bool run = true;
    srand(static_cast<unsigned int>(time(0)));
    Food O_food;

    SetColor(3);
    DrawWall();

    SetColor(color_Score);
    GetXY(Width + 6, 3);

    while (run)
    {

        int mark = 0;
        run = Get_Key(s);

        if (!isPaused)
        {
            s.Erase();

            SetColor(color_Score);
            GetXY(Width + 5, 3);
            cout << "Your total money: " << Score;
            SetColor(10);
            std::cout << " $";

            bool grew = s.Eat_food(O_food, mark);
            if (grew == true)
            {
                Score = Score + mark;
                color = (color + 1) % 16;
                if (color == color_Score)
                    color = (color + 1) % 16;
                if (color == 0)
                    color = color + 1;
            }
            SetColor(color);
            s.Move_Snake(grew);
        }

        if (s.CollisionBody())
        {
            system("cls");
            UpdateBXH("BXH", Score, player_name);
            // Control after playing
            while (true)
            {
                SetColor(14);
                GetXY(50 / 2 - 8, 25 / 2 + 6);
                std::cout << "Press 'E' to EXIT";
                GetXY(50 / 2 - 8, 25 / 2 + 8);
                std::cout << "Press 'R' to RESTART";
                Sleep(400);
                GetXY(50 / 2 - 8, 25 / 2 + 6);
                std::cout << "                 ";
                GetXY(50 / 2 - 8, 25 / 2 + 8);
                std::cout << "                     ";
                Sleep(400);

                if (_kbhit())
                {
                    char key = _getch();
                    if (key == 'e' || key == 'E')
                    {
                        GetXY(0, Height + 3);
                        SetColor(15);
                        exit(0);
                        // return;
                    }
                    else if (key == 'r' || key == 'R')
                    {
                        check_play_again = true;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        SetColor(8);
                        break;
                    }
                }
            }
            // Control after playing
            if (check_play_again)
            {
                system("cls");
                Title();
                Score = 0;
                Snake new_s;
                Setup(new_s, player_name);
                check_play_again = false;
            }
            break;
        }

        s.Draw();
        SetColor(color_Food);
        O_food.Draw_Food();

        Sleep(speed);
    }
}

void ShowBlinkingText()
{

    while (true)
    {
        GetXY(50 / 2 - 8, 25 / 2 + 1);
        cout << "Press 'S' to START";
        Sleep(400);
        GetXY(50 / 2 - 8, 25 / 2 + 1);
        cout << "                  ";
        Sleep(400);

        if (_kbhit())
        {
            char key = _getch();
            if (key == 's' || key == 'S')
                return;
        }
    }
}

int main()
{
    system("cls");
    ShowCur(false);
    Snake s;
    Title();
    ShowBlinkingText();
    SetColor(15);
    Setup(s);

    ShowCur(true);

    return 0;
}
