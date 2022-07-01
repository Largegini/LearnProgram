#include "Stage.h"
#include "Scenemanager.h"

Stage::Stage()
{

}

Stage :: ~Stage()
{

}
void Stage::Start()
{
}

void Stage::Update()
{
	Scenemanager::GetInstance()->SetScene(SceneID::EXIT);
}

void Stage::Render()
{
}

void Stage::Release()
{

}