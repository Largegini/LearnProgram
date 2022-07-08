#pragma once
#include "Headers.h"

class Object
{
protected:
	Transform Info;
	Object* Target;
	int Count;
public:
	virtual void Start()PURE;		// 초기화
	virtual int Update()PURE;		// 변경사항 및 충돌 등의 이벤트 체크
	virtual void Render()PURE;		// 그리기
	virtual void Release()PURE;		// 메모리 해제
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

