#pragma once
struct Vector3
{
	float x = 0, y = 0, z = 0;
	//	** 기본생성자
	Vector3() {};
	//	** 복사생성자
	Vector3(float _x, float _y) : 
	x(_x), y(_y){};
	//	** 복사생성자 2
	Vector3(float _x, float _y, float _z) : 
	x(_x), y(_y), z(_z) {};

};

struct Transform
{
	Vector3 Position;
	Vector3 Rotation;
	Vector3 Scale;
};

struct Information
{
	char* Texture;
	int Color;
	int Option;
};

struct Object
{
	char* Name;
	int Power;

	Transform TransInfo;
	Information Info;
};

struct DrawTextInfo
{
	Transform TransInfo;
	Information Info;
};