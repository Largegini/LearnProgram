#pragma once
#include <iostream>	
#include <Windows.h>

using namespace std;	// std��� �̸��� ���� ���ӽ����̽��� �� �����ض�

//	** ������ �����ε�
//	** [&] ��� �뵵
//	** 1. 2�� �����ڷ� ���
//	**	- & <- 1���� �����ٸ� [��Ʈ����]
//	**	- && <- 2���� �����ٸ� [�񱳿��� & ������]
// 
//	** 2. ���� �����ڷ� ���
//	**  - &���� <- ���� ���ʿ� ������� [�ּҹ�ȯ ������]
//	**  - �ڷ���(����)& <- �ڷ��� ���ʿ� ���� ��� [���۷��� ������]

class Object
{
private:

	float Number;

public:

	float GetNumber() { return Number; }

	/*
	Object& operator+=(Object& _obj)
	{
		this->Number += _obj.Number;
		return (*this);
	}

	Object& operator+=(int number)
	{
		this->Number += number;
		return (*this);
	}
	*/

	Object& operator/(Object& _obj)
	{
		this->Number = this->Number / _obj.Number;
		return (*this);
	}

	Object operator*(Object _obj)
	{
		return Object(this->Number * _obj.Number);
	}

	Object& operator/(int number)
	{
		this->Number = this->Number / number;
		return (*this);
	}

	Object& operator+(Object& _obj)
	{
		this->Number = this->Number + _obj.Number;
		return (*this);
	}

	Object& operator+(int number)
	{
		this->Number = this->Number + number;
		return (*this);
	}

	Object& operator++(int number)
	{
		++this->Number;
		return (*this);
	}



public:
	Object() {}

	Object(float _Number) : Number(_Number) {}

	~Object() {}


};


int main()
{
	//	int i1(1) �� i1 = 1 �� ����

	Object  o1(10), o2(2);
	o1 / o2;
	cout << o1.GetNumber() << endl;
	o1 / 5;
	cout << o1.GetNumber() << endl;

	o1 + o2;
	cout << o1.GetNumber() << endl;
	o1 + 7;
	cout << o1.GetNumber() << endl;

	o1++;
	cout << o1.GetNumber() << endl;

	Object o3 = o1 * o2;
	cout << o3.GetNumber() << endl;

	return 0;

}
