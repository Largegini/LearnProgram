#include "MainUpdate.h"

//	변수 = 컨테이너 = L밸류
//	상수 = R밸류

//	전역초기화
//	런타임 전에 초기화


int main(void)
{
	system("title 안정연 : Untiled");
	system("mode con cols=150 lines=40");
	MainUpdate Main;
	Main.Start();

	// ULONGLONG unsigned _int64
	//					1/1000		max 시간 = 500년
	ULONGLONG Time = GetTickCount64();
	int i = 0;
	while (true)
	{
		if (Time + 100 < GetTickCount64())
		{
			Time = GetTickCount64();

			system("cls");

			Main.Update();

			Main.Render();
		}
	}
	return 0;
}