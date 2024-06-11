#include"DoHoa.h"

//	0 = Black		8 = Gray
//	1 = Blue		9 = Light Blue
//	2 = Green		10 = Light Green
//	3 = Aqua		11 = Light Aqua
//	4 = Red			12 = Light Red
//	5 = Purple		13 = Light Purple
//	6 = Yellow		14 = Light Yellow
//	7 = White		15 = Bright White
void SetColor(int backgound_color, int text_color)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	int color_code = backgound_color * 16 + text_color;
	SetConsoleTextAttribute(hStdout, color_code);
}

void GoTo(SHORT posX, SHORT posY)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Position;
	Position.X = posX;
	Position.Y = posY;

	SetConsoleCursorPosition(hStdout, Position);
}
// lấy tọa độ x của con trỏ hiện tại
int whereX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}
// lấy tọa độ y của con trỏ hiện tại
int whereY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}
//làm ẩn trỏ chuột
void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}
//trả về mã phím người dùng bấm
int inputKey()
{
	if (_kbhit())
	{
		int key = _getch();

		if (key == 224)
		{
			key = _getch();
			return key + 1000;
		}

		return key;
	}
	else
	{
		return KEY_NONE;
	}
	return KEY_NONE;
}
//Tạo box
void box(int x, int y, int w, int h, int b_color, int t_color, string text)
{
	SetConsoleOutputCP(437);
	SetColor(b_color, t_color);
	if (h <= 1 || w <= 1)
	{
		return;
	}
	for (int ix = x; ix <= x + w; ix++)
	{
		GoTo(ix, y);
		cout << char(196);
		GoTo(ix, y + h);
		cout << char(196);
	}
	for (int iy = y; iy <= y + h; iy++)
	{
		GoTo(x, iy);
		cout << char(179);
		GoTo(x + w, iy);
		cout << char(179);
	}
	GoTo(x, y);
	cout << char(218);
	GoTo(x + w, y);
	cout << char(191);
	GoTo(x, y + h);
	cout << char(192);
	GoTo(x + w, y + h);
	cout << char(217);
	for (int iy = y + 1; iy < y + h; iy++) {
		for (int ix = x + 1; ix < x + w; ix++) {
			GoTo(ix, iy);
			cout << " ";
		}
	}
	GoTo(x + 1, y + 1);
	cout << text;

}

void boxNoText(int x, int y, int w, int h, int b_color, int t_color)
{
	SetConsoleOutputCP(437);
	SetColor(b_color, t_color);
	if (h <= 1 || w <= 1)
	{
		return;
	}
	for (int ix = x; ix <= x + w; ix++)
	{
		GoTo(ix, y);
		cout << char(205);
		GoTo(ix, y + h);
		cout << char(205);

	}
	for (int iy = y; iy <= y + h; iy++)
	{
		GoTo(x, iy);
		cout << char(186);
		GoTo(x + w, iy);
		cout << char(186);
	}
	GoTo(x, y);
	cout << char(201);
	GoTo(x + w, y);
	cout << char(187);
	GoTo(x, y + h);
	cout << char(200);
	GoTo(x + w, y + h);
	cout << char(188);
}

void boxNoTextFC(int x, int y, int w, int h, int b_color, int t_color)
{
	SetConsoleOutputCP(437);
	SetColor(b_color, t_color);
	if (h <= 1 || w <= 1) {
		return;
	}
	string gachNgang = string(w - 1, char(196));
	string khoangTrang = string(w - 1, ' ');
	GoTo(x + 1, y);
	cout << gachNgang;
	GoTo(x + 1, y + h);
	cout << gachNgang;
	for (int iy = y + 1; iy < y + h; iy++)
	{
		GoTo(x, iy);
		cout << char(179);
		GoTo(x + 1, iy);
		cout << khoangTrang;
		GoTo(x + w, iy);
		cout << char(179);
	}
	GoTo(x, y);
	cout << char(218);
	GoTo(x + w, y);
	cout << char(191);
	GoTo(x, y + h);
	cout << char(192);
	GoTo(x + w, y + h);
	cout << char(217);
}

void image(int x, int y, string fileName, int b_color, int t_color)
{
	SetConsoleOutputCP(CP_UTF8);
	ifstream fin;
	fin.open(fileName);
	if (!fin.is_open())
	{
		return;
	}
	SetColor(b_color, t_color);
	GoTo(0, y);
	while (!fin.eof())
	{
		string temp;
		GoTo(x, whereY());
		getline(fin, temp, '\n');
		cout << temp << endl;
	}
	fin.close();
}

