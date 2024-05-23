#ifndef AcademicYear_h
#define AcademicYear_h

#include"Class.h"
#include"Semester.h"

struct AcaYear
{
	Semester* sem = new Semester[3];
	Clas* APCS;
	Clas* CLC;
	Clas* CTT;
};

#endif