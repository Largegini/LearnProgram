#pragma once

//�ʱ�ȭ �Լ�(�Ű������ʱ�ȭ �ڿ������� �ȴ�)
void Initialize(Object* _Object, char* _Name, float _PosX = 0, float _PosY = 0, float _PosZ = 0);
char* SetName(Object* _Object);

// Ŀ����ġ ����
void SetCursorPosition(float _x, float _y);

//	���ڻ� ����
void SetTextColor(int _Color);

//	����� Text�� ��ġ�� ������ ������ �ش�. (Color �⺻ ���� 15(���) 
void OnDrawText(const char* _str, const float _x, const float _y, const int _Color = 15);
//	����� ������ ��ġ�� ������ ������ �ش�. (Color �⺻ ���� 15(���) 
void OnDrawText(const int _Value, const float _x, const float _y, const int _Color = 15);

//	**** �浹ó���� ��
bool Collision(Object* _ObjectA, Object* _ObjectB);
// **** bullet�� ������
Object* CreateBullet(const float _x, const float _y);
Object* CreateEnemyBullet(const float _x, const float _y);
Object* CreateEnemy(const float _x, const float _y);

//	Ŀ�� ǥ��(true)/��ǥ��(false)
void HideCursor(bool _Visible);

char* SetName(Object* _Player)
{
	char Buffer[128] = "";

	//*** ���ڿ��� ����+1��ŭ�� ���� �Ҵ�
	//char* pName = (char*)malloc(strlen(Buffer)+1);
	char* pName = new char[strlen(Buffer) + 1];


	cout << "�̸��� �Է��ϼ��� : ";


	cin >> Buffer;

	strcpy(pName, Buffer);

	return pName;
}

void Initialize(Object* _Object, char* _Name, float _PosX, float _PosY, float _PosZ)
{
	//���� ������  ���� ? A : B
	// ������ True�� A���� False�� B����
	_Object->Info.Texture = (_Name == nullptr) ? SetName(_Object) : _Name;

	_Object->Speed = 0;

	_Object->TransInfo.Position = Vector3(_PosX, _PosY, _PosZ);
	_Object->TransInfo.Rotation = Vector3(0, 0, 0);
	_Object->TransInfo.Scale = Vector3((float)strlen(_Object->Info.Texture), 1, 0);
}

//�浹
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

	Initialize(pBullet, (char*)"��ǳ!!", (float)_x + 2.0f, (float)_y);

	return pBullet;
}

Object* CreateEnemyBullet(const float _x, const float _y)
{
	Object* pBullet = new Object;

	Initialize(pBullet, (char*)"��", (float)_x -2.0f, (float)_y);

	return pBullet;
}

Object* CreateEnemy(const float _x, const float _y)
{
	Object* _Object = new Object;

	Initialize(_Object, (char*)"Ȫ", (float)_x + 2.0f, (float)_y);

	return _Object;
}

//	Ŀ����ġ ����
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

