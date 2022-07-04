#include "InputManager.h"
// 2�Ǻ����� �̿��� 2���� ���� �� + 1
// �������� ���⸦ ����
InputManager* InputManager::Instance = nullptr;

InputManager::InputManager() : dwKey(0)
{

}

InputManager::~InputManager()
{

}

void InputManager::Checkkey()
{
	dwKey = 0;

	if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W'))
	{
		dwKey |= KEY_UP;
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		dwKey |= KEY_DOWN;
	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		dwKey |= KEY_LEFT;
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		dwKey |= KEY_RIGHT;
	}
	// ����
	if (GetAsyncKeyState(VK_RETURN))
	{
		dwKey |= KEY_RETURN;;
	}
	//ESC
	if (GetAsyncKeyState(VK_ESCAPE))
	{
		dwKey |= KEY_ESCAPE;
	}
}
