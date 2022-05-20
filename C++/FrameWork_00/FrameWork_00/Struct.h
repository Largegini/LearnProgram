#pragma once
// ��������� ���߿� 3D�� ���ؼ� Vector3�� �̿�
// 2D���߿� Vector2�� �̿� ������ �ݵ�� �׷� ���� �ƴ�
struct Vector3
{
	float x = 0, y = 0, z = 0;

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
	Vector3(float _x, float _y)
		//x(_x) ���Կ��길 �̷��� ����ȭ ����
		: x(_x), y(_y), z(0) { };

	Vector3(float _x, float _y, float _z)
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
