#include <iostream>
#include <Windows.h>

using namespace std;

int main(void)
{
	//	DWORD unsigned  long
	//					1/1000		max 시간 = 49일
	DWORD dwTime = GetTickCount();
	// ULONGLONG unsigned _int64
	//					1/1000		max 시간 = 500년
	ULONGLONG Time = GetTickCount64();

	while (true)
	{
		if (Time +16 < GetTickCount64())
		{
			Time = GetTickCount64();
		}
	}
	return 0;
}