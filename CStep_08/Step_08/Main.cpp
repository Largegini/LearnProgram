#include<stdio.h>
#include<stdlib.h>
#include<malloc.h> // ����, ���˷� �̶�� �θ� M�� Memory, alloc �� allocation

// *** �����̵��� ������ �� ���� ������ �����̴�
// & (���ۼ���) �ּҹ�ȯ������
// '*' (asterisk)

int main(void)
{
	/*
	int Value = 10;

	int i = Value;
	int n = 0;

	printf_s("i : %d\n", i);
	printf_s("n : %d\n", n);

	int temp = i;
	i = n;
	n = temp;

	printf_s("i : %d\n", i);
	printf_s("n : %d\n", n);
	

	printf_s("iNumber : %d\n", iNumber1);
	printf_s("iNumber : %d\n", iNumber2);
	printf_s("iNumber1 �ּҰ� : %d\n", &iNumber1);
	printf_s("iNumber2 �ּҰ� : %d\n", &iNumber2);

	int iNumber1 = 10;
	int iNumber2 = 100;

	int* pPoint = &iNumber2;

	printf_s("iNumber2 �ּҰ� : %d\n", &iNumber2);
	printf_s("Point �� : %d\n", pPoint);

	printf_s("%d\n", *pPoint);

	iNumber2 = 50;

	printf_s("%d\n", *pPoint);
	*/

	// ** [������ ��� ��� 3����]
	// ** 1. [*] = ������ [&] = �ּ�
	// ** 2. ������ ������� ������ �����Ҵ��� ���ֵ��� �Ѵ�.
	// ** 3. [.] �ƴϸ� [->] ȭ��ǥ
	//�����ʹ� �ּҰ��� �����ϱ⿡ �뷮�� ���� �ʿ����� �ʴ�.

	int iNumber = 19;
	int* piNumber;
	piNumber = &iNumber;

	int* pPointer = ;

	printf_s("iNumber	: %d\n", iNumber);
	printf_s("*piNumber	: %d\n", *piNumber);
	printf_s("piNumber	: %d\n", piNumber);
	printf_s("&iNumber	: %d\n", &iNumber);
	printf_s("&piNumber	: %d\n", &piNumber);

	// �����Ҵ�
	// int* pNumber = (int*)malloc(sizeof(int));

	return 0;
}