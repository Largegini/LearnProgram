#include "Scenemanager.h"

#include "Logo.h"
#include "Menu.h"
#include "Stage.h"

Scenemanager* Scenemanager::Instance = nullptr;

Scenemanager::Scenemanager(): SceneState(nullptr)
{
}

Scenemanager::~Scenemanager()
{
}

void Scenemanager::SetScene(SceneID _SceneID)
{
	if (SceneState != nullptr)
	{
		delete SceneState;
		SceneState = nullptr;
	}

	switch (_SceneID)
	{
	case SceneID::LOGO:
		SceneState = new Logo;
		break;
	case SceneID::MENU:
		SceneState = new Menu;
		break;
	case SceneID::STAGE:
		SceneState = new Stage;
		break;
	case SceneID::EXIT:
		exit(NULL);
		break;
	default:
		break;
	}
	SceneState->Start();
}
