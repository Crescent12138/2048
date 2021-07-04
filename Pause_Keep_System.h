//ChinsePeach
void Pause_system(int shu_zu[4][4] ){

	FILE* fp = NULL;//文件指针->存档
	fp = fopen( "Historical_Archive.txt", "w+" );//打开可读/写文件，若文件存在则文件长度清为零，即该文件内容会消失；若文件不存在则创建该文件。

	if (fp == NULL) {//读取本地信息出错

		printf( "There is a bug in reading information, please restart and try.\n"
			"If loading fails all the time, please contact the administrator:\n"
			"QQ：2986325137 / 1272607918\n" );

		getch();//暂停程序
		system( "cls" );//清空屏幕缓存区
		return;
	}
	
	//保存此次游戏的地图
	for (int i = 0; i < 4; i++) {

		for (int j = 0; j < 4; j++) {
			fprintf( fp, "%d ", shu_zu[i][j] );
		}
		fprintf( fp, "\n" );
	}

	printf( "Saved successfully!\nPress any key to return to the main menu.\n" );//输出保存成功提醒
	
	getch();//暂停程序

	system( "cls" );//清空屏幕

	fclose( fp );//关闭指文件针

	return;
}
void Keep_Playing( ){

	FILE* fp = NULL;//文件指针->存档
	fp = fopen( "Historical_Archive.txt", "w+" );//打开可读/写文件，若文件存在则文件长度清为零，即该文件内容会消失；若文件不存在则创建该文件。

	if (fp == NULL) {//读取本地信息出错

		printf( "There is a bug in reading information, please restart and try.\n"
			"If loading fails all the time, please contact the administrator:\n"
			"QQ：2986325137 / 1272607918\n" );

		getch();//暂停程序
		system( "cls" );//清空屏幕缓存区
		return;
	}
	int symple = 0;//记录读取数据，判断本地有没有存档
	for (int i = 0; i < 4; i++) {

		for (int j = 0; j < 4; j++) {

			fscanf( fp, "%d", &shu_zu[i][j] );//全局变量
			if (shu_zu[i][j] != 0)//表明有有效数据
				symple = 1;
		}
	}
	if (!symple) {//没有有效数据

		printf( "Local archive not found!\nPress any key to return to the main menu!\n" );

		getch();//暂停程序

		system( "cls" );//清空屏幕

		return;
	}

	//当存在有效数据的时候

	test_round();

	fclose( fp );
}
