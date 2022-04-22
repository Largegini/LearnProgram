// scanf함수의 보안관련 오류를 안 띄우기위해 사용
#define _CRT_SECURE_NO_WARNINGS		

// 헤더파일을 사용하기위해 선언
#include <stdio.h>					
#include <string>
#include <time.h>
#include <malloc.h>
#include <Windows.h>

// 변수를 상수로 선언하여 배열로 관리하기위해 사용
const int PLAYER = 0;				
const int ENEMY = 1;
const int MAX = 2;

const int Scene_Logo = 0;
const int Scene_Menu = 1;
const int Scene_Stage = 2;
const int Scene_Exit = 3;

// Scene전환을 위해 전역변수로 선언
int SceneState;		

// 루프를 위한 전역 변수
short Loop = 1;

//구조체안에는 사용자가 사용하고 싶은 것을 넣어서 용도별로 구축한다

// Status 구조체
typedef struct tagInfo				
{
	
	int HP;
	int MP;

	// 도망능력관련된 스탯이며 후에 플레이어와 몬스터의 선공 후공을 결정하기위한 스탯
	int Speed;		
	int EXP;

	short Level;

	float Att;
	float Def;

}INFO;

//  객체 구조체
typedef struct tagObject		
{
	char* Name;
	INFO Info;
}Object;

// 객체를 배열로 관리하기위한 전역변수
Object* Objects[MAX];

// 함수 전방 선언
void InitializeObject(Object* _obj, int ObjectType);	// 객체정보를 초기화하기위한 함수
char* SetName();

void SceneManager(int SceneState);
void LogoScene();
void MenuScene();
void StageScene();
void Status();
void PlayerAttack();
void EnemyAttack();

int main(void)
{
	/*
	* /***** 포인터는 주소만 받는다 데이터는 대입 불가
	int iNumber = 10;
	int* pNumber = (int*)malloc(sizeof(int));

	// 힙 영역에 값을 넣기위해 pNumber 앞에 * 를 넣는다
	*pNumber = iNumber; 
	//힙영역의 주소 = iNumber ;
	*/

	//Scene을 실행하기 위한 변수 초기화
	SceneState = 0;

	while (Loop)
	{
		// 변수 SceneState를 함수 SceneManger에 넣어 작동 한다
		SceneManager(SceneState);						
	}
	

	return 0;
}

//객체 정보 초기화 함수
void InitializeObject(Object* _obj, int ObjectType)
{

	switch (ObjectType)
	{
		//PLAYER의 객체 정보를 초기화한다
		case PLAYER:
			_obj->Name = SetName();		
			_obj->Info.HP = 100;
			_obj->Info.MP = 10;
			_obj->Info.Att = 10;
			_obj->Info.Def = 10;
			_obj->Info.Speed = 10;
			_obj->Info.Level = 1;
			_obj->Info.EXP = 0;
			break;

		//ENEMY의 객체정보를 초기화한다.
		case ENEMY :
			_obj->Name = (char*)"Enemy";	

			_obj->Info.HP = 30;
			_obj->Info.MP = 5;
			_obj->Info.Att =5;
			_obj->Info.Def = 15;
			_obj->Info.Speed = 5;
			_obj->Info.Level = 1;
			_obj->Info.EXP = 0;
			break;

	}
}

//플레이어 이름을 설정하는 함수
char* SetName()
{
	//문자열을 입력받기위한 임의의 배열 선언
	//포인터로는 문자열을 입력받을 수 없기 때문에 임의의 배열을 선언한다.
	char Buffer[128] = "";								

	printf_s("이름을 입력하십시오. : ");

	//문자열을 입력 받음.
	scanf("%s", Buffer);

	// ** 입력받은 값은 배열이나 반환 값은 캐릭터 포인터형(char*)이므로 문자열을 복사해야함.
	// ** 문자열을 복사 하기위해 포인터가 가르키는 공간에 입력받은 문자열이 들어갈 만큼의 크기로 메모리 할당
	char* pName = (char*)malloc(strlen(Buffer) + 1);	//문자열은 형변환을 해야함, NULL값을 넣어주기 위해 +1을 한다

	// Buffer가 받은 문자열을 포인터pName에 문자열 복사
	strcpy(pName, Buffer);								

	// 포인터 값 반환
	return pName;										
}

