#include <iostream>
#include <conio.h>
#include <windows.h>    
void gotoxy(int x, int y)
{
    COORD coordinate;
    coordinate.X = x;
    coordinate.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}
using namespace std;

class Point
{
public:
    int x,y;
};

class Snake
{
public:
    int length;
    Point arr[100];

    Snake()
    {
        this->length = 6;
        arr[0].x = 5; arr[0].y = 4;
        arr[1].x = 4; arr[1].y = 4;
        arr[2].x = 4; arr[2].y = 3;
        arr[3].x = 4; arr[3].y = 2;
        arr[4].x = 3; arr[4].y = 2;
        arr[5].x = 2; arr[5].y = 2;
    }

    void Draw()
    {
        
        for (int i = 0 ;i < length; i++)
        {
            gotoxy(2 * arr[i].x,arr[i].y);
            std::cout << "XX";
        }
         gotoxy(2 * arr[length].x,arr[length].y); cout << "  ";
           
    }

    void Move(int direction)
    {
        for (int i = length ; i > 0; i--)
        {
            arr[i] = arr[i- 1];
        }

        if (direction == 1) arr[0].x = arr[0].x + 1;
        if (direction == 2) arr[0].y = arr[0].y + 1;
        if (direction == 3) arr[0].x = arr[0].x - 1;
        if (direction == 4) arr[0].y = arr[0].y - 1;

        
    }
};

int main()
{
    Snake s;
    int direction = 1;
    
    while (1)
    {
        s.Draw();
        Sleep(500);
        
        if (kbhit())
        { 
            char q = getch();
            if(q == 'd') direction = 1;
            if(q == 'a') direction = 3;                 
            if(q == 'w') direction = 4;
            if(q == 's') direction = 2;
            if(q == 'e') return 0;
        }    
        s.Move(direction);     
    }
    return 0;
}