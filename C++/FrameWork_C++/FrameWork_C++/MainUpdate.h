#pragma once
#include "Headers.h"

class MainUpdate
{
private: 
	int Count;
public:
	void Start();		// 초기화
	void Update();		// 변경사항 및 충돌 등의 이벤트 체크
	void Render();		// 그리기
	void Release();		// 메모리 해제
public:
	MainUpdate();
		~MainUpdate();
};

