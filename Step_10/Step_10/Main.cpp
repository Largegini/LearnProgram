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
	//입력을 임의로 저장할 공간
	char Buffer[128] = "";

	printf_s("이름 입력 : ");

	// 입력을 받음.
	scanf("%s", Buffer);

	// 포인터 변수에 문자열의 길이만큼 동적할당을 해준다.
	//char * pName = (char*)malloc(strlen(Buffer) + 1);
	info.Name = (char*)malloc(strlen(Buffer) + 1);

	//문자열 복사
	strcpy(info.Name, Buffer);
	printf_s("%s\n", info.Name);

	printf_s("%d\n", sizeof(INFO*));
	printf_s("%d", sizeof(INFO));

	// ** heap에 동적할당된 공간을 삭제 
	free(pinfo);
	*/
	INFO* pInfo = (INFO*)malloc(sizeof(INFO));
	pInfo->pinventory = (INVENTORY*)malloc(sizeof(INVENTORY));
	// 구조체 내부 포인터 동적 할당
	pInfo->iX = 10;
	pInfo->iY = 20;
	pInfo->pinventory->iHpotion = 1;
	pInfo->pinventory->iMpotion = 2;

	printf_s("iX : iY = %d : %d\n", pInfo->iX, pInfo->iY);
	printf_s("iHPotion : iMPotion = %d : %d\n",
		pInfo->pinventory->iHpotion, pInfo->pinventory->iMpotion);

	free(pInfo->pinventory);        // 구조체 내부의 포인터라서 동적 할당 해지 순서는
	free(pInfo);					// 안에서 밖으로

	return 0 ;
}