void SceneManager(int SceneState)						// Scene구성
{
	switch (SceneState)									//변수에 따라 Scene을 실행하기위한 switch문
	{
	case Scene_Logo:
		LogoScene();									// LogoScene 실행
		break;

	case Scene_Menu:
		MenuScene();									// MenuScene 실행
		break;

	case Scene_Stage:									
		StageScene();									// StageScene 실행
		break;

	case Scene_Exit:									//종료
		Loop = 0;
		break;
	}
}

void LogoScene()										//LogoScene
{
	printf_s("LogoScene \n");							

	//다음Scene으로 가기위한 변수 값 증가
	SceneState++;										
}

void MenuScene() 
{
	//입력을 받기위한 변수
	int iChoice = 0;									

	printf_s("MenuScene \n");
	printf_s("다음 Scene으로 가겠습니까? \n1.이동\n2.종료\n입력 :");
	scanf("%d",&iChoice);

	//iChoice값에 따라 씬을 넘어가거나 종료함
	switch (iChoice)									
	{
	case 1:												//1을 입력하면 다음 씬을 진행
		SceneState++;
		break;

	case 2 :											//2를 입력하면 종료
		SceneState = Scene_Exit;
		break;

	default:											//1과 2가아닌 입력을 받았을 경우 처리하기위함
		printf_s("잘못된 입력입니다! 다음씬으로 강제 이동합니다.\n");
		SceneState++;
		break;
	}

}

void StageScene()										
{
	srand(time(NULL));									//rand 함수를 사용하기위한 초기화

	// malloc 함수는 실행이 되면 주소값을 반환한다		** malloc함수의 반환 값을 변수에 대입하지 않으면 메모리 누수가 발생한다.
	//					힙영역에 공간을 만든다
	/*
	* 
	* int iNumber=10;
	* 
	// 힢 영역에 공간을 만들고 주소값을 포인터 pNumber에 대입
	//pNumber로 힢에 할당된 공간에 접근 가능
	* int*pNumber = (int*) malloc(sizeof(int)); 
	* 
	// 포인터 pNumber에 iNumber의 주소값을 대입
	// ** 더 이상 pNumber로 힢영역에 만든 공간에 접근 불가 하게됨 (메모리 누수)
	* pNumber = &iNumber;						
	* 
	*/



	Objects[PLAYER] = (Object*)malloc(sizeof(Object));	//PLAYER 동적할당
	InitializeObject(Objects[PLAYER], PLAYER);			//초기화
	Objects[ENEMY] = (Object*)malloc(sizeof(Object));	//ENEMY 동적할당
	InitializeObject(Objects[ENEMY], ENEMY);			//초기화
	
	
	
		// 전투 반복을 위한 함수
		short Battle = 1;								
		Status();

		//전투
		while (Battle)
		{
			//입력을 받기위한 임의 함수
			int iChoice = 0;

			printf_s("몬스터와 조우했다!!\n1.공격\n2. 도망\n입력 : ");
			scanf_s("%d", &iChoice);

			//입력받은 값에 따른 전투진행 
			switch (iChoice)
			{
				//공격을 선택했을 때
				case 1:

					PlayerAttack();
					// 공격시 나타나는 문구를 보이기 위한 딜레이 함수
					Sleep(500);
					
					//플레이어 공격 후 정보창 갱신
					Status();

					//플레이어 공격 후 몬스터의 공격
					EnemyAttack();

					//몬스터 공격 문구를 보이기 위한 딜레이 함수
					Sleep(500);

					// 몬스터 공격 후 정보창 갱신
					Status();

					break;

				//도망을 선택했을 때
				case 2:

					//플레이어의 Speed 가 적보다 높을 때 도망칠수 있게 함
					if (Objects[PLAYER]->Info.Speed > Objects[ENEMY]->Info.Speed)
					{
						//도망도 확률로 할 수있게 함
						//주사위 굴리는 시스템 채용
						if (rand() % 6 > 2)	
						{
							printf_s("%s(은)는 도망쳤다.\n", Objects[PLAYER]->Name);

							//전투 종료 루프해제
							Battle = 0;

							// 도망 시 적의 정보 초기화
							InitializeObject(Objects[ENEMY], ENEMY);

							//도망문구를 보이기위한 딜레이
							Sleep(500);
						}

						// 도망 실패 시
						else
						{
							printf_s("%s는 도망치치 못했다.\n", Objects[PLAYER]->Name);

							// 도망치지 못했을 때 문구를 보이기위한 딜레이
							Sleep(500);

							// 도망 실패 시 턴 소모로 몬스터의 공격을 받게하기위함
							EnemyAttack();
							Sleep(500);

							Status();
						}
					}

					else
					{
						printf_s("%s는 도망치치 못했다.\n", Objects[PLAYER]->Name);
						Sleep(500);

						EnemyAttack();

						Sleep(500);

						Status();
					}
					break;

				// 잘못된 입력시 턴 소모 하게 만들기 위함
				default:
					printf_s("잘못된 입력입니다! ");
					EnemyAttack();

					Sleep(500);

					Status();
					break;
			}
		}

	
}

