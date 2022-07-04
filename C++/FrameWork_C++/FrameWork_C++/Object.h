#pragma once
#include "Headers.h"

class Object
{
protected:
	Transform Info;
public:
	virtual void Start()PURE;		// 초기화
	virtual void Update()PURE;		// 변경사항 및 충돌 등의 이벤트 체크
	virtual void Render()PURE;		// 그리기
	virtual void Release()PURE;		// 메모리 해제
public:
	Object();
	~Object();
};

