#include "CursorManager.h"

CursorManager* CursorManager::Instance = nullptr;

//**	���ۻ���
void CursorManager::CreateBuffer(const int& _Width, const int& _Height)
{
	CONSOLE_CURSOR_INFO CursorInfo;

	//**	Ŀ�� �Ⱥ��̰� ��
	CursorInfo.bVisible = false;
	CursorInfo.dwSize = 1;

	COORD Size = { (SHORT)(_Width - 1),  (SHORT)(_Height - 1) };

	SMALL_RECT Rect = {	0,0, (SHORT)(_Width), (SHORT)(_Height)};

	HBuffer[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,
		0, NULL, CONSOLE_TEXTMODE_BUFFER,NULL);
	SetConsoleScreenBufferSize(HBuffer[0], Size);
	SetConsoleWindowInfo(HBuffer[0], TRUE, &Rect);
	SetConsoleCursorInfo(HBuffer[0], &CursorInfo);


	HBuffer[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,
		0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleScreenBufferSize(HBuffer[1], Size);
	SetConsoleWindowInfo(HBuffer[1], TRUE, &Rect);
	SetConsoleCursorInfo(HBuffer[1], &CursorInfo);
}

//**	���ۿ� ����
void CursorManager::WriteBuffer(float _x, float _y, char* _str, int _Color)
{
	COORD CursorPosition = { (SHORT)_x, (SHORT)_y };
	SetConsoleCursorPosition(HBuffer[BufferIndex], CursorPosition);

	SetColor(_Color);
	DWORD dw;

	WriteFile(HBuffer[BufferIndex], _str, (DWORD)strlen(_str), &dw, NULL);
	SetColor(_Color);

	cout << _str;
}
//**	���ۿ� ����
void CursorManager::WriteBuffer(Vector3 _Position, char* _str, int _Color)
{
	COORD CursorPosition = { (SHORT)_Position.x, (SHORT)_Position.y };
	SetConsoleCursorPosition(HBuffer[BufferIndex], CursorPosition);

	SetColor(_Color);
	DWORD dw;

	WriteFile(HBuffer[BufferIndex], _str, (DWORD)strlen(_str), &dw, NULL);
}

//**	���� ��ȯ
void CursorManager::FliptingBuffer()
{
	//**	 ���� ���۸� ������
	SetConsoleActiveScreenBuffer(HBuffer[BufferIndex]);
	//**	���� �ε����� ����
	BufferIndex = !BufferIndex;

	ClearBuffer();
}
//**	���� �����(û��)
void CursorManager::ClearBuffer()
{
	COORD Cood = { 0,0 };
	DWORD dw = 0;
	//**	���۸� ' '��� �������� ä�� ����.
	FillConsoleOutputCharacter(HBuffer[BufferIndex], ' ', 150 * 40, Cood, &dw);
}
//**	���� ����
void CursorManager::DestroyBuffer()
{
	CloseHandle(HBuffer[0]);
}

void CursorManager::SetColor(int _Color)
{
	
	SetConsoleTextAttribute(HBuffer[BufferIndex], _Color);
}

CursorManager::CursorManager():BufferIndex(0)
{
}

CursorManager::~CursorManager()
{
	DestroyBuffer();
}
