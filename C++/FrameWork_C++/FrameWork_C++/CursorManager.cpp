#include "CursorManager.h"

CursorManager* CursorManager::Instance = nullptr;

void CursorManager::SetcursorPosition(float _x, float _y, char* _str, int _Color)
{
	COORD pos = { (SHORT)_x, (SHORT)_y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	SetColor(_Color);

	cout << _str;
}

void CursorManager::SetcursorPosition(Vector3 _Position, char* _str, int _Color)
{
	COORD pos = { (SHORT)_Position.x, (SHORT)_Position.y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	SetColor(_Color);

	cout << _str;
}

void CursorManager::SetColor(int _Color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _Color);
}

CursorManager::CursorManager()
{
}

CursorManager::~CursorManager()
{
}
