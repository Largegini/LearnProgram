#include "Headers.h"

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

	//	Ŀ���� �Ⱥ��̰�
	HideCursor(false);

	//	����ʱ�ȭ
	DrawTextInfo BackGround[30];

	for (int i = 0; i < 30; ++i)
	{

		//	���� ��� ������� ������ �ʾ�����, ���� ���� �Ѿ��� �������� �÷��̾ ���� ����������� �浹���� �ʰ�,
		//	�Ѿ˰� �浹���� ��� ������ ������ �ǵ��� ���� ����
		BackGround[i].Info.option = 0;

		//	��ǥ�� �������� ������
		BackGround[i].Transform.Position.x = rand() % 100 + 10;
		BackGround[i].Transform.Position.y = rand() % 30 + 1;

		//	�������� �ʱ�ȭ ����. ū ���� ���ü� �ֵ��� time������ ������ ��������,
		//	for���� ������ ���ԵǸ� time�� ���������� ������ �ֱ⶧����,
		//	�������̶� �ϴ��� �������� ���� ���� ���ü� ����
		//	j�� ���� ���������ν� ���� ���� ������ �ʵ��� ����
		srand((GetTickCount() + i * i) * GetTickCount());

		//	������� ���� �ؽ�ó�� ����
		BackGround[i].Info.Texture = (char*)"*";

		// ������� ���� Texture�� ������ �������� ����
		BackGround[i].Info.Color = rand() % 8 + 1;


	}

	Initialize(Player, (char*)"��", 30, 10);

	Initialize(Enemy, (char*)"Ȫ", 80, 10);

	//	����ð����� �ʱ�ȭ
	ULONGLONG Time = GetTickCount64();

	Object* Bullet[128]{ nullptr };

	int BulletCount = 0;

	int Delay = 100;

	int iScore = 0;

	while (true)
	{
		//	�ʱ�ȭ�� �ð����κ��� Delay�� ����ŭ �����ϸ�
		//	�����Ӱ� �����ӻ����� �ð� ������ 0.1�ʷ� ����
		if (Time + Delay < GetTickCount64())
		{
			// ������ ����ŭ �ʱ�ȭ
			Time = GetTickCount64();

			system("cls");

			for (int i = 0; i < 30; ++i)
			{

				OnDrawText(BackGround[i].Info.Texture,
					BackGround[i].Transform.Position.x,
					BackGround[i].Transform.Position.y,
					BackGround[i].Info.Color);

				BackGround[i].Info.Color = rand() % 8 + 1;
			}

			//	for�� �ȿ����� ����� ����� �����ʴ°� ����
			for (int i = 0; i < 128; ++i)
			{
				if (Bullet[i] != nullptr)
				{
					//	ȭ�� ������ ���� �Ѿ� �����
					if ((Bullet[i]->TransInfo.Position.x + Bullet[i]->TransInfo.Scale.x) >= 120)
					{
						// ����� �� �ڿ� �ٷ� ���� �ϸ� ���α׷� ����
						delete Bullet[i];
						Bullet[i] = nullptr;

						BulletCount--;
					}
				}
			}

			//Bullet�浹�����(Enemy�� �浹�� Bullet�����Ǵ°� ����)
			Collision(Player, Enemy);

			OnDrawText(Enemy->Info.Texture, Enemy->TransInfo.Position.x, 
				Enemy->TransInfo.Position.y, 12);

			OnDrawText(Player->Info.Texture, Player->TransInfo.Position.x, 
				Player->TransInfo.Position.y, 10);

			//	Bullet ���
			for (int i = 0; i < 128; ++i)
			{
				if (Bullet[i])
					OnDrawText(Bullet[i]->Info.Texture,
						Bullet[i]->TransInfo.Position.x+=2,
						Bullet[i]->TransInfo.Position.y);
			}

			OnDrawText((char*)"BulletCount : ", 110, 1);
			OnDrawText(BulletCount, 100 + strlen("BulletCount : "), 1);
			

			OnDrawText((char*)"Score : ", 60 - strlen("Score : "), 1);
			OnDrawText(++iScore, 60, 1);

		}
	}

	return 0;

}

