#pragma once
void Initialize(Object* _Object, char* _Texture, float _Posx = 0, float _Posy = 0, float _Posz = 0);

char* SetName();

void SetCursorPosition(const float _x, const float _y);

void SetTextColor(const int _Color);

void OnDrawText(const char* _str, const float _x, const float _y, const int _Color = 15);
void OnDrawText(const int _Value, const float _x, const float _y, const int _Color = 15);

void UpdateInput(Object* _Object);

bool Collision(const Object* _ObjectA, const Object* _ObjectB);

float GetDistance(const Object* _ObjectA, const Object* _ObjectB);

Vector3 GetDirection(const Object* _ObjectA, const Object* _ObjectB);

Object* CreateBullet(const float _x, const float _y);

Object* CreateEnemy(const float _x, const float _y);

void HideCursor(const bool _Visible);

void Initialize(Object* _Object, char* _Texture, float _Posx, float _Posy, float _Posz)
{
	_Object->Info.Texture = (_Texture == nullptr) ? SetName() : _Texture;

	_Object->Power = 0;

	_Object->TransInfo.Position = Vector3(_Posx, _Posy, _Posz);
	_Object->TransInfo.Rotation = Vector3(0.0f, 0.0f, 0.0f);
	_Object->TransInfo.Scale = Vector3(
		(float)strlen(_Object->Info.Texture), 1.0f, 0.0f);
}

char* SetName()
{
	char Buffer[128] = "";

	cout << "ÀÌ¸§ ÀÔ·Â : "; cin >> Buffer;

	char* pName = new char[strlen(Buffer) + 1];

	strcpy(pName, Buffer);

	return pName;
}

void SetCursorPosition(const float _x, const float _y)
{
	COORD Pos = { (SHORT)_x, (SHORT)_y };

	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void SetTextColor(const int _Color)
{

	SetConsoleTextAttribute(
		GetStdHandle(STD_OUTPUT_HANDLE), _Color);
}

void OnDrawText(const char* _str, const float _x, const float _y, const int _Color) 
{
	SetCursorPosition(_x, _y);
	SetTextColor(_Color);

	cout << _str;
}

void OnDrawText(const int _Value, const float _x, const float _y, const int _Color)
{
	SetCursorPosition(_x, _y);
	SetTextColor(_Color);

	char* pText = new char[4];
	_itoa(_Value, pText, 10);
	cout << _Value;
}

void UpdateInput(Object* _Object)
{
	if (GetAsyncKeyState(VK_UP))
		_Object->TransInfo.Position.y -= 1;

	if (GetAsyncKeyState(VK_DOWN))
		_Object->TransInfo.Position.y += 1;

	if (GetAsyncKeyState(VK_LEFT))
		_Object->TransInfo.Position.x -= 1;

	if (GetAsyncKeyState(VK_RIGHT))
		_Object->TransInfo.Position.x += 1;
}

bool Collision(const Object* _ObjectA, const Object* _ObjectB)
{
	if ((_ObjectA->TransInfo.Position.x + _ObjectA->TransInfo.Scale.x) >= _ObjectB->TransInfo.Position.x &&
		(_ObjectB->TransInfo.Position.x + _ObjectB->TransInfo.Scale.x) >= _ObjectB->TransInfo.Position.x &&
		_ObjectA->TransInfo.Position.y == _ObjectB->TransInfo.Position.y)
		return true;
	return false;
}

float GetDistance(const Object* _ObjectA, const Object* _ObjectB)
{
	float x = _ObjectA->TransInfo.Position.x - _ObjectB->TransInfo.Position.x;
	float y = _ObjectB->TransInfo.Position.y - _ObjectB->TransInfo.Position.y;

	return sqrt((x * x) + (y * y));
}

Vector3 GetDirection(const Object* _ObjectA, const Object* _ObjectB)
{
	float x = _ObjectA->TransInfo.Position.x - _ObjectB->TransInfo.Position.x;
	float y = _ObjectB->TransInfo.Position.y - _ObjectB->TransInfo.Position.y;

	float Distance = sqrt((x * x) + (y + y));

	return Vector3(x / Distance, y / Distance);
}

Object* CreateBullet(const float _x, const float _y)
{
	Object* _Object = new Object;

	Initialize(_Object, (char*)"¡Ü", _x+2, _y);

	return _Object;
}

Object* CreateEnemy(const float _x, const float _y)
{
	Object* _Object = new Object;

	Initialize(_Object, (char*)"Èª", _x, _y);

	return _Object;
}

void HideCursor(const bool _Visible)
{
	CONSOLE_CURSOR_INFO CursorInfo;

	CursorInfo.bVisible = _Visible;
	CursorInfo.dwSize = 1;

	SetConsoleCursorInfo(
		GetStdHandle(STD_OUTPUT_HANDLE), &CursorInfo);
}
