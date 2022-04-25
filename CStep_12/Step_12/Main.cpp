// scanf�Լ��� ���Ȱ��� ������ �� �������� ���
#define _CRT_SECURE_NO_WARNINGS		

// ��������� ����ϱ����� ����
#include <stdio.h>					
#include <string>
#include <time.h>
#include <malloc.h>
#include <Windows.h>

const int Scene_Logo = 0;
const int Scene_Menu = 1;
const int Scene_Stage = 2;
const int Scene_Exit = 3;

int Check = 1;

// Scene��ȯ�� ���� ���������� ����
int SceneState = 0;

//����ü�ȿ��� ����ڰ� ����ϰ� ���� ���� �־ �뵵���� �����Ѵ�
// Status ����ü
typedef struct tagInfo				
{
	
	int HP;
	int MP;

	// �����ɷ°��õ� �����̸� �Ŀ� �÷��̾�� ������ ���� �İ��� �����ϱ����� ����
	int Speed;		
	int EXP;

	short Level;

	float Att;
	float Def;

}INFO;

//  ��ü ����ü
typedef struct tagObject		
{
	char* Name;
	INFO Info;
}Object;

// �Լ� ���� ����
char* SetName();

void SceneManager(Object* Player, Object* Enemy);
void LogoScene();
void MenuScene();
void StageScene(Object* Player, Object* Enemy);

void PlayerScene(Object* Playe);
void InitializeObjectPlayer(Object* Player);

void EnemyScene(Object* Enemy);
void InitializeObjectEnemy(Object* Enemy);

void PlayerStatus(Object* Player);
void EnemyStatus(Object* Enemy);
void PlayerAttack(Object* Player, Object* Enemy);
void EnemyAttack(Object* Player, Object* Enemy);


int main(void)
{
	Object* Player = (Object*)malloc(sizeof(Object));		//PLAYER �����Ҵ�
	InitializeObjectPlayer(Player);							//�ʱ�ȭ
	Object* Enemy = (Object*)malloc(sizeof(Object));		//ENEMY �����Ҵ�
	InitializeObjectEnemy(Enemy);							//�ʱ�ȭ

	// GetTickCount 1/1000���� ���� ����
	DWORD dwTime = GetTickCount(); // typedef unsigned long DWORD
	int Delay = 1000;

	int UpCount = 0;

	while (true)
	{
		//Scene�� �����ϱ� ���� ���� �ʱ�ȭ
		
		// ** 1�ʸ��� ����Ǵ� ����
		// ó������ 0+1000 < GetTickCount()
		if (dwTime + Delay < GetTickCount())	
		{
			//GetTickCount�� 1000���� Ŀ������ ����
			dwTime = GetTickCount(); //dwTime = 1001

			system("cls");

			printf_s("%s\n", Player->Name);

			//** ���� ����
			// ���� SceneState�� �Լ� SceneManger�� �־� �۵� �Ѵ�
			SceneManager(Player, Enemy);
		}
	}
	/*
	* /***** �����ʹ� �ּҸ� �޴´� �����ʹ� ���� �Ұ�
	int iNumber = 10;
	int* pNumber = (int*)malloc(sizeof(int));

	// �� ������ ���� �ֱ����� pNumber �տ� * �� �ִ´�
	*pNumber = iNumber; 
	//�������� �ּ� = iNumber ;

	// �� ���� ���
	void ABC(int _i,int _n)
	{
		_i =100;										//i_Number1���� �����ؿ� �� 10�� 100���� ����
		_n = 200;										//i_Number2���� �����ؿ� �� 20�� 200���� ����

		printf_s("ABC _i : %d",_i);
		printf_s("ABC _n : %d",_n);
	}

	// �� ���� ���۷���
	void DEF (int* _i,int* _n)
	{
		_i = 100;										//i_Number1�� �ּҷ� ������ �� 10�� 100���� ����
		_n = 100;										//i_Number2�� �ּҷ� ������ �� 10�� 200���� ����
		printf_s("ABC *_i : %d", *_i);
		printf_s("ABC *_n : %d", *_n);
	}

	void main()
	{
		int iNumber1 = 10;
		int iNumber2 = 20;

		printf_f("iNumber1: %d\n", &iNumber1);			//iNumber1�� �ּҰ� ���
		printf_f("iNumber2: %d\n\n", &iNumber2);		//iNumber2�� �ּҰ� ���

		// �� ���� ���
		ABC(iNumber1, iNumber2);						// iNumber1,iNumber2�� ���� �Լ� ABC�� �Ű����� _i,_n�� ����
		printf_f("ABC iNumber1: %d\n",iNumber1);		// iNumber1�� ���� �Ǿ��ִ� ���� ������ �ʾ����Ƿ� 10���
		printf_f("ABC iNumber2: %d\n\n",iNumber2);		// iNumber2�� ���� �Ǿ��ִ� ���� ������ �ʾ����Ƿ� 20���

		// �� ���� ���۷���
		DEF(&iNumber1, &iNumber2);						// iNumber1, iNumber2�� �ּҸ� �Լ� DEF�� �Ű����� *_i, *_n�� ����
		printf_f("DEF iNumber1: %d\n",iNumber1);		// iNumber1�� ���� �Ǿ��ִ� ���� �������Ƿ� 100���
		printf_f("DEF iNumber2: %d\n\n",iNumber2);		// iNumber2�� ���� �Ǿ��ִ� ���� �������Ƿ� 200���
	}



	

	while (Loop)
	{
		
							
	}
	*/
	

	return 0;
}

