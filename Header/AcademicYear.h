#ifndef AcademicYear_h
#define AcademicYear_h

#include"Class.h"
#include"Semester.h"

struct AcaYear
{
	Semester* sem;
	Clas* APCS;
	Clas* CLC;
	Clas* CTT;
};
struct calendar
{
	string Day[6]={"MON","TUE","WED","THU","FRI","SAT"};
	string Time[4] = {"S1:7h30","S2:9h30","S3:13h30","S4:15h30"};
};

struct Course
{
	string courseID;
	string courseName;
	Clas cls;
	string teacher;
	int acaCrd;
	int maxStudent;
	calendar cld;
};
#endif
