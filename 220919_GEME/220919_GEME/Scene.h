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
		TalkText("����� �׾����ϴ�.(�� 80% ����)");
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

		scene_Number(1)//Ÿ��Ʋ
		{
			cout << "Ÿ��Ʋ";
			std::string A[2] = {
				"���� ����",
				"���� ����"
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

		scene_Number(2)//����
		{
			cout << "����";

			std::string A[4] = {
					   "���尣",
					   "����",
					   "��ȸ",
					   "����"
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

		scene_Number(3)//���尣
		{
			cout << "���尣";

			std::string A[3] = {
						  "����",
						  "����",
						  "���ư���"
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
		scene_Number(4)//����
		{
			cout << "����";

			std::string A[3] = {
						  "����",
						  "�Ǹ�",
						  "���ư���"
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
			cout << "��ȸ";

			std::string A[2] = {
						  "ȸ��",
						  "���ư���"
			};
			int p = inte_choice(A, 2, ADD);
			Scene_Move(p);

			switch (p)
			{
			case 1: {Scene_Move(5); //�÷��̾� ȸ��
				if (player::Money_CHECK() < 50)
				{
					TalkText("���� �����մϴ�.(50 ��)");
				}
				else
				{
					TalkText("ȸ�� �߽��ϴ�.(50 ��)");
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
		scene_Number(6)//����
		{
			cout << "����";

			std::string A[5] = {
				  "�ϱ� ����",
				  "�߱� ����",
				  "��� ����",
				  "�ֻ�� ����",
				  "���ư���"
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
		scene_Number(7)//����
		{
			cout << "����";
			std::string A[3] = {
				  "���� ����",
				  "�� ����",
				  "���ư���"
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
		scene_Number(8)//����
		{
			cout << "����";
		}

		scene_Number(11)//���� ����
		{
			cout << "���� ����";

			std::string A[2] = {
				  "��ȭ �õ�",
				  "���ư���"
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
					TalkText("���� �����մϴ�.(20 ��)");
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
		scene_Number(12)//�� ����
		{
			cout << "�� ����";
			std::string A[2] = {
				  "��ȭ �õ�",
				  "���ư���"
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
					TalkText("���� �����մϴ�.(20 ��)");
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

		scene_Number(9)//����
		{
			cout << "����";
		}
		scene_Number(10)//�Ǹ�
		{
			cout << "�Ǹ�";
		}

		scene_Number(20)//�ϱ� ����
		{
			cout << "�ϱ� ����    BOSS���� :"<< stone::STONE_CHECK(0);
			std::string A[2] = {
				  "��+ 50",
				  "���ư���"
			};
			int p = inte_choice(A, 2, ADD);
			Scene_Move(p);

			switch (p)
			{
			case 1: {Scene_Move(20);
				player::Money_PLUS(50);
				player::HP_PLUS(-10);
				player::EXP_PLUS(10);
				TalkText("�� + 50, ü�� - 10");
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
		scene_Number(21)//�߱� ����
		{
			cout << "�߱� ����    BOSS���� :" << stone::STONE_CHECK(1);
			std::string A[2] = {
				  "��+ 100",
				  "���ư���"
			};
			int p = inte_choice(A, 2, ADD);
			Scene_Move(p);

			switch (p)
			{
			case 1: {Scene_Move(21);
				player::Money_PLUS(100);
				player::HP_PLUS(-20);
				player::EXP_PLUS(20);
				TalkText("�� + 100, ü�� - 20");
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
		scene_Number(22)//��� ����
		{
			cout << "��� ����    BOSS���� :" << stone::STONE_CHECK(2);
			std::string A[2] = {
				  "��+ 200",
				  "���ư���"
			};
			int p = inte_choice(A, 2, ADD);
			Scene_Move(p);

			switch (p)
			{
			case 1: {Scene_Move(22);
				player::Money_PLUS(200);
				player::HP_PLUS(-40);
				player::EXP_PLUS(40);
				TalkText("�� + 200, ü�� - 40");
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
		scene_Number(23)//�ֻ�� ����
		{
			cout << "�ֻ�� ����    BOSS���� :" << stone::STONE_CHECK(3);
			std::string A[2] = {
				  "��+ 500",
				  "���ư���"
			};
			int p = inte_choice(A, 2, ADD);
			Scene_Move(p);

			switch (p)
			{
			case 1: {Scene_Move(23);
				player::Money_PLUS(500);
				player::HP_PLUS(-100);
				player::EXP_PLUS(100);
				TalkText("�� + 500, ü�� - 100");
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

