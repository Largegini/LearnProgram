#pragma once
#include  "Object.h"

class Player : public Object
{
public:
	virtual void Start() override;		// �ʱ�ȭ
	virtual void Update()override;		// ������� �� �浹 ���� �̺�Ʈ üũ
	virtual void Render()override;		// �׸���
	virtual void Release()override;		// �޸� ����
public:
	Player();
	virtual ~Player();
};

