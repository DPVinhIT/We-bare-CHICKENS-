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

void menuLogin(ListClass &lcls);

void inputStudent(ListStudent& lst);

void khungLon();

void khungNho();

void menuStaff(Account& acc, ListClass& lcls, ListSeme& smt);

void Staff2_2(ListClass& lcls);

void BeginSchoolYear(ListClass& lcls);

void BeginSemester(ListSeme& lsm);

void EndSemester(ListSeme& lsm);

void displayStudent(ListStudent lst, int index, int n);
void ViewStudenOfClass(ListStudent cls, int& index, int n);

void displayClass(ListClass lcls, int index, int n);
void ViewListOfClass(ListClass lcls, int& index, int n);

void displayCourse(ListCourse lcrs, int index, int n);
void ViewListOfCourse(ListCourse lcrs, int& index, int n);

void displayScoreboardCourse(ListStudent lst, int index, int n);
void ViewScoreboardCourse(ListStudent lst, int& index, int n);

void displayScoreboardClass(ListStudent lst, int index, int n);

void board(int x, int y, int w, int maxLine, int numLine, int ax[], int n);

int soDong(int index, int n, int maxline);

void menuStudent(Account& acc);

void optionDaChon(int x, int y, int w, int h, int sl, int& op);

int optionDaChon1(int x, int y, int w, int h, int sl);

void muiTen(int x, int y, int w);

void xoaMuiTen(int x, int y, int w);

void removeText(int x, int y, int w, int h, int b_color, int t_color);

#endif
