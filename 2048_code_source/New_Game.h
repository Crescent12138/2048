#pragma once
#include"quan_ju.h"
#include"Ranking_System.h"
#include"test.h"

void new_game() {
	Leaderboard people;
	people.game_Step = 0;//��ʼ����Ϸ����
	people.MaxNum = 0;//��ʼ�����ֵ

	system( "cls" );
	

	string step;//ѡ��
	while (1) {
		printf( "1.��ͨģʽ\n2.�޾�ģʽ\n" );
		printf( "Please choose game mode:" );
		cin >> step;
		if (step != "1" && step != "2") {
			setcolor( 4, 0 );
			printf( "Your input is wrong!\nPlease input again!\n" );
			Sleep( 1000 );
			system( "cls" );
			setcolor( 11, 0 );
			continue;
			
		}
		break;
		
	}
	system( "cls" );
	printf( "Please Input Your Endlish Game Name:" );
	cin >> people.name;//�����µ���Ϸ��ɫ

	Sleep( 1000 );

	system( "cls" );
	printf( "The game begins...." );
	Sleep( 1000 );

	memset( wan_jia, 0, sizeof wan_jia );//��ʼ����Ϸ��ͼ
	get_blank( wan_jia );//����һ���������

	switch (step[0]) {
	case '1':test_round( people, 1 ); return;
	case '2':test_round( people, 2 ); return;
	}
}