#pragma once
#pragma once
//ChinsePeach
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<stdbool.h>
#include<assert.h>
#include<math.h>
#include<Windows.h>
#include<stddef.h>
#include"quan_ju.h"
//#include <corecrt_malloc.h>
#include"move.h"
#include"test.h"
#include"Ranking_System.h"
void Pause_system(int shu_zu[4][4]) {

	FILE* fp = NULL;//�ļ�ָ��->�浵
	fp = fopen("Historical_Archive.txt", "w+");//�򿪿ɶ�/д�ļ������ļ��������ļ�������Ϊ�㣬�����ļ����ݻ���ʧ�����ļ��������򴴽����ļ���

	if (fp == NULL) {//��ȡ������Ϣ����

		printf("There is a bug in reading information, please restart and try.\n"
			"If loading fails all the time, please contact the administrator:\n"
			"QQ��2986325137 / 1272607918\n");

		getch();//��ͣ����
		system("cls");//�����Ļ������
		return;
	}

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
void Keep_Playing() {

	FILE* fp = NULL;//�ļ�ָ��->�浵
	fp = fopen("Historical_Archive.txt", "w+");//�򿪿ɶ�/д�ļ������ļ��������ļ�������Ϊ�㣬�����ļ����ݻ���ʧ�����ļ��������򴴽����ļ���

	if (fp == NULL) {//��ȡ������Ϣ����

		printf("There is a bug in reading information, please restart and try.\n"
			"If loading fails all the time, please contact the administrator:\n"
			"QQ��2986325137 / 1272607918\n");

		getch();//��ͣ����
		system("cls");//�����Ļ������
		return;
	}
	int symple = 0;//��¼��ȡ���ݣ��жϱ�����û�д浵
	for (int i = 0; i < 4; i++) {

		for (int j = 0; j < 4; j++) {

			fscanf(fp, "%d", &wan_jia[i][j]);//ȫ�ֱ���
			if (wan_jia[i][j] != 0)//��������Ч����
				symple = 1;
		}
	}
	if (!symple) {//û����Ч����

		printf("Local archive not found!\nPress any key to return to the main menu!\n");

		getch();//��ͣ����

		system("cls");//�����Ļ

		return;
	}

	//��������Ч���ݵ�ʱ��

	test_round();

	fclose(fp);
}