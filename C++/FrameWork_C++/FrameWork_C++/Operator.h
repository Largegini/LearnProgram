#pragma once
#include <iostream>	
#include <Windows.h>

using namespace std;	// std라는 이름을 가진 네임스페이스를 다 생략해라

//	** 연산자 오버로딩
//	** [&] 사용 용도
//	** 1. 2항 연산자로 사용
//	**	- & <- 1번만 쓰였다면 [비트연산]
//	**	- && <- 2번만 쓰였다면 [비교연산 & 논리연산]
// 
//	** 2. 단항 연산자로 사용
//	**  - &변수 <- 변수 앞쪽에 붙은경우 [주소반환 연산자]
//	**  - 자료형(형태)& <- 자료형 뒷쪽에 붙은 경우 [레퍼런스 연산자]

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
	//	int i1(1) 은 i1 = 1 과 같다

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
