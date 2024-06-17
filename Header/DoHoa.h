#ifndef DoHoa_h
#define DoHoa_h
#include"Struct.h"
#define KEY_NONE -1

void SetColor(int backgound_color, int text_color);

void GoTo(SHORT posX, SHORT posY);

BOOL WINAPI SetConsoleTitle(
	_In_ LPCTSTR lpConsoleTitle
);

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

void menuLogin(ListClass &lcls, ListAccount LStaff, ListAccount LStudent);

void inputStudent(Clas& cls);

void khungLon();

void khungNho();

void menuStaff(ListClass& lcls);

void Staff2_2();

void BeginSchoolYear2_6(ListClass& lcls);

void displayStudent(NodeClass* cls, int index, int n);

void ViewStudenOfClass(NodeClass* cls, int& index, int n);

void board(int x, int y, int w, int maxLine, int numLine, int ax[], int n);

int soDong(int index, int n, int maxline);

void menuStudent();

int optionDaChon(int x, int y, int w, int h, int sl);

void muiTen(int x, int y, int w);

void xoaMuiTen(int x, int y, int w);

void removeText(int x, int y, int w, int h, int b_color, int t_color);

void textcolor(int x);

#endif
