#include <iostream>	//c++스타일 표준입출력 라이브러리
#include <Windows.h>

using namespace std;	// std라는 이름을 가진 네임스페이스를 다 생략해라

// 기능이 없어야 추상 클래스이다
class Parents
{
protected:
	string Name;

public:
	//	순수 가상함수
	//	함수안에 아무것도 없다
	//	가상함수만 가능하다
	//	virtual void Output() =0;
	//	PURE -> #define = 0					   오버로딩
	virtual void Output()PURE;				// <-┐	
	virtual void Output(string _str)PURE;	// <-┘  <-──────┐
											//					   │
	Parents() {}							//					   │
	Parents(string _str) : Name(_str) {}	//					   │
											//					   │
};											//					   │
											//				   오버라이딩
class Child : public Parents				//					   │
{											//					   │
public:										//					   │
	//	오버로딩												   │
	//	매개변수의 타입과 갯수에 따라 다르게 호출할 수 있는 기능   │
	//	같은 영역내에서 결정됨									   │
	//	상속여부와는 관계없다				   오버로딩     	   │
	virtual void Output() override			// <-┐		           │
	{										//	 │				   │
		cout << "Child : " << Name << endl;	//   │  <-──────┘
	}										//   │
	virtual void Output(string _str)override// <-┘
	{
		cout << "Name : " << _str << endl;
	}

	Child() {}
	Child(string _str) : Parents(_str) {}
};

class Object : public Parents
{
public:
	//	오버라이딩
	//	클래스의 형태에 따라 실행이되는 것
	//	상속관계에 영역내에서 결정
	//	상속관계일 경우에만 사용
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
//	** 오버로딩 & 오버라이딩
int main()
{

	Parents* p[2];

	p[0] = new Child("홍길동");
	p[1] = new Object("임꺽정");

	p[0]->Output();
	p[1]->Output();
	return 0;
}

