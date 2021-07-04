// 2048 2稿.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include"move.h"
#include"quan_ju.h"
#include"test.h"
#include"Ranking_System.h"
#include"num_rand.h"
#include"Pause_Keep_System.h"

void Print_Mnue() {
	printf( ">>>>>>>>>>>>>>>Game：2048<<<<<<<<<<<<<\n" );
	printf( "**************************************\n" );
	printf( "***************1.新建游戏*************\n" );
	printf( "***************2.继续游戏*************\n" );
	printf( "***************3.排 行 榜*************\n" );
	printf( "***************4.游戏说明*************\n" );
	printf( "***************5.退出游戏*************\n" );
	printf( "**************************************\n" );
}
void Game_Description()
{
	printf( "2048游戏共有16个格子，初始时初始数字由2或者4构成。\n\n"

		"1、使用wasd，所有格子会向那个方向运动。\n\n"

		"2、相同数字的两个格子，相撞时数字会相加。\n\n"

		"3、每次滑动时，空白处会随机刷新出一个数字的格子。\n\n"

		"4、当界面不可运动时（当界面全部被数字填满时），游戏结束；当界面中最大数字是2048时，游戏胜利。\n\n" );
	printf( "Enter any key to return to the main menu!\n" );
	getch();
	system( "cls" );
}
int main()
{
	while (1) {
		Print_Mnue();
		int step;//选择
		scanf( "%d", &step );
		switch (step) {
		case 1:memset(wan_jia,0,sizeof wan_jia),test_round(); break;
		case 2:Keep_Playing(); break;
		case 3:Print_Leaderboard(); break;
		case 4:Game_Description(); break;
		case 5:printf( "Thanks for your using!\n" ); exit( 0 );
		}

	}


}