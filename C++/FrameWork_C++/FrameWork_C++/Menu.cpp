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
}

void Menu::Update()
{
	Scenemanager::GetInstance()->SetScene(SceneID::STAGE);
}

void Menu::Render()
{
}

void Menu::Release()
{

}