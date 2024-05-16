#ifndef Functions_h
#define Functions_h

#include"AcademicYear.h"
typedef struct Node* node;
void createAcademicYear(int yearBegin);
Clas* createClass(string file_name[], AcaYear &aca, int& sl, int idx);
int chooseClass();
void readFileStudent(string fileName, Clas& Lop, int& n);
void printClass(Clas* cls,int n);
void printStudent(Student* st, int n);
node makeNode(Student sv);
void addNode(node &a, node newNode);
void printNode(node a);
void menu1();
void menu2();
void menu3();
void addStudent(Student &a);
#endif