//��ü ���� �ʱ�ȭ �Լ�



//�÷��̾� �̸��� �����ϴ� �Լ�
char* SetName()
{
	//���ڿ��� �Է¹ޱ����� ������ �迭 ����
	//�����ͷδ� ���ڿ��� �Է¹��� �� ���� ������ ������ �迭�� �����Ѵ�.
	char Buffer[128] = "";								

	printf_s("�̸��� �Է��Ͻʽÿ�. : ");

	//���ڿ��� �Է� ����.
	scanf("%s", Buffer);

	// ** �Է¹��� ���� �迭�̳� ��ȯ ���� ĳ���� ��������(char*)�̹Ƿ� ���ڿ��� �����ؾ���.
	// ** ���ڿ��� ���� �ϱ����� �����Ͱ� ����Ű�� ������ �Է¹��� ���ڿ��� �� ��ŭ�� ũ��� �޸� �Ҵ�
	char* pName = (char*)malloc(strlen(Buffer) + 1);	//���ڿ��� ����ȯ�� �ؾ���, NULL���� �־��ֱ� ���� +1�� �Ѵ�

	// Buffer�� ���� ���ڿ��� ������pName�� ���ڿ� ����
	strcpy(pName, Buffer);								

	// ������ �� ��ȯ
	return pName;										
}

void SceneManager(Object * Player, Object * Enemy)						// Scene����
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
		StageScene(Player, Enemy);									// StageScene ����
		break;

	case Scene_Exit:									//����
		
		exit(NULL);
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

void StageScene(Object* Player, Object *Enemy)
{
	// ** ���ȭ �Լ������ �뵵���� ����� �� �ְ�
	// ** �̵�
	//  * * * �Է�(Input)
	//  * * * �÷��̾� ��ǥ������ ����
	//  * * * ���� ������ ũ�� ������ ����
	//  * * * ���� ������Ʈ���� �̵��ӵ� ������ ����
	
	 
	// ** ����
	PlayerScene(Player);
	EnemyScene(Enemy);

	// ** ����
	// 
	// ** ��ȭ
	// 
	// 
	
	/*
	srand(time(NULL));									//rand �Լ��� ����ϱ����� �ʱ�ȭ

	// malloc �Լ��� ������ �Ǹ� �ּҰ��� ��ȯ�Ѵ�		** malloc�Լ��� ��ȯ ���� ������ �������� ������ �޸� ������ �߻��Ѵ�.
	//					�������� ������ �����
	/*
	* 
	* int iNumber=10;
	* 
	// �Q ������ ������ ����� �ּҰ��� ������ pNumber�� ����
	//pNumber�� �Q�� �Ҵ�� ������ ���� ����
	* int*pNumber = (int*) malloc(sizeof(int)); 
	* 
	// ������ pNumber�� iNumber�� �ּҰ��� ����
	// ** �� �̻� pNumber�� �Q������ ���� ������ ���� �Ұ� �ϰԵ� (�޸� ����)
	* pNumber = &iNumber;						
	*
	
	
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
							printf_s("%s(��)�� �����ƴ�.\n", Objects[PLAYER]->Name);

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
							printf_s("%s�� ����ġġ ���ߴ�.\n", Objects[PLAYER]->Name);

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
						printf_s("%s�� ����ġġ ���ߴ�.\n", Objects[PLAYER]->Name);
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
	*/
}


