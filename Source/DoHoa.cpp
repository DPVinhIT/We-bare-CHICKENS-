#include"DoHoa.h"
#include"Functions.h"

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
	for (int ix = x + 1; ix < x + w; ix++)
	{
		GoTo(ix, y);
		cout << char(196);
		GoTo(ix, y + h);
		cout << char(196);
	}
	for (int iy = y + 1; iy < y + h; iy++)
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
	GoTo(x + (w - text.length()) / 2, y + 1);
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
void menuLogin(ListClass lcls, ListAccount LStaff, ListAccount LStudent)
{
	string userName, passWord;
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
	//GoTo(15, 10); cout << char(204);
	//GoTo(195, 10); cout << char(185);
	//GoTo(16, 10);
	//for (int i = 16; i < 195; i++)
	//	cout << char(205);

	////Tọa độ 40 10 : 170 10
	//GoTo(40, 10); cout << char(203);
	//GoTo(170, 10); cout << char(203);
	//GoTo(40, 48); cout << char(202);
	//GoTo(170, 48); cout << char(202);
	////kẻ 2 đường dọc
	//for (int i = 11; i < 48; i++)
	//{
	//	GoTo(40, i);
	//	cout << char(186);
	//	GoTo(170, i);
	//	cout << char(186);
	//}
	////đường ngang cuối
	//GoTo(170, 17); cout << char(185);
	//GoTo(40, 17); cout << char(204);
	//for (int i = 41; i < 170; i++)
	//	cout << char(205);

	GoTo(15, 10); cout << char(204);
	GoTo(195, 10); cout << char(185);
	GoTo(16, 10);
	for (int i = 16; i < 195; i++)
		cout << char(205);

	//Tọa độ 40 10 : 170 10
	GoTo(72, 10); cout << char(203);
	GoTo(72 + 64, 10); cout << char(203);
	GoTo(72, 48); cout << char(202);
	GoTo(72 + 64, 48); cout << char(202);
	//kẻ 2 đường dọc
	for (int i = 11; i < 48; i++)
	{
		GoTo(72, i);
		cout << char(186);
		GoTo(72 + 64, i);
		cout << char(186);
	}
	//đường ngang cuối
	GoTo(72 + 64, 17); cout << char(185);
	GoTo(72, 17); cout << char(204);
	for (int i = 73; i < 72 + 64; i++)
		cout << char(205);
	while(true)
	{
		removeText(72, 17, 64, 31, 15, 15);//xóa option
		box(82, 24, 35, 2, 15, 0, "LOGIN");
		box(82, 28, 35, 2, 15, 0, "About Us");
		box(82, 32, 35, 2, 15, 0, "End");
		int op = optionDaChon(82, 24, 35, 4, 3);
		if (op == 1)
		{
			removeText(72, 17, 64, 31, 15, 15);//xóa option
			SetColor(15, 0);
			GoTo(73, 20); cout << "ARE YOU: ";
			box(85, 19, 10, 2, 15, 0, " STAFF");
			GoTo(102, 20); cout << "OR";
			box(85 + 25, 19, 10, 2, 15, 0, " STUDENT");
			bool option = true;
			muiTen(85, 19, 10);
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
								xoaMuiTen(85, 19, 10);
								muiTen(110, 19, 10);
								option = false;
							}
						}
						else if (c == 75)
						{
							if (!option)
							{
								xoaMuiTen(110, 19, 10);
								muiTen(85, 19, 10);
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
			GoTo(73, 24); cout << "User Name: ";
			boxNoText(whereX(), 23, 62 - strlen("User Name: "), 2, 15, 0);
			GoTo(73, 28); cout << "Password: ";
			boxNoText(whereX(), 27, 62 - strlen("Password: "), 2, 15, 0);
			ShowCur(true);
			GoTo(73 + strlen("User Name : "), 24); getline(cin, userName, '\n');
			GoTo(73 + strlen("Password:  "), 28); getline(cin, passWord, '\n');
			string a[] = { "Login Successful !","Login Failed !" };
			GoTo(74, 32);
			if (Login(LStaff, userName, passWord))
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
			break;
		}
		else if (op == 2)
		{
			removeText(72, 17, 64, 31, 15, 15);//xóa option
			SetColor(15, 0);
			GoTo(82, 29);
			cout << "Contact emai:..." << endl;
			box(82, 32, 35, 2, 15, 0, "Quit");
			muiTen(82, 32, 35);
			while (true) {
				if (_kbhit())
				{
					char c = _getch();
					if (c == 13)
					{
						break;
					}
				}
			}
		}
		else if(op==3)
		{
			return;
		}
	}

	// 72:lên ; 80:xuống ; 75:trái ; 77:phải


	menuStaff(lcls);
}

