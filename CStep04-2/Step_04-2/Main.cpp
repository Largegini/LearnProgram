#include <stdio.h>

int main(void)
{
	int iInput;
	/*
	printf_s("���� �Է� : ");
	scanf_s("%d", &iInput);

	if (iInput % 2 == 0)
	{
		printf_s(" %d �� ¦��\n", iInput);
	}
	else if (iInput % 2 == 1)
	{
		printf_s(" %d �� Ȧ��\n", iInput);
	}
	else
		printf_s("Ȧ���� ¦���� �ƴ� ����\n");
	*/

	printf_s("���� �Է� : ");
	scanf_s(" % d", &iInput);
	if (iInput <= 0)
	{
		printf_s(" % d : 0 ���� �۰ų� ����\n", iInput);
	}
	else if (iInput > 0 && iInput < 10)
	{
		printf_s(" % d : 0 ���� ũ���� 10 ���� �۴�\n");
	}
	else if ((iInput > 10 && iInput < 15) || (iInput > 20 && iInput < 25))
	{
		printf_s("�׷��ϴ�");
	}
	else
		printf("else\n");

	return 0;
}
