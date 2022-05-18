#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

// ��������� ���߿� 3D�� ���ؼ� Vector3�� �̿�
// 2D���߿� Vector2�� �̿� ������ �ݵ�� �׷� ���� �ƴ�
struct Vector3
{
	int x = 0, y = 0, z = 0;

	// �⺻ ������
	// �Ű������� ����� �⺻ ������
	Vector3() {};

	//** ���� ������
	// ��������ڸ� ����� ���ؼ��� �⺻ ������ �� �־�ߵȴ�.
	// ���� �⺻������ ���̴� ���� �����ڸ� ���� �� ����.
	// �ϳ��� ���� �� �ִ°� �ƴϴ�
	//** �Ű������� ������ ���¿� ���� ���� �����ڸ� ���� �� �ִ�
	// �Ű������� ���� �����Ϸ��� �����ؼ� ȣ��
	// ':'�� �̿��� ����ȭ�� C++�� �ִ� ��� C�δ� �Ұ�
	Vector3(int _x, int _y)
		//x(_x) ���Կ��길 �̷��� ����ȭ ����
		: x(_x), y(_y), z(0) { };

	Vector3(int _x, int _y, int _z)
		: x(_x), y(_y), z(_z) { };



};

// Object�� �����ϱ� ���� �ʿ��� �ּ����� ��
struct Transform
{
	Vector3 Position;
	Vector3 Rotation;
	Vector3 Scale;
};

struct Infomation
{
	char* Texture;

	int Color;

	int option;
};
struct Object
{
	char* Name;

	int HP;
	int MaxHp;
	int Mp;
	int MaxMp;
	int	Att;
	int Def;
	int Speed;
	Infomation Info;
	

	Transform TransInfo;
};

struct DrawTextInfo
{
	Infomation Info;

	Transform Transform;
};

//�ʱ�ȭ �Լ�(�Ű������ʱ�ȭ �ڿ������� �ȴ�)
void Initialize(Object* _Object, char* _Name, int _PosX = 0, int _PosY = 0, int _PosZ = 0);
char* SetName(Object* _Object);

// Ŀ����ġ ����
void SetCursorPosition(int _x, int _y);

//	���ڻ� ����
void SetTextColor(int _Color);

//	����� Text�� ��ġ�� ������ ������ �ش�. (Color �⺻ ���� 15(���) 
void OnDrawText(char* _str, int _x, int _y, int _Color = 15);
//	����� ������ ��ġ�� ������ ������ �ش�. (Color �⺻ ���� 15(���) 
void OnDrawText(int _Value, int _x, int _y, int _Color = 15);

//	Ŀ�� ǥ��(true)/��ǥ��(false)
void HideCursor(bool _Visible);

