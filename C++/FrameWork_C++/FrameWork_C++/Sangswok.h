#pragma once
#include <iostream>	//c++스타일 표준입출력 라이브러리

using namespace std;	// std라는 이름을 가진 네임스페이스를 다 생략해라

// ** 상속
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