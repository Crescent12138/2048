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
void print( int shu_zu[4][4], Leaderboard people, int mode ) {

   /* COORD pos = { 0, 3 };
    HANDLE out = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleCursorPosition( out, pos );*/
    /*if (mode == 1)
        printf( "GameNmae:%s\tGameStep:%d\n\n", people.name, people.game_Step );
    else
        printf( "GameNmae:%s\tMaxNum:%d\n\n", people.name, people.MaxNum );*/
    // SetPos( 0, 10 );
  /*  for (int i = 0; i < 4; i++) printf( "_________" );
    printf( "\n" );*/

    

    //for (int i = 0; i < 4; i++) {

        /*0 = 黑色       8 = 灰色
         1 = 蓝色       9 = 淡蓝色
         2 = 绿色       10/A = 淡绿色
         3 = 浅绿色     11/B = 淡浅绿色
         4 = 红色       12/C = 淡红色
         5 = 紫色       13/D = 淡紫色
         6 = 黄色       14/E = 淡黄色
         7 = 白色       15/F = 亮白色
         */

        /*for (int j = 0; j < 4; j++) {
            setcolor( 11, 0 );
            printf( "|" );
            switch (shu_zu[i][j]) {

            case 0:setcolor( 7, 0 ); break;

            case 2:setcolor( 14, 0 ); break;

            case 4:setcolor( 6, 0 ); break;

            case 8:setcolor( 1, 0 ); break;

            case 16:setcolor( 3, 0 ); break;

            case 32:setcolor( 2, 0 ); break;

            case 64:setcolor( 8, 0 ); break;

            case 128:setcolor( 4, 0 ); break;

            case 256:setcolor( 12, 0 ); break;

            case 512:setcolor( 13, 0 ); break;

            case 1024:setcolor( 5, 0 ); break;

            case 2048:setcolor( 9, 0 ); break;

            case 4096:setcolor( 15, 0 ); break;
            }

            printf( "%4d    ", shu_zu[i][j] );

        }

        setcolor( 11, 0 );

        printf( "|\n" );



        for (int j = 0; j < 4; j++) {

            printf( "|________" );
        }

        printf( "|\n" );*/
        IMAGE i0, i2, i4, i8, i16, i32, i64, i128, i256, i512, i1024, i2048, i4096, i8192;
        
        for (size_t i = 0; i < 4; i++) {

            for (size_t j = 0; j < 4; j++) {

                switch (wan_jia[i][j]) {

                case 0: {
                    loadimage( &i0, _T( "./Image/0.jpg" ), 150, 150 );
                    putimage( 50 + 155 * j, 130 + 155 * i, &i0,SRCCOPY );
                    break;
                }
                case 2: {
                    loadimage( &i2, _T( "./Image/2.jpg" ), 150, 150 );
                    putimage( 50 + 155 * j, 130 + 155 * i, &i2, SRCCOPY );
                    break;
                }
                case 4: {
                    loadimage( &i4, _T( "./Image/4.jpg" ), 150, 150 );
                    putimage( 50 + 155 * j, 130 + 155 * i, &i4, SRCCOPY );
                    break;
                }
                case 8: {
                    loadimage( &i8, _T( "./Image/8.jpg" ), 150, 150 );
                    putimage( 50 + 155 * j, 130 + 155 * i, &i8, SRCCOPY );
                    break;
                }
                case 16: {
                    loadimage( &i16, _T( "./Image/16.jpg" ), 150, 150 );
                    putimage( 50 + 155 * j, 130 + 155 * i, &i16, SRCCOPY );
                    break;
                }
                case 32: {
                    loadimage( &i32, _T( "./Image/32.jpg" ), 150, 150 );
                    putimage( 50 + 155 * j, 130 + 155 * i, &i32, SRCCOPY );
                    break;
                }
                case 64: {
                    loadimage( &i64, _T( "./Image/64.jpg" ), 150, 150 );
                    putimage( 50 + 155 * j, 130 + 155 * i, &i64, SRCCOPY );
                    break;
                }
                case 128: {
                    loadimage( &i128, _T( "./Image/128.jpg" ), 150, 150 );
                    putimage( 50 + 155 * j, 130 + 155 * i, &i128, SRCCOPY );
                    break;
                }
                case 256: {
                    loadimage( &i256, _T( "./Image/256.jpg" ), 150, 150 );
                    putimage( 50 + 155 * j, 130 + 155 * i, &i256, SRCCOPY );
                    break;
                }
                case 512: {
                    loadimage( &i512, _T( "./Image/512.jpg" ), 150, 150 );
                    putimage( 50 + 155 * j, 130 + 155 * i, &i512, SRCCOPY );
                    break;
                }
                case 1024: {
                    loadimage( &i1024, _T( "./Image/1024.jpg" ), 150, 150 );
                    putimage( 50 + 155 * j, 130 + 155 * i, &i1024, SRCCOPY );
                    break;
                }
                case 2048: {
                    loadimage( &i2048, _T( "./Image/2048.jpg" ), 150, 150 );
                    putimage( 50 + 155 * j, 130 + 155 * i, &i2048, SRCCOPY );
                    break;
                }
                case 4096: {
                    loadimage( &i4096, _T( "./Image/4096.jpg" ), 150, 150 );
                    putimage( 50 + 155 * j, 130 + 155 * i, &i4096, SRCCOPY );
                    break;
                }
                case 8192: {
                    loadimage( &i8192, _T( "./Image/8192.jpg" ), 150, 150 );
                    putimage( 50 + 155 * j, 130 + 155 * i, &i8192, SRCCOPY );
                    break;
                }
                default:break;
                }
            }
            printf( "\n" );
        }

    //}
  /*  setcolor( 11, 0 );
    printf( "Please input your operation(P is pause):\n" );*/
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
void print_score( Leaderboard people,int mode )//打印得分
{
    setbkcolor( RGB( 253, 236, 166 ) ); // set the background colour
    settextstyle( 120, 50, _T( "Times New Roman" ) ); // set the sytle
    settextcolor( BLUE ); // set the colour
    TCHAR s01[5], s02[5], s03[5], s04[5], s05[5];
    int score;
    if (mode == 1)
        score = people.game_Step;
    else
        score = people.MaxNum;
    swprintf_s( s01, _T( "%d" ), score % 10 );
    swprintf_s( s02, _T( "%d" ), (score / 10) % 10 );
    swprintf_s( s03, _T( "%d" ), (score / 100) % 10 );
    swprintf_s( s04, _T( "%d" ), (score / 1000) % 10 );
    swprintf_s( s05, _T( "%d" ), (score / 10000) % 10 ); // change into string first
    outtextxy( 780, 300, s05 );
    outtextxy( 844, 300, s04 );
    outtextxy( 908, 300, s03 );
    outtextxy( 972, 300, s02 );
    outtextxy( 1036, 300, s01 ); // print
}
void test_round(Leaderboard people,int mode) {

    system( "cls" );
    IMAGE Board;
    initgraph( 1200, 800 );
    
    if (mode == 1)
        loadimage( 0, _T( "./Image/Board_Or.jpg" ), 1200, 800 );
    else 
        loadimage( 0, _T( "./Image/Board_End.jpg" ), 1200, 800 );

    char operation;
    
    print(wan_jia,people,mode);
    print_score(people,mode);
    while (operation=getch()) {
        if (operation == ' ' || operation == ' ') {
            closegraph();
            Pause_system( wan_jia, people ,mode);
            return;
        }

        if (move_pan_ding(operation,mode,people.MaxNum)) {

            switch (operation) {

            case 'w': case 'W' :case 72: up_move();    break;

            case 's': case 'S': case 80: down_move();  break;

            case 'a': case 'A': case 75:  left_move();  break;

            case 'd': case 'D': case 77:  right_move(); break;

            }

            get_blank(wan_jia);

            people.game_Step++;

            system("cls");
            
            print(wan_jia,people,mode);
            print_score(people,mode);
        }
        

        if (!move_pan_ding('w',mode,people.MaxNum) && !move_pan_ding('s', mode, people.MaxNum ) && !move_pan_ding('a', mode, people.MaxNum ) && !move_pan_ding('d', mode, people.MaxNum )) {
            
            IMAGE Over;
        
            loadimage( &Over, _T( "./Image/over.jpg" ), 320, 100 );
            putimage( 780, 500, &Over );
            Update_Leaderboard( people,mode );

            Sleep( 5000 );
            closegraph();
            system( "cls" );
           
            return;
        }
           
         

    }
}
