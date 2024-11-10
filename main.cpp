#include <iostream>
#include <conio.h>
#include <windows.h>    
#include "mylib.h"
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
};

int main()
{
    std::cout << "hello world \n";
    return 0;
}
