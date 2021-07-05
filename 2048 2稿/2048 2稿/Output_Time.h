#pragma once
#include"quan_ju.h"

void out_Time(int &year,int &month,int &day) {
	time_t timer;
	struct tm* Now;

	time( &timer );
	Now = localtime( &timer );
	year = Now->tm_year;
	month = Now->tm_mon;
	day = Now->tm_mday;

}