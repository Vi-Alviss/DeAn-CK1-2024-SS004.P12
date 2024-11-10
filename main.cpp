#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>

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
void GetXY(int p_X, int p_Y)
{
    COORD ToaDo;
    ToaDo.X = p_X;
    ToaDo.Y = p_Y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), ToaDo);
}
class Food {
public:
    COORD Pos_food;
    int score;
    // Khoi tao thuc an
    Food() {
        score = 10;
        Respawn_food();
    }
    //Sinh ngau nhien
    void Respawn_food (){
        Pos_food.X = rand() % Width;
        Pos_food.Y = rand() % Height;
    }
    // Hien thi thuc an tren man hinh
    void Draw_Food () const{
        GetXY(Pos_food.X,Pos_food.Y);
        cout<<"O";
    }

};
class Snake
{
public:
    vector<COORD> object;
    int dx, dy;
    Snake() : dx(1), dy(0)
    {
        object.push_back({50 / 2, 25 / 2});
        object.push_back({50/2 - 1, 25/2});
        object.push_back({50/2 -2, 25/2});
    }
    void Draw()
    {
        for (const auto &pos : object)
        {
            GetXY(pos.X, pos.Y);
            cout << "X";
        }
        // GetXY(object.back().X, object.back().Y);
        // cout << " ";
    }
        void Erase()
    {
        // Xóa toàn bộ con rắn (để vẽ lại sau)
        for (const auto &pos : object)
        {
            GetXY(pos.X, pos.Y);
            cout << " ";
        }
    }
    void Move_Snake (bool grow = false){
        COORD newhead = { (SHORT)(object[0].X + (SHORT)dx), (SHORT)(object[0].Y + (SHORT)dy) };

        object.insert(object.begin(), newhead);
        if(! grow){
            object.pop_back();
        }
    }
    void Change_dir(int new_dx, int new_dy)
    {
        if (new_dx != -dx || new_dy != -dy){
            dx = new_dx;
            dy = new_dy;
        }
    }
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
    Snake s;
    bool run = true;
    srand(static_cast<unsigned int>(time(0)));
    Food O_food;
    while (run)
    {
        O_food.Respawn_food();
        O_food.Draw_Food();
        run = Get_Key(s);
        s.Erase();
        s.Move_Snake();
        s.Draw();
        Sleep(500);
        /* code */
    }
    return 0;
}
