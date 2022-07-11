#include "Stage.h"
#include "Scenemanager.h"
#include "ObjectManager.h"

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
	ObjectManager::GetInstance()->Render();
}

void Stage::Release()
{
	delete pPlayer;
	pPlayer = nullptr;
}