void resizeConsole(int width, int height) 
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;
	coord.X = width;
	coord.Y = height;
	SetConsoleScreenBufferSize(hConsole, coord);
	SMALL_RECT rect;
	rect.Left = 0;
	rect.Top = 0;
	rect.Right = width - 1;
	rect.Bottom = height - 1;
	SetConsoleWindowInfo(hConsole, TRUE, &rect);
}

void resizeConsoleBuffer(int width, int height)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;
	coord.X = width;
	coord.Y = height;
	SetConsoleScreenBufferSize(hConsole, coord);
}

void DisableResizeWindow()
{
	HWND hWnd = GetConsoleWindow();
	SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_SIZEBOX);
}

void disableMinimizeAndMaximizeButtons()
{
	HWND hWnd = GetConsoleWindow();
	if (hWnd == NULL) {
		std::cerr << "Unable to get console window handle" << std::endl;
		return;
	}
	LONG style = GetWindowLong(hWnd, GWL_STYLE);
	style &= ~WS_MINIMIZEBOX;
	style &= ~WS_MAXIMIZEBOX;
	SetWindowLong(hWnd, GWL_STYLE, style);
	SetWindowPos(hWnd, NULL, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_FRAMECHANGED);
}

void DisableSelection()
{
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);

	SetConsoleMode(hStdin, ~ENABLE_QUICK_EDIT_MODE);
}

void maximizeConsoleWindow()
{
	HWND hWnd = GetConsoleWindow();
	if (hWnd == NULL) {
		return;
	}
	ShowWindow(hWnd, SW_MAXIMIZE);
}

void SetConsoleBackgroundColor(int bgColor)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	DWORD consoleSize = csbi.dwSize.X * csbi.dwSize.Y;
	COORD coord = { 0, 0 };
	DWORD written;
	FillConsoleOutputAttribute(hConsole, (csbi.wAttributes & 0x0F) | (bgColor << 4), consoleSize, coord, &written);
	SetConsoleCursorPosition(hConsole, { 0, 0 });
}

void getConsoleSize(int& width, int& height) 
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int columns, rows;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
		columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
		rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

		width = columns;
		height = rows;
	}
	else {
		width = height = 0;
	}
}

// 72:lên ; 80:xuống ; 75:trái ; 77:phải
void menuLogin(string& userName, string& passWord, ListClass lcls)
{
	ShowCur(false);
	SetConsoleBackgroundColor(15);
	boxNoText(15, 6, 180, 42, 15, 9);
	SetConsoleOutputCP(CP_UTF8);
	//image(50, 0, "Filetext.txt", 11, 0);
	image(32, 0, "image3.txt", 15, 9);
	image(74, 8, "image4.txt", 15, 9);
	image(84, 11, "image5.txt", 15, 9);
	SetConsoleOutputCP(437);

	//đường kẻ ngang
	GoTo(15, 10); cout << char(204);
	GoTo(195, 10); cout << char(185);
	GoTo(16, 10);
	for (int i = 16; i < 195; i++)
		cout << char(205);

	//Tọa độ 55 10 : 155 10
	GoTo(40, 10); cout << char(203);
	GoTo(170, 10); cout << char(203);
	GoTo(40, 48); cout << char(202);
	GoTo(170, 48); cout << char(202);
	//kẻ 2 đường dọc
	for (int i = 11; i < 48; i++)
	{
		GoTo(40, i);
		cout << char(186);
		GoTo(170, i);
		cout << char(186);
	}
	//đường ngang cuối
	GoTo(170, 17); cout << char(185);
	GoTo(40, 17); cout << char(204);
	for (int i = 41; i < 170; i++)
		cout << char(205);

	SetColor(15, 0);
	GoTo(74, 24); cout << "ARE YOU: ";
	box(87, 23, 10, 2, 15, 0, "  STAFF  ");
	muiTen(87, 23, 10);
	xoaMuiTen(87, 23, 10);
	GoTo(103, 24); cout << "OR";
	box(110, 23, 10, 2, 15, 0, " STUDENT ");

	//image(30, 9, "image1.txt", 11, 0);
	//image(160, 9, "image2.txt", 11, 0);

	// 72:lên ; 80:xuống ; 75:trái ; 77:phải
	bool option = true;
	muiTen(87, 23, 10);
	while (true) {
		if (_kbhit())
		{
			char c = _getch();
			if (c == -32)
			{
				c = _getch();
				if (c == 77)
				{
					if (option)
					{
						xoaMuiTen(87, 23, 10);
						muiTen(110, 23, 10);
						option = false;
					}
				}
				else if (c == 75)
				{
					if (!option)
					{
						xoaMuiTen(110, 23, 10);
						muiTen(87, 23, 10);
						option = true;
					}
				}
			}
			else if (c == 13)
			{
				break;
			}
		}
	}

	GoTo(74, 27); cout << "User name: ";
	GoTo(74 + strlen("User name : "), 27);
	ShowCur(true);
	getline(cin, userName);
	GoTo(74, 29); cout << "Password: ";
	GoTo(74 + strlen("Password: "), 29);
	getline(cin, passWord);

	//if(check tk())
	GoTo(74, 33);
	string a[] = { "Login Successful !","Login Failed !" };
	if (true)
	{
		for (int i = 0; i < a[0].length(); i++)
		{
			cout << a[0][i];
			Sleep(50);
		}
	}
	else
	{
		for (int i = 0; i < a[1].length(); i++)
		{
			cout << a[1][i];
			Sleep(50);
		}
	}
	menuStaff(lcls);
}

