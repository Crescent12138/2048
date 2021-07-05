#pragma once
#include"quan_ju.h"
#include"num_rand.h"
#include"Ranking_System.h"
#include"move.h"
#include"Pause_System.h"

//打印函数，用于显示二维数组内容
void print(int shu_zu[4][4],Leaderboard people) {

    printf( "GameNmae:%s\tGameStep:%d\n", people.name, people.game_Step );

    for (int i = 0; i < 4; i++) {

        for (int j = 0; j < 4; j++) {

            printf("%d\t", shu_zu[i][j]);

        }

        printf("\n");

    }
    printf( "Please input your operation(P is pause):" );
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

void test_round(Leaderboard people) {

    system( "cls" );

    char operation;
    
    print(wan_jia,people);
    while (scanf("\n%c", &operation)) {
        if (operation == 'P' || operation == 'p') {

            Pause_system( wan_jia, people );
            return;
        }

        if (move_pan_ding(operation)) {

            switch (operation) {

            case 'w': case 'W': up_move();    break;

            case 's': case 'S': down_move();  break;

            case 'a': case 'A': left_move();  break;

            case 'd': case 'D': right_move(); break;

            }

            get_blank(wan_jia);
            people.game_Step++;

            system("cls");
            
            print(wan_jia,people);
        }
        else {
            printf("You got a bad way,try again!\n");

        }

        if (!move_pan_ding('w') && !move_pan_ding('s') && !move_pan_ding('a') && !move_pan_ding('d')) {
            printf("\nGame Over!\n");
            Update_Leaderboard( people );
            Sleep( 1000 );
            system( "cls" );
            return;
        }
           
         

    }
}
