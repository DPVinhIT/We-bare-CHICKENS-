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

//Các hàm đồ họa đã tham khảo :3
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

//Hàm di chuyển con trỏ
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
//Tạo hộp thoại có văn bản
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
//Tạo hộp thoại nhưng k có văn bản
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
//Hàm để in ra các file txt
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

//Login
void menuLogin(ListClass& lcls, NodeAca*& aca)
{
	LStaff.Head = NULL;
	UploadAccount("STAFF.csv", LStaff);
	LStudent.Head = NULL;
	UploadAccount("STUDENT.csv", LStudent);

	string userName, passWord;
	Account acc;
	ListCourse lcour;
	lcour.Head = NULL;

	ShowCur(false);
	SetConsoleBackgroundColor(15);
	khungNho();
	SetConsoleOutputCP(CP_UTF8);
	image(32, 0, "image3.txt", 15, 9);
	image(74, 8, "image4.txt", 15, 9);
	image(84, 11, "image5.txt", 15, 9);
	SetConsoleOutputCP(437);
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
		//Login
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
		 //Thông tin		
		case 2: {
			removeText(72, 17, 64, 31, 15, 15);//xóa option
			SetColor(15, 0);
			GoTo(80, 20);
			cout << "Contact emai:..." << endl;
			ShowCur(false);
			box(94, 30, 20, 2, 15, 0, "Quit");
			muiTen(94, 30, 20);
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
		 //Kết thúc		
		case 3: {
			return;
		}
		}
		if (kt == true)
		{
			if (check == 1)
			{
				menuStaff(acc, lcls, CurAcademy->acm.lsm, aca);
			}
			else
			{
				menuStudent(acc);
			}
		}
	}
}
//Các chức năng của học sinh
void menuStudent(Account& acc)
{
	bool check = false;
	if (checkSeme() == 1)
	{
		check = true;
	}
	while (true)
	{
		removeText(16, 10, 179, 38, 15, 15);
		image(74, 11, "imageStudent.txt", 15, 9);
		khungNho();
		SetColor(15, 0);
		loginSession(acc);
		int op = 0;
		ShowCur(false);
		box(92, 22, 25, 2, 15, 0, " User Account");
		box(92, 25, 25, 2, 15, 0, " Registered Courses");
		if (check)
		{
			box(92, 28, 25, 2, 15, 0, " My Scoreboard");
			box(92, 31, 25, 2, 15, 0, " Log Out");
			optionDaChon(92, 22, 25, 3, 4, op);
			if (op == 4)
			{
				return;
			}
		}
		else
		{
			box(92, 28, 25, 2, 15, 0, " Log Out");
			optionDaChon(92, 22, 25, 3, 3, op);
			if (op == 3)
			{
				return;
			}
		}
		//User account
		if (op == 1)
		{
			removeText(72, 17, 64, 31, 15, 15);//xóa option
			OptionAnnounce("User Account", 18);
			SetColor(15, 0);
			GoTo(80, 20);
			cout << "User name: " << acc.username;
			GoTo(80, 21);
			cout << "Name: " << acc.fullName;
			GoTo(80, 22);
			cout << "Gender: " << acc.gender;
			GoTo(80, 23);
			cout << "Date of birth: " << acc.born.day << "/" << acc.born.month << "/" << acc.born.year;
			box(94, 27, 20, 2, 15, 0, "Change Password");
			box(94, 30, 20, 2, 15, 0, "Quit");
			int opt = 0;
			optionDaChon(94, 27, 20, 3, 2, opt);
			switch (opt)
			{
			case 1:
			{
				removeText(72, 17, 64, 31, 15, 15);//xóa option
				SetColor(15, 0);
				OptionAnnounce("Change Password", 18);
				string pass;
				do {
					ShowCur(true);
					GoTo(80, 20);
					cout << "Input curent password: ";
					int x = whereX();
					GoTo(x, 20);
					cin >> pass;
					cin.ignore();
					if (pass != acc.password)
					{
						GoTo(80, 19);
						slowText("Wrong password !");
						ShowCur(false);
						_getch();
						GoTo(80, 19);
						slowText("                 ");
						GoTo(x, 20);
						cout << "                     ";
					}
					else
					{
						GoTo(80, 19);
						slowText("Correct password");
					}
				} while (pass != acc.password);
				ShowCur(true);
				GoTo(80, 21);
				cout << "Input new password: ";
				getline(cin, pass);
				acc.password = pass;
				changePasswordInListAccount(LStudent, acc);
				GoTo(80, 19);
				cout << "                                 ";
				GoTo(80, 19);
				slowText("Change password successfull");
				ShowCur(false);
				box(94, 30, 20, 2, 15, 0, "Quit");
				muiTen(94, 30, 20);
				_getch();
				break;
			}
			case 2:
				break;
			}
		}
		//Registered Courses
		else if (op == 2)
		{
			int index = 0;
			removeText(72, 17, 64, 31, 15, 15);//xóa option
			OptionAnnounce("Registered Courses", 18);
			SetColor(15, 0);
			ListCourse mlc = RegisteredCourse(acc.username);
			if (mlc.Head == NULL)
			{
				GoTo(80, 19);
				slowText("The student is not registered for the course");
				ShowCur(false);
				box(94, 30, 20, 2, 15, 0, "Quit");
				muiTen(94, 30, 20);
				_getch();
			}
			else
			{
				removeText(72, 17, 64, 31, 15, 15);//xóa option
				khungLon();
				OptionAnnounce("Registered Courses", 18);
				ViewListOfCourse(mlc, index, countCourse(mlc), 10);
			}
		}
		//My Scoreboard
		else if (op == 3 && check)
		{
			int index = 0;
			removeText(72, 17, 64, 31, 15, 15);//xóa option
			OptionAnnounce("My Scoreboard", 18);
			SetColor(15, 0);
			ListCourse mlc = RegisteredCourse(acc.username);
			if (mlc.Head == NULL)
			{
				GoTo(80, 19);
				slowText("The student is not registered for the course");
				ShowCur(false);
				box(94, 30, 20, 2, 15, 0, "Quit");
				muiTen(94, 30, 20);
				_getch();
			}
			else
			{
				removeText(72, 17, 64, 31, 15, 15);//xóa option
				khungLon();
				OptionAnnounce("My Scoreboard", 18);
				SetColor(15, 0);
				GoTo(42, 19);
				cout << "GPA: " << GpaOfSemester(acc.username, CurSemester);
				cout << " / " << "Total GPA: " << GpaTotal(acc.username);
				ViewMyScoreBoard(mlc, acc.username, index, countCourse(mlc), 10);
			}
		}
	}
}
//Các chức năng của staff
void menuStaff(Account& acc, ListClass& lcls, ListSeme& smt, NodeAca*& aca)
{
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
		loginSession(acc);
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
			// User Account
		case 1: {
			removeText(72, 17, 64, 31, 15, 15);//xóa option
			OptionAnnounce("User Account", 18);
			SetColor(15, 0);
			GoTo(80, 20);
			cout << "User name: " << acc.username;
			GoTo(80, 21);
			cout << "Name: " << acc.fullName;
			GoTo(80, 22);
			cout << "Gender: " << acc.gender;
			GoTo(80, 23);
			cout << "Date of birth: " << acc.born.day << "/" << acc.born.month << "/" << acc.born.year;
			box(94, 27, 20, 2, 15, 0, "Change Password");
			box(94, 30, 20, 2, 15, 0, "Quit");
			int opt = 0;
			optionDaChon(94, 27, 20, 3, 2, opt);
			switch (opt)
			{
			case 1:
			{
				removeText(72, 17, 64, 31, 15, 15);//xóa option
				SetColor(15, 0);
				OptionAnnounce("Change Password", 18);
				string pass;
				do {
					ShowCur(true);
					GoTo(80, 20);
					cout << "Input curent password: ";
					int x = whereX();
					GoTo(x, 20);
					cin >> pass;
					cin.ignore();
					if (pass != acc.password)
					{
						GoTo(80, 19);
						slowText("Wrong password !");
						ShowCur(false);
						_getch();
						GoTo(80, 19);
						slowText("                 ");
						GoTo(x, 20);
						cout << "                     ";
					}
					else
					{
						GoTo(80, 19);
						slowText("Correct password");
					}
				} while (pass != acc.password);
				ShowCur(true);
				GoTo(80, 21);
				cout << "Input new password: ";
				getline(cin, pass);
				acc.password = pass;
				changePasswordInListAccount(LStaff, acc);
				GoTo(80, 19);
				cout << "                                 ";
				GoTo(80, 19);
				slowText("Change password successfull");
				ShowCur(false);
				box(94, 30, 20, 2, 15, 0, "Quit");
				muiTen(94, 30, 20);
				_getch();
				break;
			}
			case 2:
				break;
			}

			break;
		}
			  //List Of Classes
		case 2: {
			if (ListAcademy.Head != NULL)
			{
				Staff2_2(ListAcademy.Head->acm, lcls);
			}
			else
			{
				GoTo(80, 21);
				SetColor(15, 0);
				slowText("Academy not exist");
				box(94, 30, 20, 2, 15, 0, "Quit");
				muiTen(94, 30, 20);
				_getch();
			}
			break;
		}
			  //List Of Student
		case 3: {
			OptionAnnounce("List Of Student", 18);
			GoTo(80, 20);
			SetColor(15, 0);
			cout << "Input Name Class: ";
			ShowCur(true);
			string nameClass;
			cin >> nameClass;
			cin.ignore();
			NodeClass* cls = findClassByName(lcls, nameClass);
			if (cls == NULL)
			{
				GoTo(80, 19);
				slowText("Class not exist");
				ShowCur(false);
				box(94, 30, 20, 2, 15, 0, "Quit");
				muiTen(94, 30, 20);
				_getch();
			}
			else
			{
				removeText(71, 10, 5, 7, 15, 15);//xóa | 
				removeText(134, 10, 5, 7, 15, 15);//xóa | 
				int n = 0;
				removeText(40, 17, 129, 31, 15, 15);
				khungLon();
				OptionAnnounce(cls->cls.nameClass, 18);
				ViewStudenOfClass(cls->cls.lst, index, countStudent(cls->cls.lst), 10);
			}
			break;
		}
			  //Courses Information
		case 4: {
			OptionAnnounce("Courses Information", 18);
			if (CurSemester == NULL || CurAcademy == NULL)
			{
				GoTo(80, 20);
				SetColor(15, 0);
				slowText("Academy not exist");
				box(94, 30, 20, 2, 15, 0, "Quit");
				muiTen(94, 30, 20);
				_getch();
				continue;
			}
			removeText(72, 18, 64, 30, 15, 15);//xóa option
			khungLon();
			SetColor(15, 0);
			ViewListOfCourse(CurSemester->smt.lcrs, index, countCourse(CurSemester->smt.lcrs), 10);
			break;
		}
			  //StudentList of Course
		case 5: {
			OptionAnnounce("StudentList of course", 18);
			if (smt.Head == NULL)
			{
				GoTo(80, 20);
				SetColor(15, 0);
				slowText("Academy not exist");
				box(94, 30, 20, 2, 15, 0, "Quit");
				muiTen(94, 30, 20);
				_getch();
				continue;
			}
			removeText(72, 17, 64, 31, 15, 15);//xóa option
			OptionAnnounce("StudentList of Course", 18);
			GoTo(80, 20);
			SetColor(15, 0);
			cout << "Input CourseID: ";
			string courseID;
			cin >> courseID;
			cin.ignore();
			NodeCourse* cour = findCourseByID(CurSemester->smt.lcrs, courseID);
			if (cour == NULL)
			{
				GoTo(80, 19);
				slowText("Course Not Found !!");
				ShowCur(false);
				box(94, 30, 20, 2, 15, 0, "Quit");
				muiTen(94, 30, 20);
				_getch();
			}
			else
			{
				removeText(72, 17, 64, 31, 15, 15);//xóa option
				khungLon();
				GoTo(93, 19);
				SetColor(15, 0);
				cout << "CourseID: " << courseID;
				ViewStudenOfClass(cour->crs.sv.lst, index, countStudent(cour->crs.sv.lst), 10);
			}
			break;
		}
			  //Information Semester or create academy
		case 6: {
			removeText(72, 17, 64, 31, 15, 15);//xóa option
			SetColor(15, 0);
			if (check)
			{
				BeginSchoolYear(lcls, aca);
				check = false;
			}
			else
			{
				check = false;
				if (checkSemester(CurTime) == -1)
				{
					BeginSemester(CurSemester, aca, acc);
				}
				else if (checkSemester(CurTime) == 1)
				{
					EndSemester(aca, lcls, acc);
				}
				else if (checkSemester(CurTime) == 0 && CurSemester != NULL)
				{
					OptionAnnounce("Information Semester", 18);
					GoTo(80, 20);
					cout << "Semester: " << CurSemester->smt.STT;
					GoTo(80, 21);
					cout << "Date begin: " << CurSemester->smt.begin.day << "/" << CurSemester->smt.begin.month << "/" << CurSemester->smt.begin.year;
					GoTo(80, 22);
					cout << "Date end: " << CurSemester->smt.end.day << "/" << CurSemester->smt.end.month << "/" << CurSemester->smt.end.year;
					ShowCur(false);
					box(94, 30, 20, 2, 15, 0, "Quit");
					muiTen(94, 30, 20);
					_getch();
				}
			}
			break;
		}
			  //Change The Date
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
			Date newdate;
			do
			{
				ShowCur(true);
				GoTo(74, 22);
				cout << "Input new time: ";
				int x = whereX();
				cout << "  /  /     ";
				GoTo(x, 22);
				cin >> newdate.day;
				GoTo(x + 3, 22);
				cin >> newdate.month;
				GoTo(x + 6, 22);
				cin >> newdate.year;
				cin.ignore();
				if (!laNgayHopLe(newdate))
				{
					GoTo(74, 25);
					string announce = "Date invalid";
					for (int i = 0; i < announce.length(); i++)
					{
						cout << announce[i];
						Sleep(50);
					}
				}
			} while (changeNewDay(newdate) < 0);
			CurTime = newdate;
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
			  //Logout
		case 8: {
			break;
		}
		}
	}
}
//Phiên đăng nhập
void loginSession(Account acc)
{
	SetColor(14, 0);
	GoTo(74, 18); cout << "User: "; cout << acc.username;
	GoTo(74, 19); cout << "Date: " << CurTime.day << "/" << CurTime.month << "/" << CurTime.year;
	GoTo(74, 20); cout << "Academy: ";
	if (CurAcademy != NULL)
	{
		if (CurAcademy->acm.begin > 0 && CurAcademy->acm.begin < 3000 && CurAcademy->acm.end>0 && CurAcademy->acm.end < 3000)
		{
			cout << CurAcademy->acm.begin << "-" << CurAcademy->acm.end;
		}
		else
		{
			cout << "NONE";
		}
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
}
//Hiển thị thông báo
void OptionAnnounce(string option, int y)
{
	int n = option.length();
	int x = (211 - n) / 2 - 2;
	SetColor(14, 0);
	GoTo(x, y); cout << option;
	SetColor(15, 0);
}
void slowText(string announce)
{
	for (int i = 0; i < announce.length(); i++)
	{
		cout << announce[i];
		Sleep(50);
	}
}
//In ra danh sách lớp của các năm học
void Staff2_2(Academy aca, ListClass& lcls)
{
	Freshman = lstClsInAYear(lcls, 1);
	Sophomore = lstClsInAYear(lcls, 2);
	Junior = lstClsInAYear(lcls, 3);
	Senior = lstClsInAYear(lcls, 4);
	int op = 0;

	while (op != 5)
	{
		removeText(72, 17, 64, 31, 15, 15);//xóa option
		SetColor(15, 0);
		OptionAnnounce("List Of Classes", 18);
		box(96, 21, 20, 2, 15, 0, "Freshman");
		box(96, 24, 20, 2, 15, 0, "Sophomore");
		box(96, 27, 20, 2, 15, 0, "Junior");
		box(96, 30, 20, 2, 15, 0, "Senior");
		box(96, 33, 20, 2, 15, 0, "Quit");
		optionDaChon(96, 21, 20, 3, 5, op);
		//option
		switch (op)
		{
			//Freshman
		case 1: {
			removeText(72, 17, 64, 31, 15, 15);//xóa option
			OptionAnnounce("FRESHMAN", 18);
			SetColor(15, 0);
			int index = 0;
			if (countClass(Freshman) == 0)
			{
				GoTo(80, 19);
				slowText("Class not exist");
				box(82, 32, 35, 2, 15, 0, "Quit");
				muiTen(82, 32, 35);
				_getch();
			}
			else
			{
				ViewListOfClass(Freshman, index, countClass(Freshman), 10);
			}
			break;
		}
			  //Sophomore
		case 2: {
			removeText(72, 17, 64, 31, 15, 15);//xóa option
			OptionAnnounce("SOPHOMORE", 18);
			SetColor(15, 0);
			int index = 0;
			if (countClass(Sophomore) == 0)
			{
				GoTo(80, 19);
				slowText("Class not exist");
				box(82, 32, 35, 2, 15, 0, "Quit");
				muiTen(82, 32, 35);
				_getch();
			}
			else
			{
				ViewListOfClass(Sophomore, index, countClass(Sophomore), 10);
			}
			break;
		}
			  //Junior
		case 3: {
			removeText(72, 17, 64, 31, 15, 15);//xóa option
			OptionAnnounce("JUNIOR", 18);
			SetColor(15, 0);
			int index = 0;
			if (countClass(Junior) == 0)
			{
				GoTo(80, 19);
				slowText("Class not exist");
				box(82, 32, 35, 2, 15, 0, "Quit");
				muiTen(82, 32, 35);
				_getch();
			}
			else
			{
				ViewListOfClass(Junior, index, countClass(Junior), 10);
			}
			break;
		}
			  //Senior
		case 4: {
			removeText(72, 17, 64, 31, 15, 15);//xóa option
			OptionAnnounce("SENIOR", 18);
			SetColor(15, 0);
			int index = 0;
			if (countClass(Senior) == 0)
			{
				GoTo(80, 19);
				slowText("Class not exist");
				box(82, 32, 35, 2, 15, 0, "Quit");
				muiTen(82, 32, 35);
				_getch();
			}
			else
			{
				ViewListOfClass(Senior, index, countClass(Senior), 10);
			}
			break;
		}
		case 5: {
			break;
		}
		}
	}
}
//Các chức năng đầu năm học của staff
void BeginSchoolYear(ListClass& lcls, NodeAca*& aca)
{
	int op = 0;
	Academy acad;
	removeText(39, 10, 132, 38, 15, 15);
	image(84, 11, "imageStaff.txt", 15, 9);
	//Tao nam hoc
	do
	{
		//removeText(72, 17, 64, 31, 15, 15);//xóa option
		khungNho();
		OptionAnnounce("Create Academy", 18);
		ShowCur(true);
		SetColor(15, 0);
		GoTo(80, 20);
		cout << "Input YearBegin: ";
		int x0 = whereX();
		cin >> acad.begin;
		GoTo(80, 21);
		cout << "Input YearEnd: ";
		int x1 = whereX();
		cin >> acad.end;
		if (acad.end - acad.begin != 1)
		{
			GoTo(80, 19);
			slowText("Year Invalid");
			_getch();
			GoTo(80, 19);
			slowText("             ");
			GoTo(x0, 20); cout << "           ";
			GoTo(x1, 21); cout << "           ";
		}
	} while (acad.end - acad.begin != 1);
	CurAcademy->acm = acad;
	CurAcademy->Next = NULL;
	addNodeAcademy(ListAcademy, CurAcademy);
	GoTo(80, 23);
	slowText("Create Academy Successful !");
	_getch();
	//Cac lua chon sau khi tao
	while (op != 3)
	{
		removeText(39, 10, 132, 38, 15, 15);
		image(84, 11, "imageStaff.txt", 15, 9);
		khungNho();
		OptionAnnounce("Create Academy", 18);
		box(91, 21, 30, 2, 15, 0, "Add Class Of First Year");
		box(91, 24, 30, 2, 15, 0, "View Class Of First Year");
		box(91, 27, 30, 2, 15, 0, "Quit");
		optionDaChon(91, 21, 30, 3, 3, op);
		switch (op)
		{
			//Add Class Of First Year
		case 1: {
			removeText(72, 17, 64, 31, 15, 15);//xóa option
			OptionAnnounce("Add Class of First Year", 18);
			GoTo(80, 20);
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
			GoTo(80, 22);
			SetColor(15, 0);
			OptionAnnounce("ADD STUDENT", 22);
			ShowCur(false);
			box(94, 22, 20, 2, 15, 0, "Manual Input");
			box(94, 25, 20, 2, 15, 0, "Input File CSV");
			int opt = 0;
			optionDaChon(94, 22, 20, 3, 2, opt);
			if (opt == 1)
			{
				removeText(40, 17, 129, 31, 15, 15);//xóa option
				khungLon();
				OptionAnnounce("ADD STUDENT", 18);
				SetColor(15, 0);
				GoTo(92, 19);
				cout << "Class: " << cls.nameClass;
				ShowCur(true);

				inputStudent(cls.lst);

				addNodeClass(lcls, createNodeClass(cls));
				GoTo(90, 47);
				slowText("ADD Student successful !");
				ShowCur(false);
				_getch();
			}
			else if (opt == 2)
			{
				SetColor(15, 0);
				ShowCur(true);
				GoTo(80, 28);
				cout << "Input file name: ";
				string fileName;
				cin >> fileName;
				cin.ignore();

				readFileCSV(fileName, cls.lst, check);
				if (check)
				{
					GoTo(90, 47);
					slowText("ADD Student successful !");
				}
				else
				{
					GoTo(90, 47);
					slowText("ADD Student Fail !");
				}
				ShowCur(false);
				_getch();
			}
			if (check)
				addNodeClass(lcls, createNodeClass(cls));
			break;
		}
			  //View Class Of First Year
		case 2: {
			removeText(72, 17, 64, 31, 15, 15);//xóa option
			OptionAnnounce("View Class Of First Year", 18);
			int index = 0;
			if (lcls.Head == NULL)
			{
				GoTo(80, 19);
				slowText("Class not exist");
				ShowCur(false);
				box(94, 30, 20, 2, 15, 0, "Quit");
				muiTen(94, 30, 20);
				_getch();
			}
			else
			{

				ViewListOfClass(lcls, index, countClass(lcls), 10);
			}
			break;
		}
		case 3: {
			break;
		}
		}

	}
}
//Các chức năng đầu học kì của staff
void BeginSemester(NodeSeme*& seme, NodeAca*& aca, Account acc)
{
	removeText(16, 10, 179, 38, 15, 15);
	image(84, 11, "imageStaff.txt", 15, 9);
	khungNho();
	Semester smt;
	int op = 0;
	bool kt = true;
	//Tao hoc ki
	if (seme == NULL)
	{
		OptionAnnounce("Create Semester", 18);
		SetColor(15, 0);
		box(92, 23, 25, 2, 15, 0, " Create First Semester");
		box(92, 26, 25, 2, 15, 0, " Create Second Semester");
		box(92, 29, 25, 2, 15, 0, " Create Third Semester");
		box(92, 32, 25, 2, 15, 0, " Quit");
		int opt = 0;
		optionDaChon(92, 23, 25, 3, 4, opt);
		switch (opt)
		{
			//Hoc ki 1
		case 1: {
			smt.STT = 1;
			smt.begin.day = 1;
			smt.begin.month = 9;
			smt.begin.year = aca->acm.begin;
			smt.end.day = 31;
			smt.end.month = 1;
			smt.end.year = aca->acm.end;
			break;
		}
			  //Hoc ki 2
		case 2: {
			smt.STT = 2;
			smt.begin.day = 1;
			smt.begin.month = 2;
			smt.begin.year = aca->acm.end;
			smt.end.day = 30;
			smt.end.month = 6;
			smt.end.year = aca->acm.end;
			break;
		}
			  //Hoc ki 3
		case 3: {
			smt.STT = 3;
			smt.begin.day = 1;
			smt.begin.month = 7;
			smt.begin.year = aca->acm.end;
			smt.end.day = 31;
			smt.end.month = 8;
			smt.end.year = aca->acm.end;
			break;
		}
		case 4:
			return;
		}
		GoTo(80, 19);
		slowText("Create Semester Successful !");
		GoTo(80, 20);
		slowText("Semester: ");
		SetColor(15, 0);
		cout << smt.STT;
		GoTo(80, 21);
		slowText("Begin: ");
		cout << smt.begin.day << "/" << smt.begin.month << "/" << smt.begin.year;
		GoTo(80, 22);
		slowText("End: ");
		cout << smt.end.day << "/" << smt.end.month << "/" << smt.end.year;
		CurTime.day = smt.begin.day;
		CurTime.month = smt.begin.month;
		CurTime.year = smt.begin.year;
		smt.lcrs.Head = NULL;
		seme = new NodeSeme;
		seme->smt = smt;
		seme->Next = NULL;
		addNodeSeme(aca->acm.lsm, seme);
		_getch();
	}
	//Cac chuc nang sau khi tao hoc ki
	while (op != 7)
	{
		removeText(16, 10, 179, 38, 15, 15);
		image(84, 11, "imageStaff.txt", 15, 9);
		khungNho();
		string ann = "BEGIN Semester " + to_string(CurSemester->smt.STT);
		OptionAnnounce(ann, 18);
		loginSession(acc);
		box(92, 22, 25, 2, 15, 0, "ADD Course");
		box(92, 25, 25, 2, 15, 0, "List of course");
		box(92, 28, 25, 2, 15, 0, "Update Course");
		box(92, 31, 25, 2, 15, 0, "Remove Course");
		box(92, 34, 25, 2, 15, 0, "ADD Student to course");
		box(92, 37, 25, 2, 15, 0, "Remove Student of course");
		box(92, 40, 25, 2, 15, 0, "Quit");
		optionDaChon(92, 22, 25, 3, 7, op);
		SetColor(15, 0);
		switch (op)
		{
			//ADD Course
		case 1: {
			if (seme != NULL)
			{
				removeText(72, 17, 64, 31, 15, 15);//xóa option
				SetColor(15, 0);
				OptionAnnounce("ADD Course", 18);
				ShowCur(true);
				Course cour;
				GoTo(73, 21); cout << "Course ID:";
				boxNoText(whereX(), 20, 62 - strlen("Course ID:"), 2, 15, 0);

				GoTo(73, 24); cout << "Course Name:";
				boxNoText(whereX(), 23, 62 - strlen("Course Name:"), 2, 15, 0);

				GoTo(73, 27); cout << "Class Name:";
				boxNoText(whereX(), 26, 62 - strlen("Class Name:"), 2, 15, 0);

				GoTo(73, 30); cout << "Teacher Name:";
				boxNoText(whereX(), 29, 62 - strlen("Teacher Name:"), 2, 15, 0);

				GoTo(73, 33); cout << "Number of credit:";
				boxNoText(whereX(), 32, 62 - strlen("Number of credit:"), 2, 15, 0);

				GoTo(73, 36); cout << "Student maximum:";
				boxNoText(whereX(), 35, 62 - strlen("Student maximum:"), 2, 15, 0);

				GoTo(73 + strlen("Course ID: "), 21);
				cin >> cour.courseID;
				cin.ignore();
				GoTo(73 + strlen("Course Name: "), 24);
				getline(cin, cour.courseName);
				GoTo(73 + strlen("Class Name: "), 27);
				getline(cin, cour.className);
				GoTo(73 + strlen("Teacher Name: "), 30);
				getline(cin, cour.teacher);
				GoTo(73 + strlen("Number of credit: "), 33);
				cin >> cour.acaCrd;
				GoTo(73 + strlen("Student maximum: "), 36);
				cin >> cour.maxStudent;
				cin.ignore();
				GoTo(73, 38);
				cout << "Choose Day of Week: ";
				string* dayofweek = new string[6]{ "MON","TUE","WED","THU","FRI","SAT" };
				box(74, 39, 4, 2, 15, 0, "MON");
				box(81, 39, 4, 2, 15, 0, "TUE");
				box(88, 39, 4, 2, 15, 0, "WED");
				box(95, 39, 4, 2, 15, 0, "THU");
				box(102, 39, 4, 2, 15, 0, "FRI");
				box(109, 39, 4, 2, 15, 0, "SAT");
				int dow = optionDaChon1(74, 39, 4, 3, 6);
				cour.cld.Day = dayofweek[dow - 1];
				GoTo(73, 42);
				cout << "Choose session: ";
				string* session = new string[4]{ "S1 (07:30)","S2 (09:30)","S3 (13:30)","S4 (15:30)" };
				box(74, 43, 11, 2, 15, 0, "S1 (07:30)");
				box(88, 43, 11, 2, 15, 0, "S2 (09:30)");
				box(102, 43, 11, 2, 15, 0, "S3 (13:30)");
				box(116, 43, 11, 2, 15, 0, "S4 (15:30)");
				int sess = optionDaChon1(74, 43, 11, 3, 4);
				cour.cld.Time = session[sess - 1];
				addNodeCourse(seme->smt.lcrs, createNodeCourse(cour));
				GoTo(88, 46);
				slowText("Add Course Successful !");
				_getch();
			}

			break;
		}
			  //List of course
		case 2: {
			removeText(72, 17, 64, 31, 15, 15);//xóa option
			OptionAnnounce("List of course", 18);
			int index = 0;
			if (seme == NULL || seme->smt.lcrs.Head == NULL)
			{
				GoTo(80, 20);
				SetColor(15, 0);
				slowText("Courses not exist");
				ShowCur(false);
				box(94, 30, 20, 2, 15, 0, "Quit");
				muiTen(94, 30, 20);
				_getch();
			}
			else
			{
				khungLon();
				OptionAnnounce("List of course", 18);
				ViewListOfCourse(seme->smt.lcrs, index, countCourse(seme->smt.lcrs), 10);
			}
			break;
		}
			  //Update Course
		case 3: {
			removeText(72, 17, 64, 31, 15, 15);//xóa option
			OptionAnnounce("Update Course", 18);
			SetColor(15, 0);
			ShowCur(true);
			GoTo(80, 20);
			cout << "Input courseID:";
			string courseID;
			cin >> courseID;
			cin.ignore();
			NodeCourse* cr = findCourseByID(seme->smt.lcrs, courseID);
			if (cr == NULL)
			{
				GoTo(80, 19);
				slowText("Course not found !!");
				ShowCur(false);
				box(94, 30, 20, 2, 15, 0, "Quit");
				muiTen(94, 30, 20);
				_getch();
			}
			else
			{

				GoTo(73, 22); cout << "Course Name:";
				boxNoText(whereX(), 21, 62 - strlen("Course Name:"), 2, 15, 0);

				GoTo(73, 25); cout << "Class Name:";
				boxNoText(whereX(), 24, 62 - strlen("Class Name:"), 2, 15, 0);

				GoTo(73, 28); cout << "Teacher Name:";
				boxNoText(whereX(), 27, 62 - strlen("Teacher Name:"), 2, 15, 0);

				GoTo(73, 31); cout << "Number of credit:";
				boxNoText(whereX(), 30, 62 - strlen("Number of credit:"), 2, 15, 0);

				GoTo(73, 34); cout << "Student maximum:";
				boxNoText(whereX(), 33, 62 - strlen("Student maximum:"), 2, 15, 0);

				GoTo(73 + strlen("Course Name: "), 22);
				cin >> cr->crs.courseName;
				cin.ignore();
				GoTo(73 + strlen("Class Name: "), 25);
				getline(cin, cr->crs.className);
				GoTo(73 + strlen("Teacher Name: "), 28);
				getline(cin, cr->crs.teacher);
				GoTo(73 + strlen("Number of credit: "), 31);
				cin >> cr->crs.acaCrd;
				GoTo(73 + strlen("Student maximum: "), 34);
				cin >> cr->crs.maxStudent;
				cin.ignore();
				GoTo(73, 36);
				cout << "Choose Day of Week: ";
				string* dayofweek = new string[6]{ "MON","TUE","WED","THU","FRI","SAT" };
				box(74, 37, 4, 2, 15, 0, "MON");
				box(81, 37, 4, 2, 15, 0, "TUE");
				box(88, 37, 4, 2, 15, 0, "WED");
				box(95, 37, 4, 2, 15, 0, "THU");
				box(102, 37, 4, 2, 15, 0, "FRI");
				box(109, 37, 4, 2, 15, 0, "SAT");
				int dow = optionDaChon1(74, 37, 4, 3, 6);
				cr->crs.cld.Day = dayofweek[dow - 1];
				GoTo(73, 40);
				cout << "Choose session: ";
				string* session = new string[4]{ "S1 (07:30)","S2 (09:30)","S3 (13:30)","S4 (15:30)" };
				box(74, 41, 11, 2, 15, 0, "S1 (07:30)");
				box(88, 41, 11, 2, 15, 0, "S2 (09:30)");
				box(102, 41, 11, 2, 15, 0, "S3 (13:30)");
				box(116, 41, 11, 2, 15, 0, "S4 (15:30)");
				int sess = optionDaChon1(74, 41, 11, 3, 4);
				cr->crs.cld.Time = session[sess - 1];
				GoTo(88, 46);
				slowText("Update Course Successful !");
				_getch();

			}
			break;
		}
		//Remove Course
		case 4: {
			removeText(72, 17, 64, 31, 15, 15);//xóa option
			SetColor(15, 0);
			OptionAnnounce("Remove Cource", 18);
			GoTo(80, 20);
			ShowCur(true);
			cout << "Course ID: ";
			string courseID;
			cin >> courseID;
			cin.ignore();
			NodeCourse* cr = findCourseByID(seme->smt.lcrs, courseID);
			if (seme != NULL)
			{
				if (cr != NULL)
				{
					GoTo(80, 19);
					slowText("Remove Course Successful !");
					removeCourse_IDCourse(seme->smt.lcrs, courseID);
					ShowCur(false);
					box(94, 30, 20, 2, 15, 0, "Quit");
					muiTen(94, 30, 20);
					_getch();
				}
				else
				{
					GoTo(80, 19);
					slowText("Course not found !!");
					ShowCur(false);
					box(94, 30, 20, 2, 15, 0, "Quit");
					muiTen(94, 30, 20);
					_getch();
				}
			}
			else
			{
				GoTo(80, 19);
				slowText("Semester NOT EXIST !");
				ShowCur(false);
				box(94, 30, 20, 2, 15, 0, "Quit");
				muiTen(94, 30, 20);
				_getch();
			}
			break;
		}
			  //ADD Student to course
		case 5: {
			removeText(72, 17, 64, 31, 15, 15);//xóa option
			OptionAnnounce("ADD Student to course", 18);
			SetColor(15, 0);
			GoTo(80, 20);
			cout << "Input Course ID: ";
			string courseID;
			cin >> courseID;
			cin.ignore();
			if (seme != NULL)
			{
				NodeCourse* temp = findCourseByID(seme->smt.lcrs, courseID);
				if (temp != NULL)
				{
					box(92, 22, 20, 2, 15, 0, "Manual input");
					box(92, 25, 20, 2, 15, 0, "File csv input");
					box(92, 28, 20, 2, 15, 0, "Quit");
					int opt = 0;
					optionDaChon(92, 22, 20, 3, 3, opt);
					switch (opt)
					{
					case 1:
						removeText(72, 17, 64, 31, 15, 15);//xóa option
						khungLon();
						OptionAnnounce("ADD Student to course", 18);
						GoTo(95, 19);
						SetColor(15, 0);
						cout << "CourseID: " << temp->crs.courseID;
						inputStudent(temp->crs.sv.lst);
						GoTo(88, 46);
						slowText("ADD Student successful !");
						_getch();
						break;
					case 2:
					{
						SetColor(15, 0);
						ShowCur(true);
						GoTo(80, 32);
						cout << "Input file name: ";
						string fileName;
						getline(cin, fileName);
						temp->crs.sv.nameClass = fileName.substr(0, fileName.find_first_of('.'));
						bool check;
						readFileCSV(fileName, temp->crs.sv.lst, check);
						if (countStudent(temp->crs.sv.lst) > temp->crs.maxStudent)
						{
							check = false;
							removeListStudent(temp->crs.sv.lst);
						}
						if (check)
						{
							GoTo(88, 46);
							slowText("ADD Student successful !");
						}
						else
						{
							GoTo(88, 46);
							slowText("ADD Student Fail !");
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
					GoTo(80, 19);
					slowText("Course not exist !!");
					box(94, 30, 20, 2, 15, 0, "Quit");
					muiTen(94, 30, 20);
					_getch();
				}
			}
			else
			{
				GoTo(80, 19);
				SetColor(15, 0);
				slowText("Semester not exist !!");
				ShowCur(false);
				box(82, 32, 35, 2, 15, 0, "Quit");
				muiTen(82, 32, 35);
				_getch();
			}
			break;
		}
			  //Remove Student of course
		case 6: {
			removeText(72, 17, 64, 31, 15, 15);//xóa option
			OptionAnnounce("Remove Student of course", 18);
			SetColor(15, 0);
			GoTo(80, 20);
			cout << "Input CourseID: ";
			string courseID;
			cin >> courseID;
			cin.ignore();
			NodeCourse* cr = findCourseByID(seme->smt.lcrs, courseID);
			if (cr == NULL)
			{
				GoTo(80, 19);
				slowText("Course not exist !!");
				ShowCur(false);
				box(94, 30, 20, 2, 15, 0, "Quit");
				muiTen(94, 30, 20);
				_getch();
				break;
			}
			GoTo(80, 21);
			cout << "Input StudentID: ";
			string stID;
			getline(cin, stID);
			if (findStudentByID(cr->crs.sv.lst, stID) == NULL)
			{
				GoTo(80, 19);
				slowText("Student not found in Course !!");
				ShowCur(false);
				box(94, 30, 20, 2, 15, 0, "Quit");
				muiTen(94, 30, 20);
				_getch();
				break;
			}
			else
			{
				removeStudentOfCourse(seme->smt.lcrs, courseID, stID);
				GoTo(80, 19);
				slowText("Remove Student Successful ");
				ShowCur(false);
				box(94, 30, 20, 2, 15, 0, "Quit");
				muiTen(94, 30, 20);
				_getch();
			}
			break;
		}
		case 7: {
			break;
		}
		}
	}

}
//Các chức năng cuối kì của staff
void EndSemester(NodeAca*& aca, ListClass lcls, Account acc)
{
	int op = 0;
	while (op != 6)
	{
		removeText(39, 10, 132, 38, 15, 15);
		image(84, 11, "imageStaff.txt", 15, 9);
		khungNho();
		string ann = "END Semester " + to_string(CurSemester->smt.STT);
		OptionAnnounce(ann, 18);
		loginSession(acc);
		SetColor(15, 0);
		box(90, 22, 32, 2, 15, 0, " Export listStudent in a course");
		box(90, 25, 32, 2, 15, 0, " Import file scoreborad");
		box(90, 28, 32, 2, 15, 0, " View scoreborad of a course");
		box(90, 31, 32, 2, 15, 0, " Update a student's result");
		box(90, 34, 32, 2, 15, 0, " View scoreboard of class");
		box(90, 37, 32, 2, 15, 0, " Quit");
		optionDaChon(90, 22, 32, 3, 6, op);
		removeText(72, 17, 64, 31, 15, 15);//xóa option
		switch (op)
		{
			//Export listStudent in a course
		case 1: {
			OptionAnnounce("Export listStudent in a course", 18);
			SetColor(15, 0);
			GoTo(80, 20);
			ShowCur(true);
			cout << "Input CourseID: ";
			string CourseID;
			cin >> CourseID;
			cin.ignore();
			NodeCourse* crs = findCourseByID(CurSemester->smt.lcrs, CourseID);
			if (crs == NULL)
			{
				GoTo(80, 19);
				slowText("Course not exist !!");
				ShowCur(false);
				box(94, 30, 20, 2, 15, 0, "Quit");
				muiTen(94, 30, 20);
				_getch();
				break;
			}
			GoTo(80, 21);
			cout << "Input file name: ";
			string fileName;
			getline(cin, fileName);
			writeCoure(fileName, crs->crs);
			GoTo(80, 19);
			slowText("Write file successfull !");
			ShowCur(false);
			box(94, 30, 20, 2, 15, 0, "Quit");
			muiTen(94, 30, 20);
			_getch();
			break;
		}
			  //Import file scoreborad
		case 2: {
			OptionAnnounce("Import file scoreborad", 18);
			SetColor(15, 0);
			ShowCur(true);
			GoTo(80, 20);
			cout << "Input CourseID: ";
			string courseID;
			cin >> courseID;
			cin.ignore();
			NodeCourse* crs = findCourseByID(CurSemester->smt.lcrs, courseID);
			if (crs == NULL)
			{
				GoTo(80, 19);
				slowText("Course not exist !!");
				ShowCur(false);
				box(94, 30, 20, 2, 15, 0, "Quit");
				muiTen(94, 30, 20);
				_getch();
				break;
			}
			GoTo(80, 21);
			cout << "Input fileName: ";
			string fileName;
			getline(cin, fileName);
			readFileScoreboard(fileName, crs->crs);
			GoTo(80, 19);
			slowText("Read file successful");
			ShowCur(false);
			box(94, 30, 20, 2, 15, 0, "Quit");
			muiTen(94, 30, 20);
			_getch();
			break;
		}
			  //View scoreborad of a course
		case 3: {
			OptionAnnounce("View scoreborad of a course", 18);
			SetColor(15, 0);
			GoTo(80, 20);
			ShowCur(true);
			cout << "Input CourseID: ";
			string CourseID;
			cin >> CourseID;
			cin.ignore();
			NodeCourse* crs = findCourseByID(CurSemester->smt.lcrs, CourseID);
			if (crs != NULL)
			{
				int index = 0;
				removeText(72, 17, 64, 31, 15, 15);//xóa option
				khungLon();
				OptionAnnounce("View scoreborad of a course", 18);
				GoTo(94, 19);
				cout << "CourseID: " << crs->crs.courseID;
				ViewScoreboardCourse(crs->crs.sv.lst, index, countStudent(crs->crs.sv.lst), 10);
			}
			else
			{
				GoTo(80, 19);
				slowText("Course not exist !");
				ShowCur(false);
				box(94, 30, 20, 2, 15, 0, "Quit");
				muiTen(94, 30, 20);
				_getch();
			}
			break;
		}
			  //Update a student's result
		case 4: {
			OptionAnnounce("Update a student's result", 18);
			int index = 0;
			SetColor(15, 0);
			GoTo(80, 20);
			ShowCur(true);
			cout << "Input StudentID: ";
			string studentID;
			cin >> studentID;
			cin.ignore();
			ListCourse lcr = RegisteredCourse(studentID);
			if (lcr.Head == NULL)
			{
				GoTo(80, 19);
				slowText("Student not found !!");
				ShowCur(false);
				box(94, 30, 20, 2, 15, 0, "Quit");
				muiTen(94, 30, 20);
				_getch();
			}
			else
			{
				removeText(72, 17, 64, 31, 15, 15);//xóa option
				khungLon();
				OptionAnnounce("Update a student's result", 18);
				SetColor(15, 0);
				GoTo(92, 19);
				slowText("CourseList of Student");
				ViewListOfCourse(lcr, index, countCourse(lcr), 10);
				SetColor(15, 0);
				GoTo(92, 19);
				cout << "                       ";
				GoTo(80, 19);
				slowText("Input CourseID: ");
				ShowCur(true);
				string courseID;
				getline(cin, courseID);
				NodeCourse* cr = findCourseByID(lcr, courseID);
				if (cr == NULL)
				{
					GoTo(80, 19);
					cout << "                           ";
					GoTo(80, 19);
					slowText("Course not exist !!");
					ShowCur(false);
					box(94, 45, 15, 2, 15, 0, "Quit");
					muiTen(94, 45, 15);
					_getch();
					break;
				}
				ListStudent lt;
				lt.Head = createNodeStudent(findStudentByID(cr->crs.sv.lst, studentID)->sv);
				lt.Head->Next = NULL;
				index = 0;
				removeText(40, 18, 130, 30, 15, 15);//xoa option
				khungLon();
				displayScoreboardCourse(lt, index, countStudent(lt), 10);
				int a[7] = { 47, 52,65,109,124,138,151 };
				GoTo(a[3] + 1, 23);
				cout << "         ";
				GoTo(a[4] + 1, 23);
				cout << "         ";
				GoTo(a[5] + 1, 23);
				cout << "         ";
				GoTo(a[6] + 1, 23);
				cout << "         ";
				ShowCur(true);

				GoTo(a[3] + 1, 23);
				cin >> lt.Head->sv.regularMark;
				GoTo(a[4] + 1, 23);
				cin >> lt.Head->sv.midtermMark;
				GoTo(a[5] + 1, 23);
				cin >> lt.Head->sv.finalMark;
				GoTo(a[6] + 1, 23);
				cin >> lt.Head->sv.totalMark;
				NodeStudent* st = findStudentByID(cr->crs.sv.lst, studentID);
				if (st != NULL)
				{
					st->sv = lt.Head->sv;
					GoTo(80, 19);
					slowText("Update a student's result successful !");
					ShowCur(false);
					_getch();
				}
			}
			break;
		}
			 // View scoreboard of class
		case 5: {
			int index = 0;
			SetColor(15, 0);
			OptionAnnounce("View scoreboard of class", 18);
			GoTo(80, 20);
			ShowCur(true);
			cout << "Input Class name : ";
			string className;
			cin >> className;
			cin.ignore();
			NodeClass* cls = findClassByName(lcls, className);
			if (cls == NULL)
			{
				GoTo(80, 19);
				slowText("Class not exist !!");
				ShowCur(false);
				box(94, 30, 20, 2, 15, 0, "Quit");
				muiTen(94, 30, 20);
				_getch();
				break;
			}
			ListCourse lcr = CourseOfClass(className);
			removeText(40, 18, 129, 30, 15, 15);//xoa option
			khungLon();
			SetColor(15, 0);
			GoTo(91, 19);
			cout << "CourseList of Class: " << className;
			ViewListOfCourse(lcr, index, countCourse(lcr), 10);
			SetColor(15, 0);
			GoTo(91, 19);
			cout << "                              ";
			ShowCur(true);
			GoTo(80, 19);
			slowText("Input CourseID: ");
			string courseID;
			getline(cin, courseID);
			NodeCourse* cr = findCourseByID(lcr, courseID);
			if (cr != NULL)
			{
				index = 0;
				removeText(40, 18, 130, 30, 15, 15);//xoa option
				khungLon();
				string ann = "Scoreboard of class " + className;
				OptionAnnounce(ann, 18);
				GoTo(89, 19);
				cout << "CourseID: " << courseID;
				ViewScoreBoadClass(cr->crs.sv.lst, index, countStudent(cr->crs.sv.lst), 10);
			}
			else
			{
				GoTo(80, 19);
				cout << "                                ";
				GoTo(80, 19);
				slowText("Course not exist !!");
				ShowCur(false);
				_getch();
				break;
			}
			break;
		}
		case 6:
			break;
		}

	}
}
//Hàm nhập sinh viên
void inputStudent(ListStudent& lst)
{
	SetColor(15, 0);
	GoTo(48, 20);
	cout << "Input number of students for class: ";
	ShowCur(true);
	int n;
	cin >> n;
	cin.ignore();
	int index = 0;
	while (index != n)
	{
		SetConsoleOutputCP(437);
		removeText(40, 20, 129, 27, 15, 15);//xóa bảng
		int dong = 10;
		if (n - index < 10)
		{
			dong = n - index;
		}
		int a[6] = { 47,52,65,120,129,145 };
		board(47, 21, 116, 10, dong, a, 6);
		GoTo(a[0] + 1, 22);
		cout << "Num ";
		GoTo(a[1] + 1, 22);
		cout << " Student ID ";
		GoTo(a[2] + 16, 22);
		cout << " Full Name ";
		GoTo(a[3] + 1, 22);
		cout << " Gender ";
		GoTo(a[4] + 1, 22);
		cout << " Date of birth ";
		GoTo(a[5] + 4, 22);
		cout << " Social ID ";
		ShowCur(true);
		for (int i = 1; i <= dong; i++)
		{
			Student st;
			GoTo(a[0] + 1, 22 + i * 2);
			int stt = index + 1;
			cout << stt;
			st.STT = stt;
			GoTo(a[1] + 1, 22 + i * 2);
			cin >> st.studentID;
			cin.ignore();
			GoTo(a[2] + 1, 22 + i * 2);
			getline(cin, st.fullName);
			GoTo(a[3] + 1, 22 + i * 2);
			getline(cin, st.Gender);
			do
			{
				string khoangTrang = string(a[5] - a[4] - 1, ' ');
				GoTo(a[4] + 1, 22 + i * 2); cout << khoangTrang;
				GoTo(a[4] + 3, 22 + i * 2); cout << "/";
				GoTo(a[4] + 6, 22 + i * 2); cout << "/";
				GoTo(a[4] + 1, 22 + i * 2);
				cin >> st.DoB.day;
				GoTo(a[4] + 4, 22 + i * 2);
				cin >> st.DoB.month;
				GoTo(a[4] + 7, 22 + i * 2);
				cin >> st.DoB.year;
				if (!laNgayHopLe(st.DoB))
				{
					GoTo(92, 44);
					slowText("Date Invalid");
					_getch();
					GoTo(92, 44);
					slowText("             ");
				}
			} while (!laNgayHopLe(st.DoB));
			GoTo(a[5] + 1, 22 + i * 2);
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
//x=40, w=130
void khungLon()
{
	SetConsoleOutputCP(437);
	boxNoText(72, 6, 64, 42, 15, 15);
	SetColor(15, 15);
	GoTo(72, 10); cout << " ";
	GoTo(136, 10); cout << " ";
	GoTo(73, 10);
	for (int i = 73; i < 136; i++)
		cout << " ";
	GoTo(72 + 64, 17); cout << " ";
	GoTo(72, 17); cout << " ";
	for (int i = 73; i < 72 + 64; i++)
		cout << " ";

	boxNoText(40, 6, 130, 42, 15, 9);
	SetColor(15, 9);
	GoTo(40, 10); cout << char(204);
	GoTo(170, 10); cout << char(185);
	GoTo(41, 10);
	for (int i = 41; i < 170; i++)
		cout << char(205);
	GoTo(170, 17); cout << char(185);
	GoTo(40, 17); cout << char(204);
	for (int i = 41; i < 170; i++)
		cout << char(205);
}
//x=72, w=64
void khungNho()
{
	SetConsoleOutputCP(437);

	boxNoText(40, 6, 130, 42, 15, 15);
	SetColor(15, 15);
	GoTo(40, 10); cout << " ";
	GoTo(170, 10); cout << " ";
	GoTo(41, 10);
	for (int i = 41; i < 170; i++)
		cout << " ";
	GoTo(170, 17); cout << " ";
	GoTo(40, 17); cout << " ";
	for (int i = 41; i < 170; i++)
		cout << " ";

	boxNoText(72, 6, 64, 42, 15, 9);
	SetColor(15, 9);
	GoTo(72, 10); cout << char(204);
	GoTo(136, 10); cout << char(185);
	GoTo(73, 10);
	for (int i = 73; i < 136; i++)
		cout << char(205);
	GoTo(72 + 64, 17); cout << char(185);
	GoTo(72, 17); cout << char(204);
	for (int i = 73; i < 72 + 64; i++)
		cout << char(205);

}
//Xuất danh sách sinh viên
void displayStudent(ListStudent lst, int index, int n, int maxline)
{
	SetColor(15, 0);
	int a[7] = { 47, 52,65,107,120,129,145 };
	int dong = soDong(index, n, maxline);
	board(47, 20, 116, maxline, dong, a, 7);

	GoTo(a[0] + 1, 21);
	cout << "Num ";
	GoTo(a[1] + 1, 21);
	cout << " Student ID ";
	GoTo(a[2] + 16, 21);
	cout << " Full Name ";
	GoTo(a[3] + 1, 21);
	cout << " First Name ";
	GoTo(a[4] + 1, 21);
	cout << " Gender ";
	GoTo(a[5] + 1, 21);
	cout << " Date of birth ";
	GoTo(a[6] + 4, 21);
	cout << " Social ID ";
	if (n > maxline && n - index <= maxline)
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
		GoTo(a[0] + 1, 21 + i * 2);
		cout << temp->sv.STT;
		GoTo(a[1] + 1, 21 + i * 2);
		cout << temp->sv.studentID;
		GoTo(a[2] + 1, 21 + i * 2);
		cout << temp->sv.fullName;
		GoTo(a[3] + 1, 21 + i * 2);
		cout << temp->sv.firstName;
		GoTo(a[4] + 1, 21 + i * 2);
		cout << temp->sv.Gender;
		GoTo(a[5] + 1, 21 + i * 2);
		cout << temp->sv.DoB.day;
		cout << "/";
		cout << temp->sv.DoB.month;
		cout << "/";
		cout << temp->sv.DoB.year;
		GoTo(a[6] + 1, 21 + i * 2);
		cout << temp->sv.socialID;
		temp = temp->Next;
	}
	int maxPage = (n + maxline - 1) / maxline;
	int curPage = (index + maxline - 1) / maxline;
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
void ViewStudenOfClass(ListStudent cls, int& index, int n, int maxline)
{
	ShowCur(false);
	bool kt = true;
	while (true)
	{
		if (kt == true)
		{
			removeText(40, 19, 129, 29, 15, 15);
			displayStudent(cls, index, n, maxline);
			kt = false;
		}
		if (_kbhit())
		{
			char c = _getch();
			if (c == -32)
			{
				if (n > maxline)
				{
					kt = true;
					c = _getch();
					if (c == 75)
					{
						if (index > maxline + 1)
						{
							index -= maxline;
						}
						else if (index == maxline + 1)
						{
							index -= maxline + 1;
						}
					}
					else if (c == 77)
					{
						if (index == 0)
						{
							index += maxline + 1;
						}
						else if (index < (n - n % maxline) && (n - index >= maxline))
						{
							index += maxline;
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
//Xuất danh sách các lớp
void displayClass(ListClass lcls, int index, int n, int maxline)
{
	SetColor(15, 0);
	int a[2] = { 96,100 };
	int dong = soDong(index, n, maxline);
	board(96, 21, 20, maxline, dong, a, 2);
	GoTo(a[0] + 1, 22);
	cout << "STT";
	GoTo(a[1] + 1, 22);
	cout << "Class Name";
	if (n > maxline && n - index <= maxline)
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
		GoTo(a[0] + 1, 22 + i * 2);
		int stt = i + index;
		if (index > 0)
		{
			stt -= 1;
		}
		cout << stt;
		GoTo(a[1] + 1, 22 + i * 2);
		cout << cls->cls.nameClass;
		cls = cls->Next;
	}

	int maxPage = (n + maxline - 1) / maxline;
	int curPage = (index + maxline - 1) / maxline;
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
void ViewListOfClass(ListClass lcls, int& index, int n, int maxline)
{
	ShowCur(false);
	bool kt = true;
	while (true)
	{
		if (kt == true)
		{
			removeText(72, 19, 64, 29, 15, 15);
			displayClass(lcls, index, n, maxline);
			kt = false;
		}
		if (_kbhit())
		{
			char c = _getch();
			if (c == -32)
			{
				if (n > maxline)
				{
					kt = true;
					c = _getch();
					if (c == 75)
					{
						if (index > maxline + 1)
						{
							index -= maxline;
						}
						else if (index == maxline + 1)
						{
							index -= maxline + 1;
						}
					}
					else if (c == 77)
					{
						if (index == 0)
						{
							index += maxline + 1;
						}
						else if (index < (n - n % maxline) && (n - index >= maxline))
						{
							index += maxline;
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
//Xuất danh sách các khóa học
void displayCourse(ListCourse lcrs, int index, int n, int maxline)
{
	SetColor(15, 0);
	int a[8] = { 41,45,58,89,100,133,140,152 };
	int dong = soDong(index, n, maxline);
	board(41, 20, 128, maxline, dong, a, 8);
	GoTo(a[0] + 1, 21); cout << "STT";
	GoTo(a[1] + 1, 21); cout << "CourseID";
	GoTo(a[2] + 1, 21); cout << "Course name";
	GoTo(a[3] + 1, 21); cout << "Class name";
	GoTo(a[4] + 1, 21); cout << "Teacher name";
	GoTo(a[5] + 1, 21); cout << "Credit";
	GoTo(a[6] + 1, 21); cout << "Max Student";
	GoTo(a[7] + 1, 21); cout << "Session";
	if (n > maxline && n - index <= maxline)
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
		if (index > maxline)
		{
			stt = index + i - 1;
		}
		GoTo(a[0] + 1, 21 + i * 2);
		cout << stt;
		GoTo(a[1] + 1, 21 + i * 2);
		cout << crs->crs.courseID;
		GoTo(a[2] + 1, 21 + i * 2);
		cout << crs->crs.courseName;
		GoTo(a[3] + 1, 21 + i * 2);
		cout << crs->crs.className;
		GoTo(a[4] + 1, 21 + i * 2);
		cout << crs->crs.teacher;
		GoTo(a[5] + 1, 21 + i * 2);
		cout << crs->crs.acaCrd;
		GoTo(a[6] + 1, 21 + i * 2);
		cout << crs->crs.maxStudent;
		GoTo(a[7] + 1, 21 + i * 2);
		cout << crs->crs.cld.Day << " - " << crs->crs.cld.Time;
		crs = crs->Next;
	}
	int maxPage = (n + maxline - 1) / maxline;
	int curPage = (index + maxline - 1) / maxline;
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
void ViewListOfCourse(ListCourse lcrs, int& index, int n, int maxline)
{
	ShowCur(false);
	bool kt = true;
	while (true)
	{
		if (kt == true)
		{
			removeText(40, 19, 129, 29, 15, 15);
			displayCourse(lcrs, index, n, maxline);
			kt = false;
		}
		if (_kbhit())
		{
			char c = _getch();
			if (c == -32)
			{
				if (n > maxline)
				{
					kt = true;
					c = _getch();
					if (c == 75)
					{
						if (index > maxline + 1)
						{
							index -= maxline;
						}
						else if (index == maxline + 1)
						{
							index -= maxline + 1;
						}
					}
					else if (c == 77)
					{
						if (index == 0)
						{
							index += maxline + 1;
						}
						else if (index < (n - n % maxline) && (n - index >= maxline))
						{
							index += maxline;
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
//Xuất danh bảng điểm của khóa học
void displayScoreboardCourse(ListStudent lst, int index, int n, int maxline)
{
	SetColor(15, 0);
	int a[7] = { 47, 52,65,109,124,138,151 };
	int dong = soDong(index, n, maxline);
	board(47, 20, 116, maxline, dong, a, 7);
	SetColor(15, 0);
	GoTo(a[0] + 1, 21); cout << "STT";
	GoTo(a[1] + 1, 21); cout << "Student ID";
	GoTo(a[2] + 16, 21); cout << "Full name";
	GoTo(a[3] + 1, 21); cout << "Regular mark";
	GoTo(a[4] + 1, 21); cout << "Midterm mark";
	GoTo(a[5] + 1, 21); cout << "Final mark";
	GoTo(a[6] + 1, 21); cout << "Total mark";
	if (n > maxline && n - index <= maxline)
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
		GoTo(a[0] + 1, 21 + i * 2); cout << st->sv.STT;
		GoTo(a[1] + 1, 21 + i * 2); cout << st->sv.studentID;
		GoTo(a[2] + 1, 21 + i * 2); cout << st->sv.fullName;
		GoTo(a[3] + 1, 21 + i * 2);
		if (st->sv.regularMark < 0 || st->sv.regularMark>10)
		{
			cout << "None";
		}
		else
		{
			cout << st->sv.regularMark;
		}
		GoTo(a[4] + 1, 21 + i * 2);
		if (st->sv.midtermMark < 0 || st->sv.midtermMark>10)
		{
			cout << "None";
		}
		else
		{
			cout << st->sv.midtermMark;
		}
		GoTo(a[5] + 1, 21 + i * 2);
		if (st->sv.finalMark < 0 || st->sv.finalMark >10)
		{
			cout << "None";
		}
		else
		{
			cout << st->sv.finalMark;
		}
		GoTo(a[6] + 1, 21 + i * 2);
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
	int maxPage = (n + maxline - 1) / maxline;
	int curPage = (index + maxline - 1) / maxline;
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
void ViewScoreboardCourse(ListStudent lst, int& index, int n, int maxline)
{
	ShowCur(false);
	bool kt = true;
	while (true)
	{
		if (kt == true)
		{
			removeText(40, 19, 129, 30, 15, 15);
			displayScoreboardCourse(lst, index, n, maxline);
			kt = false;
		}
		if (_kbhit())
		{
			char c = _getch();
			if (c == -32)
			{
				if (n > maxline)
				{
					kt = true;
					c = _getch();
					if (c == 75)
					{
						if (index > maxline + 1)
						{
							index -= maxline;
						}
						else if (index == maxline + 1)
						{
							index -= maxline + 1;
						}
					}
					else if (c == 77)
					{
						if (index == 0)
						{
							index += maxline + 1;
						}
						else if (index < (n - n % maxline) && (n - index >= maxline))
						{
							index += maxline;
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
//Xuất bảng điểm của lớp
void displayScoreboardClass(ListStudent lst, int index, int n, int maxline)
{
	SetColor(15, 0);
	int a[6] = { 51, 56,69,113,128,143 };
	int dong = soDong(index, n, maxline);
	board(51, 20, 107, maxline, dong, a, 6);
	GoTo(a[0] + 1, 21); cout << "STT";
	GoTo(a[1] + 1, 21); cout << "Student ID";
	GoTo(a[2] + 1, 21); cout << "Full Name";
	GoTo(a[3] + 1, 21); cout << "Total mark";
	GoTo(a[4] + 1, 21); cout << "GPA";
	GoTo(a[5] + 1, 21); cout << "Total GPA";

	if (n > maxline && n - index <= maxline)
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
		GoTo(a[0] + 1, 21 + i * 2);
		cout << st->sv.STT;
		GoTo(a[1] + 1, 21 + i * 2);
		cout << st->sv.studentID;
		GoTo(a[2] + 1, 21 + i * 2);
		cout << st->sv.fullName;
		GoTo(a[3] + 1, 21 + i * 2);
		if (st->sv.totalMark >= 0 && st->sv.totalMark <= 11)
		{
			cout << st->sv.totalMark;
		}
		else
		{
			cout << "None";
		}
		GoTo(a[4] + 1, 21 + i * 2);
		double gpa = GpaOfSemester(st->sv.studentID, CurSemester);
		if (gpa >= 0 && gpa <= 4)
		{
			cout << gpa;
		}
		else
		{
			cout << "None";
		}
		GoTo(a[5] + 1, 21 + i * 2);
		double tgpa = GpaTotal(st->sv.studentID);
		if (tgpa >= 0 && tgpa <= 5)
		{
			cout << tgpa;
		}
		else
		{
			cout << "None";
		}
		st = st->Next;
	}

	int maxPage = (n + maxline - 1) / maxline;
	int curPage = (index + maxline - 1) / maxline;
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
void ViewScoreBoadClass(ListStudent lst, int& index, int n, int maxline)
{
	ShowCur(false);
	bool kt = true;
	while (true)
	{
		if (kt == true)
		{
			removeText(40, 19, 129, 29, 15, 15);
			displayScoreboardClass(lst, index, n, maxline);
			kt = false;
		}
		if (_kbhit())
		{
			char c = _getch();
			if (c == -32)
			{
				if (n > maxline)
				{
					kt = true;
					c = _getch();
					if (c == 75)
					{
						if (index > maxline + 1)
						{
							index -= maxline;
						}
						else if (index == maxline + 1)
						{
							index -= maxline + 1;
						}
					}
					else if (c == 77)
					{
						if (index == 0)
						{
							index += maxline + 1;
						}
						else if (index < (n - n % maxline) && (n - index >= maxline))
						{
							index += maxline;
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
//Xuất bảng điểm của sinh viên
void displayMyScoreBoard(ListCourse lcr, string studentID, int index, int n, int maxline)
{
	SetColor(15, 0);
	int a[7] = { 41,56,89,100,117,134,151 };
	int dong = soDong(index, n, maxline);
	board(41, 20, 127, maxline, dong, a, 7);
	GoTo(a[0] + 1, 21); cout << "CourseID";
	GoTo(a[1] + 1, 21); cout << "Course name";
	GoTo(a[2] + 1, 21); cout << "Class name";
	GoTo(a[3] + 1, 21); cout << "Regular mark";
	GoTo(a[4] + 1, 21); cout << "Midterm mark";
	GoTo(a[5] + 1, 21); cout << "Finnal mark";
	GoTo(a[6] + 1, 21); cout << "Total mark";
	if (n > maxline && n - index <= maxline)
	{
		dong++;
	}
	NodeCourse* cr = lcr.Head;
	for (int i = 1; i <= dong; i++)
	{
		if (cr == NULL)
		{
			break;
		}
		NodeStudent* st = findStudentByID(cr->crs.sv.lst, studentID);
		GoTo(a[0] + 1, 21 + i * 2); cout << cr->crs.courseID;
		GoTo(a[1] + 1, 21 + i * 2); cout << cr->crs.courseName;
		GoTo(a[2] + 1, 21 + i * 2); cout << cr->crs.className;
		if (st == NULL)
		{
			continue;
		}
		GoTo(a[3] + 1, 21 + i * 2);
		if (st->sv.regularMark >= 0 && st->sv.regularMark <= 10)
		{
			cout << st->sv.regularMark;
		}
		else
		{
			cout << "None";
		}
		GoTo(a[4] + 1, 21 + i * 2);
		if (st->sv.midtermMark >= 0 && st->sv.midtermMark <= 10)
		{
			cout << st->sv.midtermMark;
		}
		else
		{
			cout << "None";
		}
		GoTo(a[5] + 1, 21 + i * 2);
		if (st->sv.finalMark >= 0 && st->sv.finalMark <= 10)
		{
			cout << st->sv.finalMark;
		}
		else
		{
			cout << "None";
		}
		GoTo(a[6] + 1, 21 + i * 2);
		if (st->sv.totalMark >= 0 && st->sv.totalMark <= 10)
		{
			cout << st->sv.totalMark;
		}
		else
		{
			cout << "None";
		}
		cr = cr->Next;
	}

	int maxPage = (n + maxline - 1) / maxline;
	int curPage = (index + maxline - 1) / maxline;
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
void ViewMyScoreBoard(ListCourse lcr, string studentID, int& index, int n, int maxline)
{
	ShowCur(false);
	bool kt = true;
	while (true)
	{
		if (kt == true)
		{
			removeText(40, 19, 129, 29, 15, 15);
			displayMyScoreBoard(lcr, studentID, index, n, maxline);
			kt = false;
		}
		if (_kbhit())
		{
			char c = _getch();
			if (c == -32)
			{
				if (n > maxline)
				{
					kt = true;
					c = _getch();
					if (c == 75)
					{
						if (index > maxline + 1)
						{
							index -= maxline;
						}
						else if (index == maxline + 1)
						{
							index -= maxline + 1;
						}
					}
					else if (c == 77)
					{
						if (index == 0)
						{
							index += maxline + 1;
						}
						else if (index < (n - n % maxline) && (n - index >= maxline))
						{
							index += maxline;
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
//Hàm kẻ bảng, mảng a là tọa độ các cột từ trái qua phải của bảng, không có cột cuối cùng bên phải :v
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
//Tính số dòng của bảng
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
//Hàm lựa chọn chức năng
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
//Cũng là lựa chọn chức năng nhưng theo hàng ngang
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
//Hàm in ra tam giác đỏ ở chức năng
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
//Hàm xóa tam giác đỏ đó :3
void xoaMuiTen(int x, int y, int w)
{
	SetColor(15, 15);
	GoTo(x - 1, y + 1);
	cout << " ";
	GoTo(x + 1 + w, y + 1);
	cout << " ";
	SetColor(15, 0);
}
//Xóa các kí tự từ x+1 và y+1
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
