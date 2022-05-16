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
char Loop = 1;

// Status 정보 구조체를 구축
typedef struct tagInfo				
{
	char* Name;
	int HP;
	int MP;

	// 도망능력관련된 스탯이며 후에 플레이어와 몬스터의 선공 후공을 결정하기위한 스탯
	int Speed;		
	int EXP;

	short Level;

	float Att;
	float Def;

}INFO;

//  객체 Status를 관리하기위한 구조체
typedef struct tagObject		
{
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
	
	SceneState = 0;
	while (Loop)
	{
		SceneManager(SceneState);						// 변수 SceneState를 함수 SceneManger에 넣어 작동 한다
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
			_obj->Info.Name = SetName();		
			_obj->Info.HP = 100;
			_obj->Info.MP = 10;
			_obj->Info.Att = 10;
			_obj->Info.Def = 10;
			_obj->Info.Speed = 10;
			_obj->Info.Level = 1;
			_obj->Info.EXP = 0;
			break;

		case ENEMY :
			_obj->Info.Name = (char*)"Enemy";	//ENEMY의 객체정보를 초기화한다.

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
	char Buffer[128] = "";								//문자열을 입력받기위한 임의의 공간 선언

	printf_s("이름을 입력하십시오. : ");
	scanf("%s", Buffer);

	char* pName = (char*)malloc(strlen(Buffer) + 1);	// 포인터의 동적할당
	strcpy(pName, Buffer);								// 포인터에 문자열 복사

	return pName;										// 포인터 값 반환
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
//	exit(NULL);// ** 프로그램 종료

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

	Objects[PLAYER] = (Object*)malloc(sizeof(Object));	//PLAYER 동적할당
	InitializeObject(Objects[PLAYER], PLAYER);			//초기화
	Objects[ENEMY] = (Object*)malloc(sizeof(Object));	//ENEMY 동적할당
	InitializeObject(Objects[ENEMY], ENEMY);			//초기화
	
	//무한반복하기위함
	while (true)										
	{
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
							printf_s("%s(은)는 도망쳤다.\n", Objects[PLAYER]->Info.Name);

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
							printf_s("%s는 도망치치 못했다.\n", Objects[PLAYER]->Info.Name);

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
						printf_s("%s는 도망치치 못했다.\n", Objects[PLAYER]->Info.Name);
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
}

void Status()
{
	system("cls");

	//플레이어의 정보를 출력
	printf_s("[Player] : %s\n", Objects[PLAYER]->Info.Name);
	printf_s("HP : %d\n", Objects[PLAYER]->Info.HP);
	printf_s("MP : %d\n", Objects[PLAYER]->Info.MP);
	printf_s("공격력 : %.2f\n", Objects[PLAYER]->Info.Att);
	printf_s("방어력 : %.2f\n", Objects[PLAYER]->Info.Def);
	printf_s("레벨 : %d\n", Objects[PLAYER]->Info.Level);
	printf_s("경험치 : %d\n", Objects[PLAYER]->Info.EXP);

	//몬스터의 정보를 출력
	printf_s("\n%s\n", Objects[ENEMY]->Info.Name);
	printf_s("HP : %d\n", Objects[ENEMY]->Info.HP);
	printf_s("MP : %d\n", Objects[ENEMY]->Info.MP);
	printf_s("공격력 : %.2f\n", Objects[ENEMY]->Info.Att);
	printf_s("방어력 : %.2f\n", Objects[ENEMY]->Info.Def);
	printf_s("레벨 : %d\n", Objects[ENEMY]->Info.Level);
	printf_s("경험치 : %d\n", Objects[ENEMY]->Info.EXP);

}

void PlayerAttack()
{
	printf_s("%s의 공격!!\n", Objects[PLAYER]->Info.Name);
	//플레이어의 공격력과 몬스터의 방어력을 비교하여 데미지를 계산하는 조건문
	if (Objects[PLAYER]->Info.Att > Objects[ENEMY]->Info.Def)
		Objects[ENEMY]->Info.HP -= (Objects[PLAYER]->Info.Att - Objects[ENEMY]->Info.Def);
	// 방어력이 더 높을 경우 최소 1의 데미지를 주려고함
	else
		Objects[ENEMY]->Info.HP -= 1;
}

void EnemyAttack()
{
	printf_s("몬스터의 공격!!\n");
	if (Objects[ENEMY]->Info.Att > Objects[PLAYER]->Info.Def)
		Objects[PLAYER]->Info.HP -= (Objects[ENEMY]->Info.Att - Objects[PLAYER]->Info.Def);
	else
		Objects[PLAYER]->Info.HP -= 1;
}