#ifndef Functions_h
#define Functions_h

#include"Struct.h"
bool laNgayHopLe(Date t);
int dayOfMonth(Date d);
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
void removeStudent_MSSV(ListStudent& lst, string studentID);
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
NodeAccount* Login(ListAccount lac, string user, string pass);
void printInforOfCrs(Course crs);
void printTheStudentCourses(string mssv, ListCourse lstCrs);

int countStudent(ListStudent lStd);

int countClass(ListClass lCls);

NodeStudent* findStudentByPos(ListStudent lStd, int pos);

NodeStudent* findStudentByID(ListStudent lst, string ID);

NodeClass* findClassByPos(ListClass lcls, int pos);

NodeClass* findClassByName(ListClass lcls, string name);

void readFileCSV(string fileName, ListStudent& lst, bool& check);

ListClass lstClsInAYear(Academy aca, ListClass lst, int year);

int check_Seme(Semester smt, Date cur);

int checkSemester(Date cur);

int countCourse(ListCourse lCrs);

NodeCourse* findCourseByPos(ListCourse lcrs, int pos);

NodeCourse* findCourseByID(ListCourse lcrs, string courseID);

NodeSeme* createNodeSeme(Semester sms);

void addNodeSeme(ListSeme& lsm, NodeSeme* ns);	

NodeCourse* createNodeCourse(Course crs);

void addNodeCourse(ListCourse& lcrs, NodeCourse* crs);

NodeStudent* check_Course_and_MSSV(ListCourse lcr, string IDcourse, string MSSV);

void removeStudentOfCourse(ListCourse& lcrs, string courseID, string studentID);

void inputScore_Student(ListCourse& lcr, string IDcourse, string MSSV);

void removeFirst(ListCourse& lcr);

void removeLast(ListCourse& lcr);

void removeCourse(ListCourse& lcr, int pos);

void removeCourse_IDCourse(ListCourse& lcr, string IDcourse);

void changePassword(Account& acc);

void changePasswordInListAccount(ListAccount& lAcc, Account Acc);

void readFileScoreboard(string fileName, Course& crs);

NodeAca* createNodeAcademy(Academy acm);

void addNodeAcademy(ListAca& lta, NodeAca* aca);

double GPA_one_Seme(Semester sms, string StudentID);

double* GPA_three_Seme(ListSeme lsm, string StudentID);

#endif
