// 2048 2稿.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include"quan_ju.h"
#include"num_rand.h"
#include"move.h"
#include"Ranking_System.h"
#include"test.h"
#include"Keep_System.h"
#include"Pause_System.h"

void Print_Mnue() {
	printf( ">>>>>>>>>>>>>>>Game：2048<<<<<<<<<<<<<\n" );
	printf( "**************************************\n" );
	printf( "***************1.新建游戏*************\n" );
	printf( "***************2.继续游戏*************\n" );
	printf( "***************3.排 行 榜*************\n" );
	printf( "***************4.游戏说明*************\n" );
	printf( "***************5.退出游戏*************\n" );
	printf( "**************************************\n" );
	printf( "Please enter the number before operation:\n" );
}
void Game_Description()
{
	system( "cls" );

	printf( "2048游戏共有16个格子，初始时初始数字由2或者4构成。\n\n"

		"1、使用wasd，所有格子会向那个方向运动。\n\n"

		"2、相同数字的两个格子，相撞时数字会相加。\n\n"

		"3、每次滑动时，空白处会随机刷新出一个数字的格子。\n\n"

		"4、当界面不可运动时（当界面全部被数字填满时），游戏结束；\n\n" );

	printf( "Enter any key to return to the main menu!\n" );
	getch();
	system( "cls" );
}
int main()
{
	while (1) {
		Print_Mnue();
		string step;//选择
		cin >> step;
		if (step !="1" && step != "2" && step != "3" && step != "4" && step != "5") {

			printf( "Your input is wrong!\nPlease input again!\n" );
			Sleep( 1000 );
			system( "cls" );
			continue;
		
		}
		char step_char = step[0];
		switch (step_char) {
		case '1': {
			Leaderboard people;
			people.game_Step = 0;//初始化游戏步数

			printf( "Please Input Your Endlish Game Name:" );
			cin >> people.name;//创建新的游戏角色
			
			Sleep( 1000 );

			system( "cls" );
			printf( "The game begins...." );
			Sleep( 1000 );


			memset( wan_jia, 0, sizeof wan_jia );//初始化游戏地图
			get_blank( wan_jia );//创建一个随机数据
			
			
			
			test_round(people); break;
		}
		case '2':Keep_Playing(); break;
		case '3':Print_Leaderboard(); break;
		case '4':Game_Description(); break;
		case '5':printf("Thanks for your using!\n"); exit(0);
		}

	}


}