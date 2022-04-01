#include <stdio.h>

int main(void)
{
	/*
	//변수 선언
	int na, nb;		

	//선언과 동시에 초기화
	int nc = 30, nd = 40;	

	// 초기화
	na = 10;
	nb = 20;

	printf_s("%d %d \n", na, nb);
	printf_s("%d %d \n\n", nc, nd);

	float fNumber;
	fNumber = 87.654321f;

	printf_s("%f\n", fNumber);			//형태에 알맞은 출력
	printf_s("%d\n", (int)fNumber);		//float형을 int형으로 변환
	printf_s("%c\n", (char)fNumber);	//float형을 char형으로 변환
	printf_s("%d\n\n", fNumber);		//형태에 알맞지 않은 출력 쓰레기 값 출력

	//실수형 타입의 변수를
	float fPI = 3.141592f;

	//정수형 타입의 변수에 대입하면
	//소수점 데이터는 소실 된다.
	int i = fPI;

	printf_s("%03d\n", i);		// 정수는 자릿수 설정이 가능
	printf_s("%0.3f\n\n", fPI);	// 실수는 소수점 아래 몇자리 까지 출력할지 설정 가능

	printf_s("%d\n", 3.14);		//1374389535
	printf_s("%d\n", 314);		//314	
	printf_s("%d\n", 0x13a);	//314

	printf_s("%x\n", 0x13a);	//13a
	printf_s("%X\n\n", 0X13A);	//13A

	printf_s("%d\n", 'A');		//65 문자는 정수형이다.
	printf_s("%d\n", '&');	
	printf_s("%c\n", 65);		//A
	printf_s("%c\n", 38);	
	printf_s("%x\n", 'A');		//41
	printf_s("%c\n\n", 'A');	//A
	*/

	int nNum;		//값을 저장 받을 int 형
	float fNum;		//값을 저장 받을 float 형

	printf_s("nNum 값 입력 : ");
	scanf_s("%d", &nNum);			//scanf_s(); 에 값을 입력하고 '&'(엠퍼센트)
	printf_s("fNum 값 입력 : ");
	scanf_s("%f", &fNum);

	printf_s("nNum : %d\n", nNum);
	printf_s("fNum : %f\n\n", fNum);

	printf_s("%d %d %d %d %d %d %d %d %d %d \n", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);	//왼쪽에서부터 순차적으로 들어간다.

	return 0;
}
