#pragma once
#include "Headers.h"

class Scene
{
protected:
	int Count;
public:
	virtual void Start()PURE;		// �ʱ�ȭ
	virtual void Update()PURE;		// ������� �� �浹 ���� �̺�Ʈ üũ
	virtual void Render()PURE;		// �׸���
	virtual void Release()PURE;		// �޸� ����
public:
	Scene();
	virtual ~Scene();
};

