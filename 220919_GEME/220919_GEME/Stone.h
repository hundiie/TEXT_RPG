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
	static void stac_PLUS(int a, int b)
	{
		STAC[a] += b;
	}

	static int STONE_CHECK(int a)
	{
		return STAC[a];
	}

private:

	static int STAC[4];
	//static string stone_2[5];
	//static string stone_3[5];
	//static string stone_4[5];
};

int stone::STAC[4] = { 0 };


