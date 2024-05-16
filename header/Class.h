#ifndef Clas_h
#define Clas_h

#include"Student.h"

struct Clas
{
	string nameClass;
	Student* sinhVien;
};

void readFileStudent(string fileName, Clas& Lop, int& n);

#endif
