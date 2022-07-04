#include "InputManager.h"
// 2의보수를 이용한 2진수 반전 후 + 1
// 덧셈으로 빼기를 구현
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
	// 엔터
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
