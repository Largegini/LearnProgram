#include "MainUpdate.h"
#include "Scenemanager.h"
#include "InputManager.h"
#include "CursorManager.h"

MainUpdate :: MainUpdate() : Count(0)
{

}

MainUpdate::~MainUpdate()
{
	Release();
}
void MainUpdate::Start()
{
	CursorManager::GetInstance()->CreateBuffer(150, 40);

	Scenemanager::GetInstance()->SetScene(SceneID::STAGE);
}

void MainUpdate::Update()
{
	CursorManager::GetInstance()->CreateBuffer(150, 40);
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