#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string>
#include <time.h>
#include <malloc.h>
#include <Windows.h>

const int PLAYER = 0;
const int ENEMY = 1;
const int MAX = 2;

const int Scene_Logo = 0;
const int Scene_Menu = 1;
const int Scene_Stage = 2;
const int Scene_Exit = 3;

int SceneState;


typedef struct tagInfo
{
	char* Name;
	int HP;
	int MP;
	int Speed;
	int EXP;

	short Level;

	float Att;
	float Def;
	float Dodge;
}INFO;

typedef struct tagObject
{
	INFO Info;
	// Player ��������
}Object;

Object* Objects[MAX];

void InitializeObject(Object* _obj, int ObjectType);
char* SetName();
void Status();
void SceneManager(int SceneState);
void LogoScene();
void MenuScene();
void StageScene();

int main(void)
{
	SceneState = 0;
	while (true)
	{
		SceneManager(SceneState);
	}
	

	return 0;
}

void InitializeObject(Object* _obj, int ObjectType)
{
	
	

	switch (ObjectType)
	{
		case PLAYER:
			_obj->Info.Name = SetName();
			_obj->Info.HP = 100;
			_obj->Info.MP = 10;
			_obj->Info.Att = 10;
			_obj->Info.Def = 10;
			_obj->Info.Dodge = 5;
			_obj->Info.Speed = 10;
			_obj->Info.Level = 1;
			_obj->Info.EXP = 0;
			break;
		case ENEMY :
			_obj->Info.Name = (char*)"Enemy";

			_obj->Info.HP = 30;
			_obj->Info.MP = 5;
			_obj->Info.Att =5;
			_obj->Info.Def =15;
			_obj->Info.Dodge = 1;
			_obj->Info.Speed = 5;
			_obj->Info.Level = 1;
			_obj->Info.EXP = 0;
			break;

	}
}

char* SetName()
{
	char Buffer[128] = "";

	printf_s("�̸��� �Է��Ͻʽÿ�. : ");
	scanf("%s", Buffer);

	char* pName = (char*)malloc(strlen(Buffer) + 1);
	strcpy(pName, Buffer);

	return pName;
}

void SceneManager(int SceneState)
{
	switch (SceneState)
	{
	case Scene_Logo:
		LogoScene();
		break;
	case Scene_Menu:
		MenuScene();
		break;
	case Scene_Stage:
		StageScene();
		break;
	case Scene_Exit:
		break;
	}
}

void LogoScene()
{
	printf_s("LogoScene \n");
	SceneState++;
}

void MenuScene() 
{
	int iChoice = 0;
	printf_s("MenuScene \n");
	//printf_s("1.�̵�\n2.\n����");
	//scanf("%",&iChoice);
	switch (iChoice)
	{
	case 1:
		break;

	case 2 :
		break;

	default:
		break;
	}

	SceneState++;
}