// �÷��̾�
void InitializeObjectPlayer (Object* Player)
{
		//PLAYER�� ��ü ������ �ʱ�ȭ�Ѵ�
			Player->Name = SetName();		
			Player->Info.HP = 100;
			Player->Info.MP = 10;
			Player->Info.Att = 10;
			Player->Info.Def = 10;
			Player->Info.Speed = 10;
			Player->Info.Level = 1;
			Player->Info.EXP = 0;
}

DWORD SetnameTime = 0;
void PlayerScene(Object* Player)
{
	if (SetnameTime + 10000 < GetTickCount())
		Check = 1;

	if (Check)
	{
		SetnameTime = GetTickCount();

		Player->Name = SetName();
		Check = 0;
	}
}


// ��
void InitializeObjectEnemy(Object* Enemy)
{
	Enemy->Name = (char*)"Enemy";
	Enemy->Info.HP = 30;
	Enemy->Info.MP = 5;
	Enemy->Info.Att = 5;
	Enemy->Info.Def = 15;
	Enemy->Info.Speed = 5;
	Enemy->Info.Level = 1;
	Enemy->Info.EXP = 0;
}

void EnemyScene(Object *Enemy)
{

}


/*
void PlayerStatus(Object* Player)
{
	system("cls");

	//�÷��̾��� ������ ���
	printf_s("[Player] : %s\n", Player->Name);
	printf_s("HP : %d\n", Player->Info.HP);
	printf_s("MP : %d\n", Player->Info.MP);
	printf_s("���ݷ� : %.2f\n", Player->Info.Att);
	printf_s("���� : %.2f\n", Player->Info.Def);
	printf_s("���� : %d\n", Player->Info.Level);
	printf_s("����ġ : %d\n", Player->Info.EXP);
}

void EnemyStatus(Object* Enemy)
{
	system("cls");
	//������ ������ ���
	printf_s("\n%s\n", Enemy->Name);
	printf_s("HP : %d\n", Enemy->Info.HP);
	printf_s("MP : %d\n", Enemy->Info.MP);
	printf_s("���ݷ� : %.2f\n", Enemy->Info.Att);
	printf_s("���� : %.2f\n", Enemy->Info.Def);
	printf_s("���� : %d\n", Enemy->Info.Level);
	printf_s("����ġ : %d\n", Enemy->Info.EXP);
}
void PlayerAttack(Object* Player,Object* Enemy)
{
	printf_s("%s�� ����!!\n", Player->Name);
	//�÷��̾��� ���ݷ°� ������ ������ ���Ͽ� �������� ����ϴ� ���ǹ�
	if (Player->Info.Att > Enemy->Info.Def)
		Enemy->Info.HP -= (int)(Player->Info.Att - Enemy->Info.Def);
	// ������ �� ���� ��� �ּ� 1�� �������� �ַ�����
	else
		Enemy->Info.HP -= 1;
}

void EnemyAttack(Object* Player,Object* Enemy)
{
	printf_s("������ ����!!\n");
	if (Enemy->Info.Att > Player->Info.Def)
		Enemy->Info.HP -= (int)(Enemy->Info.Att - Player->Info.Def);
	else
		Player->Info.HP -= 1;
}
*/