#include "MainUpdate.h"
#include "Scenemanager.h"


MainUpdate :: MainUpdate() : Count(0)
{

}

MainUpdate::~MainUpdate()
{
	Release();
}
void MainUpdate::Start()
{
	Scenemanager::GetInstance()->SetScene(SceneID::LOGO);
}

void MainUpdate::Update()
{
	Scenemanager::GetInstance()->Update();
}

void MainUpdate::Render()
{
	Scenemanager::GetInstance()->Render();
}

void MainUpdate::Release()
{
}