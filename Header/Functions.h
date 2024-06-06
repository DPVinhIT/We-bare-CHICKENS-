#ifndef Functions_h
#define Functions_h

#include"Struct.h"

void splitName(Student& st);
NodeStudent* createNodeStudent(Student sv);
NodeClass* createNodeClass(Clas cls);
void addNodeStudent(ListStudent& lst,NodeStudent* st);
void addNodeClass(ListClass& lcls,NodeClass* cls);
void readFileStudent(string fileName[], ListClass& lcls);
Student inputStudent();
void InputCourse(Course& cou);
void printStudent(Student st);
void printListStudent(ListStudent lst);
void printClass(Clas cls);
void printListClass(ListClass lcls);
void printCourse(Course crs);
void printListCourse(ListCourse lcrs);
void printSemester(Semester smt);
void printListSemester(ListSeme lsmt);
void printAca(Academy aca);
void printListStudentScore(Course crs);
void printClassScore(Clas cls);
void removeFirst(ListStudent& lst);
void removeLast(ListStudent& lst);
int getSize(ListStudent lst);
void removeStudent(ListStudent& lst, int pos);
void removeStudent_MSSV(ListStudent& lst);
void updateCourse(Course& crs);
void writeCoure(string fileName, Course cour);
NodePScore* createPersonalScore(PersonalScore ps);
void addNodePScore(ScoreBoard& sb, NodePScore* ps);
void readScoreBoard(string fileName, ScoreBoard& sb);
#endif
