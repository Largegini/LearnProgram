#pragma once

//초기화 함수(매개변수초기화 뒤에서부터 된다)
void Initialize(Object* _Object, char* _Name, int _PosX = 0, int _PosY = 0, int _PosZ = 0);
char* SetName(Object* _Object);

// 커서위치 변경
void SetCursorPosition(int _x, int _y);

//	글자색 변경
void SetTextColor(int _Color);

//	출력할 Text의 위치와 색상을 변경해 준다. (Color 기본 값은 15(흰색) 
void OnDrawText(const char* _str, const int _x, const int _y, const int _Color = 15);
//	출력할 숫자의 위치와 색상을 변경해 준다. (Color 기본 값은 15(흰색) 
void OnDrawText(const int _Value, const int _x, const int _y, const int _Color = 15);

//	**** 충돌처리를 함
void Collision(Object* _ObjectA, Object* _ObjectB);
// **** bullet을 생성함
Object* CreateBullet(const int _x, const int _y);

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

void Initialize(Object* _Object, char* _Name, int _PosX, int _PosY, int _PosZ)
{
	//삼항 연산자  조건 ? A : B
	// 조건이 True면 A실행 False면 B실행
	_Object->Info.Texture = (_Name == nullptr) ? SetName(_Object) : _Name;

	_Object->Speed = 0;

	_Object->TransInfo.Position = Vector3(_PosX, _PosY, _PosZ);
	_Object->TransInfo.Rotation = Vector3(0, 0, 0);
	_Object->TransInfo.Scale = Vector3(strlen(_Object->Info.Texture), 1, 0);
}

//충돌
void Collision(Object* _ObjectA, Object* _ObjectB)
{

	if ((_ObjectA->TransInfo.Position.x + _ObjectA->TransInfo.Scale.x) > _ObjectB->TransInfo.Position.x &&
		(_ObjectB->TransInfo.Position.x + _ObjectB->TransInfo.Scale.x) > _ObjectA->TransInfo.Position.x &&
		_ObjectA->TransInfo.Position.y == _ObjectB->TransInfo.Position.y
		)
	{
		OnDrawText((char*)"충돌 입니다.", 60 - strlen("충돌 입니다.") / 2, 0, 14);
	}
}

Object* CreateBullet(const int _x, const int _y)
{
	Object* pBullet = new Object;

	Initialize(pBullet, (char*)"장풍!!", _x + 2, _y);

	return pBullet;
}

//	커서위치 변경
void SetCursorPosition(int _x, int _y)
{
	COORD Pos = { (SHORT)_x, (SHORT)_y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

}

void SetTextColor(int _Color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _Color);
}

void OnDrawText(const char* _str, const int _x, const int _y, const int _Color)
{
	SetCursorPosition(_x, _y);
	SetTextColor(_Color);
	cout << _str;
}

void OnDrawText(const int _Value, const int _x, const int _y, const int _Color)
{
	SetCursorPosition(_x, _y);
	SetTextColor(_Color);

	char* pText = new char[4];
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