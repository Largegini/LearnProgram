#include <iostream>
#include <Windows.h>

using namespace std;
int main(void)
{
	ULONGLONG Time = GetTickCount64();

	bool Check = false;

	while (true)
	{
		if (Time + 50 < GetTickCount64())
		{
			Time = GetTickCount64();

			//	* ��ư�� ������ ��
			if (!Check && GetAsyncKeyState('X') & 0x0001)
			{
				cout << "Push" << endl;
				Check = true;
			}
			// * ��ư�� ������ ���� ��
			if (GetAsyncKeyState('X') & 0x8000)
			{
				cout << "Press" << endl;
			}
			if (Check && !(GetAsyncKeyState('X')& 0x8000))
			{
				cout << "relase" << endl;

				Check = false;
			}
		}
	}
}