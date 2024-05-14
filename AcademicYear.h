#ifndef AcademicYear_h
#define AcademicYear_h

#include"Class.h"

struct AcaYear
{
	string nienKhoa;
	Clas* APCS;
	Clas* CLC;
	Clas* CTT;
};
string iToStr(int i);
AcaYear createAcademicYear(int yearBegin);
void printAcaYear(AcaYear aca);


#endif
