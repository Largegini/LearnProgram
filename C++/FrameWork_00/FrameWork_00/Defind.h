#pragma once

//�ʱ�ȭ �Լ�(�Ű������ʱ�ȭ �ڿ������� �ȴ�)
void Initialize(Object* _Object, char* _Name, int _PosX = 0, int _PosY = 0, int _PosZ = 0);
char* SetName(Object* _Object);

// Ŀ����ġ ����
void SetCursorPosition(int _x, int _y);

//	���ڻ� ����
void SetTextColor(int _Color);

//	����� Text�� ��ġ�� ������ ������ �ش�. (Color �⺻ ���� 15(���) 
void OnDrawText(const char* _str, const int _x, const int _y, const int _Color = 15);
//	����� ������ ��ġ�� ������ ������ �ش�. (Color �⺻ ���� 15(���) 
void OnDrawText(const int _Value, const int _x, const int _y, const int _Color = 15);

//	**** �浹ó���� ��
void Collision(Object* _ObjectA, Object* _ObjectB);
// **** bullet�� ������
Object* CreateBullet(const int _x, const int _y);

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

void Initialize(Object* _Object, char* _Name, int _PosX, int _PosY, int _PosZ)
{
	//���� ������  ���� ? A : B
	// ������ True�� A���� False�� B����
	_Object->Info.Texture = (_Name == nullptr) ? SetName(_Object) : _Name;

	_Object->Speed = 0;

	_Object->TransInfo.Position = Vector3(_PosX, _PosY, _PosZ);
	_Object->TransInfo.Rotation = Vector3(0, 0, 0);
	_Object->TransInfo.Scale = Vector3(strlen(_Object->Info.Texture), 1, 0);
}

//�浹
void Collision(Object* _ObjectA, Object* _ObjectB)
{

	if ((_ObjectA->TransInfo.Position.x + _ObjectA->TransInfo.Scale.x) > _ObjectB->TransInfo.Position.x &&
		(_ObjectB->TransInfo.Position.x + _ObjectB->TransInfo.Scale.x) > _ObjectA->TransInfo.Position.x &&
		_ObjectA->TransInfo.Position.y == _ObjectB->TransInfo.Position.y
		)
	{
		OnDrawText((char*)"�浹 �Դϴ�.", 60 - strlen("�浹 �Դϴ�.") / 2, 0, 14);
	}
}

Object* CreateBullet(const int _x, const int _y)
{
	Object* pBullet = new Object;

	Initialize(pBullet, (char*)"��ǳ!!", _x + 2, _y);

	return pBullet;
}

//	Ŀ����ġ ����
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