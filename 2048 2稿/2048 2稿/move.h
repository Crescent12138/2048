#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<stdbool.h>
#include<assert.h>
#include<math.h>
#include<Windows.h>
#include<stddef.h>
#include <corecrt_malloc.h>
#include"quan_ju.h"

//push��ʾ�����ƶ��Ĺ���
void up_move() {
	for (int i = 0; i < 4; i++) {

		int tmp[4] = {}, p = 0, res = 0;//tmp��p��������ģ��򵥵�����˫�˶��У���������������ʵ�ָ�ֵ res�Ƕ��ڵ�i��shu_zu��ָ��

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

//down��ʾ�����ƶ��Ĺ���
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
		}
		for (int j = 3; j >= 0; j--) {
			wan_jia[j][i] = 0;
			if (tmp[j])
				wan_jia[res--][i] = tmp[j];
		}

	}
}

//left��ʾ�����ƶ��Ĺ���
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

//�����˶�
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
		for (int j = 3; j >= 0; j--) {
			wan_jia[i][j] = 0;
			if (tmp[j])
				wan_jia[i][res--] = tmp[j];
		}

	}
}

//push��ʾ�����ƶ��Ĺ���
void up_move_mo(int zhuang_tai[4][4]) {
	for (int i = 0; i < 4; i++) {

		int tmp[4] = {}, p = 0, res = 0;//tmp��p��������ģ��򵥵�����˫�˶��У���������������ʵ�ָ�ֵ res�Ƕ��ڵ�i��shu_zu��ָ��

		for (int j = 0; j < 4; j++) {

			if (zhuang_tai[j][i])
				tmp[p++] = zhuang_tai[j][i];

		}

		for (int j = 1; j < p; j++) {

			if (tmp[j] == tmp[j - 1]) {

				tmp[j - 1] = tmp[j] * 2;
				tmp[j] = 0;
			}
		}
		for (int j = 0; j < 4; j++) {
			zhuang_tai[j][i] = 0;
			if (tmp[j])
				zhuang_tai[res++][i] = tmp[j];
		}

	}
}

//down��ʾ�����ƶ��Ĺ���
void down_move_mo(int zhuang_tai[4][4]) {
	for (int i = 0; i < 4; i++) {

		int tmp[4] = {}, p = 0, res = 3;

		for (int j = 3; j >= 0; j--) {

			if (zhuang_tai[j][i])
				tmp[p++] = zhuang_tai[j][i];

		}

		for (int j = 1; j < p; j++) {

			if (tmp[j] == tmp[j - 1]) {

				tmp[j - 1] = tmp[j] * 2;
				tmp[j] = 0;
			}
		}
		for (int j = 3; j >= 0; j--) {
			zhuang_tai[j][i] = 0;
			if (tmp[j])
				zhuang_tai[res--][i] = tmp[j];
		}

	}
}

//left��ʾ�����ƶ��Ĺ���
void left_move_mo(int zhuang_tai[4][4]) {
	for (int i = 0; i < 4; i++) {

		int tmp[4] = {}, p = 0, res = 0;

		for (int j = 0; j < 4; j++) {

			if (zhuang_tai[i][j])
				tmp[p++] = zhuang_tai[i][j];

		}

		for (int j = 1; j < p; j++) {

			if (tmp[j] == tmp[j - 1]) {

				tmp[j - 1] = tmp[j] * 2;
				tmp[j] = 0;
			}
		}
		for (int j = 0; j < 4; j++) {
			zhuang_tai[i][j] = 0;
			if (tmp[j])
				zhuang_tai[i][res++] = tmp[j];
		}

	}
}
//right��ʾ�����ƶ��Ĺ���
void right_move_mo(int zhuang_tai[4][4]) {
	for (int i = 0; i < 4; i++) {

		int tmp[4] = {}, p = 0, res = 3;

		for (int j = 3; j >= 0; j--) {

			if (zhuang_tai[i][j])
				tmp[p++] = zhuang_tai[i][j];

		}

		for (int j = 1; j < p; j++) {

			if (tmp[j] == tmp[j - 1]) {

				tmp[j - 1] = tmp[j] * 2;
				tmp[j] = 0;
			}
		}
		for (int j = 3; j >= 0; j--) {
			zhuang_tai[i][j] = 0;
			if (tmp[j])
				zhuang_tai[i][res--] = tmp[j];
		}

	}
}


bool move_pan_ding(char step) {
	int tmp[4][4] = {};
	bool ok = 0;
	for (int i = 0; i < 4; i++) {

		for (int j = 0; j < 4; j++) {

			tmp[i][j] = wan_jia[i][j];

		}
	}

	switch (step) {
	case 'w':
		up_move_mo(tmp);  break;

	case 's':
		down_move_mo(tmp); break;

	case 'a':
		left_move_mo(tmp); break;

	case 'd':
		right_move_mo(tmp); break;

	}
	for (int i = 0; i < 4; i++) {

		for (int j = 0; j < 4; j++)
		{
			if (tmp[i][j] != wan_jia[i][j])ok = 1;
		}

	}
	if (ok)
		return true;
	else return false;
}