#pragma once
// 평면이지만 나중에 3D를 위해서 Vector3를 이용
// 2D개발에 Vector2를 이용 하지만 반드시 그런 것은 아님
struct Vector3
{
	float x = 0, y = 0, z = 0;

	// 기본 생성자
	// 매개변수가 없어야 기본 생성자
	Vector3() {};

	//** 복사 생성자
	// 복사생성자를 만들기 위해서는 기본 생성자 가 있어야된다.
	// 따라서 기본생성자 없이는 복사 생성자를 만들 수 없다.
	// 하나만 만들 수 있는게 아니다
	//** 매개변수의 갯수와 형태에 따라서 많은 생성자를 만들 수 있다
	// 매개변수에 따라 컴파일러가 선택해서 호출
	// ':'를 이용한 간략화는 C++에 있는 기능 C로는 불가
	Vector3(float _x, float _y)
		//x(_x) 대입연산만 이렇게 간략화 가능
		: x(_x), y(_y), z(0) { };

	Vector3(float _x, float _y, float _z)
		: x(_x), y(_y), z(_z) { };

};

// Object가 존재하기 위해 필요한 최소한의 값
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
