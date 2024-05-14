#ifndef Clas_h
#define Clas_h

#include"Student.h"

struct Clas
{
	string nameClass;
	Student* sinhVien;
};

void readFileStudent(char fileName[], Clas& Lop, int& n);
void printClass(Clas* cls,int n);
#endif
