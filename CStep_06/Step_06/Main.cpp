#include <stdio.h>

int main(void)
{
	/*
	int i = 0;

	// ** 특정조건이 만족하는 동안 
	while (i < 10)
	{
		// 현재 영역의 내용이 반복됨.

		printf_s("Hello World! \n");
		i++;
	}

	int iFahrenheit, iCelsius = 0;
	int iLower, iUpper, iStep;

	iLower = 0;
	iUpper = 300;
	iStep = 20;

	iFahrenheit = iLower;

	while (iFahrenheit <= iUpper)
	{
		iCelsius = 5 + (iFahrenheit - 32) / 9;
		printf_s("화씨 : %d\t섭씨 : %d\n", iFahrenheit, iCelsius);
		iFahrenheit += iStep;
	}

	printf_s("\n");

	for (int i = 0; i < 10; i++)
	{
		printf_s("Loop Count : %d\n", i+1);
	}

	for (int i = 2; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
			printf_s("%d x %d = %d\n", i, j, i * j);
		printf_s("\n");
	}

	int iYear = 1627;
	double dBankMoney = 24.0f;
	for (iYear; iYear < 2023; iYear++)
		dBankMoney *= 1.08f;
	printf_s("2022년에는 %.2f $의 가치일 것이다.\n", dBankMoney);
	*/

	for (int i = 0; i < 10; i++)		//1번 피라미드	
	{									
		for (int j = 0; j < 10; j++)
		{
			if (j < i + 1)
				printf_s("*");
			else
				printf_s(" ");
		}
			
		printf_s("\t");

		for (int j = 0; j < 10; j++)	//2번
		{								
			if (j < i)					
				printf_s(" ");			
			else						
				printf_s("*");
		}

		printf_s("\t");		

		
		for (int j = 0; j < 10; j++) //3번
		{
			if (j < 10 - (i + 1))
				printf_s(" ");
			else
				printf_s("*");
		}

		printf_s("\t");

		for (int j = 0; j < 10; j++) //4번
		{
			if(j < 10-i)
				printf_s("*");
			else
				printf_s(" ");
		}
		printf_s("\n");

	}	
	printf_s("\n");
		
	for (int i = 0; i < 10; i++) //5-1
	{
		for (int j = 0; j < 10; j++)
		{
			if (j < i + 1)
				printf_s("*");
			else
				printf_s(" ");
		}

		printf_s("\t");
		for (int j = 0; j < 10; j++)
			if (j < 10 - (i + 1))
				printf_s(" ");
			else
				printf_s("*");

		printf_s("\t");

		for (int j = 0; j < 10; j++)
		{
			if (j < 10 - (i + 1))
				printf_s(" ");
			else
				printf_s("*");
		}
		for (int j = 0; j < i + 1; j++)
			printf_s("*");
		printf_s("\n");

	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++) 
		{
			if (j < 10 - i)
				printf_s("*");
			else
				printf_s(" ");
		}

		printf_s("\t");

		for (int j = 0; j < 10; j++)
		{
			if (j < i)
				printf_s(" ");
			else
				printf_s("*");
		}
		printf_s("\t");

		for (int j = 0; j < 10; j++)
		{
			if (j < i)
				printf_s(" ");
			else
				printf_s("*");
		}

		for (int j = 0; j < 10 - i; j++)
			printf_s("*");
		printf_s("\n");

	}
	printf_s("\n\n");


	return 0;
}