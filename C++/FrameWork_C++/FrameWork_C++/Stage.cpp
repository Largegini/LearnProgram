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
	Count = 0;
}

void Stage::Update()
{
	Count++;

	if(Count>= 50)
		Scenemanager::GetInstance()->SetScene(SceneID::EXIT);
}

void Stage::Render()
{
	cout << "Render :" << Count << endl;
}

void Stage::Release()
{

}