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
	ListNode sv;
	string teacher;
	int acaCrd;
	int maxStudent;
	calendar cld;
};
struct N_Course {
	Course crs;
	N_Course* next;
};

typedef struct N_Course* nodecs;
#endif
