#include"DoHoa.h"
#include"Functions.h"

//Date CurTime;
//ListAccount LStaff;
//ListAccount LStudent;

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

void SetWindowSize(SHORT width, SHORT height)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	SMALL_RECT WindowSize;
	WindowSize.Top = 0;
	WindowSize.Left = 0;
	WindowSize.Right = width;
	WindowSize.Bottom = height;

	SetConsoleWindowInfo(hStdout, 1, &WindowSize);
}

void SetScreenBufferSize(SHORT width, SHORT height)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD NewSize;
	NewSize.X = width;
	NewSize.Y = height;

	SetConsoleScreenBufferSize(hStdout, NewSize);
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
	//GoTo(x + (w - text.length()) / 2, y + 1);
	GoTo(x + 1, y + 1);
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
void menuLogin(ListClass& lcls, NodeAca*& aca)


{
	LStaff.Head = NULL;
	UploadAccount("STAFF.csv", LStaff);
	LStudent.Head = NULL;
	UploadAccount("ACCOUNT.csv", LStudent);

	string userName, passWord;
	Account acc;
	ListCourse lcour;
	lcour.Head = NULL;

	ShowCur(false);
	SetConsoleBackgroundColor(15);
	boxNoText(15, 6, 180, 42, 15, 9);
	SetConsoleOutputCP(CP_UTF8);
	image(32, 0, "image3.txt", 15, 9);
	image(74, 8, "image4.txt", 15, 9);
	image(84, 11, "image5.txt", 15, 9);
	SetConsoleOutputCP(437);

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
		removeText(72, 10, 64, 7, 15, 15);//xóa login
		image(84, 11, "image5.txt", 15, 9);
		int check = 1;
		removeText(72, 17, 64, 31, 15, 15);//xóa option
		box(82, 24, 35, 2, 15, 0, "LOGIN");
		box(82, 28, 35, 2, 15, 0, "About Us");
		box(82, 32, 35, 2, 15, 0, "End");
		int op = 0;
		optionDaChon(82, 24, 35, 4, 3, op);
		bool kt = false;
		switch (op)
		{
		case 1: {
			while (kt != true)
			{
				check = 1;
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
				SetColor(15, 0);
				GoTo(73 + strlen("User Name : "), 24); getline(cin, userName, '\n');
				GoTo(73 + strlen("Password:  "), 28); getline(cin, passWord, '\n');
				string a[] = { "Login Successful !","Login Failed !" };
				GoTo(74, 32);
				if (check == 1)
				{
					NodeAccount* NAcc = Login(LStaff, userName, passWord);
					if (NAcc == NULL)
					{
						for (int i = 0; i < a[1].length(); i++)
						{
							cout << a[1][i];
							Sleep(50);
							kt = false;
						}
					}
					else
					{
						acc = NAcc->acc;
						for (int i = 0; i < a[0].length(); i++)
						{
							cout << a[0][i];
							Sleep(50);
							kt = true;
						}
					}
				}
				else
				{
					NodeAccount* NAcc = Login(LStudent, userName, passWord);
					if (NAcc != NULL)
					{
						acc = NAcc->acc;
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
			break;
		}
		case 2: {
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
			break;
		}
		case 3: {
			return;
		}
		}
		if (kt == true)
		{
			if (check == 1)
			{
				menuStaff(acc, lcls, CurAcademy->acm.lsm,aca);
			}
			else
			{
				menuStudent(acc);
			}
		}
	}
}

void menuStaff(Account& acc, ListClass& lcls, ListSeme& smt, NodeAca*& aca)
{
	//MAX 8 OPTION
	removeText(72, 10, 64, 7, 15, 15);//xóa login
	removeText(72, 17, 64, 31, 15, 15);//xóa option

	ShowCur(false);
	ListStudent lst = lcls.Head->cls.lst;

	bool check = true;
	int op = 0;

	while (op != 8)
	{
		removeText(16, 10, 179, 38, 15, 15);
		image(84, 11, "imageStaff.txt", 15, 9);
		khungNho();
		SetColor(15, 0);
		GoTo(74, 18); cout << "User: "; cout << acc.username;
		GoTo(74, 19); cout << "Date: " << CurTime.day << "/" << CurTime.month << "/" << CurTime.year;
		GoTo(74, 20); cout << "Academy: ";
		if (aca != NULL)
		{
			cout << aca->acm.begin << "-" << aca->acm.end;
		}
		else
		{
			cout << "NONE";
		}
		GoTo(74, 21); cout << "Semester: ";
		if (CurSemester != NULL)
		{
			cout << CurSemester->smt.STT;
		}
		else
		{
			cout << "NONE";
		}
		box(92, 22, 25, 2, 15, 0, "1. User Account ");
		box(92, 25, 25, 2, 15, 0, "2. List Of Classes");
		box(92, 28, 25, 2, 15, 0, "3. List Of Student");
		box(92, 31, 25, 2, 15, 0, "4. Courses Information");
		box(92, 34, 25, 2, 15, 0, "5. StudentList of Course");
		if (CurTime.day == 1 && CurTime.month == 9 && check == true)
		{
			box(92, 37, 25, 2, 15, 0, "6. Create Academy");
		}
		else
		{
			box(92, 37, 25, 2, 15, 0, "6. Information Semester");
		}
		box(92, 40, 25, 2, 15, 0, "7. Change The Date");
		box(92, 43, 25, 2, 15, 0, "8. LOG OUT");
		int index = 0;
		optionDaChon(92, 22, 25, 3, 8, op);
		removeText(72, 17, 64, 31, 15, 15);//xóa option
		switch (op)
		{
		case 1: {
			removeText(72, 17, 64, 31, 15, 15);//xóa option
			SetColor(15, 0);
			GoTo(82, 20);
			cout << "User name: " << acc.username;
			GoTo(82, 21);
			cout << "Name: " << acc.fullName;
			GoTo(82, 22);
			cout << "Gender: " << acc.gender;
			GoTo(82, 23);
			cout << "Date of birth: " << acc.born.day << "/" << acc.born.month << "/" << acc.born.year;
			box(82, 25, 25, 2, 15, 0, "Change Password");
			box(82, 28, 25, 2, 15, 0, "Quit");
			int opt = 0;
			optionDaChon(82, 25, 25, 3, 2, opt);
			switch (opt)
			{
			case 1:
			{
				removeText(72, 17, 64, 31, 15, 15);//xóa option
				SetColor(15, 0);
				string pass;
				ShowCur(true);
				do {
					GoTo(82, 21);
					cout << "Input curent password: ";
					int x = whereX();
					cout << "                     ";
					GoTo(x, 21);
					getline(cin, pass);
					if (pass != acc.password)
					{
						string announce = "Wrong password";
						GoTo(82, 25);
						for (int i = 0; i < announce.length(); i++)
						{
							cout << announce[i];
							Sleep(50);
						}
					}
					else
					{
						GoTo(82, 25);
						cout << "                                 ";
						string announce = "Correct password";
						GoTo(82, 25);
						for (int i = 0; i < announce.length(); i++)
						{
							cout << announce[i];
							Sleep(50);
						}
					}
				} while (pass != acc.password);
				GoTo(82, 22);
				cout << "Input new password: ";
				getline(cin, pass);
				acc.password = pass;
				changePasswordInListAccount(LStaff, acc);
				GoTo(82, 25);
				cout << "                                 ";
				string announce = "Change password successfull";
				GoTo(82, 25);
				for (int i = 0; i < announce.length(); i++)
				{
					cout << announce[i];
					Sleep(50);
				}
				_getch();
				break;
			}
			case 2:
				break;
			}
			break;
		}
		case 2: {
			if (ListAcademy.Head != NULL)
			{
				Staff2_2(ListAcademy.Head->acm, lcls);
			}
			else
			{
				GoTo(82, 25);
				SetColor(15, 0);
				cout << "Academy not exist";
				_getch();
			}
			break;
		}
		case 3: {
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
				ViewStudenOfClass(cls->cls.lst, index, countStudent(cls->cls.lst));
			}
			break;
		}
		case 4: {
			if (CurSemester == NULL || CurAcademy == NULL)
			{
				GoTo(82, 25);
				SetColor(15, 0);
				cout << "Academy not exist";
				_getch();
				continue;
			}
			removeText(72, 17, 64, 31, 15, 15);//xóa option
			SetColor(15, 0);
			ViewListOfCourse(CurSemester->smt.lcrs, index, countCourse(CurSemester->smt.lcrs));
			break;
		}
		case 5: {
			if (smt.Head == NULL)
			{
				GoTo(82, 25);
				SetColor(15, 0);
				cout << "Academy not exist";
				_getch();
				continue;
			}
			removeText(72, 17, 64, 31, 15, 15);//xóa option
			GoTo(73, 18);
			SetColor(15, 0);
			cout << "Course ID: ";
			string courseID;
			cin >> courseID;
			cin.ignore();
			NodeCourse* cour = findCourseByID(CurSemester->smt.lcrs, courseID);
			if (cour == NULL)
			{
				GoTo(73, 25);
				cout << "NULL";
				_getch();
			}
			else
			{

				ViewStudenOfClass(cour->crs.sv, index, countStudent(cour->crs.sv));
			}
			break;
		}
		case 6: {
			removeText(72, 17, 64, 31, 15, 15);//xóa option
			SetColor(15, 0);
			if (check)
			{
				BeginSchoolYear(lcls,aca);
				check = false;
			}
			else
			{
				check = false;
				if (smt.Head == NULL)
				{
					GoTo(73, 20);
					cout << "Semester not exist";
				}
				if (checkSemester(CurTime) == -1)
				{
					BeginSemester(CurSemester,aca);
				}
				else if (checkSemester(CurTime) == 1)
				{
					EndSemester(CurSemester,aca);
				}
				else if (checkSemester(CurTime) == 1 && smt.Head != NULL)
				{
					GoTo(73, 20);
					cout << "Semester: " << smt.Head->smt.STT;
					GoTo(73, 21);
					cout << "Date begin: " << smt.Head->smt.begin.day << "/" << smt.Head->smt.begin.month << "/" << smt.Head->smt.begin.year;
					GoTo(73, 21);
					cout << "Date end: " << smt.Head->smt.end.day << "/" << smt.Head->smt.end.month << "/" << smt.Head->smt.end.year;
					_getch();
				}
			}
			break;
		}
		case 7: {
			SetColor(15, 0);
			Date temp = CurTime;
			GoTo(73, 18);
			cout << "Curent time: " << CurTime.day << "/" << CurTime.month << "/" << CurTime.year;
			GoTo(73, 19);
			cout << "The begin school year time is usually early in September (1/9)";
			GoTo(73, 19);
			cout << "The school term begins on September 1st, February 1st, July 1st";
			GoTo(73, 20);
			cout << "The school term ends on January 31st, June 30th, August 31st";
			do
			{
				ShowCur(true);
				GoTo(74, 22);
				cout << "Input new time: ";
				int x = whereX();
				cout << "  /  /     ";
				GoTo(x, 22);
				cin >> CurTime.day;
				GoTo(x + 3, 22);
				cin >> CurTime.month;
				GoTo(x + 6, 22);
				cin >> CurTime.year;
				cin.ignore();
				if (!laNgayHopLe(CurTime))
				{
					GoTo(74, 25);
					string announce = "Date invalid";
					for (int i = 0; i < announce.length(); i++)
					{
						cout << announce[i];
						Sleep(50);
					}
				}
			} while (!laNgayHopLe(CurTime));
			if (CurTime.year > temp.year && CurTime.month == 9 && CurTime.day == 1)
			{
				CurAcademy->Next = new NodeAca;
				CurAcademy->Next = NULL;
				CurAcademy = CurAcademy->Next;
			}
			string announce = "Change time successful";
			ShowCur(false);
			GoTo(74, 25);
			for (int i = 0; i < announce.length(); i++)
			{
				cout << announce[i];
				Sleep(50);
			}
			_getch();
			break;
		}
		case 8: {
			break;
		}
		}
	}

}

void Staff2_2(Academy aca, ListClass& lcls)
{
	Freshman = lstClsInAYear(aca, lcls, 1);
	Sophomore = lstClsInAYear(aca, lcls, 2);
	Junior = lstClsInAYear(aca, lcls, 3);
	Senior = lstClsInAYear(aca, lcls, 4);
	int op = 0;

	while (op != 5)
	{
		removeText(72, 17, 64, 31, 15, 15);//xóa option
		SetColor(15, 0);
		box(74, 22, 25, 2, 15, 0, "Freshman year ");
		box(74, 25, 25, 2, 15, 0, "Sophomore year");
		box(74, 28, 25, 2, 15, 0, "Junior year");
		box(74, 31, 25, 2, 15, 0, "Senior year");
		box(74, 34, 25, 2, 15, 0, "Quit");
		optionDaChon(74, 22, 25, 3, 5, op);
		switch (op)
		{
		case 1: {
			removeText(72, 17, 64, 31, 15, 15);//xóa option
			SetColor(15, 0);
			int index = 0;
			if (countClass(Freshman) == 0)
			{
				GoTo(82, 18);
				cout << "Class not exist";
				box(82, 32, 35, 2, 15, 0, "Quit");
				muiTen(82, 32, 35);
				_getch();
			}
			else
			{
				ViewListOfClass(Freshman, index, countClass(Freshman));
			}
			break;
		}
		case 2: {
			removeText(72, 17, 64, 31, 15, 15);//xóa option
			SetColor(15, 0);
			int index = 0;
			if (countClass(Sophomore) == 0)
			{
				GoTo(82, 18);
				cout << "Class not exist";
				box(82, 32, 35, 2, 15, 0, "Quit");
				muiTen(82, 32, 35);
				_getch();
			}
			else
			{
				ViewListOfClass(Sophomore, index, countClass(Sophomore));
			}
			break;
		}
		case 3: {
			removeText(72, 17, 64, 31, 15, 15);//xóa option
			SetColor(15, 0);
			int index = 0;
			if (countClass(Junior) == 0)
			{
				GoTo(82, 18);
				cout << "Class not exist";
				box(82, 32, 35, 2, 15, 0, "Quit");
				muiTen(82, 32, 35);
				_getch();
			}
			else
			{
				ViewListOfClass(Junior, index, countClass(Junior));
			}
			break;
		}
		case 4: {
			removeText(72, 17, 64, 31, 15, 15);//xóa option
			SetColor(15, 0);
			int index = 0;
			if (countClass(Senior) == 0)
			{
				GoTo(82, 18);
				cout << "Class not exist";
				box(82, 32, 35, 2, 15, 0, "Quit");
				muiTen(82, 32, 35);
				_getch();
			}
			else
			{
				ViewListOfClass(Senior, index, countClass(Senior));
			}
			break;
		}
		case 5: {
			break;
		}
		}
	}
}

void BeginSchoolYear(ListClass& lcls,NodeAca*& aca)
{
	int op = 0;
	Academy acad;
	removeText(39, 10, 132, 38, 15, 15);
	image(84, 11, "imageStaff.txt", 15, 9);
	do
	{
		removeText(72, 17, 64, 31, 15, 15);//xóa option
		khungNho();
		ShowCur(true);
		SetColor(15, 0);
		GoTo(73, 18);
		cout << "Input YearBegin: ";
		cin >> acad.begin;
		GoTo(73, 19);
		cout << "Input YearEnd: ";
		cin >> acad.end;
		if (acad.end - acad.begin != 1)
		{
			GoTo(73, 20);
			cout << "Year Invalid";
			_getch();
		}
	} while (acad.end - acad.begin != 1);
	addNodeAcademy(ListAcademy, createNodeAcademy(acad));
	aca->acm = acad;
	while (op != 3)
	{
		removeText(39, 10, 132, 38, 15, 15);
		image(84, 11, "imageStaff.txt", 15, 9);
		khungNho();
		box(74, 22, 30, 2, 15, 0, "1.Add Class Of First Year");
		box(74, 25, 30, 2, 15, 0, "2.View Class Of First Year");
		box(74, 28, 30, 2, 15, 0, "3.Quit");
		optionDaChon(74, 22, 30, 3, 3, op);
		switch (op)
		{
		case 1: {
			removeText(72, 17, 64, 31, 15, 15);//xóa option
			GoTo(82, 22);
			SetColor(15, 0);
			cout << "Name Class: ";
			ShowCur(true);
			string nameClass;
			cin >> nameClass;
			cin.ignore();
			Clas cls;
			cls.nameClass = nameClass;
			cls.lst.Head = NULL;
			bool check = true;
			removeText(72, 17, 64, 31, 15, 15);//xóa option
			GoTo(82, 22);
			SetColor(15, 0);
			cout << "ADD Student";
			ShowCur(false);
			box(74, 25, 25, 2, 15, 0, "Manual Input");
			box(74, 28, 25, 2, 15, 0, "Input File CSV");
			int opt = 0;
			optionDaChon(74, 25, 25, 3, 2, opt);
			if (opt == 1)
			{
				removeText(71, 10, 5, 7, 15, 15);//xóa | login
				removeText(134, 10, 5, 7, 15, 15);//xóa | login
				removeText(40, 17, 129, 31, 15, 15);//xóa option
				khungLon();
				SetColor(15, 0);
				GoTo(82, 22);
				cout << "Class: " << cls.nameClass;
				ShowCur(true);
				GoTo(82, 22);

				inputStudent(cls.lst);

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

				readFileCSV(fileName, cls.lst, check);
				string xuat[2] = { "ADD Student successful !","ADD Student Fail !" };
				if (check)
				{
					GoTo(90, 47);
					for (int i = 0; i < xuat[0].length(); i++)
					{
						cout << xuat[0][i];
						Sleep(50);
					}
				}
				else
				{
					GoTo(90, 47);
					for (int i = 0; i < xuat[1].length(); i++)
					{
						cout << xuat[1][i];
						Sleep(50);
					}
				}
				ShowCur(false);
				_getch();
			}
			if (check)
				addNodeClass(lcls, createNodeClass(cls));
			break;
		}
		case 2: {
			removeText(72, 17, 64, 31, 15, 15);//xóa option
			int index = 0;
			if (lcls.Head == NULL)
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
				ViewListOfClass(lcls, index, countClass(lcls));
			}
			break;
		}
		case 3: {
			break;
		}
		}

	}
}

