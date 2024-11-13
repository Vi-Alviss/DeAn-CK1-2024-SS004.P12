#include "Snake.h"


void Snake::Erase()
{
    // Xóa toàn bộ con rắn (để vẽ lại sau)
    for (const auto &pos : object)
    {
        GetXY(pos.X, pos.Y);
        cout << " ";
    }
}
