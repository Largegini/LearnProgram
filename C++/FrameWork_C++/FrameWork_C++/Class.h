#pragma once
#include <iostream>		//c++스타일 표준입출력 라이브러리
#include <Windows.h>

using namespace std;

// namespace
//	**** 똑같은 이름으로 내용만 다른 함수를 만들수 있게 된다.
//	특정 영역을 지정한다
//	여러 개 만들 수 있다.
//	영역을 왜 써야 하는가?
//	함수를 만들어야 할 때 함수를 쓰다보면 여러개를 만들어서 쓰고 싶을 수 있다.
//	영역간 간섭이 없다.
//	namespace 접근 방식은 ' :: '로 한다 
//	점이4개 네임스페이스
//	Class는 네임스페이스의 기능을 포함하고 있다.
//	네임스페이스안에 클래스가 들어갈수 있다.

namespace AAA	// AAA라는 영역이 만들어짐
{
	int Number;
	void Output()
	{
		printf_s("Hello World %d \n", Number);
	}
}

using AAA::Output;

namespace BBB	// AAA라는 영역이 만들어짐
{
	int Number;
	void Output()
	{
		printf_s("Hello World B %d \n", Number);
	}
}

namespace CCC // AAA라는 영역이 만들어짐
{
	int Number;
	void Output()
	{
		printf_s("Hello World C %d \n", Number);
	}
}



//	**class 5가지 특징(OOP의 특징 객체지향 프로그래밍)
//	클래스는 객체를 만들기위해 사용 (인스턴스화)
//	상속과 추상화 없이도 데이터만으로도 분류가 가능하다.
//	다중상속은 특수한 경우에만 사용한다.(되도록 피해라)

//	1. 정보은닉 - 데이터는 항상 은닉(비공개)
//		- 데이터를 비공개로 하여 함부로 넘기지 않겠다
//		- 요청과 승인이 있다.
//		- 극소수의 데이터는 편의성을 위해 예외로 할 수 있다.
//
//	2. 캡슐화 - 데이터와 함수를 묶어서 사용해야함.
//		- 각자의 고유기능이 존재하며 공유할 수 없다
//		- 구조체 안에 별도의 함수를 넣어 자기 함수를 사용하게한다.
//		- 자신만의 기능(객체의 고유기능)
//
//	3. 상속 - 계층구조 - 단방향 계단형		(족보)
//		- 부모의 기능또는 데이터를 자식도 사용가능하다
//		- 부모가 그림을 잘 그리면 자녀도 잘 그릴 가능성이 있다 같은 느낌
//		- 인간은 직립보행을 하며 생각을 한다 말도 하고 (장애는 예외처리로 생각)
//
//	4. 추상화 - 추상화한다
//		- 추상성을 가진 클래스는 특정개체가 존재하지않는다(개체화 시키지않는다)
//		- 인간은 특정객체가 아닌 종을 지칭 (추상적) 대상이 없음 ( 추상화 )
//		- 객체(특정대상)가 존재하지 않는다
//		- 모든 클래스는 객체가 아니다.
//		- 모든 객체는 클래스다.
//
//	5. 다형성 - 다양한 형태
//		- 학생마다 다 다른 특징을 가지고 있다.
//		- 다 다른 형태를 취하나 학생이라는 점은 같다.

//	구조체의 제한된 기능 때문에 클래스를 사용하는 것
//	구조체는 기본적으로 퍼블릭(공개)이며 클래스는 비공개가 기본이다
//	클래스안에 함수를 만들게 되면 특별한 가치를 가진 함수가 된다. (클래스의 또 다른 기능)
//	클래스에서 선언한 함수를 네임스페이스로 접근하여 함수를 정의할수 있다.
//	정의를 하더라도 함수자체는 클래스 내에 있기에 클래스내에 private영역에 접근이 가능하다.
//	가치상실 때문에 클래스 내부에서 함수를 선언하고 외부에서 정의를 하는 것을 선호하는 편이다.
//	데이터를 공개를 하면 네임스페이스로 접근하여 객체를 생성하지 않고도 접근할 수 있다.
//

//	** 오버로딩 & 오버라이딩

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

class Object2
{
//	** 비공개 형태로 만들어 줌	/	나만사용	/ 데이터
private:
	int iNumber2;
	//static int iNumber;  비공개이기에 네임스페이스를 이용해도 접근이 제한된다.

//	** 상속간의 접근이 가능		/		구성원이 사용 가능(우리 집 화장실)
protected:

//	** 공개된 형태로 만들어 줌	/		누구나 사용가능(공중화장실)	/ 기능
public:
	static int iNumber;		// 클래스를 여러개 만들어도 이 변수는 1개이다
							// 그래서 네임스페이스로 접근가능

	int Num;					// 클래스를 여러개 만들면 여러개 생성된다.
public:
	//	안정성을 위해 나누었다
	void Setter(int _Number);
	int GetiNumber();


	// 클래스이름을 함수이름에 그대로 넣으면 생성자
	//	생성과 동시에 별도의 호출이 없어도 자동으로 호출됨
	//	우리눈에는 안보이지만 기본 생성자&소멸자가 존재한다

	//	** 생성자
	Object2()
	{

		cout << "생성자" << endl;
	}

	//	** 복사생성자 = 사용자가 직접호출했을 경우에만 호출이 된다.
	//	** 매개변수의 갯수나 형태에 따라서 선택적(자동)으로 호출됨
	Object2(string _str)
	{

		cout << _str << endl;
	}

	Object2(string _str, int _i)
	{

		cout << _str << " : " << _i << endl;
	}

	Object2(string _str, float _f)
	{

		cout << _str << " : " << _f << endl;
	}

	// 소멸자
	// 클래스이름을 함수이름에 그대로 넣고 앞에 물결표가 들어가면 소멸자
	~Object2()
	{
		cout << "소멸자" << endl;
	}

};

void Object2::Setter(int _Number)
{
	iNumber2 = _Number;
}

int Object2::GetiNumber()
{
	return iNumber2;
}


int main(void)
{
	Parents* p[2];

	p[0] = new Child("홍길동");
	p[1] = new Object("임꺽정");

	p[0]->Output();
	p[1]->Output();

	
	Object2 o = Object2("복사생성자", 10.2f);	//생성자 호출

	cout << "=========================" << endl;
	Object2 o1, o2;

	//	변경
	//	기능은 퍼블릭이기에 가능
	//	변경할 때는 변경만
	o1.Setter(10);
	o2.Setter(20);

	//	참조
	//	참조할 때는 참조만
	cout << o1.GetiNumber() << endl;
	cout << o2.GetiNumber() << endl;

	AAA::Number = 1;
	BBB::Number = 10;
	CCC::Number = 100;

	Output();
	Output();
	Output();
	Output();
	Output();
	Output();
	Output();
	Output();

	BBB::Output();
	CCC::Output();


	// ** 퍼블릭일 경우에만 사용이 가능하다
	o1.iNumber = 10;
	o2.iNumber = 20;
	//	출력
	cout << o1.iNumber << endl;

	cout << o2.iNumber << endl;


	return 0;	// 소멸자 호출
}