//xém xong (còn bug :3)
void BeginSemester(NodeSeme*& seme,NodeAca*&aca)
{
	removeText(16, 10, 179, 38, 15, 15);
	image(84, 11, "imageStaff.txt", 15, 9);
	khungNho();
	Semester smt;
	int op = 0;
	bool kt = true;
	if (seme == NULL)
	{
		box(92, 22, 25, 2, 15, 0, "1. Create Semester");
		box(92, 25, 25, 2, 15, 0, "2. Quit");
		int opt = 0;
		optionDaChon(92, 22, 25, 3, 2, opt);
		if (opt == 1)
		{
			while (kt)
			{
				removeText(72, 17, 64, 31, 15, 15);//xóa option
				SetColor(15, 0);
				ShowCur(true);
				GoTo(92, 19);
				cout << "Input Semester: ";
				cin >> smt.STT;
				GoTo(92, 20);
				cout << "Input Date begin: ";
				cin >> smt.begin.day >> smt.begin.month >> smt.begin.year;
				GoTo(92, 21);
				cout << "Input Date end: ";
				cin >> smt.end.day >> smt.end.month >> smt.end.year;
				if (!laNgayHopLe(smt.begin) || !laNgayHopLe(smt.end))
				{
					GoTo(92, 22);
					string announce = "Date Invalid";
					for (int i = 0; i < announce.length(); i++)
					{
						cout << announce[i];
						Sleep(50);
					}
					_getch();

				}
				else
				{
					addNodeSeme(aca->acm.lsm, createNodeSeme(smt));
					seme = createNodeSeme(smt);
					GoTo(92, 22);
					string announce = "Date Hop le";
					for (int i = 0; i < announce.length(); i++)
					{
						cout << announce[i];
						Sleep(50);
					}
					kt = false;
				}
			}
		}
		else
		{
			return;
		}
	}
	while (op != 6)
	{
		removeText(16, 10, 179, 38, 15, 15);
		image(84, 11, "imageStaff.txt", 15, 9);
		khungNho();
		box(92, 22, 25, 2, 15, 0, "1. ADD Course");
		box(92, 25, 25, 2, 15, 0, "2. List of course");
		box(92, 28, 25, 2, 15, 0, "3. Remove Course");
		box(92, 31, 25, 2, 15, 0, "4. ADD Student to course");
		box(92, 34, 25, 2, 15, 0, "5. Remove Student");
		box(92, 37, 25, 2, 15, 0, "6. Quit");
		optionDaChon(92, 22, 25, 3, 6, op);
		SetColor(15, 0);
		switch (op)
		{

		case 1: {
			if (seme != NULL)
			{
				removeText(72, 17, 64, 31, 15, 15);//xóa option
				SetColor(15, 0);
				ShowCur(true);
				Course cour;
				GoTo(73, 18);
				cout << "Course ID: ";
				cin >> cour.courseID;
				cin.ignore();
				GoTo(100, 18);
				cout << cour.courseID;
				GoTo(73, 19);
				cout << "Course Name: ";
				getline(cin, cour.courseName);
				GoTo(73, 20);
				cout << "Class Name: ";
				getline(cin, cour.className);
				GoTo(73, 21);
				cout << "Teacher Name: ";
				getline(cin, cour.teacher);
				GoTo(73, 22);
				cout << "Credit Number: ";
				cin >> cour.acaCrd;
				GoTo(73, 23);
				cout << "Student maximum: ";
				cin >> cour.maxStudent;
				cin.ignore();
				GoTo(73, 24);
				cout << "Choose Day of Week: ";
				string* dayofweek = new string[6]{ "MON","TUE","WED","THU","FRI","SAT" };
				box(74, 25, 4, 2, 15, 0, "MON");
				box(81, 25, 4, 2, 15, 0, "TUE");
				box(88, 25, 4, 2, 15, 0, "WED");
				box(95, 25, 4, 2, 15, 0, "THU");
				box(102, 25, 4, 2, 15, 0, "FRI");
				box(109, 25, 4, 2, 15, 0, "SAT");
				int dow = optionDaChon1(74, 25, 4, 3, 6);
				cour.cld.Day = dayofweek[dow - 1];
				GoTo(73, 28);
				cout << "Choose session: ";
				string* session = new string[4]{ "S1 (07:30)","S2 (09:30)","S3 (13:30)","S4 (15:30)" };
				box(74, 29, 11, 2, 15, 0, "S1 (07:30)");
				box(88, 29, 11, 2, 15, 0, "S2 (09:30)");
				box(102, 29, 11, 2, 15, 0, "S3 (13:30)");
				box(116, 29, 11, 2, 15, 0, "S4 (15:30)");
				int sess = optionDaChon1(74, 29, 11, 3, 4);
				cour.cld.Time = session[sess - 1];
				addNodeCourse(seme->smt.lcrs, createNodeCourse(cour));
				_getch();
			}

			break;
		}
		case 2: {
			removeText(72, 17, 64, 31, 15, 15);//xóa option
			int index = 0;
			if (seme == NULL || seme->smt.lcrs.Head == NULL)
			{
				GoTo(82, 31);
				SetColor(15, 0);
				cout << "Courses not exist";
				ShowCur(false);
				box(82, 32, 35, 2, 15, 0, "Quit");
				muiTen(82, 32, 35);
				_getch();
			}
			else
			{
				removeText(71, 10, 5, 7, 15, 15);//xóa | login
				removeText(134, 10, 5, 7, 15, 15);//xóa | login
				removeText(71, 17, 66, 31, 15, 15);//xóa khung nho
				khungLon();
				ViewListOfCourse(seme->smt.lcrs, index, countCourse(seme->smt.lcrs));
			}
			break;
		}
		case 3: {
			removeText(72, 17, 64, 31, 15, 15);//xóa option
			SetColor(15, 0);
			GoTo(73, 18);
			cout << "Course ID: ";
			string courseID;
			cin >> courseID;
			cin.ignore();
			if (seme != NULL)
			{
				removeCourse_IDCourse(seme->smt.lcrs, courseID);
			}
			else
			{
				GoTo(82, 31);
				SetColor(15, 0);
				cout << "Semester Init";
				ShowCur(false);
				box(82, 32, 35, 2, 15, 0, "Quit");
				muiTen(82, 32, 35);
				_getch();
			}
			break;
		}
		case 4: {
			removeText(72, 17, 64, 31, 15, 15);//xóa option
			GoTo(73, 18);
			SetColor(15, 0);
			cout << "Course ID: ";
			string courseID;
			cin >> courseID;
			cin.ignore();
			if (seme != NULL)
			{
				NodeCourse* temp = findCourseByID(seme->smt.lcrs, courseID);
				if (temp != NULL)
				{
					box(92, 20, 25, 2, 15, 0, "Manual input");
					box(92, 23, 25, 2, 15, 0, "File csv input");
					box(92, 26, 25, 2, 15, 0, "Quit");
					int opt = 0;
					optionDaChon(92, 20, 25, 3, 3, opt);
					switch (opt)
					{
					case 1:
						removeText(72, 17, 64, 31, 15, 15);//xóa option
						inputStudent(temp->crs.sv);
						break;
					case 2:
					{
						removeText(72, 17, 64, 31, 15, 15);//xóa option
						SetColor(15, 0);
						ShowCur(true);
						GoTo(82, 22);
						cout << "Nhap ten file csv: ";
						string fileName;
						getline(cin, fileName);
						bool check;
						readFileCSV(fileName, temp->crs.sv, check);
						string xuat[2] = { "ADD Student successful !","ADD Student Fail !" };
						if (check)
						{
							GoTo(90, 47);
							for (int i = 0; i < xuat[0].length(); i++)
							{
								cout << xuat[0][i];
								Sleep(50);
							}
						}
						else
						{
							GoTo(90, 47);
							for (int i = 0; i < xuat[1].length(); i++)
							{
								cout << xuat[1][i];
								Sleep(50);
							}
						}
						ShowCur(false);
						_getch();
						break;
					}
					case 3:
						break;
					}

				}
				else
				{
					GoTo(75, 25);
					cout << "NULL";
					_getch();
				}
			}
			else
			{
				GoTo(82, 31);
				SetColor(15, 0);
				cout << "Semester Init";
				ShowCur(false);
				box(82, 32, 35, 2, 15, 0, "Quit");
				muiTen(82, 32, 35);
				_getch();
			}
			break;
		}
		case 5: {
			removeText(72, 17, 64, 31, 15, 15);//xóa option
			SetColor(15, 0);
			GoTo(73, 18);
			cout << "Course ID: ";
			string courseID;
			cin >> courseID;
			cin.ignore();
			GoTo(73, 19);
			cout << "Student ID: ";
			string stID;
			getline(cin, stID);
			GoTo(73, 25);
			cout << courseID << " " << stID;
			removeStudentOfCourse(seme->smt.lcrs, courseID, stID);
			_getch();
			break;
		}
		case 6: {
			break;
		}
		}
	}

}