int main(void)
{
	Vector3 vPosition1 = Vector3(10, 20);
	Vector3 vPosition2 = Vector3(10, 20, 30);

	/*
	cout << vPosition1.x << "," << vPosition1.y << endl;
	cout << vPosition2.x << "," << vPosition2.y << vPosition2.z << endl;
	*/

	Object* Player = new Object;

	Object* Enemy = new Object;

	//	Ŀ���� �Ⱥ��̰�
	HideCursor(false);

	//	����ʱ�ȭ
	DrawTextInfo BackGround[30];

	for (int i = 0; i < 30; ++i)
	{
		
			//	���� ��� ������� ������ �ʾ�����, ���� ���� �Ѿ��� �������� �÷��̾ ���� ����������� �浹���� �ʰ�,
			//	�Ѿ˰� �浹���� ��� ������ ������ �ǵ��� ���� ����
			BackGround[i].Info.option = 0;

			//	��ǥ�� �������� ������
			BackGround[i].Transform.Position.x = rand() % 100 + 10;
			BackGround[i].Transform.Position.y = rand() % 30 + 1;

			//	�������� �ʱ�ȭ ����. ū ���� ���ü� �ֵ��� time������ ������ ��������,
			//	for���� ������ ���ԵǸ� time�� ���������� ������ �ֱ⶧����,
			//	�������̶� �ϴ��� �������� ���� ���� ���ü� ����
			//	j�� ���� ���������ν� ���� ���� ������ �ʵ��� ����
			srand((GetTickCount64() + i * i) * GetTickCount64() );

			//	������� ���� �ؽ�ó�� ����
			BackGround[i].Info.Texture = (char*)"*";
				
			// ������� ���� Texture�� ������ �������� ����
			BackGround[i].Info.Color = rand()%8;

		
	}

	Initialize(Player, (char*)"��", 30, 10);

	Initialize(Enemy, (char*)"Ȫ", 80, 10);

	//	����ð����� �ʱ�ȭ
	ULONGLONG Time = GetTickCount64();

	int Delay = 100;
	
	int iScore = 0;

	while (true)
	{
		//	�ʱ�ȭ�� �ð����κ��� Delay�� ����ŭ �����ϸ�
		//	�����Ӱ� �����ӻ����� �ð� ������ 1�ʷ� ����
		if (Time + Delay < GetTickCount64())
		{
			// ������ ����ŭ �ʱ�ȭ
			Time = GetTickCount64();

			system("cls");

			for (int i = 0; i < 30; ++i)
			{
				for (int j = 0; j < 30; ++j)
				{
					OnDrawText(BackGround[i].Info.Texture,
						BackGround[i].Transform.Position.x, 
						BackGround[i].Transform.Position.y,
						BackGround[i].Info.Color);
				}
			}
			// ** [��] ����Ű �Է¹���
			if (GetAsyncKeyState(VK_UP))
			{
				Player->TransInfo.Position.y -= 1;
			}
			// ** [��] ����Ű �Է¹���
			if (GetAsyncKeyState(VK_DOWN))
			{
				Player->TransInfo.Position.y += 1;
			}
			// ** [��] ����Ű �Է¹���
			if (GetAsyncKeyState(VK_LEFT))
			{
				Player->TransInfo.Position.x -= 1;
			}
			// ** [��] ����Ű �Է¹���
			if (GetAsyncKeyState(VK_RIGHT))
			{
				Player->TransInfo.Position.x += 1;
			}
			// ** [�����̽� ��] Ű�� �Է¹���
			if (GetAsyncKeyState(VK_SPACE))
			{
				OnDrawText((char*)"��ǳ!!",
					Player->TransInfo.Position.x + strlen(Player->Info.Texture) + 1,
					Player->TransInfo.Position.y, 13);
			}

			OnDrawText(Player->Info.Texture, Player->TransInfo.Position.x, Player->TransInfo.Position.y, 10);

			OnDrawText(Enemy->Info.Texture, Enemy->TransInfo.Position.x, Enemy->TransInfo.Position.y, 12);

			

			OnDrawText((char*)"Score : ", 60 - strlen("Score : "), 1);
			OnDrawText(++iScore, 60, 1);

		}
	}

	//Output(Enemy);

	return 0;

}

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
	_Object->TransInfo.Rotation = Vector3(_PosX, _PosY, _PosZ);
	_Object->TransInfo.Scale = Vector3(_PosX, _PosY, _PosZ);
}

//	Ŀ����ġ ����
void SetCursorPosition(int _x, int _y)
{
	COORD Pos = { (SHORT) _x, (SHORT)_y };

	SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), Pos);

}

void SetTextColor(int _Color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _Color);
}

void OnDrawText(char* _str, int _x, int _y, int _Color)
{
	SetCursorPosition(_x, _y);
	SetTextColor(_Color);
	cout << _str;
}

void OnDrawText(int _Value, int _x, int _y, int _Color)
{
	SetCursorPosition(_x, _y);
	SetTextColor(_Color);

	char* pText = new char[4];
	//
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

//	����Լ�
