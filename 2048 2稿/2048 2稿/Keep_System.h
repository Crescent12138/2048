#pragma once
#include"quan_ju.h"
#include"Ranking_System.h"
#include"test.h"


void Keep_Playing() {

	FILE* fp = NULL;//�ļ�ָ��->�浵
	fp = fopen( "Historical_Archive.txt", "r" );

	if (fp == NULL) {//��ȡ������Ϣ����

		printf( "Local archive not found!\n" );

		getch();//��ͣ����
		system( "cls" );//�����Ļ������
		return;
	}
	int symple = 0;//��¼��ȡ���ݣ��жϱ�����û�д浵

	Leaderboard people;
	fscanf( fp, "%s %d", people.name, &people.game_Step );

	for (int i = 0; i < 4; i++) {

		for (int j = 0; j < 4; j++) {

			fscanf( fp, "%d", &wan_jia[i][j] );//ȫ�ֱ���
			if (wan_jia[i][j] != 0)//��������Ч����
				symple = 1;
		}
	}
	if (!symple) {//û����Ч����

		printf( "Local archive not found!\n" );

		Sleep( 1000 );//��ͣ����

		system( "cls" );//�����Ļ

		return;
	}

	//��������Ч���ݵ�ʱ��

	test_round( people );

	fclose( fp );
}