#pragma once
#include <iostream>	//c++��Ÿ�� ǥ������� ���̺귯��

using namespace std;	// std��� �̸��� ���� ���ӽ����̽��� �� �����ض�

// ** ���
class Parents
{
protected:
	int Number;

	string Name;
public:
	void Output()
	{
		cout << Name << endl;
	}

	Parents() {}
	Parents(string _str) : Name(_str) {}

};

class Child : public Parents
{
public:


	Child() {}
	Child(string _str) : Parents(_str) {}
};

int main()
{
	Child c = Child("Child");
	c.Output();
	return 0;
}