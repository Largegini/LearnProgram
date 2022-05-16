// scanf�Լ��� ���Ȱ��� ������ �� �������� ���
#define _CRT_SECURE_NO_WARNINGS		

// ��������� ����ϱ����� ����
#include <stdio.h>					
#include <string>
#include <time.h>
#include <malloc.h>
#include <Windows.h>

// ������ ����� �����Ͽ� �迭�� �����ϱ����� ���
const int PLAYER = 0;				
const int ENEMY = 1;
const int MAX = 2;

const int Scene_Logo = 0;
const int Scene_Menu = 1;
const int Scene_Stage = 2;
const int Scene_Exit = 3;

// Scene��ȯ�� ���� ���������� ����
int SceneState;		

// ������ ���� ���� ����
char Loop = 1;

// Status ���� ����ü�� ����
typedef struct tagInfo				
{
	char* Name;
	int HP;
	int MP;

	// �����ɷ°��õ� �����̸� �Ŀ� �÷��̾�� ������ ���� �İ��� �����ϱ����� ����
	int Speed;		
	int EXP;

	short Level;

	float Att;
	float Def;

}INFO;

//  ��ü Status�� �����ϱ����� ����ü
typedef struct tagObject		
{
	INFO Info;
}Object;

// ��ü�� �迭�� �����ϱ����� ��������
Object* Objects[MAX];

// �Լ� ���� ����
void InitializeObject(Object* _obj, int ObjectType);	// ��ü������ �ʱ�ȭ�ϱ����� �Լ�
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
		SceneManager(SceneState);						// ���� SceneState�� �Լ� SceneManger�� �־� �۵� �Ѵ�
	}
	

	return 0;
}

