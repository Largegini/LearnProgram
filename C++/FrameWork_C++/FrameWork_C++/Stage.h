#pragma once
#include "Scene.h"
class Object;
class Stage : public Scene
{
private:
	Object* pPlayer;
	char* Array[40][150];
public:
	virtual void Start()override;		// �ʱ�ȭ
	virtual void Update()override;		// ������� �� �浹 ���� �̺�Ʈ üũ
	virtual void Render()override;		// �׸���
	virtual void Release()override;		// �޸� ����
public:
	Stage();
	~Stage();
};

