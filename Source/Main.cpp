#include "Functions.h"
#include"DoHoa.h"

Date CurTime;
ListAccount LStaff;
ListAccount LStudent;
ListAca ListAcademy;


int main()
{
	Academy acd;
	ListClass cls;
	string fileName[] = { "23CTT1.csv", "21CTT2.csv", "23CTT3.csv", "23CTT4.csv", "23CTT5.csv", "23CLC01.csv",
	"23CLC02.csv", "23APCS1.csv", "23APCS2.csv" };
	readFileStudent(fileName, cls);
	SetConsoleTitle("WeBearCHICKEN");

	//ShowCur(false);
	//DisableSelection();
	//DisableResizeWindow();
	maximizeConsoleWindow();

	CurTime.day = 20;
	CurTime.month = 6;
	CurTime.year = 2024;

	SetConsoleBackgroundColor(15);

	menuLogin(cls);

	_getch();
	GoTo(0, 45);
	return 0;
}
