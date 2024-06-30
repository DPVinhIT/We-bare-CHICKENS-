#ifndef DoHoa_h
#define DoHoa_h
#include"Struct.h"
#include"Functions.h"
#define KEY_NONE -1

//	0 = Black		8 = Gray
//	1 = Blue		9 = Light Blue
//	2 = Green		10 = Light Green
//	3 = Aqua		11 = Light Aqua
//	4 = Red			12 = Light Red
//	5 = Purple		13 = Light Purple
//	6 = Yellow		14 = Light Yellow
//	7 = White		15 = Bright White
void SetColor(int backgound_color, int text_color);

//Các hàm đồ họa đã tham khảo :3
void SetWindowSize(SHORT width, SHORT height);
void SetScreenBufferSize(SHORT width, SHORT height);
void resizeConsole(int width, int height);
void resizeConsoleBuffer(int width, int height);
void DisableResizeWindow();
void disableMinimizeAndMaximizeButtons();
void DisableSelection();
void maximizeConsoleWindow();
void SetConsoleBackgroundColor(int bgColor);
void getConsoleSize(int& width, int& height);

//Hàm di chuyển con trỏ
void GoTo(SHORT posX, SHORT posY);
// lấy tọa độ x của con trỏ hiện tại
int whereX();
// lấy tọa độ y của con trỏ hiện tại
int whereY();
//làm ẩn trỏ chuột
void ShowCur(bool CursorVisibility);
//Tạo hộp thoại có văn bản
void box(int x, int y, int w, int h, int b_color, int t_color, string text);
//Tạo hộp thoại nhưng k có văn bản
void boxNoText(int x, int y, int w, int h, int b_color, int t_color);
void boxNoTextFC(int x, int y, int w, int h, int b_color, int t_color);
//Hàm để in ra các file txt
void image(int x, int y, string fileName, int b_color, int t_color);

//Login
void menuLogin(ListClass& lcls, NodeAca*& aca);
//Các chức năng của học sinh
void menuStudent(Account& acc);
//Các chức năng của staff
void menuStaff(Account& acc, ListClass& lcls, ListSeme& smt, NodeAca*& aca);
//Phiên đăng nhập
void loginSession(Account acc);
//Hiển thị thông báo
void OptionAnnounce(string option, int y);
void slowText(string announce);
//In ra danh sách lớp của các năm học
void Staff2_2(Academy aca, ListClass& lcls);
//Các chức năng đầu năm học của staff
void BeginSchoolYear(ListClass& lcls, NodeAca*& aca);
//Các chức năng đầu học kì của staff
void BeginSemester(NodeSeme*& seme, NodeAca*& aca, Account acc);
//Các chức năng cuối kì của staff
void EndSemester(NodeAca*& aca, ListClass lcls, Account acc);
//Hàm nhập sinh viên
void inputStudent(ListStudent& lst);
//x=40, w=130
void khungLon();
//x=72, w=64
void khungNho();
//Xuất danh sách sinh viên
void displayStudent(ListStudent lst, int index, int n, int maxline);
void ViewStudenOfClass(ListStudent cls, int& index, int n, int maxline);
//Xuất danh sách các lớp
void displayClass(ListClass lcls, int index, int n, int maxline);
void ViewListOfClass(ListClass lcls, int& index, int n, int maxline);
//Xuất danh sách các khóa học
void displayCourse(ListCourse lcrs, int index, int n, int maxline);
void ViewListOfCourse(ListCourse lcrs, int& index, int n, int maxline);
//Xuất danh bảng điểm của khóa học
void displayScoreboardCourse(ListStudent lst, int index, int n, int maxline);
void ViewScoreboardCourse(ListStudent lst, int& index, int n, int maxline);
//Xuất bảng điểm của lớp
void displayScoreboardClass(ListStudent lst, int index, int n, int maxline);
void ViewScoreBoadClass(ListStudent lst, int& index, int n, int maxline);
//Xuất bảng điểm của sinh viên
void displayMyScoreBoard(ListCourse lcr, string studentID, int index, int n, int maxline);
void ViewMyScoreBoard(ListCourse lcr, string studentID, int& index, int n, int maxline);
//Hàm kẻ bảng, mảng a là tọa độ các cột từ trái qua phải của bảng, không có cột cuối cùng bên phải :v
void board(int x, int y, int w, int maxLine, int numLine, int ax[], int n);
//Tính số dòng của bảng
int soDong(int index, int n, int maxline);
//Hàm lựa chọn chức năng
void optionDaChon(int x, int y, int w, int h, int sl, int& op);
//Cũng là lựa chọn chức năng nhưng theo hàng ngang
int optionDaChon1(int x, int y, int w, int h, int sl);
//Hàm in ra tam giác đỏ ở chức năng
void muiTen(int x, int y, int w);
//Hàm xóa tam giác đỏ đó :3
void xoaMuiTen(int x, int y, int w);
//Xóa các kí tự từ x+1 và y+1
void removeText(int x, int y, int w, int h, int b_color, int t_color);

#endif
