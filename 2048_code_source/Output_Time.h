#pragma once
#include"quan_ju.h"

void out_Time(int &year,int &month,int &day) {//��ȡ����ʱ��
	time_t timer;
	struct tm* Now;//����һ��ʱ��ṹ��

	time( &timer );

	Now = localtime( &timer );
	
	year = Now->tm_year +1900;
	
	month = Now->tm_mon +1;
	
	day = Now->tm_mday;

}