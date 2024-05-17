#ifndef Courses_h
#define Courses_h

#include "Class.h"

struct calendar
{
	string Day;
	string Time;
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
