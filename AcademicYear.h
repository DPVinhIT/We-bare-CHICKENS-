#ifndef AcademicYear_h
#define AcademicYear_h

#include"Class.h"
#include "Student.h"

struct AcaYear
{
	string nienKhoa;
	Clas* APCS;
	Clas* CLC;
	Clas* CTT;
};
string iToStr(int i);
void swap(string& a, string& b);
AcaYear createAcademicYear(int yearBegin);
void printAcaYear(AcaYear aca);


#endif
