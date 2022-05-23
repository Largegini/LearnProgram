#pragma once

//초기화 함수(매개변수초기화 뒤에서부터 된다)
void Initialize(Object* _Object, char* _Name, float _PosX = 0, float _PosY = 0, float _PosZ = 0);
char* SetName(Object* _Object);

// 커서위치 변경
void SetCursorPosition(float _x, float _y);

//	글자색 변경
void SetTextColor(int _Color);

//	출력할 Text의 위치와 색상을 변경해 준다. (Color 기본 값은 15(흰색) 
void OnDrawText(const char* _str, const float _x, const float _y, const int _Color = 15);
//	출력할 숫자의 위치와 색상을 변경해 준다. (Color 기본 값은 15(흰색) 
void OnDrawText(const int _Value, const float _x, const float _y, const int _Color = 15);

//	**** 충돌처리를 함
bool Collision(Object* _ObjectA, Object* _ObjectB);
// **** bullet을 생성함
Object* CreateBullet(const float _x, const float _y);
Object* CreateEnemyBullet(const float _x, const float _y);
Object* CreateEnemy(const float _x, const float _y);

//	커서 표시(true)/비표시(false)
void HideCursor(bool _Visible);

char* SetName(Object* _Player)
{
	char Buffer[128] = "";

	//*** 문자열의 길이+1만큼의 공간 할당
	//char* pName = (char*)malloc(strlen(Buffer)+1);
	char* pName = new char[strlen(Buffer) + 1];


	cout << "이름을 입력하세요 : ";


	cin >> Buffer;

	strcpy(pName, Buffer);

	return pName;
}

void Initialize(Object* _Object, char* _Name, float _PosX, float _PosY, float _PosZ)
{
	//삼항 연산자  조건 ? A : B
	// 조건이 True면 A실행 False면 B실행
	_Object->Info.Texture = (_Name == nullptr) ? SetName(_Object) : _Name;

	_Object->Speed = 0;

	_Object->TransInfo.Position = Vector3(_PosX, _PosY, _PosZ);
	_Object->TransInfo.Rotation = Vector3(0, 0, 0);
	_Object->TransInfo.Scale = Vector3((float)strlen(_Object->Info.Texture), 1, 0);
}

//충돌
bool Collision(Object* _ObjectA, Object* _ObjectB)
{
	bool Coll = false;
	if ((_ObjectA->TransInfo.Position.x + 0.5f + _ObjectA->TransInfo.Scale.x) > _ObjectB->TransInfo.Position.x &&
		(_ObjectB->TransInfo.Position.x + 0.5f + _ObjectB->TransInfo.Scale.x) > _ObjectA->TransInfo.Position.x &&
		_ObjectA->TransInfo.Position.y + 0.5f == _ObjectB->TransInfo.Position.y
		)
		return true;

	return false;
}

Object* CreateBullet(const float _x, const float _y)
{
	Object* pBullet = new Object;

	Initialize(pBullet, (char*)"장풍!!", (float)_x + 2.0f, (float)_y);

	return pBullet;
}

Object* CreateEnemyBullet(const float _x, const float _y)
{
	Object* pBullet = new Object;

	Initialize(pBullet, (char*)"◆", (float)_x -2.0f, (float)_y);

	return pBullet;
}

Object* CreateEnemy(const float _x, const float _y)
{
	Object* _Object = new Object;

	Initialize(_Object, (char*)"홋", (float)_x + 2.0f, (float)_y);

	return _Object;
}

//	커서위치 변경
void SetCursorPosition(float _x, float _y)
{
	COORD Pos = { (SHORT)_x, (SHORT)_y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

}

void SetTextColor(int _Color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _Color);
}

void OnDrawText(const char* _str, const float _x, const float _y, const int _Color)
{
	SetCursorPosition((float)_x, (float)_y);
	SetTextColor(_Color);
	cout << _str;
}

void OnDrawText(const int _Value, const float _x, const float _y, const int _Color)
{
	SetCursorPosition((float)_x, (float)_y);
	SetTextColor(_Color);

	char* pText = new char[8];
	_itoa(_Value, pText, 10);

	cout << _Value;
}

void HideCursor(bool _Visible)
{
	CONSOLE_CURSOR_INFO CursorInfo;

	CursorInfo.bVisible = _Visible;
	CursorInfo.dwSize = 1;

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CursorInfo);
}

