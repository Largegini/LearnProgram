#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>
#include <string>
#include <stdlib.h>
#include <time.h>

char* SetName();

int main(void)
{
	/*
	char cAlphabet;
	char cHanguel;

	cAlphabet = 'A';	//알파벳을 제외한 언어는 모두 2byte
	cHanguel = '한';	//1 byte인 char형에 한글 저장 안됨

	printf_s("Alphabet : %c / Hanguel : %c \n", cAlphabet, cHanguel);
	char cHarray[] = "한";			// 한글 저장 시 문자열 사용
	printf_s("%s\n\n", cHarray);	// 문자열 정의는 " ";

	printf_s("%d\n", sizeof(cHarray));
	char* cpArray = (char*)"Character Pointer Array";

	printf_s("&cpArray		: %d\n", &cpArray);
	printf_s("cpArray		: %d\n", cpArray);
	printf_s("&cpArray[0]	: %d\n", &cpArray[0]);
	printf_s("cpArray		: %s\n\n", cpArray);

	printf_s("*cpArray		: %c\n", *cpArray);
	printf_s("cpArray[0]	: %c\n", cpArray[0]);
	printf_s("cpArray[1]	: %c\n\n", cpArray[1]);

	printf_s("*cpArray++	: %c\n", *cpArray++);
	printf_s("cpArray		: %s\n", cpArray);
	printf_s("*cpArray--	: %c\n", *cpArray);
	printf_s("cpArray		: %s\n\n", cpArray);

	printf_s("cpArray		: %d\n", cpArray);
	printf_s("*cpArray		: %c\n", *cpArray);
	cpArray++;
	printf_s("cpArray		: %d\n", cpArray);
	printf_s("cpArray[0]	: %c\n\n", cpArray[0]);

	char Buffer[128] = "";
	char* pName = nullptr;	//nullptr 널 포인터

	scanf("%s", Buffer);
	pName = (char*)malloc(strlen(Buffer) + 1);
	strcpy(pName, Buffer);

	printf_s("당신의 이름은 무엇입니까? : ");

	char* pName = SetName();

	printf_s("%s님이군요 부디 위험에 빠진 아크라시아를 구해주세요\n", pName);
	*/

	// ** 랜덤 함수 초기화
	srand(time(NULL)); 
	int iLotto[8] = {};
	int iNumber = 0;;

	printf_s("SGA Lotto 당첨번호는 ? \n");
	for (int i = 0; i < 7; i++)
	{
		iNumber = rand() % 46;
		for (int j = 0; j < 7; j++)
		{
			if (iNumber == iLotto[j])
				break;
			else if (iNumber != iLotto[j])
				iLotto[i] = iNumber;
		}
	}
	for (int i = 0; i < 7; i++)
	{
		printf_s("%d\t", iLotto[i]);
		if (i == 5)
			printf_s("+\t");
	}
	printf_s("\n");
		
	

	return 0;
}

char* SetName()
{
	char Buffer[128] = "";
	//char* pName = nullptr;	//nullptr 널 포인터

	scanf("%s", Buffer);
	//
	//	  결과값을 받아올 포인터 변수 {heap(힙)영역에 저장된 문자열의 주소를 받아옴}
	//	  ▽	  heap(힙) 영역에 저장될 문자열의 형태
	//	  ▽	  ▽	malloc(크기) = 동적할당
	//	  ▽	  ▽	 ▽			strlen(문자열) = 문자열의 길이를 변환
	//	  ▽	  ▽	 ▽			▽
	char* pName = (char*)malloc(strlen(Buffer) + 1);
	//△			△
	//└------------┘	같은 형태여야 한다.

	strcpy(pName, Buffer);

	return pName;
}