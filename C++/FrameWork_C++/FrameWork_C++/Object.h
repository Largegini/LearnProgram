#pragma once
#include "Headers.h"

class Object
{
protected:
	Transform Info;
	Object* Target;
	int Count;
public:
	virtual void Start()PURE;		// �ʱ�ȭ
	virtual int Update()PURE;		// ������� �� �浹 ���� �̺�Ʈ üũ
	virtual void Render()PURE;		// �׸���
	virtual void Release()PURE;		// �޸� ����
public:
	Vector3 GetPosition() const { return Info.Position; }

	void SetPosition(Vector3 Position)
	{ Info.Position = Position; }

	void SetPosition(float _x, float _y) 
	{ Info.Position = Vector3(_x,_y); }

	void SetDirection(Vector3 _Direction) 
	{ Info.Direction= _Direction; }

	void SetDirection(float _x, float _y) 
	{ Info.Direction = Vector3(_x,_y); }

	void SetTarget(Object* _Target) { Target = _Target; }
public:
	Object();
	~Object();
};

