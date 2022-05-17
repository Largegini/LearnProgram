#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

// 평면이지만 나중에 3D를 위해서 Vector3를 이용
// 2D개발에 Vector2를 이용 하지만 반드시 그런 것은 아님
struct Vector3
{
	int x = 0 , y = 0, z = 0;
	
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
	Vector3(int _x, int _y)
		//x(_x) 대입연산만 이렇게 간략화 가능
		: x(_x), y(_y), z(0) { };

	Vector3(int _x, int _y, int _z)
		: x(_x), y(_y), z(_z) { };

	;Vector3(int _x, int _y, float _z)
		: x(_x), y(_y), z(_z) { };
	

};

// Object가 존재하기 위해 필요한 최소한의 값
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

//초기화 함수(매개변수초기화 뒤에서부터 된다)
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

	//*** 문자열의 길이+1만큼의 공간 할당
	//char* pName = (char*)malloc(strlen(Buffer)+1);
	char* pName = new char[strlen(Buffer)+1];
	

	cout << "이름을 입력하세요 : ";


	cin >> Buffer;

	strcpy(pName, Buffer);

	return pName;
}

void Initialize(Object* _Object, char* _Name, int _PosX , int _PosY , int _PosZ )
{
	//삼항 연산자  조건 ? A : B
	// 조건이 True면 A실행 False면 B실행
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