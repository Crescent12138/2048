// 2048 2稿.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include"quan_ju.h"
#include"num_rand.h"
#include"move.h"
#include"Ranking_System.h"
#include"test.h"
#include"Keep_System.h"
#include"Pause_System.h"
#include"New_Game.h"
#include"Wipe_Cache.h"

void Print_Mnue() {
	printf( ">>>>>>>>>>>>>>>>>>>>>>>>Game：2048<<<<<<<<<<<<<<<<<<<<<\n" );
	printf( "*******************************************************\n" );
	printf( "******			1.新建游戏		   ****\n" );
	printf( "******			2.继续游戏		   ****\n" );
	printf( "******			3.普通模式排行榜	   ****\n" );
	printf( "******			4.无尽模式排行榜	   ****\n" );
	printf( "******			5.游戏说明		   ****\n" );
	printf( "******			6.退出游戏		   ****\n" );
	printf( "******			7.清空缓存		   ****\n" );
	printf( "*******************************************************\n" );
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
		case '1': new_game(); break;
		case '2':Keep_Playing_GameMode(); break;
		case '3':Print_Leaderboard( 1 ); break;
		case '4':Print_Leaderboard( 2 ); break;
		case '5':Game_Description(); break;
		case '6':printf("Thanks for your using!\n"); exit(0);
		case '7':Wipe_cache(); break;
		}

	}


}