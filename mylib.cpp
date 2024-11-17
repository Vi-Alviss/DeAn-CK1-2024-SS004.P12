#include "mylib.h"

int whereX() // lay toa do X
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
        return csbi.dwCursorPosition.X;
    return -1;
}

int whereY() // lay toa do y
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
        return csbi.dwCursorPosition.Y;
    return -1;
}

void GetXY(int p_X, int p_Y)
{
    COORD ToaDo;
    ToaDo.X = p_X;
    ToaDo.Y = p_Y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), ToaDo);
}

void SetColor(WORD color) // dat mau cho chu
{
    HANDLE hConsoleOutPut;
    hConsoleOutPut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutPut, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    wAttributes &= 0xfff0;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutPut, wAttributes);
}

void ShowCur(bool CursorVisibility) // lam an con tro chuot
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor = {1, CursorVisibility};
    SetConsoleCursorInfo(handle,&cursor);
}

void DrawWall()
{
    for (int i = 0; i < Width + 2; i++)
    {
        GetXY(i, 0);
        cout << "#";
        GetXY(i, Height + 1);
        cout << "#";
    }
    for (int i = 0; i < Height + 2; i++)
    {
        GetXY(0, i);
        cout << "#";
        GetXY(Width + 1, i);
        cout << "#";
    }
}

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