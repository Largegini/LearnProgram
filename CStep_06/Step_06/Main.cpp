#include <stdio.h>

int main(void)
{
	/*
	int i = 0;

	// ** Ư�������� �����ϴ� ���� 
	while (i < 10)
	{
		// ���� ������ ������ �ݺ���.

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
		printf_s("ȭ�� : %d\t���� : %d\n", iFahrenheit, iCelsius);
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
	printf_s("2022�⿡�� %.2f $�� ��ġ�� ���̴�.\n", dBankMoney);
	*/

	for (int i = 0; i < 10; i++)		//1�� �Ƕ�̵�	
	{									
		for (int j = 0; j < 10; j++)
		{
			if (j < i + 1)
				printf_s("*");
			else
				printf_s(" ");
		}
			
		printf_s("\t");

		for (int j = 0; j < 10; j++)	//2��
		{								
			if (j < i)					
				printf_s(" ");			
			else						
				printf_s("*");
		}

		printf_s("\t");		

		
		for (int j = 0; j < 10; j++) //3��
		{
			if (j < 10 - (i + 1))
				printf_s(" ");
			else
				printf_s("*");
		}

		printf_s("\t");

		for (int j = 0; j < 10; j++) //4��
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