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
#include"move.h"
#include"Ranking_System.h"
//移动函数装里面了，为了体现代码不是cv的，所以做了一点小小的防护
// 
// ----------------------------------------------------------------------
// 
//  ————        /\         ————      ———  -------    -       
// |               /  \        |       |       |     |          |       
// |              /    \       |       |       |     |          |       
//  ————     /______\      |————       |     |------    |       
//          |   /        \     |        \      |     |          |       
//          |  /          \    |         \     |     |          |       
//  ————  /            \   |          \  ———  --------   ---------  
// 
// ----------------------------------------------------------------------
// 
// 以上为我大概认为用的到的头文件，包括常用宏定义，字符串，输出入，布尔判定，时间，算法随机，断言，数学,自制移动函数

//这里是菜单
void menu() {
    printf("here is 2048.\n");
    system("pause");
}

int wan_jia[4][4] = {};

//判定是否可移动，若不可则继续读取数字
bool move_pan_ding( char step ) {
    int tmp[4][4] = {};
    bool ok = 0;
    for (int i = 0; i < 4; i++) {
        
        for (int j = 0; j < 4; j++) {
            
            tmp[i][j] = wan_jia[i][j];

        }
    }

    switch (step){
    case 'w': 
        up(tmp)
        
        
        
        ; break;

    case 's': 
        down(tmp)
        
        
        ; break;

    case 'a': 
        
        
        
        
        ; break;

    case 'd': 
        
        
        
        ; 
        
        break;

    }
    return 1;
}

void print(int shu_zu[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d\t",shu_zu[i][j]);
        }
        printf("\n");
    }
}
void test() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            wan_jia[i][j] = 2;
        }
    }
    down(wan_jia);
    print(wan_jia);
    left(wan_jia);
    print(wan_jia);
    right(wan_jia);
    print(wan_jia);

}
int main() {
   // menu();
   
    Print_Leaderboard();
    

}
