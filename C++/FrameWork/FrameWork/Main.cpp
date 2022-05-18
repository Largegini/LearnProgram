#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

// 평면이지만 나중에 3D를 위해서 Vector3를 이용
// 2D개발에 Vector2를 이용 하지만 반드시 그런 것은 아님
struct Vector3
{
	int x = 0, y = 0, z = 0;

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

//초기화 함수(매개변수초기화 뒤에서부터 된다)
void Initialize(Object* _Object, char* _Name, int _PosX = 0, int _PosY = 0, int _PosZ = 0);
char* SetName(Object* _Object);

// 커서위치 변경
void SetCursorPosition(int _x, int _y);

//	글자색 변경
void SetTextColor(int _Color);

//	출력할 Text의 위치와 색상을 변경해 준다. (Color 기본 값은 15(흰색) 
void OnDrawText(char* _str, int _x, int _y, int _Color = 15);
//	출력할 숫자의 위치와 색상을 변경해 준다. (Color 기본 값은 15(흰색) 
void OnDrawText(int _Value, int _x, int _y, int _Color = 15);

//	커서 표시(true)/비표시(false)
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

	//	커서를 안보이게
	HideCursor(false);

	//	배경초기화
	DrawTextInfo BackGround[30];

	for (int i = 0; i < 30; ++i)
	{
		
			//	현재 어떻게 사용할지 정하지 않았지만, 추후 배경과 총알을 구분지어 플레이어가 배경과 닿았을때에는 충돌하지 않고,
			//	총알과 충돌했을 경우 때에만 판정이 되도록 해줄 것임
			BackGround[i].Info.option = 0;

			//	좌표를 랜덤으로 설정함
			BackGround[i].Transform.Position.x = rand() % 100 + 10;
			BackGround[i].Transform.Position.y = rand() % 30 + 1;

			//	랜덤값을 초기화 해줌. 큰 값이 나올수 있도록 time값끼리 곱해줄 것이지만,
			//	for문이 빠르게 돌게되면 time의 증가값보다 빠를수 있기때문에,
			//	랜덤값이라 하더라도 연속으로 같은 값이 나올수 있음
			//	j의 값을 더해줌으로써 같은 값이 나오지 않도록 해줌
			srand((GetTickCount64() + i * i) * GetTickCount64() );

			//	배경으로 사용될 텍스처를 설정
			BackGround[i].Info.Texture = (char*)"*";
				
			// 배경으로 사용될 Texture의 색상을 랜덤으로 설정
			BackGround[i].Info.Color = rand()%8;

		
	}

	Initialize(Player, (char*)"옷", 30, 10);

	Initialize(Enemy, (char*)"홋", 80, 10);

	//	현재시간으로 초기화
	ULONGLONG Time = GetTickCount64();

	int Delay = 100;
	
	int iScore = 0;

	while (true)
	{
		//	초기화된 시간으로부터 Delay의 값만큼 증가하면
		//	프레임과 프레임사이의 시간 간격을 1초로 셋팅
		if (Time + Delay < GetTickCount64())
		{
			// 증가된 값만큼 초기화
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
			// ** [상] 방향키 입력받음
			if (GetAsyncKeyState(VK_UP))
			{
				Player->TransInfo.Position.y -= 1;
			}
			// ** [하] 방향키 입력받음
			if (GetAsyncKeyState(VK_DOWN))
			{
				Player->TransInfo.Position.y += 1;
			}
			// ** [좌] 방향키 입력받음
			if (GetAsyncKeyState(VK_LEFT))
			{
				Player->TransInfo.Position.x -= 1;
			}
			// ** [우] 방향키 입력받음
			if (GetAsyncKeyState(VK_RIGHT))
			{
				Player->TransInfo.Position.x += 1;
			}
			// ** [스페이스 바] 키를 입력받음
			if (GetAsyncKeyState(VK_SPACE))
			{
				OnDrawText((char*)"장풍!!",
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
	_Object->TransInfo.Rotation = Vector3(_PosX, _PosY, _PosZ);
	_Object->TransInfo.Scale = Vector3(_PosX, _PosY, _PosZ);
}

//	커서위치 변경
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

//	출력함수
