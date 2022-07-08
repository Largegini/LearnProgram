#pragma once
#include "Headers.h"
#include <wincrypt.h>

class CursorManager
{
private:
	static CursorManager* Instance;
public:
	static CursorManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new CursorManager;
		return Instance;
	}
public:
	void SetcursorPosition(float _x, float _y, char* _str, int _Color = 15);
	void SetcursorPosition(Vector3 _Position, char* _str, int _Color = 15);

	void SetColor(int _Color);
private:
	CursorManager();
public:
	~CursorManager();
};