void StageScene()
{
	srand(time(NULL));



	Objects[PLAYER] = (Object*)malloc(sizeof(Object));
	InitializeObject(Objects[PLAYER], PLAYER);
	Objects[ENEMY] = (Object*)malloc(sizeof(Object));
	InitializeObject(Objects[ENEMY], ENEMY);




	while (true)
	{
		short Battle = 1;

		system("cls");
		printf_s("[Player] : %s\n", Objects[PLAYER]->Info.Name);
		printf_s("HP : %d\n", Objects[PLAYER]->Info.HP);
		printf_s("MP : %d\n", Objects[PLAYER]->Info.MP);
		printf_s("���ݷ� : %.2f\n", Objects[PLAYER]->Info.Att);
		printf_s("���� : %.2f\n", Objects[PLAYER]->Info.Def);
		printf_s("ȸ�� : %.2f\n", Objects[PLAYER]->Info.Dodge);
		printf_s("���� : %d\n", Objects[PLAYER]->Info.Level);
		printf_s("����ġ : %d\n", Objects[PLAYER]->Info.EXP);

		printf_s("\n%s\n", Objects[ENEMY]->Info.Name);
		printf_s("HP : %d\n", Objects[ENEMY]->Info.HP);
		printf_s("MP : %d\n", Objects[ENEMY]->Info.MP);
		printf_s("���ݷ� : %.2f\n", Objects[ENEMY]->Info.Att);
		printf_s("���� : %.2f\n", Objects[ENEMY]->Info.Def);
		printf_s("ȸ�� : %.2f\n", Objects[ENEMY]->Info.Dodge);
		printf_s("���� : %d\n", Objects[ENEMY]->Info.Level);
		printf_s("����ġ : %d\n", Objects[ENEMY]->Info.EXP);


		while (Battle)
		{
			int iChoice = 0;
			printf_s("���Ϳ� �����ߴ�!!\n1.����\n2. ����\n�Է� : ");
			scanf_s("%d", &iChoice);

			switch (iChoice)
			{
			case 1:
				printf_s("%s�� ����!!\n", Objects[PLAYER]->Info.Name);
				if (Objects[PLAYER]->Info.Att > Objects[ENEMY]->Info.Def)
					Objects[ENEMY]->Info.HP -= (Objects[PLAYER]->Info.Att - Objects[ENEMY]->Info.Def);
				else
					Objects[ENEMY]->Info.HP -= 1;
				// ������ �Լ�
				Sleep(500);

				system("cls");
				printf_s("[Player] : %s\n", Objects[PLAYER]->Info.Name);
				printf_s("HP : %d\n", Objects[PLAYER]->Info.HP);
				printf_s("MP : %d\n", Objects[PLAYER]->Info.MP);
				printf_s("���ݷ� : %.2f\n", Objects[PLAYER]->Info.Att);
				printf_s("���� : %.2f\n", Objects[PLAYER]->Info.Def);
				printf_s("ȸ�� : %.2f\n", Objects[PLAYER]->Info.Dodge);
				printf_s("���� : %d\n", Objects[PLAYER]->Info.Level);
				printf_s("����ġ : %d\n\n", Objects[PLAYER]->Info.EXP);

				printf_s("\n%s\n", Objects[ENEMY]->Info.Name);
				printf_s("HP : %d\n", Objects[ENEMY]->Info.HP);
				printf_s("MP : %d\n", Objects[ENEMY]->Info.MP);
				printf_s("���ݷ� : %.2f\n", Objects[ENEMY]->Info.Att);
				printf_s("���� : %.2f\n", Objects[ENEMY]->Info.Def);
				printf_s("ȸ�� : %.2f\n", Objects[ENEMY]->Info.Dodge);
				printf_s("���� : %d\n", Objects[ENEMY]->Info.Level);
				printf_s("����ġ : %d\n\n", Objects[ENEMY]->Info.EXP);

				printf_s("������ ����!!\n");
				if (Objects[ENEMY]->Info.Att > Objects[PLAYER]->Info.Def)
					Objects[PLAYER]->Info.HP -= (Objects[ENEMY]->Info.Att - Objects[PLAYER]->Info.Def);
				else
					Objects[PLAYER]->Info.HP -= 1;
				Sleep(500);

				system("cls");
				printf_s("[Player] : %s\n", Objects[PLAYER]->Info.Name);
				printf_s("HP : %d\n", Objects[PLAYER]->Info.HP);
				printf_s("MP : %d\n", Objects[PLAYER]->Info.MP);
				printf_s("���ݷ� : %.2f\n", Objects[PLAYER]->Info.Att);
				printf_s("���� : %.2f\n", Objects[PLAYER]->Info.Def);
				printf_s("ȸ�� : %.2f\n", Objects[PLAYER]->Info.Dodge);
				printf_s("���� : %d\n", Objects[PLAYER]->Info.Level);
				printf_s("����ġ : %d\n\n", Objects[PLAYER]->Info.EXP);

				printf_s("\n%s\n", Objects[ENEMY]->Info.Name);
				printf_s("HP : %d\n", Objects[ENEMY]->Info.HP);
				printf_s("MP : %d\n", Objects[ENEMY]->Info.MP);
				printf_s("���ݷ� : %.2f\n", Objects[ENEMY]->Info.Att);
				printf_s("���� : %.2f\n", Objects[ENEMY]->Info.Def);
				printf_s("ȸ�� : %.2f\n", Objects[ENEMY]->Info.Dodge);
				printf_s("���� : %d\n", Objects[ENEMY]->Info.Level);
				printf_s("����ġ : %d\n\n", Objects[ENEMY]->Info.EXP);

				break;

			case 2:
				if (Objects[PLAYER]->Info.Speed > Objects[ENEMY]->Info.Speed)
				{
					if (rand() % 6 > 2)
					{
						printf_s("%s(��)�� �����ƴ�.\n", Objects[PLAYER]->Info.Name);
						Battle = 0;
						InitializeObject(Objects[ENEMY], ENEMY);
						Sleep(500);
					}
					else
					{
						printf_s("%s�� ����ġġ ���ߴ�.\n", Objects[PLAYER]->Info.Name);
						Sleep(500);

						printf_s("������ ����!!\n");
						if (Objects[ENEMY]->Info.Att > Objects[PLAYER]->Info.Def)
							Objects[PLAYER]->Info.HP -= (Objects[ENEMY]->Info.Att - Objects[PLAYER]->Info.Def);
						else
							Objects[PLAYER]->Info.HP -= 1;
						Sleep(500);

						system("cls");
						printf_s("[Player] : %s\n", Objects[PLAYER]->Info.Name);
						printf_s("HP : %d\n", Objects[PLAYER]->Info.HP);
						printf_s("MP : %d\n", Objects[PLAYER]->Info.MP);
						printf_s("���ݷ� : %.2f\n", Objects[PLAYER]->Info.Att);
						printf_s("���� : %.2f\n", Objects[PLAYER]->Info.Def);
						printf_s("ȸ�� : %.2f\n", Objects[PLAYER]->Info.Dodge);
						printf_s("���� : %d\n", Objects[PLAYER]->Info.Level);
						printf_s("����ġ : %d\n\n", Objects[PLAYER]->Info.EXP);

						printf_s("\n%s\n", Objects[ENEMY]->Info.Name);
						printf_s("HP : %d\n", Objects[ENEMY]->Info.HP);
						printf_s("MP : %d\n", Objects[ENEMY]->Info.MP);
						printf_s("���ݷ� : %.2f\n", Objects[ENEMY]->Info.Att);
						printf_s("���� : %.2f\n", Objects[ENEMY]->Info.Def);
						printf_s("ȸ�� : %.2f\n", Objects[ENEMY]->Info.Dodge);
						printf_s("���� : %d\n", Objects[ENEMY]->Info.Level);
						printf_s("����ġ : %d\n\n", Objects[ENEMY]->Info.EXP);
					}
				}

				else
				{
					printf_s("%s�� ����ġġ ���ߴ�.\n", Objects[PLAYER]->Info.Name);
					Sleep(500);

					printf_s("������ ����!!\n");
					if (Objects[ENEMY]->Info.Att > Objects[PLAYER]->Info.Def)
						Objects[PLAYER]->Info.HP -= (Objects[ENEMY]->Info.Att - Objects[PLAYER]->Info.Def);
					else
						Objects[PLAYER]->Info.HP -= 1;
					Sleep(500);
				}
				break;

			default:
				printf_s("�߸��� �Է��Դϴ�! �ٽ� �Է��Ͻʽÿ�\n");
				break;
			}
		}

	}
}