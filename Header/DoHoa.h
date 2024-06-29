#ifndef DoHoa_h
#define DoHoa_h
#include"Struct.h"
#include"Functions.h"
#define KEY_NONE -1

void SetColor(int backgound_color, int text_color);

void SetWindowSize(SHORT width, SHORT height);

void SetScreenBufferSize(SHORT width, SHORT height);

void GoTo(SHORT posX, SHORT posY);

//BOOL WINAPI SetConsoleTitle(
//	_In_ LPCTSTR lpConsoleTitle
//);

int whereX();

int whereY();
//Ẩn con trỏ chuột
void ShowCur(bool CursorVisibility);
//Trả về phím nhập từ người dùng
int inputKey();
//Tạo box
void box(int x, int y, int w, int h, int b_color, int t_color, string text);
void boxNoText(int x, int y, int w, int h, int b_color, int t_color);
void boxNoTextFC(int x, int y, int w, int h, int b_color, int t_color);
void image(int x, int y, string fileName, int b_color, int t_color);
//Đặt size hiển thị
void resizeConsole(int width, int height);
//Đặt size tối đa của console
void resizeConsoleBuffer(int width, int height);
//Vô hiệu thay đổi kích thước console
void DisableResizeWindow();
//Vô hiệu phóng to thu nhỏ
void disableMinimizeAndMaximizeButtons();
//vô hiệu hóa bôi đen
void DisableSelection();
//console full màn hình
void maximizeConsoleWindow();
//background console
void SetConsoleBackgroundColor(int bgColor);
//Lấy kích thước cửa sổ hiện tại
void getConsoleSize(int& width, int& height);

void menuLogin(ListClass& lcls, NodeAca*& aca);

void inputStudent(ListStudent& lst);

void khungLon();

void khungNho();

void loginSession(Account acc);

void OptionAnnounce(string option, int y);

void slowText(string announce);

void menuStaff(Account& acc, ListClass& lcls, ListSeme& smt, NodeAca*& aca);

void Staff2_2(Academy aca, ListClass& lcls);

void BeginSchoolYear(ListClass& lcls, NodeAca*& aca);

void BeginSemester(NodeSeme*& seme, NodeAca*& aca, Account acc);

void EndSemester(NodeAca*& aca, ListClass lcls, Account acc);

void displayStudent(ListStudent lst, int index, int n, int maxline);
void ViewStudenOfClass(ListStudent cls, int& index, int n, int maxline);

void displayClass(ListClass lcls, int index, int n, int maxline);
void ViewListOfClass(ListClass lcls, int& index, int n, int maxline);

void displayCourse(ListCourse lcrs, int index, int n, int maxline);
void ViewListOfCourse(ListCourse lcrs, int& index, int n, int maxline);

void displayScoreboardCourse(ListStudent lst, int index, int n, int maxline);
void ViewScoreboardCourse(ListStudent lst, int& index, int n, int maxline);

void displayScoreboardClass(ListStudent lst, int index, int n, int maxline);
void ViewScoreBoadClass(ListStudent lst, int& index, int n, int maxline);

void displayMyScoreBoard(ListCourse lcr, string studentID, int index, int n, int maxline);
void ViewMyScoreBoard(ListCourse lcr, string studentID, int& index, int n, int maxline);

void board(int x, int y, int w, int maxLine, int numLine, int ax[], int n);

int soDong(int index, int n, int maxline);

void menuStudent(Account& acc);

void optionDaChon(int x, int y, int w, int h, int sl, int& op);

int optionDaChon1(int x, int y, int w, int h, int sl);

void muiTen(int x, int y, int w);

void xoaMuiTen(int x, int y, int w);

void removeText(int x, int y, int w, int h, int b_color, int t_color);

#endif