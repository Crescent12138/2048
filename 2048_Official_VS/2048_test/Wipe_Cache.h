#pragma once
#include"quan_ju.h"


void Wipe_cache() {
	system( "cls" );

	FILE* fp = NULL;
	fp = fopen( "Historical_Archive_Ori.txt", "w+" );
	fclose( fp );

	fp = fopen( "Historical_Archive_endless.txt", "w+" );
	fclose( fp );

	//FILE* fp = NULL;
	fp = fopen( "OrdinaryLeaderboard.txt", "w+" );
	fclose( fp );

	//FILE* fp = NULL;
	fp = fopen( "EndlessLeaderboard.txt", "w+" );
	fclose( fp );

	printf( "Local cache cleared!\n" );
	Sleep( 2000 );
	system( "cls" );
	return;
}