#pragma once
//ChinesePeach
#include"quan_ju.h"
#include"Output_Time.h"


struct Completion_time {//游戏成就达成时间
	int year;//完成年
	int month;//完成月
	int day;//完成日
};

struct Leaderboard {//排行榜中的元素内容
	char name[100];//游戏用户名 && 只允许英文字符
	int game_Step;//游戏步数
	Completion_time completion_time;//完成时间
}leaderboard[1000];//排行榜成员

int Sort_rules(const void* a, const void* b)//排序规则
{
	Leaderboard* Sort_Elements_One = (Leaderboard*)a;//快排元素1
	Leaderboard* Sort_Elements_Two = (Leaderboard*)b;//快排元素2

	if ((*Sort_Elements_One).game_Step != (*Sort_Elements_Two).game_Step)								//关键字1：游戏步数
		return (*Sort_Elements_One).game_Step > (*Sort_Elements_Two).game_Step ? 1 : -1;

	else if ((*Sort_Elements_One).completion_time.year != (*Sort_Elements_Two).completion_time.year)	//关键字2：完成年份
		return (*Sort_Elements_One).completion_time.year > (*Sort_Elements_Two).completion_time.year ? 1 : -1;

	else if ((*Sort_Elements_One).completion_time.month != (*Sort_Elements_Two).completion_time.month)	//关键字3：完成月份
		return (*Sort_Elements_One).completion_time.month > (*Sort_Elements_Two).completion_time.month ? 1 : -1;

	else if ((*Sort_Elements_One).completion_time.day != (*Sort_Elements_Two).completion_time.day)		//关键字4：完成日
		return (*Sort_Elements_One).completion_time.day > (*Sort_Elements_Two).completion_time.day ? 1 : -1;

	else if (strlen((*Sort_Elements_One).name) != strlen((*Sort_Elements_Two).name))				//关键字5：名称长度
		return strlen((*Sort_Elements_One).name) > strlen((*Sort_Elements_Two).name) ? 1 : -1;

	else {																								//关键字6：字母ACSII顺序
		for (int i = 0; i < strlen((*Sort_Elements_One).name); i++) {

			if ((*Sort_Elements_One).name[i] != (*Sort_Elements_Two).name[i])
				return (*Sort_Elements_One).name[i] > (*Sort_Elements_Two).name[i] ? 1 : -1;

		}
	}
}
void InitializationLeaderboard() {//初始化排行榜

	for (int i = 0; i < 10; i++) {

		leaderboard[i].game_Step = 999999;

		strcpy(leaderboard[i].name, "empty");

		leaderboard[i].completion_time.year = leaderboard[i].completion_time.month = leaderboard[i].completion_time.day = 9999;
	}
}
void Print_Leaderboard() {//输出排行榜
	system( "cls" );

	FILE* fp = NULL;//文件指针->打开排行榜信息
	fp = fopen("Leaderboard.txt", "r");

	if (fp == NULL) {//读取本地信息出错

		printf("No local date!\n");

		Sleep( 1000 );//暂停程序
		system("cls");//清空屏幕缓存区
		return;
	}

	InitializationLeaderboard();//初始化排行榜结构体

	int local_Population = 0;//本地保存的人数

	while ((fscanf(fp, "%s", leaderboard[local_Population].name)) != EOF) {

		fscanf(fp, "%d", &leaderboard[local_Population].game_Step);

		fscanf(fp, "%d", &leaderboard[local_Population].completion_time.year);

		fscanf(fp, "%d", &leaderboard[local_Population].completion_time.month);

		fscanf(fp, "%d", &leaderboard[local_Population++].completion_time.day);
	}

	qsort(leaderboard, local_Population, sizeof leaderboard[0], Sort_rules);//对排名信息进行排序
	printf("\t\tHistorical Optimum\n");
	printf("GamerName\tGameStep\tAchieveTime\n");

	for (int i = 0; i < 10; i++) {

		printf("%s\t\t%d\t\t%d.%d.%d\n", leaderboard[i].name, leaderboard[i].game_Step, leaderboard[i].completion_time.year, leaderboard[i].completion_time.month, leaderboard[i].completion_time.day);

	}
	printf("Press any key to return to the main menu!\n");
	getch();//暂停程序

	system( "cls" );
	fclose( fp );
}

void Update_Leaderboard( Leaderboard people ) {

	FILE* fp = NULL;//文件指针->打开排行榜信息
	fp = fopen( "Leaderboard.txt", "wt+" );

	if (fp == NULL) {//读取本地信息出错

		printf( "There is a bug in reading information, please restart and try.\n"
			"If loading fails all the time, please contact the administrator:\n"
			"QQ：2986325137 / 1272607918\n" );

		getch();//暂停程序
		system( "cls" );//清空屏幕缓存区
		return;
	}

	InitializationLeaderboard();//初始化排行榜结构体

	int local_Population = 0;//本地保存的人数

	while ((fscanf( fp, "%s", leaderboard[local_Population].name )) != EOF) {

		fscanf( fp, "%d", &leaderboard[local_Population].game_Step );

		fscanf( fp, "%d", &leaderboard[local_Population].completion_time.year );

		fscanf( fp, "%d", &leaderboard[local_Population].completion_time.month );

		fscanf( fp, "%d", &leaderboard[local_Population++].completion_time.day );
	}

	qsort( leaderboard, local_Population, sizeof leaderboard[0], Sort_rules );//对排名信息进行排序

	if (people.game_Step < leaderboard[9].game_Step) {

		leaderboard[9].game_Step = people.game_Step;
		strcpy( leaderboard[9].name, people.name );
		out_Time( leaderboard[9].completion_time.year, leaderboard[9].completion_time.month, leaderboard[9].completion_time.day );
	
	}
	for (int i = 0; i < 10; i++) {

		fprintf( fp, "%s %d %d %d %d\n", leaderboard[i].name, leaderboard[i].game_Step
			, leaderboard[i].completion_time.year, leaderboard[i].completion_time.month
			, leaderboard[i].completion_time.day );

	}
	fclose( fp );
}