#pragma once
#include"move.h"
#include"quan_ju.h"
#include"num_rand.h"
#include<stdio.h>

//打印函数，用于显示二维数组内容
void print(int shu_zu[4][4]) {

    for (int i = 0; i < 4; i++) {

        for (int j = 0; j < 4; j++) {

            printf("%d\t", shu_zu[i][j]);

        }

        printf("\n");

    }

}

////测试上下左右的移动问题
void test_move_up() {
    for (int i = 0; i < 4; i++) {

        for (int j = 0; j < 4; j++) {

            wan_jia[i][j] = 2;

        }

    }
    down_move();
    print(wan_jia);
    left_move();
    print(wan_jia);
    right_move();
    print(wan_jia);

}

//测试是否判定可以移动问题
void test_move() {
    for (int i = 0; i < 4; i++) {

        for (int j = 0; j < 4; j++) {

            wan_jia[i][j] = 2;

        }

    }
    if (move_pan_ding('w')) {
        up_move();
        print(wan_jia);
        printf("\n");

    }

    if (move_pan_ding('w')) {
        up_move();
        print(wan_jia);
        printf("\n");

    }

    if (move_pan_ding('w')) {
        up_move();
        print(wan_jia);
        printf("\n");

    }


}
void rand_test() {
    for (int i = 0; i < 15; i++) {

        get_blank(wan_jia);

        print(wan_jia);
    }
}

void test_round() {
    char operation;
    get_blank(wan_jia);
    print(wan_jia);
    while (scanf("%c", &operation)) {
        if (move_pan_ding(operation)) {
            switch (operation) {
            case 'w': up_move();   break;
            case 's': down_move(); break;
            case 'a':left_move();  break;
            case 'd':right_move(); break;
            }
            get_blank(wan_jia);
            print(wan_jia);
        }
           
         

    }
}
