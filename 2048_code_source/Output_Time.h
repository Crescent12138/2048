#pragma once
#include"quan_ju.h"

void out_Time(int &year,int &month,int &day) {//获取本地时间
	time_t timer;
	struct tm* Now;//创建一个时间结构体

	time( &timer );

	Now = localtime( &timer );
	
	year = Now->tm_year +1900;
	
	month = Now->tm_mon +1;
	
	day = Now->tm_mday;

}