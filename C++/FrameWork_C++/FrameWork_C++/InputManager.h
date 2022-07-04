#pragma once
#include "Headers.h"

class InputManager
{
private:
	static InputManager* Instance;
public:
	static InputManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new InputManager;
		return Instance;
	}
private:
	DWORD dwKey;
public:
	void Checkkey();
	DWORD Getkey() { return dwKey; }
public:
	InputManager();
	~InputManager();
};

