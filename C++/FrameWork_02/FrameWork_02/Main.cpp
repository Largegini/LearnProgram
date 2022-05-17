#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

// ��������� ���߿� 3D�� ���ؼ� Vector3�� �̿�
// 2D���߿� Vector2�� �̿� ������ �ݵ�� �׷� ���� �ƴ�
struct Vector3
{
	int x = 0 , y = 0, z = 0;
	
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

	;Vector3(int _x, int _y, float _z)
		: x(_x), y(_y), z(_z) { };
	

};

// Object�� �����ϱ� ���� �ʿ��� �ּ����� ��
struct Transform
{
	Vector3 Position;
	Vector3 Rotation;
	Vector3 Scale;
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

	Transform TransInfo;
};

//�ʱ�ȭ �Լ�(�Ű������ʱ�ȭ �ڿ������� �ȴ�)
void Initialize(Object* _Object, char* _Name, int _PosX = 0, int _PosY = 0, int _PosZ = 0);
char* SetName(Object* _Object);
void Output(Object* _Obj);

int main(void)
{
	Vector3 vPosition1 = Vector3(10, 20);
	Vector3 vPosition2 = Vector3(10, 20, 30);
	Vector3 vPosition3 = Vector3(10, 20, 30.0f);

	/*
	cout << vPosition1.x << "," << vPosition1.y << endl;
	cout << vPosition2.x << "," << vPosition2.y << vPosition2.z << endl;
	cout << vPosition3.x << "," << vPosition3.y << vPosition3.z << endl;
	*/

	Object* Player = new Object;

	Object* Enemy = new Object;

	Initialize(Player, nullptr, 10, 20, 30);

	//Initialize(Enemy, (char*)"Enemy", 100, 200, 300);
	Initialize(Enemy, nullptr, 100, 200, 300);
	
	Output(Player);

	Output(Enemy);

	return 0;

}

char* SetName(Object* _Player)
{
	char Buffer[128] = "";

	//*** ���ڿ��� ����+1��ŭ�� ���� �Ҵ�
	//char* pName = (char*)malloc(strlen(Buffer)+1);
	char* pName = new char[strlen(Buffer)+1];
	

	cout << "�̸��� �Է��ϼ��� : ";


	cin >> Buffer;

	strcpy(pName, Buffer);

	return pName;
}

void Initialize(Object* _Object, char* _Name, int _PosX , int _PosY , int _PosZ )
{
	//���� ������  ���� ? A : B
	// ������ True�� A���� False�� B����
	_Object->Name = (_Name == nullptr) ? SetName(_Object) : _Name;

	_Object->Speed = 0;

	_Object->TransInfo.Position = Vector3(_PosX, _PosY, _PosZ);
	_Object->TransInfo.Rotation = Vector3(_PosX, _PosY, _PosZ);
	_Object->TransInfo.Scale = Vector3(_PosX, _PosY, _PosZ);
}

void Output(Object * _Obj)
{
	if (_Obj->Name != nullptr)
		cout << "Name : " << _Obj->Name << endl;

	cout << "Speed : " << _Obj->Speed << endl;

	cout << "X : " << _Obj->TransInfo.Position.x << "	Y : " << _Obj->TransInfo.Position.y << "	Z : " << _Obj->TransInfo.Position.z << endl;
	
}