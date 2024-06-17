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
	SetColor(15, 0);
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
void menuLogin(ListClass& lcls, ListAccount LStaff, ListAccount LStudent)
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
	while (true)
	{
		int check = 1;
		removeText(72, 17, 64, 31, 15, 15);//xóa option
		box(82, 24, 35, 2, 15, 0, "LOGIN");
		box(82, 28, 35, 2, 15, 0, "About Us");
		box(82, 32, 35, 2, 15, 0, "End");
		int op = optionDaChon(82, 24, 35, 4, 3);
		bool kt = false;
		if (op == 1)
		{
			while (kt != true)
			{
				ShowCur(false);
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
									check = 2;
									option = false;
								}
							}
							else if (c == 75)
							{
								if (!option)
								{
									xoaMuiTen(110, 19, 10);
									muiTen(85, 19, 10);
									check = 1;
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

				if (check == 1)
				{
					if (Login(LStaff, userName, passWord))
					{
						for (int i = 0; i < a[0].length(); i++)
						{
							cout << a[0][i];
							Sleep(50);
							kt = true;
						}
					}
					else
					{
						for (int i = 0; i < a[1].length(); i++)
						{
							cout << a[1][i];
							Sleep(50);
							kt = false;
						}
					}
				}
				else
				{
					if (Login(LStudent, userName, passWord))
					{
						for (int i = 0; i < a[0].length(); i++)
						{
							cout << a[0][i];
							Sleep(50);
							kt = true;
						}
					}
					else
					{
						for (int i = 0; i < a[1].length(); i++)
						{
							cout << a[1][i];
							Sleep(50);
							kt = false;
						}
					}
				}
			}
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
		else if (op == 3)
		{
			return;
		}
		if (kt == true)
		{
			if (check == 1)
			{
				menuStaff(lcls);
			}
			else
			{
				menuStudent();
			}
		}
	}

	// 72:lên ; 80:xuống ; 75:trái ; 77:phải


}

void menuStaff(ListClass& lcls)
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

	//SetColor(15, 0);
	//GoTo(74, 19); cout << "User: lht";
	//GoTo(74, 20); cout << "Saturday";
	//GoTo(74, 21); cout << "9/6/2024";
	//box(74, 22, 25, 2, 15, 0, "1. User Account ");
	//box(74, 25, 25, 2, 15, 0, "2. List Of Classes");
	//box(74, 28, 25, 2, 15, 0, "3. List Of Student");
	//box(74, 31, 25, 2, 15, 0, "4. Courses Information");
	//box(74, 34, 25, 2, 15, 0, "5. Create Academy");
	//box(74, 37, 25, 2, 15, 0, "6. Change The Date");
	//box(74, 40, 25, 2, 15, 0, "7. Log Out");

	ShowCur(false);
	ListStudent lst = lcls.Head->cls.lst;

	while (true)
	{
		removeText(16, 10, 179, 38, 15, 15);
		image(84, 11, "imageStaff.txt", 15, 9);
		khungNho();
		SetColor(15, 0);
		GoTo(74, 18); cout << "User: None";
		GoTo(74, 19); cout << "Date: 15/6/2024";
		GoTo(74, 20); cout << "Academy: 2024-2025";
		GoTo(74, 21); cout << "Semester: 1";
		box(92, 22, 25, 2, 15, 0, "1. User Account ");
		box(92, 25, 25, 2, 15, 0, "2. List Of Classes");
		box(92, 28, 25, 2, 15, 0, "3. List Of Student");
		box(92, 31, 25, 2, 15, 0, "4. Courses Information");
		box(92, 34, 25, 2, 15, 0, "5. Create Academy");
		box(92, 37, 25, 2, 15, 0, "6. Change The Date");
		box(92, 40, 25, 2, 15, 0, "7. Log Out");
		int index = 0, n = 6;
		int op = optionDaChon(92, 22, 25, 3, 7);
		removeText(72, 17, 64, 31, 15, 15);//xóa option
		if (op == 1)
		{
			removeText(72, 17, 64, 31, 15, 15);//xóa option
			SetColor(15, 0);
			GoTo(82, 29);
			cout << "Hello world";
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
		else if (op == 2)
		{
			Staff2_2();
		}
		else if (op == 3)
		{
			GoTo(82, 29);
			SetColor(15, 0);
			cout << "Name Class: ";
			ShowCur(true);
			string nameClass;
			getline(cin, nameClass);
			NodeClass* cls = findClassByName(lcls, nameClass);
			if (cls == NULL)
			{
				GoTo(82, 31);
				cout << "Class not exist";
				ShowCur(false);
				box(82, 32, 35, 2, 15, 0, "Quit");
				muiTen(82, 32, 35);
				_getch();
			}
			else
			{
				removeText(71, 10, 5, 7, 15, 15);//xóa | login
				removeText(134, 10, 5, 7, 15, 15);//xóa | login
				int n = 0;
				ViewStudenOfClass(cls, n, countStudent(cls->cls.lst));
			}

		}
		else if (op == 5)
		{
			BeginSchoolYear2_6(lcls);
		}
		else if (op == 7)
		{
			break;
		}
	}

}

