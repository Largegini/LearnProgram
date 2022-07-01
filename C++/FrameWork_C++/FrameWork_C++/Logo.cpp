#include "Logo.h"
#include "Scenemanager.h"

Logo::Logo()
{

}

Logo :: ~Logo()
{

}
void Logo::Start()
{
}

void Logo::Update()
{
	Scenemanager::GetInstance()->SetScene(SceneID::MENU);
}

void Logo::Render()
{
}

void Logo::Release()
{

}