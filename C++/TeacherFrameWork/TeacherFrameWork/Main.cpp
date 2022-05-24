#include "Headers.h"

int main(void)
{
	DrawTextInfo BackGround[30];

	for (int i = 0; i < 30; ++i)
	{
		srand((GetTickCount64() + i * i) * GetTickCount64());

		BackGround[i].Info.Option = 0;

		BackGround[i].TransInfo.Position.x = (float)(rand() % 100 + 10);
		BackGround[i].TransInfo.Position.y = (float)(rand() % 26 + 1);

		BackGround[i].Info.Texture = (char*)"*";

		BackGround[i].Info.Color = rand() % 8 + 1;
	}

	Object* Player = new Object;

	Initialize(Player, (char*)"¿Ê/", 30, 10);

	Object* Enemy[32];
	for (int i = 0; i < 32; ++i)
		Enemy[i] = nullptr;

	Object* Bullet[128] = {nullptr};

	Object* Temp = nullptr;
	Vector3 Direction;

	ULONGLONG Time = GetTickCount64();
	ULONGLONG EnemyTime = GetTickCount64();

	bool Chek = false;
	int Power = 0;

	HideCursor(false);

	while (true)
	{
		if (Time + 80 < GetTickCount64())
		{
			Time = GetTickCount64();
			for (int i = 0; i < 30; ++i)
			{
				OnDrawText(
					BackGround[i].Info.Texture,
					BackGround[i].TransInfo.Position.x,
					BackGround[i].TransInfo.Position.y,
					BackGround[i].Info.Color);

				BackGround[i].Info.Color = rand()%8+1;
			}
		}
	}


}