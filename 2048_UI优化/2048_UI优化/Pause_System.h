#pragma once
#pragma once
//ChinsePeach
#include"quan_ju.h"
#include"Ranking_System.h"
#include"move.h"
#include"test.h"

void Pause_system(int shu_zu[4][4],Leaderboard people,int mode) {

	FILE* fp = NULL;//�ļ�ָ��->�浵
	if (mode == 1)
		fp = fopen( "Historical_Archive_Ori.txt", "w+" );//�򿪿ɶ�/д�ļ������ļ��������ļ�������Ϊ�㣬�����ļ����ݻ���ʧ�����ļ��������򴴽����ļ���
	else 
		fp=fopen( "Historical_Archive_endless.txt", "w+" );

	if (fp == NULL) {//��ȡ������Ϣ����

		//setcolor( 4, 0 );//bug��ɫ
		
		printf("There is a bug in reading information, please restart and try.\n"
			"If loading fails all the time, please contact the administrator:\n"
			"QQ��2986325137 / 1272607918\n");
		
		//setcolor( 11, 0 );//ϵͳ��ɫ

		getch();//��ͣ����
		system("cls");//�����Ļ������
		return;
	}
	if(mode==1)
		fprintf( fp, "%s %d\n", people.name, people.game_Step );
	else
		fprintf( fp, "%s %d\n", people.name, people.MaxNum );

	//����˴���Ϸ�ĵ�ͼ
	for (int i = 0; i < 4; i++) {

		for (int j = 0; j < 4; j++) {
			fprintf(fp, "%d ", shu_zu[i][j]);
		}
		fprintf(fp, "\n");
	}

	printf("Saved successfully!\nPress any key to return to the main menu.\n");//�������ɹ�����

	getch();//��ͣ����

	system("cls");//�����Ļ

	fclose(fp);//�ر�ָ�ļ���

	return;
}