void menuStaff(ListClass lcls)
{
	//MAX 8 OPTION
	//removeText(40, 10, 130, 7, 15, 15);//xóa login
	//removeText(40, 17, 118, 31, 15, 15);//xóa option

	removeText(72, 10, 64, 7, 15, 15);//xóa login
	removeText(72, 17, 64, 31, 15, 15);//xóa option

	//SetColor(15, 9);
	//GoTo(15, 10); cout << char(204);
	//GoTo(195, 10); cout << char(185);
	//GoTo(16, 10);
	//for (int i = 16; i < 195; i++)
	//	cout << char(205);

	////Tọa độ 40 10 : 170 10
	//GoTo(40, 10); cout << char(203);
	//GoTo(170, 10); cout << char(203);
	//GoTo(40, 48); cout << char(202);
	//GoTo(170, 48); cout << char(202);
	////kẻ 2 đường dọc
	//for (int i = 11; i < 48; i++)
	//{
	//	GoTo(40, i);
	//	cout << char(186);
	//	GoTo(170, i);
	//	cout << char(186);
	//}
	////đường ngang cuối
	//GoTo(170, 17); cout << char(185);
	//GoTo(40, 17); cout << char(204);
	//for (int i = 41; i < 170; i++)
	//	cout << char(205);

	//GoTo(72, 48); cout << char(205);
	//GoTo(72 + 64, 48); cout << char(205);

	image(84, 11, "imageStaff.txt", 15, 9);
	SetColor(15, 0);
	GoTo(74, 19); cout << "User: lht";
	GoTo(74, 20); cout << "Saturday";
	GoTo(74, 21); cout << "9/6/2024";
	box(74, 22, 25, 2, 15, 0, "1. User Account ");
	box(74, 25, 25, 2, 15, 0, "2. List Of Classes");
	box(74, 28, 25, 2, 15, 0, "3. List Of Student");
	box(74, 31, 25, 2, 15, 0, "4. Courses Information");
	box(74, 34, 25, 2, 15, 0, "5. Create Academy");
	box(74, 37, 25, 2, 15, 0, "6. Change The Date");
	box(74, 40, 25, 2, 15, 0, "7. Log Out");

	ShowCur(false);
	ListStudent lst = lcls.Head->cls.lst;
	int index = 0, n = 30;
	if (optionDaChon(74, 22, 25, 3, 7) == 3)
	{
		removeText(71, 10, 5, 7, 15, 15);//xóa login
		removeText(134, 10, 5, 7, 15, 15);//xóa login

		SetColor(15, 9);
GoTo(15, 10); cout << char(204);
GoTo(195, 10); cout << char(185);
GoTo(16, 10);
for (int i = 16; i < 195; i++)
	cout << char(205);
//Tọa độ 40 10 : 170 10
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
GoTo(72, 48); cout << char(205);
GoTo(72 + 64, 48); cout << char(205);
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
	int a[7] = { 47, 52,65,107,120,129,145 };

	board(47, 19, 116, 12, index, n, a, 7);

	//trên 194 dọc trái 195 dọc phải 180 dưới 193 cong 197
	GoTo(a[0] + 1, 20);
	cout << "Num ";
	GoTo(a[1] + 1, 20);
	cout << " Student ID ";
	GoTo(a[2] + 16, 20);
	cout << " Full Name ";
	GoTo(a[3] + 1, 20);
	cout << " First Name ";
	GoTo(a[4] + 1, 20);
	cout << " Gender ";
	GoTo(a[5] + 1, 20);
	cout << " Date of birth ";
	GoTo(a[6] + 4, 20);
	cout << " Social ID ";
	for (int i = 1; i <= soDong(index, n, 12); i++)
	{
		if (lst.Head == NULL)
		{
			break;
		}
		GoTo(a[0] + 1, 20 + i * 2);
		cout << lst.Head->sv.STT;
		GoTo(a[1] + 1, 20 + i * 2);
		cout << lst.Head->sv.studentID;
		GoTo(a[2] + 1, 20 + i * 2);
		cout << lst.Head->sv.fullName;
		GoTo(a[3] + 1, 20 + i * 2);
		cout << lst.Head->sv.firstName;
		GoTo(a[4] + 1, 20 + i * 2);
		cout << lst.Head->sv.Gender;
		GoTo(a[5] + 1, 20 + i * 2);
		cout << lst.Head->sv.DoB.day;
		cout << "/";
		cout << lst.Head->sv.DoB.month;
		cout << "/";
		cout << lst.Head->sv.DoB.year;
		GoTo(a[6] + 1, 20 + i * 2);
		cout << lst.Head->sv.socialID;
		lst.Head = lst.Head->Next;
	}
	//174<< 175>>
	if (n <= 12)
	{
		GoTo(104, 46);
		cout << 0;
	}
	else if (index <= 12)
	{
		GoTo(104, 46);
		cout << 1;
		cout << " ";
		cout << char(175);
	}
	else if ((n - n % 12) < index || (n > 12 && n <= 24))
	{
		GoTo(102, 46);
		cout << char(174);
		cout << " ";
		if ((n > 12 && n <= 24))
		{
			cout << (n - n % 12) / 12;
		}
		else
		{
			cout << (n - n % 12) / 12 + 1;
		}
	}
	else
	{
		GoTo(102, 46);
		cout << char(174);
		cout << " ";
		cout << (index / 13) + 1;
		cout << " ";
		cout << char(175);
	}
	GoTo(103, 47);
	cout << "BACK";
	muiTen(102, 46, 5);
}

//Mảng a là tọa độ các cột từ trái qua phải của bảng, không có cột cuối cùng bên phải :v
void board(int x, int y, int w, int maxLine, int index, int quantity, int ax[], int n)
{
	SetConsoleOutputCP(437);
	SetColor(15, 0);
	int dong = soDong(index, quantity, maxLine) + 1;
	//kẻ ngang
	string gachNgang = string(w - 1, char(196));
	for (int iy = y; iy <= dong * 2 + y; iy += 2)
	{
		GoTo(x + 1, iy);
		cout << gachNgang;
	}
	//kẻ dọc nhưng k phải | và +
	for (int iy = y + 2; iy < dong * 2 + y; iy += 2)
	{
		GoTo(x, iy);
		cout << char(195);
		GoTo(x + w, iy);
		cout << char(180);
		for (int i = 1; i < n; i++)
		{
			GoTo(ax[i], iy);
			cout << char(197);
		}
	}
	//kẻ dọc | 
	for (int iy = y + 1; iy < dong * 2 + y; iy += 2)
	{
		GoTo(x, iy);
		cout << char(179);
		GoTo(x + w, iy);
		cout << char(179);
		for (int i = 1; i < n; i++)
		{
			GoTo(ax[i], iy);
			cout << char(179);
		}
	}
	//đường trên và dưới
	for (int i = 1; i < n; i++)
	{
		GoTo(ax[i], y);
		cout << char(194);
		GoTo(ax[i], dong * 2 + y);
		cout << char(193);
	}
	//Các góc
	GoTo(x, y);
	cout << char(218);
	GoTo(x + w, y);
	cout << char(191);
	GoTo(x, dong * 2 + y);
	cout << char(192);
	GoTo(x + w, dong * 2 + y);
	cout << char(217);
}

int soDong(int index, int n, int maxline)
{
	if (n - index < maxline)
	{
		return n - index;
	}
	return maxline;
}

void menuStudent()
{
	removeText(40, 10, 130, 7, 15, 15);//xóa login
	removeText(40, 17, 118, 31, 15, 15);//xóa option
	image(74, 11, "imageStudent.txt", 15, 9);
	SetColor(15, 0);
	GoTo(74, 19); cout << "User: lht";
	GoTo(74, 20); cout << "Saturday";
	GoTo(74, 21); cout << "9/6/2024";
	box(74, 22, 25, 2, 15, 0, "1. User Account");
	box(74, 25, 25, 2, 15, 0, "2. Registered Courses");
	box(74, 37, 25, 2, 15, 0, "3. Log Out");
}

int optionDaChon(int x, int y, int w, int h, int sl)
{
	int xp = x; int yp = y;
	int xcu = xp; int ycu = yp;
	bool kt = true;
	while (true)
	{
		if (kt == true)
		{
			GoTo(xcu, ycu);
			xoaMuiTen(xcu, ycu, w);
			xcu = xp; ycu = yp;
			muiTen(xp, yp, w);
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
						yp -= h;
					}
					else
					{
						yp = y + h * (sl - 1);
					}
				}
				else if (c == 80)
				{
					if (yp != y + h * (sl - 1))
					{
						yp += h;
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
	return (yp - y) / h + 1;
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

void removeText(int x, int y, int w, int h, int b_color, int t_color)
{
	SetColor(b_color, t_color);
	string khoangTrang = string(w - 1, ' ');
	for (int iy = y + 1; iy < y + h; iy++)
	{
		GoTo(x + 1, iy);
		cout << khoangTrang;
	}
}

void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
