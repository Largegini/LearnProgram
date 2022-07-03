#include "Menu.h"
#include "Scenemanager.h"

Menu::Menu()
{

}

Menu :: ~Menu()
{

}
void Menu::Start()
{

	Count = 0;
}

void Menu::Update()
{
	Count++;

	if(Count>=50)
		Scenemanager::GetInstance()->SetScene(SceneID::STAGE);
}

void Menu::Render()
{
	cout << "Menu :" << Count << endl;
}

void Menu::Release()
{

}