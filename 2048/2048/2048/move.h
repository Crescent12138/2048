#include<stdio.h>

//push��ʾ�����ƶ��Ĺ���
void up(int shu_zu[4][4]) {
	for (int i = 0; i < 4; i++) {
		
 		int tmp[4] = {}, p = 0, res=0;//tmp��p��������ģ��򵥵�����˫�˶��У���������������ʵ�ָ�ֵ res�Ƕ��ڵ�i��shu_zu��ָ��

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

//down��ʾ�����ƶ��Ĺ���
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

//left��ʾ�����ƶ��Ĺ���
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

//right��ʾ�����ƶ��Ĺ���
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