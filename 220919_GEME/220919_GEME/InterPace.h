#pragma once
#include "common.h"

#define NomalColer SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15)

/// <summary>
/// ���ڻ� �ٲٱ�
/// </summary>
/// <param name="a">���� 0 ~ 15</param>
/// <param name="b">���ڻ� 0 ~ 15</param>
void inte_TextColer(int a, int b)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a * 16 + b);
}

void inte_CuserMove(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

/// <summary>
/// Ű ����
/// </summary>
void inte_explanation()
{
	std::string explanation[5] = {
					   "��ȣ�ۿ�\tF",
					   "�̵�  \tWASD",
					   "����  \t�����̽� ��",
					   "������ â\tQ"
	};

	inte_TextColer(0, 9);
	for (int i = 0; i < 4; i++)
	{
		inte_CuserMove(60, 20 + i);
		std::cout << explanation[i] << std::endl;

	}
	NomalColer;
	inte_CuserMove(0, 0);
}



/// <summary>
/// ������ ���
/// </summary>
/// <param name="choice">������ �迭</param>
/// <param name="choiceN">������ ��</param>
/// <param name="COUNT">���� ������ (int ����)</param>
int inte_choice(std::string* choice, int choiceN, int &COUNT)
{
	while (true)
	{
		for (int i = 0; i < choiceN; i++)
		{
			inte_CuserMove(20, 20+i);
			if (i != COUNT * -1)
			{
				inte_TextColer(0, 8);
				std::cout << i + 1 << ".\t" << choice[i] << "\n";
			}
			else
			{
				NomalColer;
				std::cout << i + 1 << ".\t" << choice[i] << "\n";
			}
			NomalColer;
		}
		int key = _getch();

		if (key < 'a')
		{
			key += 'a' - 'A';
		}

		switch (key)
		{
		case'w':
			if (COUNT < 0)
			{
				COUNT++;
			}
			break;
		case's':
			if (COUNT > (choiceN * -1) + 1)
			{
				COUNT--;
			}
			break;
		case'f': return (COUNT * -1) + 1;
			break;
		default:
			break;
		}
		return COUNT;
	}
}


