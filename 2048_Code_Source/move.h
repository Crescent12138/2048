#pragma once

#include"quan_ju.h"
//push表示向上移动的过程
void up_move() {
	for (int i = 0; i < 4; i++) {

		int tmp[4] = {}, p = 0, res = 0;//tmp和p联合起来模拟简单的数组双端队列，保留数组特性来实现赋值 res是对于第i列shu_zu的指针

		for (int j = 0; j < 4; j++) {

			if (wan_jia[j][i])
				tmp[p++] = wan_jia[j][i];

		}

		for (int j = 1; j < p; j++) {

			if (tmp[j] == tmp[j - 1]) {

				tmp[j - 1] = tmp[j] * 2;
				tmp[j] = 0;
			}
		}
		for (int j = 0; j < 4; j++) {
			wan_jia[j][i] = 0;
			if (tmp[j])
				wan_jia[res++][i] = tmp[j];
		}

	}
}

//down表示向下移动的过程
void down_move() {
	for (int i = 0; i < 4; i++) {

		int tmp[4] = {}, p = 0, res = 3;

		for (int j = 3; j >= 0; j--) {

			if (wan_jia[j][i])
				tmp[p++] = wan_jia[j][i];

		}

		for (int j = 1; j < p; j++) {

			if (tmp[j] == tmp[j - 1]) {

				tmp[j - 1] = tmp[j] * 2;
				tmp[j] = 0;
			}
			//wan_jia[j][i] = 0;
		}
		for (int j = 0; j < 4; j++)wan_jia[j][i] = 0;

		for (int j = 0; j < 4; j++) {
			//wan_jia[j][i] = 0;
			if (tmp[j])
				wan_jia[res--][i] = tmp[j];
		}

	}
}

//left表示向左移动的过程
void left_move() {
	for (int i = 0; i < 4; i++) {

		int tmp[4] = {}, p = 0, res = 0;

		for (int j = 0; j < 4; j++) {

			if (wan_jia[i][j])
				tmp[p++] = wan_jia[i][j];

		}

		for (int j = 1; j < p; j++) {

			if (tmp[j] == tmp[j - 1]) {

				tmp[j - 1] = tmp[j] * 2;
				tmp[j] = 0;
			}
		}
		for (int j = 0; j < 4; j++) {
			wan_jia[i][j] = 0;
			if (tmp[j])
				wan_jia[i][res++] = tmp[j];
		}

	}
}

//向右运动
void right_move() {
	for (int i = 0; i < 4; i++) {

		int tmp[4] = {}, p = 0, res = 3;

		for (int j = 3; j >= 0; j--) {

			if (wan_jia[i][j])
				tmp[p++] = wan_jia[i][j];

		}

		for (int j = 1; j < p; j++) {

			if (tmp[j] == tmp[j - 1]) {

				tmp[j - 1] = tmp[j] * 2;
				tmp[j] = 0;
			}
		}
		for (int j = 0; j < 4; j++)wan_jia[i][j] = 0;

		for (int j = 0; j < 4; j++) {
			//wan_jia[i][j] = 0;
			if (tmp[j])
				wan_jia[i][res--] = tmp[j];
		}

	}
}




bool move_pan_ding(char step,int mode,int &MaxNum) {
	int tmp[4][4] = {};
	bool ok = 0;
	
	for (int i = 0; i < 4; i++) {

		for (int j = 0; j < 4; j++) {

			tmp[i][j] = wan_jia[i][j];
			MaxNum = max( MaxNum, wan_jia[i][j] );
		}
	}
	if (mode==1&&MaxNum >= 2048) {
		//达到条件，结束游戏
		return false;
	}
	switch (step) {
	case 'w': case 'W':case 72: up_move();    break;

	case 's': case 'S': case 80: down_move();  break;

	case 'a': case 'A': case 75:  left_move();  break;

	case 'd': case 'D': case 77:  right_move(); break;

	}
	for (int i = 0; i < 4; i++) {

		for (int j = 0; j < 4; j++)
		{
			if (wan_jia[i][j] != tmp[i][j])
				ok = 1;

			
			wan_jia[i][j] = tmp[i][j];
		}

	}
	return ok;
}