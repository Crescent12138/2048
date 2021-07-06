#pragma once
#include"quan_ju.h"
#include"Ranking_System.h"
#include"test.h"

void new_game() {
	Leaderboard people;
	people.game_Step = 0;//初始化游戏步数
	people.MaxNum = 0;//初始化最大值

	system( "cls" );
	

	string step;//选择
	while (1) {
		printf( "1.普通模式\n2.无尽模式\n" );
		printf( "Please choose game mode:" );
		cin >> step;
		if (step != "1" && step != "2") {
			setcolor( 4, 0 );
			printf( "Your input is wrong!\nPlease input again!\n" );
			Sleep( 1000 );
			system( "cls" );
			setcolor( 11, 0 );
			continue;
			
		}
		break;
		
	}
	system( "cls" );
	printf( "Please Input Your Endlish Game Name:" );
	cin >> people.name;//创建新的游戏角色

	Sleep( 1000 );

	system( "cls" );
	printf( "The game begins...." );
	Sleep( 1000 );

	memset( wan_jia, 0, sizeof wan_jia );//初始化游戏地图
	get_blank( wan_jia );//创建一个随机数据

	switch (step[0]) {
	case '1':test_round( people, 1 ); return;
	case '2':test_round( people, 2 ); return;
	}
}