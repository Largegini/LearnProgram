#pragma once
#include "Scene.h"
class Stage : public Scene
{
public:
	virtual void Start()override;		// �ʱ�ȭ
	virtual void Update()override;		// ������� �� �浹 ���� �̺�Ʈ üũ
	virtual void Render()override;		// �׸���
	virtual void Release()override;		// �޸� ����
public:
	Stage();
	~Stage();
};

