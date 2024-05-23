#ifndef Functions_h
#define Functions_h

#include"AcademicYear.h"
typedef struct Node* node;
void createAcademicYear(int yearBegin);
Clas* createClass(string file_name[], AcaYear& aca, int& sl, int idx,int n[]);
int chooseClass();
void readFileStudent(string fileName, Clas& Lop, int& n);
void printClass(Clas* cls, int n);
void printStudent(Student*& st, int n);
node makeNode(Student sv);
void addNodeSV(node& a, node newNode);
void printNode(node a);
void menu1();
void menu2();
void menu3();
void inputDate(Date& d);
void inputAStudent(Student& hs);
void nhap3HK(Semester *smt, int i);
void xuat3HK(Semester *smt, int i);
int chooseSemester();
//void addNodeC(node& a, node newNode);
#endif