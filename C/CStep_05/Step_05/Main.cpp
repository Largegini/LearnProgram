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
	printf_s("����� ź������?\n");
	printf_s("�¾ ���� �Է��� �ּ��� : ");
	scanf_s("%d", &nBirthMon);
	printf_s("\n");

	switch (nBirthMon)
	{
		case 1 :
			printf_s("����� ź������ �����Դϴ�.\n�ǹ̴� ����, �����Դϴ�.\n");
			break;		// Ż�⹮

		case 2:
			printf_s("����� ź������ �ڼ����Դϴ�.\n�ǹ̴� ����, ��ȭ�Դϴ�.\n");
			break;

		case 3:
			printf_s("����� ź������ ����Ƹ����Դϴ�.\n�ǹ̴� ����, �ູ�Դϴ�.\n");
			break;

		case 4:
			printf_s("����� ź������ ���̾Ƹ���Դϴ�.\n�ǹ̴� �Ҹ�, ����Դϴ�.\n");
			break;

		case 5:
			printf_s("����� ź������ ���޶����Դϴ�.\n�ǹ̴� �ູ, ����Դϴ�.\n");
			break;

		case 6:
			printf_s("����� ź������ �����Դϴ�.\n�ǹ̴� ����, �α��Դϴ�.\n");
			break;

		case 7:
			printf_s("����� ź������ ����Դϴ�.\n�ǹ̴� ���, ��ȭ�Դϴ�.\n");
			break;

		case 8:
			printf_s("����� ź������ �丮��Ʈ�Դϴ�.\n�ǹ̴� �κ��� �ູ�Դϴ�.\n");
			break;

		case 9:
			printf_s("����� ź������ �����̾��Դϴ�.\n�ǹ̴� ����, �����Դϴ�.\n");
			break;

		case 10:
			printf_s("����� ź������ �����Դϴ�.\n�ǹ̴� ���, �����Դϴ�.\n");
			break;

		case 11:
			printf_s("����� ź������ �������Դϴ�.\n�ǹ̴� �ǰ�, ����Դϴ�.\n");
			break;

		case 12:
			printf_s("����� ź������ ��Ű���Դϴ�.\n�ǹ̴� ����, �¸��Դϴ�.\n");
			break;

		default :
			printf_s("�߸��� �Է��Դϴ�!!\n");
	}

	// ** ������ �̸��� ���ٸ� �ش� ������ �ִ� ������ �켱������ ��.
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

	// ** ���� ���� ���
	printf_s("%d\n", nCount);

	nCount = 20;
	printf_s("%d\n", nCount);
	int nResult = Add(37, 14);

	printf_s("%d\n", Add(20, 35));
	printf_s("%d\n", nResult);
	*/

	int iNumber;

	printf_s("1~255 �� �ϳ� : ");
	scanf_s("%d", &iNumber);

	switch (Input(iNumber))
	{
		case 1:
			printf_s("���� 1 �Է�\n\n");
			break;

		case 2:
			printf_s("���� 2 �Է�\n\n");
			break;

		case 3:
			printf_s("���� 3 �Է�\n\n");
			break;

		default :
			printf_s("%c\n", Output(iNumber));
				break;
	}

	return 0;
}

// **�Ű������� �ش� ������ ��� �� ����.

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

