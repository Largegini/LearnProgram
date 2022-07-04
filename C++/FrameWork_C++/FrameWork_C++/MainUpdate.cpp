#include "MainUpdate.h"
#include "Scenemanager.h"
#include "InputManager.h"


MainUpdate :: MainUpdate() : Count(0)
{

}

MainUpdate::~MainUpdate()
{
	Release();
}
void MainUpdate::Start()
{
	Scenemanager::GetInstance()->SetScene(SceneID::STAGE);
}

void MainUpdate::Update()
{
	InputManager::GetInstance()->Checkkey();
	Scenemanager::GetInstance()->Update();
}

void MainUpdate::Render()
{
	Scenemanager::GetInstance()->Render();
}

void MainUpdate::Release()
{
}