#include "ObjectManager.h"
#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"
#include "CollisionManager.h"
#include "CursorManager.h"

ObjectManager* ObjectManager::Instance = nullptr;

void ObjectManager::CreateObject(int _StateIndex)
{
	for (int i = 0; i < 128; ++i)
	{
		if (pBullet[i] == nullptr)
		{
			pBullet[i] = new Bullet;
			pBullet[i]->Start();
			pBullet[i]->SetPosition(74.0f, 1.0f);

			switch (_StateIndex)
			{
			case 0:
			{
				Vector3 Direction = pPlayer->GetPosition() - pBullet[i]->GetPosition();
				pBullet[i]->SetDirection(Direction);
				((Bullet*)pBullet[i])->SetIndex(_StateIndex);
			}
				break;
			case 1:
				pBullet[i]->SetTarget(pPlayer);
				((Bullet*)pBullet[i])->SetIndex(_StateIndex);
				break;
			default:
				break;
			}
		}
	}
}

void ObjectManager::Start()
{
	pPlayer = new Player;
	pPlayer->Start();
	pEnemy = new Enemy;
	pEnemy->Start();
}

void ObjectManager::Update()
{
	int result = 0;
	pPlayer->Update();

	if (pEnemy != nullptr)
		pEnemy->Update();

	if (pEnemy)
	{
		if (CollisionManager::RectCollision(pPlayer->GetTransform(),
			pEnemy->GetTransform()))
		{
			CursorManager::GetInstance()->WriteBuffer(0.0f, 0.0f, (char*)"�浹�Դϴ�");
			result = 2;
		}

		if (result == 2)
		{
			delete pEnemy;
			pEnemy = nullptr;
		}
	}

	for (int i = 0; i < 128; ++i)
	{
		if (pBullet[i])
		{
			result = pBullet[i]->Update();

			if (CollisionManager::RectCollision(pPlayer->GetTransform(),
				pBullet[i]->GetTransform()))
			{
				CursorManager::GetInstance()->WriteBuffer(0.0f, 0.0f, (char*)"�浹�Դϴ�");
				result = 1;
			}
		}

		if (result == 1)
		{
			delete pBullet[i];
			pBullet[i] = nullptr;
		}
	}
	
}

void ObjectManager::Render()
{
	pPlayer->Render();
	if (pEnemy != nullptr)
		pEnemy->Render();

	for (int i = 0; i < 128; ++i)
	{
		if(pBullet[i])
			pBullet[i]->Render();
	}
}

void ObjectManager::Release()
{
	delete pPlayer;
	pPlayer = nullptr;
	delete pEnemy;
	pEnemy = nullptr;

	for (int i = 0; i < 128; ++i)
	{
		if (pBullet[i])
		{
			delete pBullet[i];
			pBullet[i] = nullptr;
		}
	}
}

ObjectManager::ObjectManager():pPlayer(nullptr),pEnemy(nullptr)
{
	for (int i = 0; i < 128; ++i)
	{
		pBullet[i] = nullptr;
	}
}

ObjectManager::~ObjectManager()
{
	Release();
}
