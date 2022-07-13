#include "Enemy.h"
#include "ObjectManager.h"
#include "CursorManager.h"

Enemy::Enemy()
{

}

Enemy :: ~Enemy()
{

}
void Enemy::Start()
{
	Info.Position = Vector3(0.0f, 0.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(2.0f, 1.0f);
	Info.Direction = Vector3(0.0f, 0.0f);

	Target = nullptr;
	Time = GetTickCount64();
}

int Enemy::Update()
{
	Info.Position.x=25.0f;

	Info.Position.y =10.0f;
	if (Time + 250 < GetTickCount64())
	{
		++Count;
		if (Count >= 10)
		{
			Count = 0;
			ObjectManager::GetInstance()->CreateObject(1);
		}
		else
			ObjectManager::GetInstance()->CreateObject(0);

		Time = GetTickCount64();
	}

	return 0;
}

void Enemy::Render()
{
	CursorManager::GetInstance()->WriteBuffer(Info.Position, (char*)"бс");
}

void Enemy::Release()
{

}