#include <stdio.h>

/** main 컴파일러실행 될때 main함수만 실행(main함수가 없으면 진입점이 없다는 오류발생)
	* 하나만 존재할 수 있다.
	*다른 함수같은 경우에는 main함수 안에서 호출하여 실행 
*/

/*
	[%c]	=	문자출력
	[%d]	=	부호있는 10진 정수
	[%f]	=	부호있는 10진 실수
	[%s]	=	문자열출력
*/

//함수는 컴퓨터에게 
int main(void)
{
	printf_s("\nHello, World!!\n\n");				//_s 2011버전에 보안문제로 인해 추가됨

	printf_s("char : %d\n", sizeof(char));		// %d 자리에 정수값 입력가능 
	printf_s("short : %d\n", sizeof(short));	// \n 줄바꿈, \t 공백
	printf_s("int : %d\n", sizeof(int));
	printf_s("float : %d\n", sizeof(float));
	printf_s("long : %d\n", sizeof(long));
	printf_s("double : %d\n\n", sizeof(double));

	// sizeof ( datatype ) = 자료형의 크기를 바이트 단위로 반환시켜줌.

	printf_s("*************************************\n");
	printf_s("Let's Study C/C++ Game Programming!!!\n");
	printf_s("*************************************\n\n");
	//	위와 아래의 출력 결과는 같다.
	printf_s("*************************************\nLet's Study C/C++ Game Programming!!!\n*************************************\n");

	return 0;		//메인 함수의 리턴은 프로그램의 대부분 정상종료를 뜻한다.
					//반환값은 항상 하나
}