void menuStaff(ListClass lcls)
{
	boxNoTextFC(56, 11, 98, 5, 15, 15);//xóa login
	boxNoTextFC(56, 18, 98, 29, 15, 15);//xóa option
	image(84, 11, "imageStaff.txt", 15, 9);
	SetColor(15, 0);
	GoTo(74, 19); cout << "User: lht";
	GoTo(74, 20); cout << "Saturday";
	GoTo(74, 21); cout << "9/6/2024";
	box(74, 22, 25, 2, 15, 0, "1. Profile ");
	box(74, 25, 25, 2, 15, 0, "2. User account");
	box(74, 28, 25, 2, 15, 0, "3. Manage Student");
	box(74, 31, 25, 2, 15, 0, "4. Manage Course");
	box(74, 34, 25, 2, 15, 0, "5. Date");
	box(74, 37, 25, 2, 15, 0, "6. Quit");

	ShowCur(false);
	ListStudent lst = lcls.Head->cls.lst;
	int index = 24, n = 30;
	if (optionDaChon(74, 22, 6) == 3)
	{
		displayStudent(lst, index, n);
	}
}

//max 13 dòng
void displayStudent(ListStudent lst, int& index, int n)
{
	SetConsoleOutputCP(437);
	boxNoTextFC(56, 18, 98, 29, 15, 15);
	SetColor(15, 0);
	GoTo(96, 18);
	cout << "VIEW CLASS: 23CTT5";
	GoTo(41, 19);
	SetConsoleOutputCP(437);
	SetColor(15, 0);
	GoTo(47, 19);
	//goctrentrai 218 : goctrenphai 191 : gocduoitrai 192 : gocduoiphai 217	: doc  179 : ngang 196 
	//Tọa độ các cột
	int a[8] = { 47, 52,65,107,120,129,145 };
	string gachNgang = string(115, char(196));
	//kẻ dọc nhưng k phải |
	for (int iy = 21; iy < soDong(index, n) * 2 + 21; iy += 2)
	{
		GoTo(47, iy);
		cout << char(195);
		GoTo(47 + 116, iy);
		cout << char(180);
	}
	//kẻ ngang
	for (int iy = 19; iy <= soDong(index, n) * 2 + 21; iy += 2)
	{
		GoTo(48, iy);
		cout << gachNgang;
	}
	//kẻ dọc |
	for (int iy = 20; iy < soDong(index, n) * 2 + 21; iy += 2)
	{
		GoTo(47, iy);
		cout << char(179);
		GoTo(47 + 116, iy);
		cout << char(179);
	}
	// dấu + và _
	for (int iy = 20; iy < soDong(index, n) * 2 + 21; iy += 2)
	{
		for (int i = 1; i < 8; i++)
		{
			GoTo(a[i], iy+1);
			cout << char(197);
			GoTo(a[i], iy);
			cout << char(179);
		}
	}
	//đường trên và dưới
	for (int i = 1; i < 8; i++)
	{
		GoTo(a[i], 19);
		cout << char(194);
		GoTo(a[i], soDong(index, n) * 2 + 21);
		cout << char(193);
	}
	GoTo(47, 19);
	cout << char(218);
	GoTo(47 + 116, 19);
	cout << char(191);
	GoTo(47, soDong(index, n) * 2 + 21);
	cout << char(192);
	GoTo(47 + 116, soDong(index, n) * 2 + 21);
	cout << char(217);

	GoTo(48, 20);
	//dài 117
	//trên 194 dọc trái 195 dọc phải 180 dưới 193 cong 197
	cout << "Num ";
	GoTo(a[1] + 1, 20);
	cout << " Student ID ";
	GoTo(a[2] + 16, 20);
	cout << " Full Name ";
	GoTo(a[3]+1, 20);
	cout << " First Name ";
	GoTo(a[4]+1, 20);
	cout << " Gender ";
	GoTo(a[5]+1, 20);
	cout << " Date of birth ";
	GoTo(a[6]+4, 20);
	cout << " Social ID ";
	for (int i = 1; i <= soDong(index, n); i++)
	{
		GoTo(a[0]+1, 20 +i*2);
		cout << lst.Head->sv.STT;
		GoTo(a[1]+1, 20 + i*2);
		cout << lst.Head->sv.studentID;
		GoTo(a[2]+1, 20 + i * 2);
		cout << lst.Head->sv.fullName;
		GoTo(a[3]+1, 20 + i * 2);
		cout << lst.Head->sv.firstName;
		GoTo(a[4]+1, 20 + i * 2);
		cout << lst.Head->sv.Gender;
		GoTo(a[5]+1, 20 + i * 2);
		cout << lst.Head->sv.DoB.day;
		cout << "/";
		cout << lst.Head->sv.DoB.month;
		cout << "/";
		cout << lst.Head->sv.DoB.year;
		GoTo(a[6]+1, 20 + i * 2);
		cout << lst.Head->sv.socialID;
		lst.Head = lst.Head->Next;
	}
}

