#pragma once
#include"move.h"
#include"quan_ju.h"
#include<stdio.h>

//��������
int get_random(int number_size) {
    srand((unsigned)time(NULL));
    int res = (rand()) % number_size;
    return res;
}

//��һ�������2��4 װ����ֵΪ0��shu_zu��
void get_blank(int shu_zu[4][4]) {

    struct node {

        int x, y;

    }count[16], hash;

    int p = 0;
    for (int i = 0; i < 4; i++) {

        for (int j = 0; j < 4; j++) {

            if (!shu_zu[i][j]) {

                count[p].x = i, count[p].y = j, p++;

            }

        }

    }

    int pos = get_random(p);

    int num_pos = get_random(2);

    shu_zu[count[pos].x][count[pos].y] = num_pos * 2 + 2;

}

