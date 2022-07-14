#pragma once
#include "Headers.h"

class ObjectFactory
{
public:
	static Object* CreatePlayer()
	{
		Object* pObeject = new Player;
		pObeject->Start();

		return pObeject;
	}
	static Object* CreateEnemy()
	{
		Object* pObeject = new Enemy;
		pObeject->Start();

		return pObeject;
	}

	static Object* CreateEnemy(Vector3 _Position)
	{
		Object* pObeject = new Enemy;
		pObeject->Start();
		pObeject->SetPosition(_Position);

		return pObeject;
	}

	static Object* CreateBullet()
	{
		Object* pObeject = new Bullet;
		pObeject->Start();

		return pObeject;
	}

	static Object* CreateBullet(Vector3 _Position)
	{
		Object* pObeject = new Bullet;
		pObeject->Start();
		pObeject->SetPosition(_Position);

		return pObeject;
	}

	static Object* CreateBullet(float _x, float _y)
	{
		Object* pObeject = new Bullet;
		pObeject->Start();
		pObeject->SetPosition(_x, _y);

		return pObeject;
	}
};