#include <stdio.h>

int main(void)
{
	/*
	//���� ����
	int na, nb;		

	//����� ���ÿ� �ʱ�ȭ
	int nc = 30, nd = 40;	

	// �ʱ�ȭ
	na = 10;
	nb = 20;

	printf_s("%d %d \n", na, nb);
	printf_s("%d %d \n\n", nc, nd);

	float fNumber;
	fNumber = 87.654321f;

	printf_s("%f\n", fNumber);			//���¿� �˸��� ���
	printf_s("%d\n", (int)fNumber);		//float���� int������ ��ȯ
	printf_s("%c\n", (char)fNumber);	//float���� char������ ��ȯ
	printf_s("%d\n\n", fNumber);		//���¿� �˸��� ���� ��� ������ �� ���

	//�Ǽ��� Ÿ���� ������
	float fPI = 3.141592f;

	//������ Ÿ���� ������ �����ϸ�
	//�Ҽ��� �����ʹ� �ҽ� �ȴ�.
	int i = fPI;

	printf_s("%03d\n", i);		// ������ �ڸ��� ������ ����
	printf_s("%0.3f\n\n", fPI);	// �Ǽ��� �Ҽ��� �Ʒ� ���ڸ� ���� ������� ���� ����

	printf_s("%d\n", 3.14);		//1374389535
	printf_s("%d\n", 314);		//314	
	printf_s("%d\n", 0x13a);	//314

	printf_s("%x\n", 0x13a);	//13a
	printf_s("%X\n\n", 0X13A);	//13A

	printf_s("%d\n", 'A');		//65 ���ڴ� �������̴�.
	printf_s("%d\n", '&');	
	printf_s("%c\n", 65);		//A
	printf_s("%c\n", 38);	
	printf_s("%x\n", 'A');		//41
	printf_s("%c\n\n", 'A');	//A
	*/

	int nNum;		//���� ���� ���� int ��
	float fNum;		//���� ���� ���� float ��

	printf_s("nNum �� �Է� : ");
	scanf_s("%d", &nNum);			//scanf_s(); �� ���� �Է��ϰ� '&'(���ۼ�Ʈ)
	printf_s("fNum �� �Է� : ");
	scanf_s("%f", &fNum);

	printf_s("nNum : %d\n", nNum);
	printf_s("fNum : %f\n\n", fNum);

	printf_s("%d %d %d %d %d %d %d %d %d %d \n", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);	//���ʿ������� ���������� ����.

	return 0;
}
