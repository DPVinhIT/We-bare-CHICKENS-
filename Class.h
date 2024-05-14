#ifndef Clas_h
#define Clas_h

#include"Student.h"

struct Clas
{
	string nameClass;
	Student* sinhVien;
};
int chooseClass();
void readFileStudent(char fileName[], Clas& Lop, int& n);
bool findSubstring(string mainString, string subString);
Clas* createClass(string file_name[], AcaYear& aca, int& sl, int idx);
void printClass(Clas* cls,int n);
#endif
