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

string stone::stone_1[5] = { "1¹ø ±¤¹°", "2¹ø ±¤¹°", "3¹ø ±¤¹°", "4¹ø ±¤¹°", "5¹ø ±¤¹°", };


