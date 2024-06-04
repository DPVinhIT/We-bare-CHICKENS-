#ifndef Functions_h
#define Functions_h

#include"Struct.h"

NodeStudent* createNodeStudent(Student sv);
NodeClass* createNodeClass(Clas cls);
void addNodeStudent(ListStudent& lst,NodeStudent* st);
void addNodeClass(ListClass& lcls,NodeClass* cls);
void readFileStudent(string fileName[], ListClass& lcls);
void printStudent(Student st);
void printListStudent(ListStudent lst);
void printClass(Clas cls);
void printListClass(ListClass lcls);
void printCourse(Course crs);
void printListCourse(ListCourse lcrs);
void printSemester(Semester smt);
void printListSemester(ListSeme lsmt);
void printAca(Academy aca);

#endif
