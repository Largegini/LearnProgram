#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
#include<malloc.h>
/*
typedef struct taginfo
{
	char *Name;

	int iKor;
	int iEng;
	int iMath;
}INFO;
*/

typedef struct taginvertory
{
	int iHpotion;
	int iMpotion;
}INVENTORY;

typedef struct tahinfo
{
	int iX;
	int iY;
	INVENTORY* pinventory;
}INFO;

int main(void)
{
	/*
	INFO *pinfo = (INFO*)malloc(sizeof(INFO));
	//�Է��� ���Ƿ� ������ ����
	char Buffer[128] = "";

	printf_s("�̸� �Է� : ");

	// �Է��� ����.
	scanf("%s", Buffer);

	// ������ ������ ���ڿ��� ���̸�ŭ �����Ҵ��� ���ش�.
	//char * pName = (char*)malloc(strlen(Buffer) + 1);
	info.Name = (char*)malloc(strlen(Buffer) + 1);

	//���ڿ� ����
	strcpy(info.Name, Buffer);
	printf_s("%s\n", info.Name);

	printf_s("%d\n", sizeof(INFO*));
	printf_s("%d", sizeof(INFO));

	// ** heap�� �����Ҵ�� ������ ���� 
	free(pinfo);
	*/
	INFO* pInfo = (INFO*)malloc(sizeof(INFO));
	pInfo->pinventory = (INVENTORY*)malloc(sizeof(INVENTORY));
	// ����ü ���� ������ ���� �Ҵ�
	pInfo->iX = 10;
	pInfo->iY = 20;
	pInfo->pinventory->iHpotion = 1;
	pInfo->pinventory->iMpotion = 2;

	printf_s("iX : iY = %d : %d\n", pInfo->iX, pInfo->iY);
	printf_s("iHPotion : iMPotion = %d : %d\n",
		pInfo->pinventory->iHpotion, pInfo->pinventory->iMpotion);

	free(pInfo->pinventory);        // ����ü ������ �����Ͷ� ���� �Ҵ� ���� ������
	free(pInfo);					// �ȿ��� ������

	return 0 ;
}