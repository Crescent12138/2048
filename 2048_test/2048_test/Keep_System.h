#pragma once
#include"quan_ju.h"
#include"Ranking_System.h"
#include"test.h"


void Keep_Playing( int mode ) {

	FILE* fp = NULL;//�ļ�ָ��->�浵
	if (mode == 1)
		fp = fopen( "Historical_Archive_Ori.txt", "r" );
	else 
		fp = fopen( "Historical_Archive_endless.txt", "r" );
	
	if (fp == NULL) {//��ȡ������Ϣ����

		printf( "Local archive not found!\n" );

		Sleep( 1000 );//��ͣ����
		system( "cls" );//�����Ļ������
		return;
	}

	int symple = 0;//��¼��ȡ���ݣ��жϱ�����û�д浵

	Leaderboard people;
	if(mode==1)
		fscanf( fp, "%s %d", people.name, &people.game_Step );
	else 
		fscanf( fp, "%s %d", people.name, &people.MaxNum );

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

	test_round( people ,mode);

	fclose( fp );
}

void Keep_Playing_GameMode() {

	system( "cls" );

	
	while (1) {
		
		printf( "1.��ͨģʽ\n2.�޾�ģʽ\n" );
		printf( "Please choose game pattern:" );

		string step;//ѡ��
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
