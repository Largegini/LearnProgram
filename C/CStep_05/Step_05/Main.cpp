#include<stdio.h>

int nCount;
float g_fVarable;

void LocalFcn(void);
int Add(int i, int j);
int Input(int _inumber);
char Output(int _inumber);

int main(void)
{
	/*
	int nBirthMon = 0;
	printf_s("당신의 탄생석은?\n");
	printf_s("태어난 월을 입력해 주세요 : ");
	scanf_s("%d", &nBirthMon);
	printf_s("\n");

	switch (nBirthMon)
	{
		case 1 :
			printf_s("당신의 탄생석은 가넷입니다.\n의미는 진실, 우정입니다.\n");
			break;		// 탈출문

		case 2:
			printf_s("당신의 탄생석은 자수정입니다.\n의미는 성실, 평화입니다.\n");
			break;

		case 3:
			printf_s("당신의 탄생석은 아쿠아마린입니다.\n의미는 젊음, 행복입니다.\n");
			break;

		case 4:
			printf_s("당신의 탄생석은 다이아몬드입니다.\n의미는 불멸, 사랑입니다.\n");
			break;

		case 5:
			printf_s("당신의 탄생석은 에메랄드입니다.\n의미는 행복, 행운입니다.\n");
			break;

		case 6:
			printf_s("당신의 탄생석은 진주입니다.\n의미는 순결, 부귀입니다.\n");
			break;

		case 7:
			printf_s("당신의 탄생석은 루비입니다.\n의미는 사랑, 평화입니다.\n");
			break;

		case 8:
			printf_s("당신의 탄생석은 페리도트입니다.\n의미는 부부의 행복입니다.\n");
			break;

		case 9:
			printf_s("당신의 탄생석은 사파이어입니다.\n의미는 성실, 진실입니다.\n");
			break;

		case 10:
			printf_s("당신의 탄생석은 오팔입니다.\n의미는 희망, 순결입니다.\n");
			break;

		case 11:
			printf_s("당신의 탄생석은 토파즈입니다.\n의미는 건강, 희망입니다.\n");
			break;

		case 12:
			printf_s("당신의 탄생석은 터키석입니다.\n의미는 성공, 승리입니다.\n");
			break;

		default :
			printf_s("잘못된 입력입니다!!\n");
	}

	// ** 변수의 이름이 같다면 해당 영역에 있는 변수가 우선순위가 됨.
	int val = 10;

	if (val == 10)
	{
		int val = 20;

		printf_s("%d\n", val);
	}
	
	LocalFcn();

	//g_fVarable = 3.14f;
	char cMainA = 'A';
	char cMainB = 'B';

	{
		int m_iLocal = 10;
		g_fVarable = 6.28f;

		printf_s("m_iLocal : %d\ng_fVarable : %.2f\n\n", m_iLocal, g_fVarable);
	}

	printf_s("cMainA : %c\n", cMainA);
	printf_s("cMainB : %c\n", cMainB);
	printf_s("g_fVarable : %.2f\n\n", g_fVarable);

	// ** 전역 변수 사용
	printf_s("%d\n", nCount);

	nCount = 20;
	printf_s("%d\n", nCount);
	int nResult = Add(37, 14);

	printf_s("%d\n", Add(20, 35));
	printf_s("%d\n", nResult);
	*/

	int iNumber;

	printf_s("1~255 중 하나 : ");
	scanf_s("%d", &iNumber);

	switch (Input(iNumber))
	{
		case 1:
			printf_s("숫자 1 입력\n\n");
			break;

		case 2:
			printf_s("숫자 2 입력\n\n");
			break;

		case 3:
			printf_s("숫자 3 입력\n\n");
			break;

		default :
			printf_s("%c\n", Output(iNumber));
				break;
	}

	return 0;
}

// **매개변수는 해당 영역을 벗어날 수 없다.

void LocalFcn(void)
{
	int iLocalA = 20;
	int iLocalB = 30;
	g_fVarable = 9.24f;
	nCount = 10;

	printf_s("iLocalA : %d\niLocalB : %d\ng_fVarable : %.2f\n\n", iLocalA, iLocalB, g_fVarable);
	
}

int Add(int i, int j)
{
	return i + j;
}

int Input(int _inumber)
{
	return _inumber;
}

char Output(int _inumber)
{
	return _inumber;
}

