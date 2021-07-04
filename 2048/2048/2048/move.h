#include<stdio.h>

//push表示向上移动的过程
void up(int shu_zu[4][4]) {
	for (int i = 0; i < 4; i++) {
		
 		int tmp[4] = {}, p = 0, res=0;//tmp和p联合起来模拟简单的数组双端队列，保留数组特性来实现赋值 res是对于第i列shu_zu的指针

		for (int j = 0; j < 4; j++) {
		
			if(shu_zu[j][i])
				tmp[p++] = shu_zu[j][i];
		
		}

		for (int j = 1; j < p; j++) {
			
			if (tmp[j] == tmp[j - 1]) {

				tmp[j-1] = tmp[j] * 2;
				tmp[j] = 0;
			}
		}
		for (int j = 0; j < 4; j++) {
			shu_zu[j][i] = 0;
			if (tmp[j])
				shu_zu[res++][i] = tmp[j];
		}
		
	}
}

//down表示向下移动的过程
void down(int shu_zu[4][4]) {
	for (int i = 0; i < 4; i++) {

		int tmp[4] = {}, p = 0, res = 3;

		for (int j = 3; j >= 0; j--) {

			if (shu_zu[j][i])
				tmp[p++] = shu_zu[j][i];

		}

		for (int j = 1; j < p; j++) {

			if (tmp[j] == tmp[j - 1]) {

				tmp[j - 1] = tmp[j] * 2;
				tmp[j] = 0;
			}
		}
		for (int j = 3; j >= 0; j--) {
			shu_zu[j][i] = 0;
			if (tmp[j])
				shu_zu[res--][i] = tmp[j];
		}

	}
}

//left表示向左移动的过程
void left(int shu_zu[4][4]) {
	for (int i = 0; i < 4; i++) {

		int tmp[4] = {}, p = 0, res = 0;

		for (int j = 0; j < 4; j++) {

			if (shu_zu[i][j])
				tmp[p++] = shu_zu[i][j];

		}

		for (int j = 1; j < p; j++) {

			if (tmp[j] == tmp[j - 1]) {

				tmp[j - 1] = tmp[j] * 2;
				tmp[j] = 0;
			}
		}
		for (int j = 0; j < 4; j++) {
			shu_zu[i][j] = 0;
			if (tmp[j])
				shu_zu[i][res++] = tmp[j];
		}

	}
}

//right表示向下移动的过程
void right(int shu_zu[4][4]) {
	for (int i = 0; i < 4; i++) {

		int tmp[4] = {}, p = 0, res = 3;

		for (int j = 3; j >= 0; j--) {

			if (shu_zu[i][j])
				tmp[p++] = shu_zu[i][j];

		}

		for (int j = 1; j < p; j++) {

			if (tmp[j] == tmp[j - 1]) {

				tmp[j - 1] = tmp[j] * 2;
				tmp[j] = 0;
			}
		}
		for (int j = 3; j >= 0; j--) {
			shu_zu[i][j] = 0;
			if (tmp[j])
				shu_zu[i][res--] = tmp[j];
		}

	}
}