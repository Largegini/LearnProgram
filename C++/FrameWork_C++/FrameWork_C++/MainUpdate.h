#pragma once
#include "Headers.h"

class Object;	//	��� - ���̱�

class MainUpdate
{
private: 
	int Hour;
	int Min;
	int Sec;
	Object* pPlayer;

public:
	void Start();		// �ʱ�ȭ
	void Update();		// ������� �� �浹 ���� �̺�Ʈ üũ
	void Render();		// �׸���
	void Release();		// �޸� ����
public:
	MainUpdate();
		~MainUpdate();
};
