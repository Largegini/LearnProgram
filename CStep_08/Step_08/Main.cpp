#include<stdio.h>
#include<stdlib.h>
#include<malloc.h> // 말록, 엠알록 이라고 부름 M은 Memory, alloc 은 allocation

// *** 파일이동은 복사한 뒤 기존 데이터 삭제이다
// & (엠퍼센드) 주소반환연산자
// '*' (asterisk)

int main(void)
{
	/*
	int Value = 10;

	int i = Value;
	int n = 0;

	printf_s("i : %d\n", i);
	printf_s("n : %d\n", n);

	int temp = i;
	i = n;
	n = temp;

	printf_s("i : %d\n", i);
	printf_s("n : %d\n", n);
	

	printf_s("iNumber : %d\n", iNumber1);
	printf_s("iNumber : %d\n", iNumber2);
	printf_s("iNumber1 주소값 : %d\n", &iNumber1);
	printf_s("iNumber2 주소값 : %d\n", &iNumber2);

	int iNumber1 = 10;
	int iNumber2 = 100;

	int* pPoint = &iNumber2;

	printf_s("iNumber2 주소값 : %d\n", &iNumber2);
	printf_s("Point 값 : %d\n", pPoint);

	printf_s("%d\n", *pPoint);

	iNumber2 = 50;

	printf_s("%d\n", *pPoint);
	*/

	// ** [포인터 사용 방법 3가지]
	// ** 1. [*] = 데이터 [&] = 주소
	// ** 2. 포인터 변수라면 무조건 동적할당을 해주도록 한다.
	// ** 3. [.] 아니면 [->] 화살표
	//포인터는 주소값만 저장하기에 용량이 많이 필요하지 않다.

	int iNumber = 19;
	int* piNumber;
	piNumber = &iNumber;

	int* pPointer = ;

	printf_s("iNumber	: %d\n", iNumber);
	printf_s("*piNumber	: %d\n", *piNumber);
	printf_s("piNumber	: %d\n", piNumber);
	printf_s("&iNumber	: %d\n", &iNumber);
	printf_s("&piNumber	: %d\n", &piNumber);

	// 동적할당
	// int* pNumber = (int*)malloc(sizeof(int));

	return 0;
}