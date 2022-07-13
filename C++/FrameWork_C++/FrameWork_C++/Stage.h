#pragma once
#include "Scene.h"
class Object;
class Stage : public Scene
{
private:
	Object* pPlayer;
	char* Array[40][150];
public:
	virtual void Start()override;		// 초기화
	virtual void Update()override;		// 변경사항 및 충돌 등의 이벤트 체크
	virtual void Render()override;		// 그리기
	virtual void Release()override;		// 메모리 해제
public:
	Stage();
	~Stage();
};

