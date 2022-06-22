#include <iostream>

using namespace std;

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
//		- 각자의 고유기능이 존해하며 공유할 수 없다
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

//	** Getter & Setter

//	** namespace
//	** 생성자 & 소멸자 & 복사생성자
//	** 가상함수 & 순수가상함수
//	** 오버로딩 & 오버라이딩
//	** 연산자 오버로딩

struct Info
{
	int iNumber;
};

class Object
{
//	** 비공개 형태로 만들어 줌	/	나만사용	/ 데이터
private:
	int iNumber;

//	** 상속간의 접근이 가능		/		구성원이 사용 가능(우리 집 화장실)
protected:

//	** 공개된 형태로 만들어 줌	/		누구나 사용가능(공중화장실)	/ 기능
public:

public:
	//	안정성을 위해 나누었다
	void Setter(int _Number)
	{
		iNumber = _Number;
	}

	int Getter()
	{ 
		return iNumber; 
	}
};


int main(void)
{
	Object o1, o2;

	//	변경
	//	기능은 퍼블릭이기에 가능
	//	변경할 때는 변경만
	o1.Setter(10);
	o2.Setter(20);

	//	참조
	//	참조할 때는 참조만
	cout << o1.Getter() << endl;
	cout << o2.Getter() << endl;


	/*	** 퍼블릭일 경우에만 사용이 가능하다
	o1.iNumber = 10;
	o2.iNumber = 20;
	//	출력
	cout << o1.iNumber << endl;

	cout << o2.iNumber << endl;
	*/
	return 0;
}