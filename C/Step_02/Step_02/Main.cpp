#include <stdio.h>

/** main �����Ϸ����� �ɶ� main�Լ��� ����(main�Լ��� ������ �������� ���ٴ� �����߻�)
	* �ϳ��� ������ �� �ִ�.
	*�ٸ� �Լ����� ��쿡�� main�Լ� �ȿ��� ȣ���Ͽ� ���� 
*/

/*
	[%c]	=	�������
	[%d]	=	��ȣ�ִ� 10�� ����
	[%f]	=	��ȣ�ִ� 10�� �Ǽ�
	[%s]	=	���ڿ����
*/

//�Լ��� ��ǻ�Ϳ��� 
int main(void)
{
	printf_s("\nHello, World!!\n\n");				//_s 2011������ ���ȹ����� ���� �߰���

	printf_s("char : %d\n", sizeof(char));		// %d �ڸ��� ������ �Է°��� 
	printf_s("short : %d\n", sizeof(short));	// \n �ٹٲ�, \t ����
	printf_s("int : %d\n", sizeof(int));
	printf_s("float : %d\n", sizeof(float));
	printf_s("long : %d\n", sizeof(long));
	printf_s("double : %d\n\n", sizeof(double));

	// sizeof ( datatype ) = �ڷ����� ũ�⸦ ����Ʈ ������ ��ȯ������.

	printf_s("*************************************\n");
	printf_s("Let's Study C/C++ Game Programming!!!\n");
	printf_s("*************************************\n\n");
	//	���� �Ʒ��� ��� ����� ����.
	printf_s("*************************************\nLet's Study C/C++ Game Programming!!!\n*************************************\n");

	return 0;		//���� �Լ��� ������ ���α׷��� ��κ� �������Ḧ ���Ѵ�.
					//��ȯ���� �׻� �ϳ�
}