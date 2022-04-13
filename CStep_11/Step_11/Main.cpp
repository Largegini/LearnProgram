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

	cAlphabet = 'A';	//���ĺ��� ������ ���� ��� 2byte
	cHanguel = '��';	//1 byte�� char���� �ѱ� ���� �ȵ�

	printf_s("Alphabet : %c / Hanguel : %c \n", cAlphabet, cHanguel);
	char cHarray[] = "��";			// �ѱ� ���� �� ���ڿ� ���
	printf_s("%s\n\n", cHarray);	// ���ڿ� ���Ǵ� " ";

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
	char* pName = nullptr;	//nullptr �� ������

	scanf("%s", Buffer);
	pName = (char*)malloc(strlen(Buffer) + 1);
	strcpy(pName, Buffer);

	printf_s("����� �̸��� �����Դϱ�? : ");

	char* pName = SetName();

	printf_s("%s���̱��� �ε� ���迡 ���� ��ũ��þƸ� �����ּ���\n", pName);
	*/

	// ** ���� �Լ� �ʱ�ȭ
	srand(time(NULL)); 
	int iLotto[8] = {};
	int iNumber = 0;;

	printf_s("SGA Lotto ��÷��ȣ�� ? \n");
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
	//char* pName = nullptr;	//nullptr �� ������

	scanf("%s", Buffer);
	//
	//	  ������� �޾ƿ� ������ ���� {heap(��)������ ����� ���ڿ��� �ּҸ� �޾ƿ�}
	//	  ��	  heap(��) ������ ����� ���ڿ��� ����
	//	  ��	  ��	malloc(ũ��) = �����Ҵ�
	//	  ��	  ��	 ��			strlen(���ڿ�) = ���ڿ��� ���̸� ��ȯ
	//	  ��	  ��	 ��			��
	char* pName = (char*)malloc(strlen(Buffer) + 1);
	//��			��
	//��------------��	���� ���¿��� �Ѵ�.

	strcpy(pName, Buffer);

	return pName;
}