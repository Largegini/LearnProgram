#include <iostream>	//c++��Ÿ�� ǥ������� ���̺귯��
#include <Windows.h>

using namespace std;	// std��� �̸��� ���� ���ӽ����̽��� �� �����ض�

// ����� ����� �߻� Ŭ�����̴�
class Parents
{
protected:
	string Name;

public:
	//	���� �����Լ�
	//	�Լ��ȿ� �ƹ��͵� ����
	//	�����Լ��� �����ϴ�
	//	virtual void Output() =0;
	//	PURE -> #define = 0					   �����ε�
	virtual void Output()PURE;				// <-��	
	virtual void Output(string _str)PURE;	// <-��  <-��������������
											//					   ��
	Parents() {}							//					   ��
	Parents(string _str) : Name(_str) {}	//					   ��
											//					   ��
};											//					   ��
											//				   �������̵�
class Child : public Parents				//					   ��
{											//					   ��
public:										//					   ��
	//	�����ε�												   ��
	//	�Ű������� Ÿ�԰� ������ ���� �ٸ��� ȣ���� �� �ִ� ���   ��
	//	���� ���������� ������									   ��
	//	��ӿ��οʹ� �������				   �����ε�     	   ��
	virtual void Output() override			// <-��		           ��
	{										//	 ��				   ��
		cout << "Child : " << Name << endl;	//   ��  <-��������������
	}										//   ��
	virtual void Output(string _str)override// <-��
	{
		cout << "Name : " << _str << endl;
	}

	Child() {}
	Child(string _str) : Parents(_str) {}
};

class Object : public Parents
{
public:
	//	�������̵�
	//	Ŭ������ ���¿� ���� �����̵Ǵ� ��
	//	��Ӱ��迡 ���������� ����
	//	��Ӱ����� ��쿡�� ���
	virtual void Output()override
	{
		cout << "Object : " << Name << endl;
	}
	virtual void Output(string _str)override
	{
		cout << "Object : " << Name << endl;
	}

	Object() {}
	Object(string _str) : Parents(_str) {}
};
//	** �����ε� & �������̵�
int main()
{

	Parents* p[2];

	p[0] = new Child("ȫ�浿");
	p[1] = new Object("�Ӳ���");

	p[0]->Output();
	p[1]->Output();
	return 0;
}

