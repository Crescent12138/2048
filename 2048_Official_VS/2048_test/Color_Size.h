


VOID SetColor( UINT uFore, UINT uBack ) {//更改背景颜色
	HANDLE handle = GetStdHandle( STD_OUTPUT_HANDLE );
	SetConsoleTextAttribute( handle, uFore + uBack * 0x10 );
	/*0 = 黑色       8 = 灰色
    1 = 蓝色       9 = 淡蓝色
    2 = 绿色       A = 淡绿色
    3 = 浅绿色     B = 淡浅绿色
    4 = 红色       C = 淡红色
    5 = 紫色       D = 淡紫色
    6 = 黄色       E = 淡黄色
    7 = 白色       F = 亮白色*/
}
void SetSize( unsigned uCol, unsigned uLine )//设置窗口大小
{
	char cmd[64];
	sprintf( cmd, "mode con cols=%d lines=%d", uCol, uLine );
	system( cmd );
}
VOID SetPosC( COORD a ) { // 设置文字位置
	HANDLE out = GetStdHandle( STD_OUTPUT_HANDLE );
	SetConsoleCursorPosition( out, a );
}
VOID SetPos( int x, int y ) { // 设置文字位置
	COORD pos = { x, y };
	SetPosC( pos );
}
VOID HideConsoleCursor( VOID ) {//隐藏光标
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo( GetStdHandle( STD_OUTPUT_HANDLE ),
		&cursor_info );
}
VOID KillConsoleCloseButton( VOID ) {//关闭窗口关闭按键
	DeleteMenu( GetSystemMenu( GetConsoleWindow(), FALSE ),
		SC_CLOSE, MF_DISABLED );
	DrawMenuBar( GetConsoleWindow() );
}
//改变字体大小
void the_size_of_word() {
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof cfi;
	cfi.nFont = 1;
	cfi.dwFontSize.X = 12;
	cfi.dwFontSize.Y = 25;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	SetCurrentConsoleFontEx( GetStdHandle( STD_OUTPUT_HANDLE ), true, &cfi );
}
