#pragma once
#include"quan_ju.h"

void out_Time(int &year,int &month,int &day) {
	time_t timer;
	struct tm* Now;

	time( &timer );
	Now = localtime( &timer );
	year = Now->tm_year +1900;
	month = Now->tm_mon +1;
	day = Now->tm_mday;

}