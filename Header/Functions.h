#ifndef Functions_h
#define Functions_h

#include"Struct.h"
void createAca(Academy acd);
int chooseClass();
int chooseSemester();
void splitName(Student& st);
NodeStudent* createNodeStudent(Student sv);
NodeClass* createNodeClass(Clas cls);
void addNodeStudent(ListStudent& lst, NodeStudent* st);
void addNodeClass(ListClass& lcls, NodeClass* cls);
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
void removeFirst(ListStudent& lst);
void removeLast(ListStudent& lst);
int getSize(ListStudent lst);
void removeStudent(ListStudent& lst, int pos);
void removeStudent_MSSV(ListStudent& lst);
void updateCourse(Course& crs);
void writeCoure(string fileName, Course cour);
void printListStudentScore(Course crs);
void printListCourseScore(Course crs);
void outputScore(Course a);
int PrintScore();
NodeAccount* createNodeAccount(Account acc);
void addNodeAccount(ListAccount& lac, NodeAccount* acc);
void UploadAccount(string fileName, ListAccount& acc);
void printListAccount(ListAccount lac);
bool Login(ListAccount lac, string user, string pass);
void printInforOfCrs(Course crs);
void printTheStudentCourses(string mssv, ListCourse lstCrs);
#endif
