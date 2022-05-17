#include <stdio.h>

int main(void)
{
	int iInput;
	/*
	printf_s("숫자 입력 : ");
	scanf_s("%d", &iInput);

	if (iInput % 2 == 0)
	{
		printf_s(" %d 는 짝수\n", iInput);
	}
	else if (iInput % 2 == 1)
	{
		printf_s(" %d 는 홀수\n", iInput);
	}
	else
		printf_s("홀수도 짝수도 아닌 숫자\n");
	*/

	printf_s("숫자 입력 : ");
	scanf_s(" % d", &iInput);
	if (iInput <= 0)
	{
		printf_s(" % d : 0 보다 작거나 같다\n", iInput);
	}
	else if (iInput > 0 && iInput < 10)
	{
		printf_s(" % d : 0 보다 크지만 10 보다 작다\n");
	}
	else if ((iInput > 10 && iInput < 15) || (iInput > 20 && iInput < 25))
	{
		printf_s("그러하다");
	}
	else
		printf("else\n");

	return 0;
}
