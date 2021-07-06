


VOID SetColor( UINT uFore, UINT uBack ) {//���ı�����ɫ
	HANDLE handle = GetStdHandle( STD_OUTPUT_HANDLE );
	SetConsoleTextAttribute( handle, uFore + uBack * 0x10 );
	/*0 = ��ɫ       8 = ��ɫ
    1 = ��ɫ       9 = ����ɫ
    2 = ��ɫ       A = ����ɫ
    3 = ǳ��ɫ     B = ��ǳ��ɫ
    4 = ��ɫ       C = ����ɫ
    5 = ��ɫ       D = ����ɫ
    6 = ��ɫ       E = ����ɫ
    7 = ��ɫ       F = ����ɫ*/
}
void SetSize( unsigned uCol, unsigned uLine )//���ô��ڴ�С
{
	char cmd[64];
	sprintf( cmd, "mode con cols=%d lines=%d", uCol, uLine );
	system( cmd );
}
VOID SetPosC( COORD a ) { // ��������λ��
	HANDLE out = GetStdHandle( STD_OUTPUT_HANDLE );
	SetConsoleCursorPosition( out, a );
}
VOID SetPos( int x, int y ) { // ��������λ��
	COORD pos = { x, y };
	SetPosC( pos );
}
VOID HideConsoleCursor( VOID ) {//���ع��
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo( GetStdHandle( STD_OUTPUT_HANDLE ),
		&cursor_info );
}
VOID KillConsoleCloseButton( VOID ) {//�رմ��ڹرհ���
	DeleteMenu( GetSystemMenu( GetConsoleWindow(), FALSE ),
		SC_CLOSE, MF_DISABLED );
	DrawMenuBar( GetConsoleWindow() );
}
//�ı������С
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
