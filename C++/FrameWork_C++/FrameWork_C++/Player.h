#pragma once
#include  "Object.h"

class Player : public Object
{
public:
	virtual void Start() override;		// �ʱ�ȭ
	virtual int Update()override;		// ������� �� �浹 ���� �̺�Ʈ üũ
	virtual void Render()override;		// �׸���
	virtual void Release()override;		// �޸� ����
public:
	Player();
	virtual ~Player();

private:
	Vector3 V1;
	Vector3 V2;
	Vector3 V3;
};

