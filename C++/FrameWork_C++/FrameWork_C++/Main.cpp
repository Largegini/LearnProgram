#include "MainUpdate.h"

//	** 싱글톤
//	디자인 패턴
//	혼자만 쓰임

//	변수 = 컨테이너 = L밸류
//	상수 = R밸류

class Singleton
{
private :
	static Singleton* Instance;
public:
	static Singleton* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new Singleton;
		return Instance;
	}

	
};
//	전역초기화
Singleton* Singleton::Instance = nullptr;

int main(void)
{
	MainUpdate Main;
	Main.Start();

	// ULONGLONG unsigned _int64
	//					1/1000		max 시간 = 500년
	ULONGLONG Time = GetTickCount64();
	int i = 0;
	while (true)
	{
		if (Time + 10 < GetTickCount64())
		{
			Time = GetTickCount64();

			system("cls");

			Main.Update();

			Main.Render();
		}
	}
	return 0;
}