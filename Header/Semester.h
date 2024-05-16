#ifndef Semester_h
#define Semester_h

#include"Courses.h"

struct Semester {
	Course* cou;
	int year;
	Date begin;
	Date end;
};

#endif
