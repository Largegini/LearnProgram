#include <stdio.h>

// true�� false�� 0�� �ƴ� ���� 0���� ���еȴ�.
// f9					�ߴ��� ���
// crtl + shift + f9	��� �ߴ��� ����

int main(void)
{
	/*
	int i = 3;
	printf_s("%d\n",i);
	printf_s("%d\n",i == 3);

	i = !i;
	printf_s("%d\n", i);

	if (33)
		printf_s("%d\n", 33);
	int i = 0;

	printf_s("1.�� �� \n2.������\n3.�� ��\n");
	printf_s("�Է� : ");
	scanf_s("%d", &i);

	if (i == 1) printf_s("��縦 �����ϼ̽��ϴ�! \n");

	else if (i == 2) printf_s("�����縦 �����ϼ̽��ϴ�!");

	else if (i == 3) printf_s("�ü��� �����ϼ̽��ϴ�! \n");

	else printf_s("�߸� �����ϼ̽��ϴ�!!\n");
	*/

	float fHeight = 0;
	int nWeight = 0;

	printf_s("Ű�� �Է��Ͻʽÿ�.(cm)\n");
	scanf_s("%f", &fHeight);
	fHeight /= 100.0f;								//Ű�� M�� ������ȯ

	printf_s("�����Ը� �Է��Ͻʽÿ�.(kg) \n");
	scanf_s("%d", &nWeight);

	float fBMI = nWeight / (fHeight * fHeight);		//BMI����
	printf_s("����� BMI�� %.1f�̸�, ", fBMI);		// %.nf n������ �����ڸ�����ŭ ǥ��

	if (fBMI >= 30)						
		printf_s("�����Դϴ�.");

	else if (fBMI < 30 && fBMI >= 25)	
		printf_s("���Դϴ�.");

	else if (fBMI < 25 && fBMI >= 23)	
		printf_s("��ü���Դϴ�.");
						   
	else if (fBMI < 23 && fBMI >= 18.5) 
		printf_s("ǥ�ظ������Դϴ�.");

	else if (fBMI < 18.5 )				
		printf_s("ǥ�ع̴��Դϴ�.");

	else								
		printf_s("�߸��� �Է��Դϴ�!");

	return  0;
}