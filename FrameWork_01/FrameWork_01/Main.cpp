#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

typedef struct tagInfo
{
	int iNumber;

	//�⺻���� ����Ǵ� ������
	tagInfo() 
	{
		cout << "�⺻������" << endl;
	}
	
	//������ ������
	tagInfo(int _iNumber) 
	{
		iNumber = _iNumber;
		cout << "���������" << endl;
	}

}INFO;

int main(void)
{
	//	**	���
	//	printf_s == cout
	
	//	**	�ٹٲ�
	//	\n == endl(���� ����: ���� ��)
	
	//	*	cout c�ܼ�â���� out�������� ������? �ڿ� ���� ���ڿ��� "HelloWorld"
	//	**	'<<' Shift ������
	cout << "HelloWorld!!" << endl << "�ٹٲ�" << endl;

	//	**	�Է�
	int iTest = 0;

	//	scanf == cin
	//	cout <<(������)	"��"(���ڿ���) :	�ڿ� ���ڿ��� cout���� ������ �׷��⿡ ������ cout << ""
	cout << "�Է� : ";

	//	cin >>(������) iTest�� : cin���� �޾ƿͼ� �ڿ� iTest�� ������ �׷��� ������ cin >> iTest
	cin >> iTest;

	cout << iTest << endl;

	// ** void������
	//	malloc�Լ��� ��ȯ ���� void�������̱� ������ �տ� ����ȯ�� �ʿ��ϴ�
	//	void�� �ƹ� �͵� ���� �����̳� �����͸� ���̸� 4byte�� �Ҵ�ȴ�
	//	�� ���´� ���� ũ�⸸ �Ҵ�Ǿ��ִ�
	//	�׷��Ƿ� ��� ���·ε� ������ �����ϴ�

	//	**	�����Ҵ�
	//	INFO* pInfo = (INFO*)malloc(sizeof(INFO));
	//	(INFO*)malloc(sizeof(INFO)) == new INFO;
	//	������ ���� ���� �ƴ�
	//	�ʱ�ȭ�� ���� �������� �˾Ƽ� �����ڸ� �����Ϸ��� ȣ����
	//	new INFO; �� INFO�� �����̸鼭 �������̴�?
	INFO* pInfo = new INFO(10);

	cout << pInfo->iNumber << endl;
	//	**	�Ҵ�����
	//free(pInfo); == delete pInfo;
	delete pInfo;

	return 0;
}