void Status()
{
	system("cls");

	//플레이어의 정보를 출력
	printf_s("[Player] : %s\n", Objects[PLAYER]->Name);
	printf_s("HP : %d\n", Objects[PLAYER]->Info.HP);
	printf_s("MP : %d\n", Objects[PLAYER]->Info.MP);
	printf_s("공격력 : %.2f\n", Objects[PLAYER]->Info.Att);
	printf_s("방어력 : %.2f\n", Objects[PLAYER]->Info.Def);
	printf_s("레벨 : %d\n", Objects[PLAYER]->Info.Level);
	printf_s("경험치 : %d\n", Objects[PLAYER]->Info.EXP);

	//몬스터의 정보를 출력
	printf_s("\n%s\n", Objects[ENEMY]->Name);
	printf_s("HP : %d\n", Objects[ENEMY]->Info.HP);
	printf_s("MP : %d\n", Objects[ENEMY]->Info.MP);
	printf_s("공격력 : %.2f\n", Objects[ENEMY]->Info.Att);
	printf_s("방어력 : %.2f\n", Objects[ENEMY]->Info.Def);
	printf_s("레벨 : %d\n", Objects[ENEMY]->Info.Level);
	printf_s("경험치 : %d\n", Objects[ENEMY]->Info.EXP);

}

void PlayerAttack()
{
	printf_s("%s의 공격!!\n", Objects[PLAYER]->Name);
	//플레이어의 공격력과 몬스터의 방어력을 비교하여 데미지를 계산하는 조건문
	if (Objects[PLAYER]->Info.Att > Objects[ENEMY]->Info.Def)
		Objects[ENEMY]->Info.HP -= (int)(Objects[PLAYER]->Info.Att - Objects[ENEMY]->Info.Def);
	// 방어력이 더 높을 경우 최소 1의 데미지를 주려고함
	else
		Objects[ENEMY]->Info.HP -= 1;
}

void EnemyAttack()
{
	printf_s("몬스터의 공격!!\n");
	if (Objects[ENEMY]->Info.Att > Objects[PLAYER]->Info.Def)
		Objects[PLAYER]->Info.HP -= (int)(Objects[ENEMY]->Info.Att - Objects[PLAYER]->Info.Def);
	else
		Objects[PLAYER]->Info.HP -= 1;
}