void Staff2_2()
{
	while (true)
	{
		removeText(72, 17, 64, 31, 15, 15);//xóa option
		SetColor(15, 0);
		box(74, 22, 25, 2, 15, 0, "First Year ");
		box(74, 25, 25, 2, 15, 0, "Second Year");
		box(74, 28, 25, 2, 15, 0, "Third Year");
		box(74, 31, 25, 2, 15, 0, "Fourth Year");
		box(74, 34, 25, 2, 15, 0, "Quit");
		int op = optionDaChon(74, 22, 25, 3, 5);
		if (op == 1)
		{
			removeText(72, 17, 64, 31, 15, 15);//xóa option
			GoTo(82, 27);
			SetColor(15, 0);
			cout << "Nam 1";
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
		else if (op == 2)
		{
			removeText(72, 17, 64, 31, 15, 15);//xóa option
			GoTo(82, 27);
			SetColor(15, 0);
			cout << "Nam 2";
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
		else if (op == 3)
		{
			removeText(72, 17, 64, 31, 15, 15);//xóa option
			GoTo(82, 27);
			SetColor(15, 0);
			cout << "Nam 3";
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
		else if (op == 4)
		{
			removeText(72, 17, 64, 31, 15, 15);//xóa option
			GoTo(82, 27);
			SetColor(15, 0);
			cout << "Nam 4";
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
		else if (op == 5)
		{
			break;
		}
	}
}

void BeginSchoolYear2_6(ListClass& lcls)
{
	removeText(72, 17, 64, 31, 15, 15);//xóa option
	box(74, 22, 30, 2, 15, 0, "1.Add Class Of First Year");
	box(74, 25, 30, 2, 15, 0, "2.View Class Of First Year");
	box(74, 28, 30, 2, 15, 0, "3.Quit");
	int op = optionDaChon(74, 22, 30, 3, 3);
	if (op == 3)
	{
		return;
	}
	else if (op == 1)
	{
		removeText(72, 17, 64, 31, 15, 15);//xóa option
		GoTo(82, 22);
		SetColor(15, 0);
		cout << "Name Class: ";
		ShowCur(true);
		string nameClass;
		getline(cin, nameClass);
		Clas cls;
		cls.nameClass = nameClass;
		cls.lst.Head = NULL;
		removeText(72, 17, 64, 31, 15, 15);//xóa option
		GoTo(82, 22);
		SetColor(15, 0);
		cout << "ADD Student";
		ShowCur(false);
		box(74, 25, 25, 2, 15, 0, "Manual Input");
		box(74, 28, 25, 2, 15, 0, "Input File CSV");
		int opt = optionDaChon(74, 25, 25, 3, 2);
		if (opt == 1)
		{
			removeText(71, 10, 5, 7, 15, 15);//xóa | login
			removeText(134, 10, 5, 7, 15, 15);//xóa | login
			removeText(40, 17, 129, 31, 15, 15);//xóa option
			khungLon();
			SetColor(15, 0);
			ShowCur(true);
			GoTo(82, 22);
			inputStudent(cls);
			addNodeClass(lcls, createNodeClass(cls));
			string xuat = "ADD Student successful !";
			GoTo(90, 47);
			for (int i = 0; i < xuat.length(); i++)
			{
				cout << xuat[i];
				Sleep(50);
			}
			ShowCur(false);
			_getch();
		}
		else if (opt == 2)
		{
			removeText(72, 17, 64, 31, 15, 15);//xóa option
			SetColor(15, 0);
			ShowCur(true);
			GoTo(82, 22);
			cout << "Nhap ten file csv: ";
			string fileName;
			getline(cin, fileName);
		}
	}
}

void inputStudent(Clas& cls)
{
	SetColor(15, 0);
	GoTo(48, 18);
	cout <<"Class: "<< cls.nameClass;
	GoTo(48, 19);
	cout << "Input number of students for class: ";
	ShowCur(true);
	int n;
	cin >> n;
	cin.ignore();
	int index = 0;
	while (index != n)
	{
		SetConsoleOutputCP(437);
		removeText(40, 19, 129, 28, 15, 15);//xóa bảng
		int dong = 12;
		if (n - index < 12)
		{
			dong = n - index;
		}
		int a[6] = { 47,52,65,120,129,145 };
		board(47, 20, 116, 12, dong, a, 6);
		GoTo(a[0] + 1, 21);
		cout << "Num ";
		GoTo(a[1] + 1, 21);
		cout << " Student ID ";
		GoTo(a[2] + 16, 21);
		cout << " Full Name ";
		GoTo(a[3] + 1, 21);
		cout << " Gender ";
		GoTo(a[4] + 1, 21);
		cout << " Date of birth ";
		GoTo(a[5] + 4, 21);
		cout << " Social ID ";
		ShowCur(true);
		for (int i = 1; i <= dong; i++)
		{
			Student st;
			GoTo(a[0] + 1, 21 + i * 2);
			int stt = index + 1;
			cout << stt;
			st.STT = stt;
			GoTo(a[1] + 1, 21 + i * 2);
			getline(cin, st.studentID);
			GoTo(a[2] + 1, 21 + i * 2);
			getline(cin, st.fullName);
			GoTo(a[3] + 1, 21 + i * 2);
			getline(cin, st.Gender);
			GoTo(a[4] + 1, 21 + i * 2);
			cin >> st.DoB.day;
			GoTo(a[4] + 5, 21 + i * 2);
			cin >> st.DoB.month;
			GoTo(a[4] + 9, 21 + i * 2);
			cin >> st.DoB.year;
			GoTo(a[5] + 1, 21 + i * 2);
			cin.ignore();
			getline(cin, st.socialID);
			splitName(st);
			addNodeStudent(cls.lst, createNodeStudent(st));
			index++;
		}
		if (index >= n)
		{
			break;
		}
	}

}

void khungLon()
{
	SetConsoleOutputCP(437);
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
}

void khungNho()
{
	SetConsoleOutputCP(437);
	SetColor(15, 9);
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
	GoTo(170, 48); cout << char(205);
	GoTo(40, 48); cout << char(205);
}

//max 13 dòng
void displayStudent(NodeClass* cls, int index, int n)
{
	SetConsoleOutputCP(437);
	khungLon();
	boxNoTextFC(56, 18, 98, 29, 15, 15);
	SetColor(15, 0);
	GoTo(96, 18);
	cout << "VIEW CLASS: " << cls->cls.nameClass;
	SetConsoleOutputCP(437);
	SetColor(15, 0);
	GoTo(47, 19);
	//goctrentrai 218 : goctrenphai 191 : gocduoitrai 192 : gocduoiphai 217	: doc  179 : ngang 196 
	//Tọa độ các cột
	int a[7] = { 47, 52,65,107,120,129,145 };
	int dong = soDong(index, n, 12);
	board(47, 19, 116, 12, dong, a, 7);

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
	if (n > 12 && n - index <= 12)
	{
		dong++;
	}
	NodeStudent* temp = findStudentByPos(cls->cls.lst, index);
	for (int i = 1; i <= dong; i++)
	{
		if (temp == NULL)
		{
			break;
		}
		GoTo(a[0] + 1, 20 + i * 2);
		cout << temp->sv.STT;
		GoTo(a[1] + 1, 20 + i * 2);
		cout << temp->sv.studentID;
		GoTo(a[2] + 1, 20 + i * 2);
		cout << temp->sv.fullName;
		GoTo(a[3] + 1, 20 + i * 2);
		cout << temp->sv.firstName;
		GoTo(a[4] + 1, 20 + i * 2);
		cout << temp->sv.Gender;
		GoTo(a[5] + 1, 20 + i * 2);
		cout << temp->sv.DoB.day;
		cout << "/";
		cout << temp->sv.DoB.month;
		cout << "/";
		cout << temp->sv.DoB.year;
		GoTo(a[6] + 1, 20 + i * 2);
		cout << temp->sv.socialID;
		temp = temp->Next;
	}
	int maxPage = (n + 12 - 1) / 12;
	int curPage = (index + 12 - 1) / 12;
	if (index == 0)
	{
		curPage = 1;
	}

	if (maxPage == 1)
	{
		GoTo(104, 46);
		cout << 0;
	}
	else if (curPage == 1)
	{
		GoTo(104, 46);
		cout << 1;
		cout << " ";
		cout << char(175);
	}
	else if (curPage == maxPage)
	{
		GoTo(102, 46);
		cout << char(174) << " ";
		cout << curPage;
	}
	else
	{
		GoTo(102, 46);
		cout << char(174) << " " << curPage << " " << char(175);
	}

	GoTo(103, 47);
	cout << "BACK";
	muiTen(102, 46, 5);
}

void ViewStudenOfClass(NodeClass* cls, int& index, int n)
{
	ShowCur(false);
	bool kt = true;
	while (true)
	{
		if (kt == true)
		{
			removeText(40, 18, 129, 30, 15, 15);
			displayStudent(cls, index, n);
			kt = false;
		}
		if (_kbhit())
		{
			char c = _getch();
			if (c == -32)
			{
				if (n > 12)
				{
					kt = true;
					c = _getch();
					if (c == 75)
					{
						if (index > 13)
						{
							index -= 12;
						}
						else if (index == 13)
						{
							index -= 13;
						}
					}
					else if (c == 77)
					{
						if (index == 0)
						{
							index += 13;
						}
						else if (index < (n - n % 12) && (n - index >= 12))
						{
							index += 12;
						}
					}
				}
			}
			else if (c == 13)
			{
				break;
			}
		}
	}
}

//Mảng a là tọa độ các cột từ trái qua phải của bảng, không có cột cuối cùng bên phải :v
void board(int x, int y, int w, int maxLine, int numLine, int ax[], int n)
{
	SetConsoleOutputCP(437);
	SetColor(15, 0);
	int dong = numLine + 1;
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
	if (index == 0 && n - index < maxline)
	{
		return n - index;
	}
	if (n - index < maxline)
	{
		return n - index + 1;
	}
	return maxline;
}

void menuStudent()
{
	while (true)
	{
		removeText(72, 17, 64, 31, 15, 15);//xóa option
		image(74, 11, "imageStudent.txt", 15, 9);
		SetColor(15, 0);
		GoTo(74, 19); cout << "User: lht";
		GoTo(74, 20); cout << "Saturday";
		GoTo(74, 21); cout << "9/6/2024";
		ShowCur(false);
		box(74, 22, 25, 2, 15, 0, "1. User Account");
		box(74, 25, 25, 2, 15, 0, "2. Registered Courses");
		box(74, 28, 25, 2, 15, 0, "3. Log Out");
		int op = optionDaChon(74, 22, 25, 3, 3);
		if (op == 1)
		{
			removeText(72, 17, 64, 31, 15, 15);//xóa option
			GoTo(74, 19);
			SetColor(15, 0);
			cout << "Alo Alo ";
			box(74, 28, 25, 2, 15, 0, "Quit");
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
		else if (op == 2)
		{
			removeText(72, 17, 64, 31, 15, 15);//xóa option
			GoTo(74, 19);
			SetColor(15, 0);
			cout << "Alo Alo ";
			box(74, 28, 25, 2, 15, 0, "Quit");
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
		else if (op == 3)
		{
			return;
		}
	}
	_getch();
}

int optionDaChon(int x, int y, int w, int h, int sl)
{
	ShowCur(false);
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
	SetColor(15, 0);
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
	SetColor(15, 15);
	GoTo(x - 1, y + 1);
	cout << " ";
	GoTo(x + 1 + w, y + 1);
	cout << " ";
	SetColor(15, 0);
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
