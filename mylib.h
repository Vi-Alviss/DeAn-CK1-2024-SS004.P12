#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>
#define KEY_NONE -1

#define Width 53
#define Height 25

using namespace std;

int whereX();
int whereY();
void GetXY(int p_X, int p_Y);
void SetColor(WORD color);
void ShowCur(bool CursorVisibility);
void DrawWall();
