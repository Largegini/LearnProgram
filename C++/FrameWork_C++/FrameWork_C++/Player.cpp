#include "Player.h"
#include "InputManager.h"
#include "CursorManager.h"

Player::Player()
{

}

Player :: ~Player()
{

}

void Player::Start()
{
	Info.Position = Vector3(74.0f, 20.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(2.0f, 1.0f);
	V1 = Vector3(10.0f, 10.0f);
	V2 = Vector3(0.0f, 0.0f);
	V3 = Vector3(0.0f, 0.0f);

	Target = nullptr;
}

int Player::Update()
{
	//순수 방향벡터는 빼는 것만으로는 만들어지진 않는다.
	// 좌표 A,B가 있을 때 A에서 B좌표값을 빼면 B에서 A로 향하는 벡터가 만들어진다.

	DWORD dwkey = InputManager::GetInstance()->Getkey();

	
	
	V2 = V1 - Info.Position;
	V3 = V1 + Info.Position;


	if (dwkey & KEY_UP)
		Info.Position.y--;

	if (dwkey & KEY_DOWN)
		Info.Position.y++;

	if (dwkey & KEY_LEFT)
		Info.Position.x-=2;

	if (dwkey & KEY_RIGHT)
		Info.Position.x+=2;

	if (dwkey & KEY_SPACE)
	{
		
	}

	//if (dwkey & KEY_ESCAPE)
	//	Info.Position = Vector3(0.0f, 0.0f);
	return 0;
}

void Player::Render()
{
	CursorManager::GetInstance()->WriteBuffer(Info.Position, (char*)"△");
}

void Player::Release()
{

}
