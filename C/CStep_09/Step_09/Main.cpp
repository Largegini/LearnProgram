#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string>

typedef struct taginfo
{
	char Name[7];
	int iKor;
	int iEng;
	int iMath;
}INFO;

int main(void)
{
	// ** ���� 
	//typedef int INT;
	//printf_s("%d\n", sizeof(INT));
/*
	taginfo StudentA;
	taginfo StudentB;

	printf_s("StudentA : \n");
	printf_s("�������� : ");
	scanf_s("%d", &StudentA.iKor);
	printf_s("�������� : ");
	scanf_s("%d", &StudentA.iEng);
	printf_s("�������� : ");
	scanf_s("%d", &StudentA.iMath);
	printf_s("��: %d, ��: %d, ��: %d\n\n", StudentA.iKor, StudentA.iEng, StudentA.iMath);

	printf_s("StudentB : \n");
	printf_s("�������� : ");
	scanf_s("%d", &StudentB.iKor);
	printf_s("�������� : ");
	scanf_s("%d", &StudentB.iEng);
	printf_s("�������� : ");
	scanf_s("%d", &StudentB.iMath);
	printf_s("��: %d, ��: %d, ��: %d\n", StudentB.iKor, StudentB.iEng, StudentB.iMath);
	// ����
	INFO info;

	char name[7] = "ȫ�浿";

	//���ڿ� ����
	strcpy(info.Name, name);
	info.iKor = 70;
	info.iEng = 80;
	info.iMath = 95;

	printf_s("%s\n", info.Name);
	printf_s("%d\n", info.iKor);
	printf_s("%d\n", info.iEng);
	printf_s("%d\n", info.iMath);
	INFO info;
	int iIndex = 0;

	printf_s("����� ������ ���� �Դϱ�?\n");
	printf_s("*****************************************\n");
	printf_s("*		 1. ��    ��		*\n");
	printf_s("*		 2. �� �� ��		*\n");
	printf_s("*		 3. ��    ��		*\n");
	printf_s("*****************************************\n");
	scanf_s("%d", &iIndex);

	switch(iIndex)
	{
	case 1 :
		strcpy(info.Name, "�� ��");
		printf_s("����� ������ %s �Դϴ�.\n", info.Name);
		break;
	case 2:
		strcpy(info.Name, "�� �� ��");
		printf_s("����� ������ %s �Դϴ�.\n", info.Name);
		break;
	case 3:
		strcpy(info.Name, "�� ��");
		printf_s("����� ������ %s �Դϴ�.\n", info.Name);
		break;
	default :
		break;
	}

*/
	INFO StudentA;
	INFO StudentB;
	INFO StudentC;
	
	char AName[20] = "";
	char BName[20] = "";
	char CName[20] = "";

	printf_s("�� ���� �л��� ������ �Է��Ͻʽÿ�.\n");
	
	INFO Student[3];
	char Name[10] = "ȫ�浿";
	int input = 0;
	for(int i = 0; i<3; i++)
	{
		
		if (input < 3)
		{
			for (int j = 0; j < 3; j++)
			{
				printf_s("%d ��° �л� �̸�(����) : ", j+1);
				if(j==0)
				{
					scanf_s("%s", AName, sizeof(AName));
					strcpy(Student[j].Name, AName);
				}
				else if(j==1)
				{
					scanf_s("%s", BName, sizeof(BName));
					strcpy(Student[j].Name, BName);
				}
				else if(j==2)
				{
					scanf_s("%s", CName, sizeof(CName));
					strcpy(Student[j].Name, CName);
				}
					printf_s("%d ��° �л� ���� ���� : ",j+1);
					scanf_s("%d", &Student[j].iKor);
					printf_s("%d ��° �л� ���� ���� : ",j+1);
					scanf_s("%d", &Student[j].iEng);
					printf_s("%d ��° �л� ���� ���� : ", j+1);
					scanf_s("%d", &Student[j].iMath);
					printf_s("\n");
					input++;
			}
		}
		printf_s("%s �л��� ������ �� : %d �� : %d �� : %d �Դϴ�.\n", Student[i].Name, Student[i].iKor, Student[i].iEng, Student[i].iMath);
	}
	

	return 0;
}