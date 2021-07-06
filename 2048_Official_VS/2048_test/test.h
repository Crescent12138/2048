#pragma once
#include"quan_ju.h"
#include"num_rand.h"
#include"Ranking_System.h"
#include"move.h"
#include"Pause_System.h"

VOID setcolor( UINT uFore, UINT uBack ) {//更改背景颜色
    HANDLE handle = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute( handle, uFore + uBack * 0x10 );
    /*0 = 黑色       8 = 灰色
    1 = 蓝色       9 = 淡蓝色
    2 = 绿色       10/A = 淡绿色
    3 = 浅绿色     11/B = 淡浅绿色
    4 = 红色       12/C = 淡红色
    5 = 紫色       13/D = 淡紫色
    6 = 黄色       14/E = 淡黄色
    7 = 白色       15/F = 亮白色*/
}

//打印函数，用于显示二维数组内容
void print(int shu_zu[4][4],Leaderboard people,int mode) {

    COORD pos = { 0, 3 };
    HANDLE out = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleCursorPosition( out, pos );
    if(mode==1)
       printf( "GameNmae:%s\tGameStep:%d\n\n", people.name, people.game_Step );
    else
        printf( "GameNmae:%s\tMaxNum:%d\n\n", people.name, people.MaxNum );
   // SetPos( 0, 10 );
    
    for (int i = 0; i < 4; i++) {

        for (int j = 0; j < 4; j++) {
            switch (shu_zu[i][j]) {
            case 0:setcolor( 7, 7 ); break;
            case 2:setcolor( 14, 7 ); break;
            case 4:setcolor( 6, 7 ); break;
            case 8:setcolor( 1, 7 ); break;
            case 16:setcolor( 3, 7 ); break;
            case 32:setcolor( 2, 7 ); break;
            case 64:setcolor( 8, 7 ); break;
            case 128:setcolor( 4, 7 ); break;
            case 256:setcolor( 12, 7 ); break;
            case 512:setcolor( 13, 7 ); break;
            case 1024:setcolor( 5, 7 ); break;
            case 2048:setcolor( 9, 7 ); break;
            case 4096:setcolor( 15, 7 ); break;
            }
            printf("%d\t", shu_zu[i][j]);

        }

        printf("\n\n");

    }
    setcolor( 11, 0 );
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
    while (operation=getch()) {
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
