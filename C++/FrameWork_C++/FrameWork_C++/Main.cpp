#include "MainUpdate.h"

//	���� = �����̳� = L���
//	��� = R���

//	�����ʱ�ȭ
//	��Ÿ�� ���� �ʱ�ȭ


int main(void)
{
	system("title ������ : Untiled");
	system("mode con cols=150 lines=40");
	MainUpdate Main;
	Main.Start();

	// ULONGLONG unsigned _int64
	//					1/1000		max �ð� = 500��
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