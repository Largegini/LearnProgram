#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

typedef struct tagInfo
{
	int iNumber;

	//기본으로 실행되는 생성자
	tagInfo() 
	{
		cout << "기본생성자" << endl;
	}
	
	//복사한 생성자
	tagInfo(int _iNumber) 
	{
		iNumber = _iNumber;
		cout << "복사생성자" << endl;
	}

}INFO;

int main(void)
{
	//	**	출력
	//	printf_s == cout
	
	//	**	줄바꿈
	//	\n == endl(엔드 라인: 줄의 끝)
	
	//	*	cout c콘솔창으로 out내보내라 무엇을? 뒤에 오는 문자열을 "HelloWorld"
	//	**	'<<' Shift 연산자
	cout << "HelloWorld!!" << endl << "줄바꿈" << endl;

	//	**	입력
	int iTest = 0;

	//	scanf == cin
	//	cout <<(보낸다)	"ㅇ"(문자열을) :	뒤에 문자열을 cout으로 보낸다 그렇기에 방향이 cout << ""
	cout << "입력 : ";

	//	cin >>(보낸다) iTest에 : cin에서 받아와서 뒤에 iTest에 보낸다 그래서 방향이 cin >> iTest
	cin >> iTest;

	cout << iTest << endl;

	// ** void포인터
	//	malloc함수의 반환 값은 void포인터이기 때문에 앞에 형변환이 필요하다
	//	void는 아무 것도 없는 상태이나 포인터를 붙이면 4byte가 할당된다
	//	즉 형태는 없고 크기만 할당되어있다
	//	그러므로 어떠한 형태로도 선언이 가능하다

	//	**	동적할당
	//	INFO* pInfo = (INFO*)malloc(sizeof(INFO));
	//	(INFO*)malloc(sizeof(INFO)) == new INFO;
	//	완전히 같은 것은 아님
	//	초기화만 했을 뿐이지만 알아서 생성자를 컴파일러가 호출함
	//	new INFO; 의 INFO는 형태이면서 생성자이다?
	INFO* pInfo = new INFO(10);

	cout << pInfo->iNumber << endl;
	//	**	할당해제
	//free(pInfo); == delete pInfo;
	delete pInfo;

	return 0;
}