void EndSemester(NodeSeme*& seme,NodeAca*&aca)
{
	int op = 0;
	while (op != 6)
	{
		removeText(39, 10, 132, 38, 15, 15);
		image(84, 11, "imageStaff.txt", 15, 9);
		khungNho();
		SetColor(15, 0);
		box(87, 22, 35, 2, 15, 0, "1. Export listStudent in a course");
		box(87, 25, 35, 2, 15, 0, "2. Import file scoreborad");
		box(87, 28, 35, 2, 15, 0, "3. View scoreborad of a course");
		box(87, 31, 35, 2, 15, 0, "4. Update a student's result");
		box(87, 34, 35, 2, 15, 0, "5. View scoreboard of class");
		box(87, 37, 35, 2, 15, 0, "6. Quit");
		optionDaChon(87, 22, 35, 3, 6, op);
		removeText(72, 17, 64, 31, 15, 15);//xóa option
		switch (op)
		{
		case 1:
		{
			SetColor(15, 0);
			GoTo(73, 18);
			cout << "Course ID: ";
			string CourseID;
			getline(cin, CourseID);
			NodeCourse* crs = findCourseByID(seme->smt.lcrs, CourseID);
			GoTo(73, 19);
			cout << "File CSV name: ";
			string fileName;
			getline(cin, fileName);
			writeCoure(fileName, crs->crs);
			GoTo(73, 21);
			cout << "Ghi file thanh cong";
			break;
		}
		case 2:
		{
			SetColor(15, 0);
			GoTo(73, 18);
			cout << "Input CourseID: ";
			string courseID;
			cin >> courseID;
			cin.ignore();
			GoTo(73, 19);
			cout << "Input fileName: ";
			string fileName;
			getline(cin, fileName);
			NodeCourse* crs = findCourseByID(seme->smt.lcrs, courseID);
			if (crs != NULL) {
				readFileScoreboard(fileName, crs->crs);
				GoTo(73, 25);
				cout << "Read file successful";
			}
			else
			{
				GoTo(73, 25);
				cout << "course not exist";
				_getch();
			}
			break;
		}
		case 3:
		{
			SetColor(15, 0);
			GoTo(73, 18);
			cout << "Course ID: ";
			string CourseID;
			getline(cin, CourseID);
			NodeCourse* crs = findCourseByID(seme->smt.lcrs, CourseID);
			if (crs != NULL)
			{
				int index = 0;
				khungLon();
				ViewScoreboardCourse(crs->crs.sv, index, countStudent(crs->crs.sv));
			}
			else
			{
				GoTo(74, 20);
				cout << "Course not exist ";
				_getch();
			}
			break;
		}
		case 4:
		{
			SetColor(15, 0);
			GoTo(73, 18);
			cout << "Student ID: ";
			string studentID;
			cin >> studentID;
			cin.ignore();
			
			break;
		}
		case 6:
			break;
		}

	}
}

