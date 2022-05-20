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

	for (int i = 0; i < 32; ++i)
		Enemy[i] = nullptr;

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
		BackGround[i].Transform.Position.x = (float)(rand() % 100 + 10);
		BackGround[i].Transform.Position.y = (float)(rand() % 30 + 1);

		//	랜덤값을 초기화 해줌. 큰 값이 나올수 있도록 time값끼리 곱해줄 것이지만,
		//	for문이 빠르게 돌게되면 time의 증가값보다 빠를수 있기때문에,
		//	랜덤값이라 하더라도 연속으로 같은 값이 나올수 있음
		//	j의 값을 더해줌으로써 같은 값이 나오지 않도록 해줌
		srand((GetTickCount() + i * i) * GetTickCount());

		//	배경으로 사용될 텍스처를 설정
		BackGround[i].Info.Texture = (char*)"*";

		// 배경으로 사용될 Texture의 색상을 랜덤으로 설정
		BackGround[i].Info.Color = rand() % 8 + 1;


	}

	Initialize(Player, (char*)"옷", 30, 10);

	

	//	현재시간으로 초기화
	ULONGLONG Time = GetTickCount64();
	ULONGLONG EnemyTime = GetTickCount64();
	ULONGLONG EnemyBulletTime = GetTickCount64();
	
	Object* Bullet[128]{ nullptr };

	Object* EnemyBullet[128]{ nullptr };

	int Delay = 100;

	int iScore = 0;

	while (true)
	{
		//	초기화된 시간으로부터 Delay의 값만큼 증가하면
		//	프레임과 프레임사이의 시간 간격을 0.1초로 셋팅
		if (Time + Delay < GetTickCount64())
		{
			// 증가된 값만큼 초기화
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

			//	** Enemy생성
			if (EnemyTime +1500 < GetTickCount64())
			{
				EnemyTime = GetTickCount64();

				for (int i = 0; i < 32; ++i)
				{
					if (Enemy[i] == nullptr)
					{
						srand((GetTickCount() + i * i) * GetTickCount());

						Enemy[i] = CreateEnemy(115, rand() % 30);
						break;
					}
				}
			}

			// Enemy Bullet 생성
			if (EnemyBulletTime + rand()%3000 < GetTickCount64())
			{
				EnemyBulletTime = GetTickCount64();

				for (int i = 0; i < 32; ++i)
				{
					if (Enemy[i] != nullptr)
					{
						for (int j = 0; j < 128; ++j)
						{
							if (EnemyBullet[j] == nullptr)
							{
								EnemyBullet[j] =
									CreateBullet(Enemy[i]->TransInfo.Position.x
										, Enemy[i]->TransInfo.Position.y);
								break;
							}
						}
					}
				}
			}

			//	for문 안에서는 지우는 기능은 넣지않는게 좋음
			for (int i = 0; i < 128; ++i)
			{
				if (Bullet[i] != nullptr)
				{
					for (int j = 0; j < 32; ++j)
					{
						//Bullet이 Enemy와 충돌하면 지우기
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
						//	화면 밖으로 나간 총알 지우기
						if ((Bullet[i]->TransInfo.Position.x + 
							Bullet[i]->TransInfo.Scale.x) >= 120)
						{
							// 지우고 난 뒤에 바로 접근 하면 프로그램 터짐
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

					if (EnemyBullet[i] != nullptr)
					{
						if (EnemyBullet[i] != nullptr)
						{
							
						}
					}
				}
			}

			if (GetAsyncKeyState(VK_UP))
				Player->TransInfo.Position.y -= 1;

			if (GetAsyncKeyState(VK_DOWN))
				Player->TransInfo.Position.y += 1;

			if (GetAsyncKeyState(VK_LEFT))
				Player->TransInfo.Position.x-= 1;

			if (GetAsyncKeyState(VK_RIGHT))
				Player->TransInfo.Position.x += 1;

			if (GetAsyncKeyState(VK_SPACE))
			{
				for (int i = 0; i < 128; ++i)
				{
					if (Bullet[i] == nullptr)
					{
						Bullet[i] = CreateBullet(Player->TransInfo.Position.x,
							Player->TransInfo.Position.y);
						break;
					}
				}
			}

			/*
			if (Collision(Player, Enemy))
			{
				OnDrawText((char*)"충돌 입니다.",
					60 - (int)(strlen("충돌 입니다.")) / 2, 0, 14);
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

					// Enemy 스크린 충돌
					if (Enemy[i]->TransInfo.Position.x <= 0)
					{
						delete Enemy[i];
						Enemy[i] = nullptr;
					}
				}
			}

			OnDrawText(Player->Info.Texture, Player->TransInfo.Position.x, 
				Player->TransInfo.Position.y, 10);

			//	Bullet 출력

			for (int i = 0; i < 128; ++i)
			{
				if (Bullet[i])
					OnDrawText(Bullet[i]->Info.Texture,
						Bullet[i]->TransInfo.Position.x+=2,
						Bullet[i]->TransInfo.Position.y);
			}

			for (int i = 0; i < 128; ++i)
			{
				if (EnemyBullet[i])
				{
					OnDrawText(EnemyBullet[i]->Info.Texture,
						EnemyBullet[i]->TransInfo.Position.x -= 2,
						EnemyBullet[i]->TransInfo.Position.y);
					//	화면 밖으로 나간 총알 지우기
					if ((EnemyBullet[i]->TransInfo.Position.x) <= 0)
					{
						// 지우고 난 뒤에 바로 접근 하면 프로그램 터짐
						delete EnemyBullet[i];
						EnemyBullet[i] = nullptr;
					}
				}
			}

			OnDrawText((char*)"Score : ", (int)(60 - strlen("Score : ")), 1);
			OnDrawText(++iScore, 60, 1);

		}
	}

	return 0;

}

