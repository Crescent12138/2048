#pragma once
#include"quan_ju.h"
#include"Ranking_System.h"
#include"test.h"


void Keep_Playing( int mode ) {

	FILE* fp = NULL;//文件指针->存档
	if (mode == 1)
		fp = fopen( "Historical_Archive_Ori.txt", "r" );
	else 
		fp = fopen( "Historical_Archive_endless.txt", "r" );
	
	if (fp == NULL) {//读取本地信息出错

		printf( "Local archive not found!\n" );

		Sleep( 1000 );//暂停程序
		system( "cls" );//清空屏幕缓存区
		return;
	}

	int symple = 0;//记录读取数据，判断本地有没有存档

	Leaderboard people;
	if(mode==1)
		fscanf( fp, "%s %d", people.name, &people.game_Step );
	else 
		fscanf( fp, "%s %d", people.name, &people.MaxNum );

	for (int i = 0; i < 4; i++) {

		for (int j = 0; j < 4; j++) {

			fscanf( fp, "%d", &wan_jia[i][j] );//全局变量
			if (wan_jia[i][j] != 0)//表明有有效数据
				symple = 1;
		}
	}
	if (!symple) {//没有有效数据

		printf( "Local archive not found!\n" );

		Sleep( 1000 );//暂停程序

		system( "cls" );//清空屏幕

		return;
	}

	//当存在有效数据的时候

	test_round( people ,mode);

	fclose( fp );
}

void Keep_Playing_GameMode() {

	system( "cls" );

	
	while (1) {
		
		printf( "1.普通模式\n2.无尽模式\n" );
		printf( "Please choose game pattern:" );

		string step;//选择
		cin >> step;
		if (step != "1" && step != "2") {

			printf( "Your input is wrong!\nPlease input again!\n" );
			Sleep( 1000 );
			system( "cls" );

			continue;
		}

		switch (step[0]) {

		case '1':Keep_Playing( 1 ); return;
		case '2':Keep_Playing( 2 ); return;

		}
	}
}
