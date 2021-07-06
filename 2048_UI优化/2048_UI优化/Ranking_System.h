#pragma once
//ChinesePeach
#include"quan_ju.h"
#include"Output_Time.h"


struct Completion_time {//��Ϸ�ɾʹ��ʱ��
	int year;//�����
	int month;//�����
	int day;//�����
};

struct Leaderboard {//���а��е�Ԫ������
	char name[100];//��Ϸ�û��� && ֻ����Ӣ���ַ�
	int game_Step;//��Ϸ����
	int MaxNum;//���ֵ��������
	Completion_time completion_time;//���ʱ��
}leaderboard[10000];//���а��Ա
//���а�����Ϊ 10000
int Sort_rules_ordinary(const void* a, const void* b)//�������
{
	Leaderboard* Sort_Elements_One = (Leaderboard*)a;//����Ԫ��1
	Leaderboard* Sort_Elements_Two = (Leaderboard*)b;//����Ԫ��2

	if ((*Sort_Elements_One).game_Step != (*Sort_Elements_Two).game_Step)								//�ؼ���1����Ϸ����
		return (*Sort_Elements_One).game_Step > (*Sort_Elements_Two).game_Step ? 1 : -1;

	else if ((*Sort_Elements_One).completion_time.year != (*Sort_Elements_Two).completion_time.year)	//�ؼ���2��������
		return (*Sort_Elements_One).completion_time.year > (*Sort_Elements_Two).completion_time.year ? 1 : -1;

	else if ((*Sort_Elements_One).completion_time.month != (*Sort_Elements_Two).completion_time.month)	//�ؼ���3������·�
		return (*Sort_Elements_One).completion_time.month > (*Sort_Elements_Two).completion_time.month ? 1 : -1;

	else if ((*Sort_Elements_One).completion_time.day != (*Sort_Elements_Two).completion_time.day)		//�ؼ���4�������
		return (*Sort_Elements_One).completion_time.day > (*Sort_Elements_Two).completion_time.day ? 1 : -1;

	else if (strlen((*Sort_Elements_One).name) != strlen((*Sort_Elements_Two).name))				//�ؼ���5�����Ƴ���
		return strlen((*Sort_Elements_One).name) > strlen((*Sort_Elements_Two).name) ? 1 : -1;

	else {																								//�ؼ���6����ĸACSII˳��
		for (int i = 0; i < strlen((*Sort_Elements_One).name); i++) {

			if ((*Sort_Elements_One).name[i] != (*Sort_Elements_Two).name[i])
				return (*Sort_Elements_One).name[i] > (*Sort_Elements_Two).name[i] ? 1 : -1;

		}
	}
}
int Sort_rules_endless( const void* a, const void* b )//�������
{
	Leaderboard* Sort_Elements_One = (Leaderboard*)a;//����Ԫ��1
	Leaderboard* Sort_Elements_Two = (Leaderboard*)b;//����Ԫ��2

	if ((*Sort_Elements_One).MaxNum != (*Sort_Elements_Two).MaxNum)								//�ؼ���1����Ϸ����
		return (*Sort_Elements_One).MaxNum < (*Sort_Elements_Two).MaxNum ? 1 : -1;

	else if ((*Sort_Elements_One).completion_time.year != (*Sort_Elements_Two).completion_time.year)	//�ؼ���2��������
		return (*Sort_Elements_One).completion_time.year > (*Sort_Elements_Two).completion_time.year ? 1 : -1;

	else if ((*Sort_Elements_One).completion_time.month != (*Sort_Elements_Two).completion_time.month)	//�ؼ���3������·�
		return (*Sort_Elements_One).completion_time.month > (*Sort_Elements_Two).completion_time.month ? 1 : -1;

	else if ((*Sort_Elements_One).completion_time.day != (*Sort_Elements_Two).completion_time.day)		//�ؼ���4�������
		return (*Sort_Elements_One).completion_time.day > (*Sort_Elements_Two).completion_time.day ? 1 : -1;

	else if (strlen( (*Sort_Elements_One).name ) != strlen( (*Sort_Elements_Two).name ))				//�ؼ���5�����Ƴ���
		return strlen( (*Sort_Elements_One).name ) > strlen( (*Sort_Elements_Two).name ) ? 1 : -1;

	else {																								//�ؼ���6����ĸACSII˳��
		for (int i = 0; i < strlen( (*Sort_Elements_One).name ); i++) {

			if ((*Sort_Elements_One).name[i] != (*Sort_Elements_Two).name[i])
				return (*Sort_Elements_One).name[i] > ( *Sort_Elements_Two ).name[i] ? 1 : -1;

		}
	}
}
void InitializationLeaderboard() {//��ʼ�����а�

	
	leaderboard[0].game_Step = 99999;
	leaderboard[0].MaxNum = 0;
	strcpy( leaderboard[0].name, "empty" );

	leaderboard[0].completion_time.year = leaderboard[0].completion_time.month = leaderboard[0].completion_time.day = 9999;
	
}
void Print_Leaderboard(int mode) {//������а�
	system( "cls" );

	FILE* fp = NULL;//�ļ�ָ��->�����а���Ϣ

	if (mode == 1)
		fp = fopen( "OrdinaryLeaderboard.txt", "r" );//��ͨģʽ���а��ļ�
	else fp = fopen( "EndlessLeaderboard.txt", "r" );//�޾�ģʽ���а��ļ�

	if (fp == NULL) {//��ȡ������Ϣ����
		
		printf("No local date!\n");

		Sleep( 1000 );//��ͣ����
		system("cls");//�����Ļ������
		return;
	}

	InitializationLeaderboard();//��ʼ�����а�ṹ��

	int local_Population = 0;//���ر��������

	while ((fscanf(fp, "%s", leaderboard[local_Population].name)) != EOF) {

		if (mode == 1)
			fscanf( fp, "%d", &leaderboard[local_Population].game_Step );
		else
			fscanf( fp, "%d", &leaderboard[local_Population].MaxNum );

		fscanf(fp, "%d", &leaderboard[local_Population].completion_time.year);

		fscanf(fp, "%d", &leaderboard[local_Population].completion_time.month);

		fscanf(fp, "%d", &leaderboard[local_Population++].completion_time.day);
	}

	if (local_Population==0) {//��ȡ������Ϣ����

		printf( "No local date!\n" );

		Sleep( 1000 );//��ͣ����
		system( "cls" );//�����Ļ������
		return;
	}

	if(mode==1)
		qsort(leaderboard, local_Population, sizeof leaderboard[0], Sort_rules_ordinary);//��������Ϣ��������
	else 
		qsort( leaderboard, local_Population, sizeof leaderboard[0], Sort_rules_endless );//��������Ϣ��������

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
	getch();//��ͣ����

	system( "cls" );
	fclose( fp );
}

void Update_Leaderboard( Leaderboard people ,int mode) {

	FILE* fp = NULL;//�ļ�ָ��->�����а���Ϣ
	
	if (mode == 1)
		fp = fopen( "OrdinaryLeaderboard.txt", "wt+" );//��ͨģʽ���а��ļ�
	else fp = fopen( "EndlessLeaderboard.txt", "wt+" );//�޾�ģʽ���а��ļ�


	if (fp == NULL) {//��ȡ������Ϣ����

		printf( "There is a bug in reading information, please restart and try.\n"
			"If loading fails all the time, please contact the administrator:\n"
			"QQ��2986325137 / 1272607918\n" );

		getch();//��ͣ����
		system( "cls" );//�����Ļ������
		return;
	}

	


	out_Time( people.completion_time.year, people.completion_time.month, people.completion_time.day );
	if(mode==1&&people.MaxNum>=2048)
	fprintf( fp, "%s %d %d %d %d\n", people.name, people.game_Step
		, people.completion_time.year, people.completion_time.month
		, people.completion_time.day );
	else if(mode==2)
		fprintf( fp, "%s %d %d %d %d\n", people.name, people.MaxNum
			, people.completion_time.year, people.completion_time.month
			, people.completion_time.day );
	
	fclose( fp );
}