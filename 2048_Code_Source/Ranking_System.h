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
	int MaxNum;//出现的最大数字
	Completion_time completion_time;//完成时间
}leaderboard[10000];//排行榜成员
//排行榜容量为 10000
int Sort_rules_ordinary(const void* a, const void* b)//排序规则
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
int Sort_rules_endless( const void* a, const void* b )//排序规则
{
	Leaderboard* Sort_Elements_One = (Leaderboard*)a;//快排元素1
	Leaderboard* Sort_Elements_Two = (Leaderboard*)b;//快排元素2

	if ((*Sort_Elements_One).MaxNum != (*Sort_Elements_Two).MaxNum)								//关键字1：游戏步数
		return (*Sort_Elements_One).MaxNum < (*Sort_Elements_Two).MaxNum ? 1 : -1;

	else if ((*Sort_Elements_One).completion_time.year != (*Sort_Elements_Two).completion_time.year)	//关键字2：完成年份
		return (*Sort_Elements_One).completion_time.year > (*Sort_Elements_Two).completion_time.year ? 1 : -1;

	else if ((*Sort_Elements_One).completion_time.month != (*Sort_Elements_Two).completion_time.month)	//关键字3：完成月份
		return (*Sort_Elements_One).completion_time.month > (*Sort_Elements_Two).completion_time.month ? 1 : -1;

	else if ((*Sort_Elements_One).completion_time.day != (*Sort_Elements_Two).completion_time.day)		//关键字4：完成日
		return (*Sort_Elements_One).completion_time.day > (*Sort_Elements_Two).completion_time.day ? 1 : -1;

	else if (strlen( (*Sort_Elements_One).name ) != strlen( (*Sort_Elements_Two).name ))				//关键字5：名称长度
		return strlen( (*Sort_Elements_One).name ) > strlen( (*Sort_Elements_Two).name ) ? 1 : -1;

	else {																								//关键字6：字母ACSII顺序
		for (int i = 0; i < strlen( (*Sort_Elements_One).name ); i++) {

			if ((*Sort_Elements_One).name[i] != (*Sort_Elements_Two).name[i])
				return (*Sort_Elements_One).name[i] > ( *Sort_Elements_Two ).name[i] ? 1 : -1;

		}
	}
}
void InitializationLeaderboard() {//初始化排行榜

	
	leaderboard[0].game_Step = 99999;
	leaderboard->MaxNum = 0;
	strcpy( leaderboard[0].name, "empty" );

	leaderboard[0].completion_time.year = leaderboard[0].completion_time.month = leaderboard[0].completion_time.day = 9999;
	
}
void Print_Leaderboard(int mode) {//输出排行榜
	system( "cls" );

	FILE* fp = NULL;//文件指针->打开排行榜信息

	if (mode == 1)
		fp = fopen( "OrdinaryLeaderboard.txt", "r" );//普通模式排行榜文件
	else fp = fopen( "EndlessLeaderboard.txt", "r" );//无尽模式排行榜文件

	if (fp == NULL) {//读取本地信息出错
		
		printf("No local date!\n");

		Sleep( 1000 );//暂停程序
		system("cls");//清空屏幕缓存区
		return;
	}

	InitializationLeaderboard();//初始化排行榜结构体

	int local_Population = 0;//本地保存的人数

	while ((fscanf(fp, "%s", leaderboard[local_Population].name)) != EOF) {

		if (mode == 1)
			fscanf( fp, "%d", &leaderboard[local_Population].game_Step );
		else
			fscanf( fp, "%d", &leaderboard[local_Population].MaxNum );

		fscanf(fp, "%d", &leaderboard[local_Population].completion_time.year);

		fscanf(fp, "%d", &leaderboard[local_Population].completion_time.month);

		fscanf(fp, "%d", &leaderboard[local_Population++].completion_time.day);
	}

	if (local_Population==0) {//读取本地信息出错

		printf( "No local date!\n" );

		Sleep( 1000 );//暂停程序
		system( "cls" );//清空屏幕缓存区
		return;
	}

	if(mode==1)
		qsort(leaderboard, local_Population, sizeof leaderboard[0], Sort_rules_ordinary);//对排名信息进行排序
	else 
		qsort( leaderboard, local_Population, sizeof leaderboard[0], Sort_rules_endless );//对排名信息进行排序

	printf("\t\tHistorical Optimum\n");
	if (mode == 1)
		printf( "Ranking\tGamerName\tGameStep\tAchieveTime\n" );
	else 
		printf( "Ranking\tGamerName\tMaxNum\tAchieveTime\n" );
	if(mode==1)
		for (int i = 0; i < min(10,local_Population); i++) {

			printf("%d\t%s\t\t%d\t\t%d.%d.%d\n",i+1, leaderboard[i].name, leaderboard[i].game_Step, leaderboard[i].completion_time.year, leaderboard[i].completion_time.month, leaderboard[i].completion_time.day);

		}
	else 
		for (int i = 0; i < min( 10, local_Population ); i++) {

			printf( "%d\t%s\t\t%d\t\t%d.%d.%d\n", i + 1, leaderboard[i].name, leaderboard[i].MaxNum, leaderboard[i].completion_time.year, leaderboard[i].completion_time.month, leaderboard[i].completion_time.day );

		}
	printf("Press any key to return to the main menu!\n");
	getch();//暂停程序

	system( "cls" );
	fclose( fp );
}

void Update_Leaderboard( Leaderboard people ,int mode) {

	FILE* fp = NULL;//文件指针->打开排行榜信息
	
	if (mode == 1)
		fp = fopen( "OrdinaryLeaderboard.txt", "wt+" );//普通模式排行榜文件
	else fp = fopen( "EndlessLeaderboard.txt", "wt+" );//无尽模式排行榜文件


	if (fp == NULL) {//读取本地信息出错

		printf( "There is a bug in reading information, please restart and try.\n"
			"If loading fails all the time, please contact the administrator:\n"
			"QQ：2986325137 / 1272607918\n" );

		getch();//暂停程序
		system( "cls" );//清空屏幕缓存区
		return;
	}

	


	out_Time( people.completion_time.year, people.completion_time.month, people.completion_time.day );
	if(mode==1&&people.MaxNum>=2048)
	fprintf( fp, "%s %d %d %d %d\n", people.name, people.game_Step
		, people.completion_time.year, people.completion_time.month
		, people.completion_time.day );
	else 
		fprintf( fp, "%s %d %d %d %d\n", people.name, people.MaxNum
			, people.completion_time.year, people.completion_time.month
			, people.completion_time.day );
	
	fclose( fp );
}
