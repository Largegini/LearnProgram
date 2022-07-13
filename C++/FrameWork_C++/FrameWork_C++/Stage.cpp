#include "Stage.h"
#include "Scenemanager.h"
#include "ObjectManager.h"
#include "CursorManager.h"

Stage::Stage()
{

}

Stage :: ~Stage()
{
	Release();
}
void Stage::Start()
{
	ObjectManager::GetInstance()->Start();
}

void Stage::Update()
{
	ObjectManager::GetInstance()->Update();
}

void Stage::Render()
{
	for (float y = 0; y < 40; ++y)
	{
		for (float x = 0; x < 150; ++x)
		{
			CursorManager::GetInstance()->WriteBuffer(x, y, (char*)"A");
		}
	}
	ObjectManager::GetInstance()->Render();
}

void Stage::Release()
{
	delete pPlayer;
	pPlayer = nullptr;
}