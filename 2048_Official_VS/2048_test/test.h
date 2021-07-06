#pragma once
#include"quan_ju.h"
#include"num_rand.h"
#include"Ranking_System.h"
#include"move.h"
#include"Pause_System.h"

//打印函数，用于显示二维数组内容
void print(int shu_zu[4][4],Leaderboard people,int mode) {

    if(mode==1)
       printf( "GameNmae:%s\tGameStep:%d\n", people.name, people.game_Step );
    else
        printf( "GameNmae:%s\tMaxNum:%d\n", people.name, people.MaxNum );

    for (int i = 0; i < 4; i++) {

        for (int j = 0; j < 4; j++) {

            printf("%d\t", shu_zu[i][j]);

        }

        printf("\n");

    }
    printf( "Please input your operation(P is pause):\n" );
}

////测试上下左右的移动问题
//void test_move_up() {
//    for (int i = 0; i < 4; i++) {
//
//        for (int j = 0; j < 4; j++) {
//
//            wan_jia[i][j] = 2;
//
//        }
//
//    }
//    down_move();
//    print(wan_jia);
//    left_move();
//    print(wan_jia);
//    right_move();
//    print(wan_jia);
//
//}

//测试是否判定可以移动问题
//void test_move() {
//    for (int i = 0; i < 4; i++) {
//
//        for (int j = 0; j < 4; j++) {
//
//            wan_jia[i][j] = 2;
//
//        }
//
//    }
//    if (move_pan_ding('w')) {
//        up_move();
//        print(wan_jia);
//        printf("\n");
//
//    }
//
//    if (move_pan_ding('w')) {
//        up_move();
//        print(wan_jia);
//        printf("\n");
//
//    }
//
//    if (move_pan_ding('w')) {
//        up_move();
//        print(wan_jia);
//        printf("\n");
//
//    }
//
//
//}
//void rand_test() {
//    for (int i = 0; i < 15; i++) {
//
//        get_blank(wan_jia);
//
//        print(wan_jia);
//    }
//}

void test_round(Leaderboard people,int mode) {

    system( "cls" );

    char operation;
    
    print(wan_jia,people,mode);
    while (scanf("\n%c", &operation)) {
        if (operation == 'P' || operation == 'p') {

            Pause_system( wan_jia, people ,mode);
            return;
        }

        if (move_pan_ding(operation,mode,people.MaxNum)) {

            switch (operation) {

            case 'w': case 'W': up_move();    break;

            case 's': case 'S': down_move();  break;

            case 'a': case 'A': left_move();  break;

            case 'd': case 'D': right_move(); break;

            }

            get_blank(wan_jia);
            people.game_Step++;

            system("cls");
            
            print(wan_jia,people,mode);
        }
        else {
            printf("You got a bad way,try again!\n");

        }

        if (!move_pan_ding('w',mode,people.MaxNum) && !move_pan_ding('s', mode, people.MaxNum ) && !move_pan_ding('a', mode, people.MaxNum ) && !move_pan_ding('d', mode, people.MaxNum )) {
            printf("\nGame Over!\n");

            Update_Leaderboard( people,mode );

            Sleep( 5000 );
            system( "cls" );

            return;
        }
           
         

    }
}
