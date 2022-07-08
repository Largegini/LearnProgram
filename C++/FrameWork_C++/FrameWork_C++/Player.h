#pragma once
#include  "Object.h"

class Player : public Object
{
public:
	virtual void Start() override;		// 초기화
	virtual int Update()override;		// 변경사항 및 충돌 등의 이벤트 체크
	virtual void Render()override;		// 그리기
	virtual void Release()override;		// 메모리 해제
public:
	Player();
	virtual ~Player();

private:
	Vector3 V1;
	Vector3 V2;
	Vector3 V3;
};

