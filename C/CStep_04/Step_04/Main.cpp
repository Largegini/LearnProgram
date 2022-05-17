#include <stdio.h>

// true와 false는 0이 아닌 값과 0으로 구분된다.
// f9					중단점 찍기
// crtl + shift + f9	모든 중단점 삭제

int main(void)
{
	/*
	int i = 3;
	printf_s("%d\n",i);
	printf_s("%d\n",i == 3);

	i = !i;
	printf_s("%d\n", i);

	if (33)
		printf_s("%d\n", 33);
	int i = 0;

	printf_s("1.기 사 \n2.마법사\n3.궁 수\n");
	printf_s("입력 : ");
	scanf_s("%d", &i);

	if (i == 1) printf_s("기사를 선택하셨습니다! \n");

	else if (i == 2) printf_s("마법사를 선택하셨습니다!");

	else if (i == 3) printf_s("궁수를 선택하셨습니다! \n");

	else printf_s("잘못 선택하셨습니다!!\n");
	*/

	float fHeight = 0;
	int nWeight = 0;

	printf_s("키를 입력하십시오.(cm)\n");
	scanf_s("%f", &fHeight);
	fHeight /= 100.0f;								//키를 M로 단위변환

	printf_s("몸무게를 입력하십시오.(kg) \n");
	scanf_s("%d", &nWeight);

	float fBMI = nWeight / (fHeight * fHeight);		//BMI공식
	printf_s("당신의 BMI는 %.1f이며, ", fBMI);		// %.nf n에들어가는 숫자자릿수만큼 표기

	if (fBMI >= 30)						
		printf_s("고도비만입니다.");

	else if (fBMI < 30 && fBMI >= 25)	
		printf_s("비만입니다.");

	else if (fBMI < 25 && fBMI >= 23)	
		printf_s("과체중입니다.");
						   
	else if (fBMI < 23 && fBMI >= 18.5) 
		printf_s("표준몸무게입니다.");

	else if (fBMI < 18.5 )				
		printf_s("표준미달입니다.");

	else								
		printf_s("잘못된 입력입니다!");

	return  0;
}