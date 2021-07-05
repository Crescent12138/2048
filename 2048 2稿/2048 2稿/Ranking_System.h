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
	Completion_time completion_time;//���ʱ��
}leaderboard[1000];//���а��Ա

int Sort_rules(const void* a, const void* b)//�������
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
void InitializationLeaderboard() {//��ʼ�����а�

	for (int i = 0; i < 10; i++) {

		leaderboard[i].game_Step = 999999;

		strcpy(leaderboard[i].name, "empty");

		leaderboard[i].completion_time.year = leaderboard[i].completion_time.month = leaderboard[i].completion_time.day = 9999;
	}
}
void Print_Leaderboard() {//������а�
	system( "cls" );

	FILE* fp = NULL;//�ļ�ָ��->�����а���Ϣ
	fp = fopen("Leaderboard.txt", "r");

	if (fp == NULL) {//��ȡ������Ϣ����

		printf("No local date!\n");

		Sleep( 1000 );//��ͣ����
		system("cls");//�����Ļ������
		return;
	}

	InitializationLeaderboard();//��ʼ�����а�ṹ��

	int local_Population = 0;//���ر��������

	while ((fscanf(fp, "%s", leaderboard[local_Population].name)) != EOF) {

		fscanf(fp, "%d", &leaderboard[local_Population].game_Step);

		fscanf(fp, "%d", &leaderboard[local_Population].completion_time.year);

		fscanf(fp, "%d", &leaderboard[local_Population].completion_time.month);

		fscanf(fp, "%d", &leaderboard[local_Population++].completion_time.day);
	}

	qsort(leaderboard, local_Population, sizeof leaderboard[0], Sort_rules);//��������Ϣ��������
	printf("\t\tHistorical Optimum\n");
	printf("GamerName\tGameStep\tAchieveTime\n");

	for (int i = 0; i < 10; i++) {

		printf("%s\t\t%d\t\t%d.%d.%d\n", leaderboard[i].name, leaderboard[i].game_Step, leaderboard[i].completion_time.year, leaderboard[i].completion_time.month, leaderboard[i].completion_time.day);

	}
	printf("Press any key to return to the main menu!\n");
	getch();//��ͣ����

	system( "cls" );
	fclose( fp );
}

void Update_Leaderboard( Leaderboard people ) {

	FILE* fp = NULL;//�ļ�ָ��->�����а���Ϣ
	fp = fopen( "Leaderboard.txt", "wt+" );

	if (fp == NULL) {//��ȡ������Ϣ����

		printf( "There is a bug in reading information, please restart and try.\n"
			"If loading fails all the time, please contact the administrator:\n"
			"QQ��2986325137 / 1272607918\n" );

		getch();//��ͣ����
		system( "cls" );//�����Ļ������
		return;
	}

	InitializationLeaderboard();//��ʼ�����а�ṹ��

	int local_Population = 0;//���ر��������

	while ((fscanf( fp, "%s", leaderboard[local_Population].name )) != EOF) {

		fscanf( fp, "%d", &leaderboard[local_Population].game_Step );

		fscanf( fp, "%d", &leaderboard[local_Population].completion_time.year );

		fscanf( fp, "%d", &leaderboard[local_Population].completion_time.month );

		fscanf( fp, "%d", &leaderboard[local_Population++].completion_time.day );
	}

	qsort( leaderboard, local_Population, sizeof leaderboard[0], Sort_rules );//��������Ϣ��������

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