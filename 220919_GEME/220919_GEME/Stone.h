#pragma once
#include "common.h"

using namespace std;

class stone
{
public:
	stone() = delete;
	~stone() = delete;
	stone(const stone&) = delete;
	stone& operator=(const stone&) = delete;

	static void mine1()
	{
		int g = rand() % 5;

	}


private:
	static string stone_1[5];
	static struct STONE
	{
		int MAXHP;
		int HP;
		int GOLD;
		
	}A[20];

	//static string stone_2[5];
	//static string stone_3[5];
	//static string stone_4[5];
};

string stone::stone_1[5] = { "1�� ����", "2�� ����", "3�� ����", "4�� ����", "5�� ����", };


