#include "Functions.h"
#include"DoHoa.h"

Date CurTime;

ListAccount LStaff;
ListAccount LStudent;

ListAca ListAcademy;

ListClass Freshman;
ListClass Sophomore;
ListClass Junior;
ListClass Senior;

NodeAca* CurAcademy;
NodeSeme* CurSemester;

int main()
{

	ListClass cls;
	string fileName[] = { "23CTT1.csv", "23CTT2.csv", "23CTT3.csv", "23CTT4.csv", "23CTT5.csv", "23CLC01.csv",
	"23CLC02.csv", "23APCS1.csv", "23APCS2.csv","20CTT1.csv","20CTT2.csv","21CTT1.csv","21CTT2.csv","22CTT1.csv","22CTT2.csv"};

	readFileStudent(fileName, cls, sizeof(fileName) / sizeof(fileName[0]));
	SetConsoleTitle("WeBearCHICKEN");

	//ShowCur(false);
	//DisableSelection();
	//DisableResizeWindow();
	maximizeConsoleWindow();

	CurTime.day = 1;
	CurTime.month = 9;
	CurTime.year = 2023;

	CurAcademy = ListAcademy.Head;
	CurAcademy = new NodeAca;
	if (CurAcademy != NULL)
	{
		CurAcademy->acm.lsm.Head = NULL;
		CurSemester = CurAcademy->acm.lsm.Head;
	}

	menuLogin(cls, CurAcademy);

	_getch();
	GoTo(0, 45);
	return 0;
}
