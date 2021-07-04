#include<stdio.h>
#include<string.h>
#include<math.h>
#include<Windows.h>
#include<stdlib.h>
#include<conio.h>

struct Completion_time {//游戏成就达成时间
	int year;
	int month;
	int day;
};
struct Leaderboard {//排行榜中的元素内容
	char name[100];//游戏用户名 && 只允许英文字符
	int game_Step;
	Completion_time completion_time;
}leaderboard[10];
int Sort_rules( const void* a, const void* b )//排序规则
{
	Leaderboard* Sort_Elements_One = (Leaderboard*)a;
	Leaderboard* Sort_Elements_Two = (Leaderboard*)b;
	if ((*Sort_Elements_One).game_Step != (*Sort_Elements_Two).game_Step)								//关键字1：游戏步数
		return (*Sort_Elements_One).game_Step < (*Sort_Elements_Two).game_Step;
	else if ((*Sort_Elements_One).completion_time.year != (*Sort_Elements_Two).completion_time.year)	//关键字2：完成年份
		return (*Sort_Elements_One).completion_time.year < (*Sort_Elements_Two).completion_time.year;
	else if ((*Sort_Elements_One).completion_time.month != (*Sort_Elements_Two).completion_time.month)	//关键字3：完成月份
		return (*Sort_Elements_One).completion_time.month < (*Sort_Elements_Two).completion_time.month;
	else if ((*Sort_Elements_One).completion_time.day != (*Sort_Elements_Two).completion_time.day)		//关键字4：完成日
		return (*Sort_Elements_One).completion_time.day < (*Sort_Elements_Two).completion_time.day;
	else if (strlen( (*Sort_Elements_One).name ) != strlen( (*Sort_Elements_Two).name ))				//关键字5：名称长度
		return strlen( (*Sort_Elements_One).name ) < strlen( (*Sort_Elements_Two).name );
	else {																								//关键字6：字母ACSII顺序
		for (int i = 0; i < strlen( (*Sort_Elements_One).name ); i++) {
			if ((*Sort_Elements_One).name[i] != (*Sort_Elements_Two).name[i])
				return (*Sort_Elements_One).name[i] < (*Sort_Elements_Two).name[i];
		}
	}
}
void InitializationLeaderboard() {
	for (int i = 0; i < 10; i++) {
		leaderboard[i].game_Step = 99999;
		strcpy(leaderboard[i].name , "empty");
		leaderboard[i].completion_time.year = leaderboard[i].completion_time.month = leaderboard[i].completion_time.day = 9999;
	}
}
void Print_Leaderboard() {//输出排行榜
	printf( "GamerName\tGameStep\tAchieveTime\n" );
	for (int i = 0; i < 10; i++) {
		printf( "%s\t\t%d\t\t%d.%d.%d\n", leaderboard[i].name, leaderboard[i].game_Step, leaderboard[i].completion_time.year, leaderboard[i].completion_time.month, leaderboard[i].completion_time.day );
	}
	printf( "Press any key to return to the main menu!\n" );
	getch();
}
int main()
{

	FILE* fp = NULL;//文件指针->打开排行榜信息
	fp=fopen( "Leaderboard.txt", "r" );
	if (fp == NULL) {//读取本地信息出错
		printf( "读取信息出现一个bug，请重启尝试。\n如果一直加载失败，请联系管理员：\nQQ：2986325137 / 1272607918\n" );
		system( "pause" );//暂停程序
		system( "cls" );//清空屏幕缓存区
		return 0;
	}
	InitializationLeaderboard();//初始化排行榜结构体
	int local_Population = 0;//本地保存的人数
	while ((fscanf( fp, "%s", leaderboard[++local_Population].name )) != EOF) {
		fscanf( fp, "%d", &leaderboard[local_Population].game_Step );
		fscanf( fp, "%d", &leaderboard[local_Population].completion_time.year );
		fscanf( fp, "%d", &leaderboard[local_Population].completion_time.month );
		fscanf( fp, "%d", &leaderboard[local_Population].completion_time.day );
	}
	qsort( leaderboard, 10, sizeof leaderboard[0], Sort_rules );//对排名信息进行排序
	Print_Leaderboard();
	return 0;

}