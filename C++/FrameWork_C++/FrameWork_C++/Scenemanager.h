#pragma once
#include "Headers.h"
class Scene;
class Scenemanager
{
private:
	static Scenemanager* Instance;
public:
	static Scenemanager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new Scenemanager;
		return Instance;
	}
private:
	Scene* SceneState;
public:
	void SetScene(SceneID _SceneID);
	void Update();
	void Render();
	void Release();

private:
	Scenemanager();
public:
	~Scenemanager();
};