//��ü ���� �ʱ�ȭ �Լ�
void InitializeObject(Object* _obj, int ObjectType)
{

	switch (ObjectType)
	{
		//PLAYER�� ��ü ������ �ʱ�ȭ�Ѵ�
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
			_obj->Info.Name = (char*)"Enemy";	//ENEMY�� ��ü������ �ʱ�ȭ�Ѵ�.

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

//�÷��̾� �̸��� �����ϴ� �Լ�
char* SetName()
{
	char Buffer[128] = "";								//���ڿ��� �Է¹ޱ����� ������ ���� ����

	printf_s("�̸��� �Է��Ͻʽÿ�. : ");
	scanf("%s", Buffer);

	char* pName = (char*)malloc(strlen(Buffer) + 1);	// �������� �����Ҵ�
	strcpy(pName, Buffer);								// �����Ϳ� ���ڿ� ����

	return pName;										// ������ �� ��ȯ
}

void SceneManager(int SceneState)						// Scene����
{
	switch (SceneState)									//������ ���� Scene�� �����ϱ����� switch��
	{
	case Scene_Logo:
		LogoScene();									// LogoScene ����
		break;
	case Scene_Menu:
		MenuScene();									// MenuScene ����
		break;
	case Scene_Stage:									
		StageScene();									// StageScene ����
		break;
	case Scene_Exit:									//����
		Loop = 0;
//	exit(NULL);// ** ���α׷� ����

		break;
	}
}

void LogoScene()										//LogoScene
{
	printf_s("LogoScene \n");							

	//����Scene���� �������� ���� �� ����
	SceneState++;										
}

void MenuScene() 
{
	//�Է��� �ޱ����� ����
	int iChoice = 0;									

	printf_s("MenuScene \n");
	printf_s("���� Scene���� ���ڽ��ϱ�? \n1.�̵�\n2.����\n�Է� :");
	scanf("%d",&iChoice);

	//iChoice���� ���� ���� �Ѿ�ų� ������
	switch (iChoice)									
	{
	case 1:												//1�� �Է��ϸ� ���� ���� ����
		SceneState++;
		break;

	case 2 :											//2�� �Է��ϸ� ����
		SceneState = Scene_Exit;
		break;

	default:											//1�� 2���ƴ� �Է��� �޾��� ��� ó���ϱ�����
		printf_s("�߸��� �Է��Դϴ�! ���������� ���� �̵��մϴ�.\n");
		SceneState++;
		break;
	}

}

void StageScene()										
{
	srand(time(NULL));									//rand �Լ��� ����ϱ����� �ʱ�ȭ

	Objects[PLAYER] = (Object*)malloc(sizeof(Object));	//PLAYER �����Ҵ�
	InitializeObject(Objects[PLAYER], PLAYER);			//�ʱ�ȭ
	Objects[ENEMY] = (Object*)malloc(sizeof(Object));	//ENEMY �����Ҵ�
	InitializeObject(Objects[ENEMY], ENEMY);			//�ʱ�ȭ
	
	//���ѹݺ��ϱ�����
	while (true)										
	{
		// ���� �ݺ��� ���� �Լ�
		short Battle = 1;								
		Status();

		//����
		while (Battle)
		{
			//�Է��� �ޱ����� ���� �Լ�
			int iChoice = 0;

			printf_s("���Ϳ� �����ߴ�!!\n1.����\n2. ����\n�Է� : ");
			scanf_s("%d", &iChoice);

			//�Է¹��� ���� ���� �������� 
			switch (iChoice)
			{
				//������ �������� ��
				case 1:

					PlayerAttack();
					// ���ݽ� ��Ÿ���� ������ ���̱� ���� ������ �Լ�
					Sleep(500);
					
					//�÷��̾� ���� �� ����â ����
					Status();

					//�÷��̾� ���� �� ������ ����
					EnemyAttack();

					//���� ���� ������ ���̱� ���� ������ �Լ�
					Sleep(500);

					// ���� ���� �� ����â ����
					Status();

					break;

				//������ �������� ��
				case 2:

					//�÷��̾��� Speed �� ������ ���� �� ����ĥ�� �ְ� ��
					if (Objects[PLAYER]->Info.Speed > Objects[ENEMY]->Info.Speed)
					{
						//������ Ȯ���� �� ���ְ� ��
						//�ֻ��� ������ �ý��� ä��
						if (rand() % 6 > 2)	
						{
							printf_s("%s(��)�� �����ƴ�.\n", Objects[PLAYER]->Info.Name);

							//���� ���� ��������
							Battle = 0;

							// ���� �� ���� ���� �ʱ�ȭ
							InitializeObject(Objects[ENEMY], ENEMY);

							//���������� ���̱����� ������
							Sleep(500);
						}

						// ���� ���� ��
						else
						{
							printf_s("%s�� ����ġġ ���ߴ�.\n", Objects[PLAYER]->Info.Name);

							// ����ġ�� ������ �� ������ ���̱����� ������
							Sleep(500);

							// ���� ���� �� �� �Ҹ�� ������ ������ �ް��ϱ�����
							EnemyAttack();
							Sleep(500);

							Status();
						}
					}

					else
					{
						printf_s("%s�� ����ġġ ���ߴ�.\n", Objects[PLAYER]->Info.Name);
						Sleep(500);

						EnemyAttack();

						Sleep(500);

						Status();
					}
					break;

				// �߸��� �Է½� �� �Ҹ� �ϰ� ����� ����
				default:
					printf_s("�߸��� �Է��Դϴ�! ");
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

	//�÷��̾��� ������ ���
	printf_s("[Player] : %s\n", Objects[PLAYER]->Info.Name);
	printf_s("HP : %d\n", Objects[PLAYER]->Info.HP);
	printf_s("MP : %d\n", Objects[PLAYER]->Info.MP);
	printf_s("���ݷ� : %.2f\n", Objects[PLAYER]->Info.Att);
	printf_s("���� : %.2f\n", Objects[PLAYER]->Info.Def);
	printf_s("���� : %d\n", Objects[PLAYER]->Info.Level);
	printf_s("����ġ : %d\n", Objects[PLAYER]->Info.EXP);

	//������ ������ ���
	printf_s("\n%s\n", Objects[ENEMY]->Info.Name);
	printf_s("HP : %d\n", Objects[ENEMY]->Info.HP);
	printf_s("MP : %d\n", Objects[ENEMY]->Info.MP);
	printf_s("���ݷ� : %.2f\n", Objects[ENEMY]->Info.Att);
	printf_s("���� : %.2f\n", Objects[ENEMY]->Info.Def);
	printf_s("���� : %d\n", Objects[ENEMY]->Info.Level);
	printf_s("����ġ : %d\n", Objects[ENEMY]->Info.EXP);

}

void PlayerAttack()
{
	printf_s("%s�� ����!!\n", Objects[PLAYER]->Info.Name);
	//�÷��̾��� ���ݷ°� ������ ������ ���Ͽ� �������� ����ϴ� ���ǹ�
	if (Objects[PLAYER]->Info.Att > Objects[ENEMY]->Info.Def)
		Objects[ENEMY]->Info.HP -= (Objects[PLAYER]->Info.Att - Objects[ENEMY]->Info.Def);
	// ������ �� ���� ��� �ּ� 1�� �������� �ַ�����
	else
		Objects[ENEMY]->Info.HP -= 1;
}

void EnemyAttack()
{
	printf_s("������ ����!!\n");
	if (Objects[ENEMY]->Info.Att > Objects[PLAYER]->Info.Def)
		Objects[PLAYER]->Info.HP -= (Objects[ENEMY]->Info.Att - Objects[PLAYER]->Info.Def);
	else
		Objects[PLAYER]->Info.HP -= 1;
}