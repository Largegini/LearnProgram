#include "Bullet.h"
#include "CursorManager.h"

void Bullet::Start()
{
	Info.Position = Vector3(0.0f, 0.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(0.0f, 0.0f);
	Info.Direction = Vector3(0.0f, 0.0f);

	Target = 0;
}

int Bullet::Update()
{
	switch (Index)
	{
	case 0:
		Info.Position += Info.Direction * 0.05f;
		break;
	case 1:
	{	
		Info.Direction = Target->GetPosition() - Info.Position;
		Info.Position += Info.Direction * 0.05f;
	}
		break;
	}
	if (Info.Position.x <= 0 || Info.Position.x >= 150 || Info.Position.y <= 0 ||
		Info.Position.y >= 40)
	{
		return 1;
	}
	return 0;
}

void Bullet::Render()
{
	switch (Index)
	{
	case 0:
	CursorManager::GetInstance()->SetcursorPosition(Info.Position, (char*)"*");
		break;
	case 1:
	CursorManager::GetInstance()->SetcursorPosition(Info.Position, (char*)"*",12);
		break;
	default:
		break;
	}
}

void Bullet::Release()
{
}

Bullet::Bullet(): Index(0)
{
}

Bullet::~Bullet()
{
}
