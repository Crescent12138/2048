#pragma once
#include"quan_ju.h"
#include"Ranking_System.h"
#include"test.h"


void Keep_Playing() {

	FILE* fp = NULL;//文件指针->存档
	fp = fopen( "Historical_Archive.txt", "r" );

	if (fp == NULL) {//读取本地信息出错

		printf( "Local archive not found!\n" );

		getch();//暂停程序
		system( "cls" );//清空屏幕缓存区
		return;
	}
	int symple = 0;//记录读取数据，判断本地有没有存档

	Leaderboard people;
	fscanf( fp, "%s %d", people.name, &people.game_Step );

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

	test_round( people );

	fclose( fp );
}