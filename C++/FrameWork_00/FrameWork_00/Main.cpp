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

	Object* Temp = new Object;

	Object* Enemy[32];

	Vector3 Direction[128];
	int Speed =0 ;

	for (int i = 0; i < 32; ++i)
		Enemy[i] = nullptr;

	//	����ʱ�ȭ
	DrawTextInfo BackGround[30];

	//	Ŀ���� �Ⱥ��̰�
	HideCursor(false);

	for (int i = 0; i < 30; ++i)
	{

		//	���� ��� ������� ������ �ʾ�����, ���� ���� �Ѿ��� �������� �÷��̾ ���� ����������� �浹���� �ʰ�,
		//	�Ѿ˰� �浹���� ��� ������ ������ �ǵ��� ���� ����
		BackGround[i].Info.option = 0;

		//	��ǥ�� �������� ������
		BackGround[i].Transform.Position.x = (float)(rand() % 100 + 10);
		BackGround[i].Transform.Position.y = (float)(rand() % 30 + 1);

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

	

	//	����ð����� �ʱ�ȭ
	ULONGLONG Time = GetTickCount64();
	ULONGLONG EnemyTime = GetTickCount64();
	ULONGLONG EnemyBulletTime = GetTickCount64();
	
	Object* Bullet[128]{ nullptr };

	Object* EnemyBullet[128]{ nullptr };

	int Delay = 100;

	int iScore = 0;
	bool Check = false;

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

			//	** Enemy����
			if (EnemyTime +2000 < GetTickCount64())
			{
				EnemyTime = GetTickCount64();

				for (int i = 0; i < 32; ++i)
				{
					if (Enemy[i] == nullptr)
					{
						srand((GetTickCount() + i * i) * GetTickCount());

						Enemy[i] = CreateEnemy(115, (float) (rand() % 30));
						break;
					}
				}
			}

			// Enemy Bullet ����
			if (EnemyBulletTime + rand()%1250 < GetTickCount64())
			{
				EnemyBulletTime = GetTickCount64();

				int random = rand() % 32;
					if (Enemy[random] != nullptr)
					{
						for (int j = 0; j < 128; ++j)
						{
							if (EnemyBullet[j] == nullptr)
							{
								EnemyBullet[j] =
									CreateEnemyBullet(Enemy[random]->TransInfo.Position.x
										, Enemy[random]->TransInfo.Position.y);
								//	** EnemyBullet�� Player�� �̵��ϱ� ���� ������ �޾ƿ�
								Direction[j] = GetDirection(Player, EnemyBullet[j]);
								break;
							}
						}
					}
			}

			//	for�� �ȿ����� ����� ����� �����ʴ°� ����
			for (int i = 0; i < 128; ++i)
			{
				if (Bullet[i] != nullptr)
				{
					for (int j = 0; j < 32; ++j)
					{
						//Bullet�� Enemy�� �浹�ϸ� �����
						if (Enemy[j] != nullptr)
						{
							if (Collision(Enemy[j], Bullet[i]))
							{
								delete Enemy[j];
								Enemy[j] = nullptr;

								delete Bullet[i];
								Bullet[i] = nullptr;
								break;
							}
						}
					}
					if (Bullet[i] != nullptr)
					{
						//	ȭ�� ������ ���� �Ѿ� �����
						if ((Bullet[i]->TransInfo.Position.x + 
							Bullet[i]->TransInfo.Scale.x) >= 120)
						{
							// ����� �� �ڿ� �ٷ� ���� �ϸ� ���α׷� ����
							delete Bullet[i];
							Bullet[i] = nullptr;
						}
					}
				}
			}

			for (int i = 0; i < 128; ++i)
			{
				if (EnemyBullet[i] != nullptr)
				{
					if (Collision(Player, EnemyBullet[i]))
					{
						delete EnemyBullet[i];
						EnemyBullet[i] = nullptr;
						break;
					}

				}
			}

			UpdateKey(Player);
			/******************************************************************
			0x0000 ������ ���� ���� ������ ���� ȣ������� ������ ���� ����
			0x8000 ������ ���� ���� ������ ���� ȣ������� ���� ����
			0x0001 ������ ���� ���� ������ ���� ȣ������� ������ ���� ����
			0x8001 ������ ���� ���� ������ ���� ȣ������� ���� ����
			******************************************************************/
			if (!Check && GetAsyncKeyState(VK_SPACE) & 0x0001)
			{
				Speed = 0;
				Check = true;
				
				
				
				
			}
			if (GetAsyncKeyState(VK_SPACE) & 0x8001)
			{
				if (Speed < 10)
					++Speed;

				for(int i =0; i< Speed; ++i)
					OnDrawText((char*)"/", 25.0f+(float)i, 1.0f);
			}
			if (Check && !(GetAsyncKeyState(VK_SPACE) & 0x8000))
			{
				for (int i = 0; i < 128; ++i)
				{
					if (Bullet[i] == nullptr)
					{
						Bullet[i] = CreateBullet(Player->TransInfo.Position.x,
							Player->TransInfo.Position.y);
						if (Bullet[i])
						{
							Bullet[i]->Speed = Speed;
							break;
						}
						break;
					}
				}
				Speed = 0;
				Check = false;
			}

		

			/*
			if (Collision(Player, Enemy))
			{
				OnDrawText((char*)"�浹 �Դϴ�.",
					60 - (int)(strlen("�浹 �Դϴ�.")) / 2, 0, 14);
			}
			*/

			for (int i = 0; i < 32; ++i)
			{
				if (Enemy[i])
				{
					Enemy[i]->TransInfo.Position.x--;

					OnDrawText(Enemy[i]->Info.Texture, 
						Enemy[i]->TransInfo.Position.x,
						Enemy[i]->TransInfo.Position.y, 12);

					// Enemy ��ũ�� �浹
					if (Enemy[i]->TransInfo.Position.x <= 0)
					{
						delete Enemy[i];
						Enemy[i] = nullptr;
					}
				}
			}

			OnDrawText(Player->Info.Texture, Player->TransInfo.Position.x, 
				Player->TransInfo.Position.y, 10);

			//	Bullet ���

			for (int i = 0; i < 128; ++i)
			{
				if (Bullet[i])
					OnDrawText(Bullet[i]->Info.Texture,
						Bullet[i]->TransInfo.Position.x+= Bullet[i]->Speed+1,
						Bullet[i]->TransInfo.Position.y);
			}

			

			for (int i = 0; i < 128; ++i)
			{
				if (EnemyBullet[i])
				{
					//	** �ش� �������� �̵���
					EnemyBullet[i]->TransInfo.Position.x += Direction[i].x;
					EnemyBullet[i]->TransInfo.Position.y += Direction[i].y;

					OnDrawText(EnemyBullet[i]->Info.Texture,
						EnemyBullet[i]->TransInfo.Position.x ,
						EnemyBullet[i]->TransInfo.Position.y,5);

					//	ȭ�� ������ ���� �Ѿ� �����
					if (EnemyBullet[i]->TransInfo.Position.x <= 2 ||
						EnemyBullet[i]->TransInfo.Position.x >= 118 ||
						EnemyBullet[i]->TransInfo.Position.y <= 2 ||
						EnemyBullet[i]->TransInfo.Position.y >= 28)
					{
						// ����� �� �ڿ� �ٷ� ���� �ϸ� ���α׷� ����
						delete EnemyBullet[i];
						EnemyBullet[i] = nullptr;
					}
				}
			}

			OnDrawText((char*)"Score : ", (float)(60.0f - strlen("Score : ")), 1.0f);
			OnDrawText(++iScore, 60.0f, 1);
			
			

			OnDrawText((char*)"[",
				25.0f, 1.0f);
			OnDrawText((char*)"]",
				35.0f, 1.0f);
		}
	}

	return 0;

}

