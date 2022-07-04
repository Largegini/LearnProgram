#include "Player.h"
#include "InputManager.h"
Player::Player()
{

}

Player :: ~Player()
{

}

void Player::Start()
{
}

void Player::Update()
{

	DWORD dwkey = InputManager::GetInstance()->Getkey();
	
	if (dwkey & KEY_UP)
		Info.Position.y-=1;

	if (dwkey & KEY_DOWN)
		Info.Position.y+=1;

	if (dwkey & KEY_LEFT)
		Info.Position.x-=1;

	if (dwkey & KEY_RIGHT)
		Info.Position.x+=1;
}

void Player::Render()
{
	cout << "X :" << Info.Position.x << endl;
	cout << "Y :" << Info.Position.y << endl;
}

void Player::Release()
{

}
