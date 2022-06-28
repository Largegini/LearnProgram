#include "MainUpdate.h"

//	** �̱���
//	������ ����
//	ȥ�ڸ� ����

//	���� = �����̳� = L���
//	��� = R���

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
//	�����ʱ�ȭ
Singleton* Singleton::Instance = nullptr;

int main(void)
{
	MainUpdate Main;
	Main.Start();

	// ULONGLONG unsigned _int64
	//					1/1000		max �ð� = 500��
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