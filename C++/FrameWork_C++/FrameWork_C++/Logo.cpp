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
	Count = 0;
}

void Logo::Update()
{
	Count++;

	if(Count>=50)
		Scenemanager::GetInstance()->SetScene(SceneID::MENU);
}

void Logo::Render()
{
	cout << "Logo : " << Count << endl;
}

void Logo::Release()
{

}