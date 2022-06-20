#pragma once
#include "common.h"
#include "Player.h"
#include "Weapon.h"
#include "Stone.h"

using namespace std;

#define scene_Number(n)  if (SCENE == n)
#define TalkText(n)  talk = true;player::talk(n)
#define ADD in_N

int SCENE = 1;

int b = 0;
int& in_N = b;
bool talk = false;

void SCENE_Init()
{
	system("cls");
	inte_explanation();
	if (SCENE != 1)
	{
		player::printStatus();
		weapon::WeaponPrint();
	}
	if (player::HP_CHECK() <= 0)
	{
		SCENE = 2;
		TalkText("당신은 죽었습니다.(돈 80% 감소)");
		player::Money_ADD((player::Money_CHECK() / 5));
		player::HP_ADD(10);
	}
	if (talk == true)
	{
		player::talkPrint();
	}

	talk = false;
}

void Initpage()
{
	in_N = 0;
}

void Scene_Move(int num)
{
	if (num < 1)
	{
		return;
	}

	Initpage();
	SCENE = num;
	
}

void Scene()
{
	while (true)
	{
		SCENE_Init();

		scene_Number(1)//타이틀
		{
			cout << "타이틀";
			std::string A[2] = {
				"게임 시작",
				"게임 종료"
			};

			int p = inte_choice(A, 2, in_N);

			switch (p)
			{
			case 1:{Scene_Move(2);}
				break;
			case 2:{return;}
				break;
			default:
				break;
			}

			continue;
		}

		scene_Number(2)//마을
		{
			cout << "마을";

			std::string A[4] = {
					   "대장간",
					   "상점",
					   "교회",
					   "광산"
			};

			int p = inte_choice(A, 4, ADD);
			Scene_Move(p);

			switch (p)
			{
			case 1:{Scene_Move(3);}
				break;
			case 2:{Scene_Move(4);}
				break;
			case 3:{Scene_Move(5);}
				break;
			case 4:{Scene_Move(6);}
				break;
			default:
				break;
			}

			continue;
		}

		scene_Number(3)//대장간
		{
			cout << "대장간";

			std::string A[3] = {
						  "업글",
						  "제작",
						  "돌아가기"
			};

			int p = inte_choice(A, 3, ADD);
			Scene_Move(p);

			switch (p)
			{
			case 1:{Scene_Move(7);}
				break;
			case 2:{Scene_Move(2); }//Scene_Move(8);}
				break;
			case 3:{Scene_Move(2);}
				break;
			default:
				break;
			}
			continue;
		}
		scene_Number(4)//상점
		{
			cout << "상점";

			std::string A[3] = {
						  "구매",
						  "판매",
						  "돌아가기"
			};
			int p = inte_choice(A, 3, ADD);
			Scene_Move(p);

			switch (p)
			{
			case 1: {Scene_Move(2); }//Scene_Move(9); }
				  break;
			case 2: {Scene_Move(2); }//Scene_Move(10); }
				  break;
			case 3: {Scene_Move(2); }
				  break;
			default:
				break;
			}
			continue;
		}

		scene_Number(5)
		{
			cout << "교회";

			std::string A[2] = {
						  "회복",
						  "돌아가기"
			};
			int p = inte_choice(A, 2, ADD);
			Scene_Move(p);

			switch (p)
			{
			case 1: {Scene_Move(5); //플레이어 회복
				if (player::Money_CHECK() < 50)
				{
					TalkText("돈이 부족합니다.(50 원)");
				}
				else
				{
					TalkText("회복 했습니다.(50 원)");
					player::Money_PLUS(-50);
					player::HP_ADD(player::HPM_CHECK());
				}
				}
				  break;
			case 2: {Scene_Move(2); }
				  break;
			default:
				break;
			}
			continue;
		}
		scene_Number(6)//광산
		{
			cout << "광산";

			std::string A[5] = {
				  "하급 광산",
				  "중급 광산",
				  "상급 광산",
				  "최상급 광산",
				  "돌아가기"
			};
			int p = inte_choice(A, 5, ADD);
			Scene_Move(p);

			switch (p)
			{
			case 1: {Scene_Move(20); }
				  break;
			case 2: {Scene_Move(21); }
				  break;
			case 3: {Scene_Move(22); }
				  break;
			case 4: {Scene_Move(23); }
				  break;
			case 5: {Scene_Move(2); }
				  break;
			default:
				break;
			}
			continue;
		}
		scene_Number(7)//업글
		{
			cout << "업글";
			std::string A[3] = {
				  "무기 업글",
				  "방어구 업글",
				  "돌아가기"
			};
			int p = inte_choice(A, 3, ADD);
			Scene_Move(p);

			switch (p)
			{
			case 1: {Scene_Move(11); }
				  break;
			case 2: {Scene_Move(12); }
				  break;
			case 3: {Scene_Move(3); }
				  break;
			default:
				break;
			}
			continue;
		}
		scene_Number(8)//제작
		{
			cout << "제작";
		}

		scene_Number(11)//무기 업글
		{
			cout << "무기 업글";

			std::string A[2] = {
				  "강화 시도",
				  "돌아가기"
			};
			int p = inte_choice(A, 2, ADD);
			Scene_Move(p);

			switch (p)
			{
			case 1: {Scene_Move(11);

				if (player::Money_CHECK() >= 20)
				{
					weapon::WeaponW_Upgrade(); 
					player::Money_PLUS(-20);
					talk = true;
				}
				else
				{
					TalkText("돈이 부족합니다.(20 원)");
				}
			}
				  break;
			case 2: {Scene_Move(7); }
				  break;
			default:
				break;
			}
			continue;
		}
		scene_Number(12)//방어구 업글
		{
			cout << "방어구 업글";
			std::string A[2] = {
				  "강화 시도",
				  "돌아가기"
			};
			int p = inte_choice(A, 2, ADD);
			Scene_Move(p);

			switch (p)
			{
			case 1: {Scene_Move(12);
				if (player::Money_CHECK() >= 20)
				{
					weapon::WeaponD_Upgrade();
					player::Money_PLUS(-20);
					talk = true;
				}
				else
				{
					TalkText("돈이 부족합니다.(20 원)");
				}
			}
				  break;
			case 2: {Scene_Move(7); }
				  break;
			default:
				break;
			}
			continue;
		}

		scene_Number(9)//구매
		{
			cout << "구매";
		}
		scene_Number(10)//판매
		{
			cout << "판매";
		}

		scene_Number(20)//하급 광산
		{
			cout << "하급 광산    BOSS스택 :"<< stone::STONE_CHECK(0);
			std::string A[2] = {
				  "돈+ 50",
				  "돌아가기"
			};
			int p = inte_choice(A, 2, ADD);
			Scene_Move(p);

			switch (p)
			{
			case 1: {Scene_Move(20);
				player::Money_PLUS(50);
				player::HP_PLUS(-10);
				player::EXP_PLUS(10);
				TalkText("돈 + 50, 체력 - 10");
				stone::stac_PLUS(0,player::STR_CHECK());
			}
				  break;
			case 2: {Scene_Move(2); }
				  break;
			default:
				break;
			}
			continue;
		}
		scene_Number(21)//중급 광산
		{
			cout << "중급 광산    BOSS스택 :" << stone::STONE_CHECK(1);
			std::string A[2] = {
				  "돈+ 100",
				  "돌아가기"
			};
			int p = inte_choice(A, 2, ADD);
			Scene_Move(p);

			switch (p)
			{
			case 1: {Scene_Move(21);
				player::Money_PLUS(100);
				player::HP_PLUS(-20);
				player::EXP_PLUS(20);
				TalkText("돈 + 100, 체력 - 20");
				stone::stac_PLUS(1, player::STR_CHECK());
			}
				  break;
			case 2: {Scene_Move(2); }
				  break;
			default:
				break;
			}
			continue;
		}
		scene_Number(22)//상급 광산
		{
			cout << "상급 광산    BOSS스택 :" << stone::STONE_CHECK(2);
			std::string A[2] = {
				  "돈+ 200",
				  "돌아가기"
			};
			int p = inte_choice(A, 2, ADD);
			Scene_Move(p);

			switch (p)
			{
			case 1: {Scene_Move(22);
				player::Money_PLUS(200);
				player::HP_PLUS(-40);
				player::EXP_PLUS(40);
				TalkText("돈 + 200, 체력 - 40");
				stone::stac_PLUS(2, player::STR_CHECK());
			}
				  break;
			case 2: {Scene_Move(2); }
				  break;
			default:
				break;
			}
			continue;
		}
		scene_Number(23)//최상급 광산
		{
			cout << "최상급 광산    BOSS스택 :" << stone::STONE_CHECK(3);
			std::string A[2] = {
				  "돈+ 500",
				  "돌아가기"
			};
			int p = inte_choice(A, 2, ADD);
			Scene_Move(p);

			switch (p)
			{
			case 1: {Scene_Move(23);
				player::Money_PLUS(500);
				player::HP_PLUS(-100);
				player::EXP_PLUS(100);
				TalkText("돈 + 500, 체력 - 100");
				stone::stac_PLUS(3, player::STR_CHECK());
			}
				  break;
			case 2: {Scene_Move(2); }
				  break;
			default:
				break;
			}
			continue;
		}
	}
}