void inputStudent(ListStudent& lst)
{
	SetColor(15, 0);
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
			do
			{
				string khoangTrang = string(a[5] - a[4] - 1, ' ');
				GoTo(a[4] + 1, 21 + i * 2); cout << khoangTrang;
				GoTo(a[4] + 3, 21 + i * 2); cout << "/";
				GoTo(a[4] + 6, 21 + i * 2); cout << "/";
				GoTo(a[4] + 1, 21 + i * 2);
				cin >> st.DoB.day;
				GoTo(a[4] + 4, 21 + i * 2);
				cin >> st.DoB.month;
				GoTo(a[4] + 7, 21 + i * 2);
				cin >> st.DoB.year;
			} while (!laNgayHopLe(st.DoB));
			GoTo(a[5] + 1, 21 + i * 2);
			cin.ignore();
			getline(cin, st.socialID);
			splitName(st);
			addNodeStudent(lst, createNodeStudent(st));
			index++;
		}
		if (index >= n)
		{
			break;
		}
	}

}

//x=40,y=17,w=130
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

//x=72,y=17,w=64
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
void displayStudent(ListStudent lst, int index, int n)
{
	SetConsoleOutputCP(437);
	khungLon();
	boxNoTextFC(56, 18, 98, 29, 15, 15);
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
	NodeStudent* temp = findStudentByPos(lst, index);
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
void ViewStudenOfClass(ListStudent cls, int& index, int n)
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

void displayClass(ListClass lcls, int index, int n)
{
	SetColor(15, 0);
	int a[2] = { 96,100 };
	int dong = soDong(index, n, 12);
	board(96, 19, 20, 12, dong, a, 2);
	GoTo(a[0] + 1, 20);
	cout << "STT";
	GoTo(a[1] + 1, 20);
	cout << "Class Name";
	if (n > 12 && n - index <= 12)
	{
		dong++;
	}
	NodeClass* cls = findClassByPos(lcls, index);
	for (int i = 1; i <= dong; i++)
	{
		if (cls == NULL)
		{
			break;
		}
		GoTo(a[0] + 1, 20 + i * 2);
		int stt = i + index;
		if (index > 0)
		{
			stt - 1;
		}
		cout << stt;
		GoTo(a[1] + 1, 20 + i * 2);
		cout << cls->cls.nameClass;
		cls = cls->Next;
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
void ViewListOfClass(ListClass lcls, int& index, int n)
{
	ShowCur(false);
	bool kt = true;
	while (true)
	{
		if (kt == true)
		{
			removeText(72, 17, 64, 31, 15, 15);//xóa option
			displayClass(lcls, index, n);
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

void displayCourse(ListCourse lcrs, int index, int n)
{
	SetColor(15, 0);
	int a[8] = { 41,45,58,89,100,133,140,152 };
	int dong = soDong(index, n, 12);
	board(41, 19, 128, 12, dong, a, 8);
	GoTo(a[0] + 1, 20); cout << "STT";
	GoTo(a[1] + 1, 20); cout << "CourseID";
	GoTo(a[2] + 1, 20); cout << "Course name";
	GoTo(a[3] + 1, 20); cout << "Class name";
	GoTo(a[4] + 1, 20); cout << "Teacher name";
	GoTo(a[5] + 1, 20); cout << "Credit";
	GoTo(a[6] + 1, 20); cout << "Max Student";
	GoTo(a[7] + 1, 20); cout << "Session";
	if (n > 12 && n - index <= 12)
	{
		dong++;
	}
	NodeCourse* crs = findCourseByPos(lcrs, index);
	for (int i = 1; i <= dong; i++)
	{
		if (crs == NULL)
		{
			break;
		}
		int stt = index + i;
		if (index > 11)
		{
			stt = index + i - 1;
		}
		GoTo(a[0] + 1, 20 + i * 2);
		cout << stt;
		GoTo(a[1] + 1, 20 + i * 2);
		cout << crs->crs.courseID;
		GoTo(a[2] + 1, 20 + i * 2);
		cout << crs->crs.courseName;
		GoTo(a[3] + 1, 20 + i * 2);
		cout << crs->crs.className;
		GoTo(a[4] + 1, 20 + i * 2);
		cout << crs->crs.teacher;
		GoTo(a[5] + 1, 20 + i * 2);
		cout << crs->crs.acaCrd;
		GoTo(a[6] + 1, 20 + i * 2);
		cout << crs->crs.maxStudent;
		GoTo(a[7] + 1, 20 + i * 2);
		cout << crs->crs.cld.Day << " - " << crs->crs.cld.Time;
		crs = crs->Next;
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
void ViewListOfCourse(ListCourse lcrs, int& index, int n)
{
	ShowCur(false);
	bool kt = true;
	while (true)
	{
		if (kt == true)
		{
			removeText(40, 18, 129, 30, 15, 15);
			displayCourse(lcrs, index, n);
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

void displayScoreboardCourse(ListStudent lst, int index, int n)
{
	SetColor(15, 0);
	int a[7] = { 47, 52,65,109,124,138,151 };
	int dong = soDong(index, n, 12);
	board(47, 19, 116, 12, dong, a, 7);
	SetColor(15, 0);
	GoTo(a[0] + 1, 20); cout << "STT";
	GoTo(a[1] + 1, 20); cout << "Student ID";
	GoTo(a[2] + 16, 20); cout << "Full name";
	GoTo(a[3] + 1, 20); cout << "Regular mark";
	GoTo(a[4] + 1, 20); cout << "Midterm mark";
	GoTo(a[5] + 1, 20); cout << "Final mark";
	GoTo(a[6] + 1, 20); cout << "Total mark";
	if (n > 12 && n - index <= 12)
	{
		dong++;
	}
	NodeStudent* st = findStudentByPos(lst, index);
	for (int i = 1; i <= dong; i++)
	{
		if (st == NULL)
		{
			break;
		}
		GoTo(a[0] + 1, 20 + i * 2); cout << st->sv.STT;
		GoTo(a[1] + 1, 20 + i * 2); cout << st->sv.studentID;
		GoTo(a[2] + 1, 20 + i * 2); cout << st->sv.fullName;
		GoTo(a[3] + 1, 20 + i * 2);
		if (st->sv.regularMark < 0 || st->sv.regularMark>10)
		{
			cout << "None";
		}
		else
		{
			cout << st->sv.regularMark;
		}
		GoTo(a[4] + 1, 20 + i * 2);
		if (st->sv.midtermMark < 0 || st->sv.midtermMark>10)
		{
			cout << "None";
		}
		else
		{
			cout << st->sv.midtermMark;
		}
		GoTo(a[5] + 1, 20 + i * 2);
		if (st->sv.finalMark < 0 || st->sv.finalMark >10)
		{
			cout << "None";
		}
		else
		{
			cout << st->sv.finalMark;
		}
		GoTo(a[6] + 1, 20 + i * 2);
		if (st->sv.totalMark < 0 || st->sv.totalMark >10)
		{
			cout << "None";
		}
		else
		{
			cout << st->sv.totalMark;
		}
		st = st->Next;
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
void ViewScoreboardCourse(ListStudent lst, int& index, int n)
{
	ShowCur(false);
	bool kt = true;
	while (true)
	{
		if (kt == true)
		{
			removeText(40, 18, 129, 30, 15, 15);
			displayScoreboardCourse(lst, index, n);
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

void displayScoreboardClass(ListStudent lst, int index, int n);

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

void menuStudent(Account& acc)
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
		int op = 0;
		optionDaChon(74, 22, 25, 3, 3, op);
		if (op == 1)
		{
			removeText(72, 17, 64, 31, 15, 15);//xóa option
			SetColor(15, 0);
			GoTo(74, 29);
			cout << "User name: " << acc.username;
			GoTo(82, 30);
			cout << "Name: " << acc.fullName;
			GoTo(82, 31);
			cout << "Gender: " << acc.gender;
			GoTo(82, 32);
			cout << "Date of birth: " << acc.born.day << "/" << acc.born.month << "/" << acc.born.year;
			box(82, 35, 35, 2, 15, 0, "Quit");
			muiTen(82, 35, 35);
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

// 72:lên ; 80:xuống ; 75:trái ; 77:phải
void optionDaChon(int x, int y, int w, int h, int sl, int& op)
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
				SetColor(15, 0);
				op = (yp - y) / h + 1;
				return;
			}
		}
	}
}

int optionDaChon1(int x, int y, int w, int h, int sl)
{
	ShowCur(false);
	int xp = x; int yp = y;
	int xcu = xp; int ycu = yp;
	bool kt = true;
	int wx = w + 3;
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
				if (c == 75)
				{
					if (xp != x)
					{
						xp -= wx;
					}
					else
					{
						xp = x + wx * (sl - 1);
					}
				}
				else if (c == 77)
				{
					if (xp != x + wx * (sl - 1))
					{
						xp += wx;
					}
					else
					{
						xp = x;
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
	return (xp - x) / wx + 1;
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
