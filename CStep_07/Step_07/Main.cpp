#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	/*
	int iArrayA[5] = {1, 2, 3, 4, 5};
	int iArrayB[] = { 1, 2, 3, 4, 5 };
	int iArrayC[5] = { 1, 2 };
	int iArrayD[5] = { 0 };

	for (int i = 0; i < 5; i++)
	{
		printf_s("%d번-[A : %d] [B : %d] [C : %d] [D : %d]\n\n", i, iArrayA[i], iArrayB[i], iArrayC[i], iArrayD[i]);
	}
	int iArray[3][3] =
	{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};

	for (int i = 0; i < 3; i++)
	{
		for(int j =0; j<3; j++)
		{
			printf_s("%d\t", iArray[i][j]);

			if (j == 2)
				printf_s("\n");
		}
	}
	printf_s("\n");

	char str[5] = "Good";
	for (int i = 0; i < 4; ++i)
	{
		printf_s("%d", str[i]);
	}

	char str2[9] = "Morning!";

	const int Number = 10;			//Number를 상수 10으로 정의(지정)
	*/
	char str1[5] = { 'G', 'o', 'o', 'd' , '\0'};
	char str2[9] = { 'M', 'o', 'r', 'n', 'i', 'n', 'g', '!'};

	char str3[] = "Sunshine!";
	char str4[] = { 'G', 'o', 'o', 'd' , 32, 'M', 'o', 'r', 'n', 'i', 'n', 'g', '!', '\0'};

	

	for (int i = 0; i < 5; ++i)
	{
		printf_s("%c", str1[i]);
	}
	printf_s("\n");

	
	printf_s("%s %s", str2, str3);
	printf_s("\n");

	for (int i = 0; i < 14; ++i)
	{
		printf_s("%c", str4[i]);
	}

	return 0;
}