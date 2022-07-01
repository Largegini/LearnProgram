#include "MainUpdate.h"
#include "Scenemanager.h"


MainUpdate :: MainUpdate()
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

}

void MainUpdate::Render()
{

}

void MainUpdate::Release()
{
}