#pragma once
#include "common.h"

class weapon:public player
{
public:
	weapon() = delete;
	~weapon() = delete;
	weapon(const weapon&) = delete;
	weapon& operator=(const weapon&) = delete;
	static void WeaponPrint()
	{
		std::string Now[2] = { "무기   레벨","방어구 레벨"};
		int now[2] = { W_UPGREAD,D_UPGREAD };

		for (int i = 0; i < 2; i++)
		{
			inte_CuserMove(60, 13 + i);
			if (i == 0)
			{
				inte_TextColer(0, 12);
			}
			if (i == 1)
			{
				inte_TextColer(0, 10);
			}
			std::cout << Now[i] << "\t" << now[i] << "\n";
		}
		inte_TextColer(0, 15);
		inte_CuserMove(0,0);
	}
	static void WeaponW_Upgrade()
	{
		int random = rand() % 100 + 1;
		
		if (random < 100 - W_UPGREAD)
		{
			W_UPGREAD += 1;
		}
		else
		{
			W_UPGREAD -= 1;
		}
		player::WSTR_ADD(W_UPGREAD);
	}

	static void WeaponD_Upgrade()
	{
		int random = rand() % 100 + 1;

		if (random < 100 - D_UPGREAD)
		{
			D_UPGREAD += 1;
		}
		else
		{
			D_UPGREAD -= 1;
		}
		player::DHP_ADD(D_UPGREAD * 10);
	}



private:
	static int W_UPGREAD;
	static int D_UPGREAD;
};

int weapon::W_UPGREAD = 0;
int weapon::D_UPGREAD = 0;