int soDong(int index, int n)
{
	if (n - index < 12)
	{
		return n - index;
	}
	return 12;
}

void menuStudent()
{
	boxNoTextFC(56, 11, 98, 5, 15, 15);//xóa login
	boxNoTextFC(56, 18, 98, 29, 15, 15);
	image(74, 11, "imageStudent.txt", 15, 9);

}

int optionDaChon(int x, int y, int sl)
{
	int xp = x; int yp = y;
	int xcu = xp; int ycu = yp;
	bool kt = true;
	while (true)
	{
		if (kt == true)
		{
			GoTo(xcu, ycu);
			xoaMuiTen(xcu, ycu, 25);
			xcu = xp; ycu = yp;
			muiTen(xp, yp, 25);
			kt = false;
		}
		if (_kbhit())
		{
			char c = _getch();
			if (c == -32)
			{
				kt = true;
				c = _getch();
				if (c == 72)
				{
					if (yp != y)
					{
						yp -= 3;
					}
					else
					{
						yp = y + 3 * (sl - 1);
					}
				}
				else if (c == 80)
				{
					if (yp != y + 3 * (sl - 1))
					{
						yp += 3;
					}
					else
					{
						yp = y;
					}
				}
			}
			else if (c == 13)
			{
				break;
			}
		}
	}
	return (yp - y) / 3 + 1;
}

void muiTen(int x, int y, int w)
{
	SetColor(15, 4);
	SetConsoleOutputCP(437);
	GoTo(x - 1, y + 1);
	cout << char(16);
	GoTo(x + 1 + w, y + 1);
	cout << char(17);
	SetColor(15, 0);
}

void xoaMuiTen(int x, int y, int w)
{
	GoTo(x - 1, y + 1);
	cout << " ";
	GoTo(x + 1 + w, y + 1);
	cout << " ";
}

void thanh_sang(int x, int y, int w, int h, int b_color, int t_color, string nd)
{
	SetColor(b_color, t_color);
	for (int iy = y + 1; iy <= y + h - 1; iy++)
	{
		for (int ix = x + 1; ix <= x + w - 1; ix++)
		{
			GoTo(ix, iy); cout << " ";
		}
	}
	GoTo(x + 1, y + 1);
	cout << nd;
	ShowCur(false);
}

void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}