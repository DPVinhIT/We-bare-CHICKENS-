#ifndef Functions_h
#define Functions_h

#include"Struct.h"

bool laNgayHopLe(Date t);
int dayOfMonth(Date d);
void splitName(Student& st);

//Hàm xử lí dữ liệu student
NodeStudent* createNodeStudent(Student sv);
NodeStudent* findStudentByPos(ListStudent lStd, int pos);
NodeStudent* findStudentByID(ListStudent lst, string ID);
void addNodeStudent(ListStudent& lst, NodeStudent* st);
void removeFirst(ListStudent& lst);
void removeLast(ListStudent& lst);
int getSize(ListStudent lst);
int countStudent(ListStudent lStd);
void removeStudent(ListStudent& lst, int pos);
void removeStudent_MSSV(ListStudent& lst, string studentID);
void readFileCSV(string fileName, ListStudent& lst, bool& check);

//Hàm xử lí dữ liệu clas
NodeClass* createNodeClass(Clas cls);
NodeClass* findClassByPos(ListClass lcls, int pos);
NodeClass* findClassByName(ListClass lcls, string name);
void addNodeClass(ListClass& lcls, NodeClass* cls);
void readFileStudent(string fileName[], ListClass& lcls);
int countClass(ListClass lCls);
ListClass lstClsInAYear(Academy aca, ListClass lst, int year);

//Hàm xử lí tài khoản
NodeAccount* createNodeAccount(Account acc);
void addNodeAccount(ListAccount& lac, NodeAccount* acc);
NodeAccount* Login(ListAccount lac, string user, string pass);
void changePasswordInListAccount(ListAccount& lAcc, Account Acc);
void UploadAccount(string fileName, ListAccount& acc);
void printListAccount(ListAccount lac);

//Hàm xử lí khóa hoc
NodeCourse* findCourseByPos(ListCourse lcrs, int pos);
NodeCourse* findCourseByID(ListCourse lcrs, string courseID);
NodeCourse* createNodeCourse(Course crs);
void addNodeCourse(ListCourse& lcrs, NodeCourse* crs);
void removeStudentOfCourse(ListCourse& lcrs, string courseID, string studentID);
void removeFirst(ListCourse& lcr);
void removeLast(ListCourse& lcr);
void removeCourse(ListCourse& lcr, int pos);
void removeCourse_IDCourse(ListCourse& lcr, string IDcourse);
int countCourse(ListCourse lCrs);
ListCourse RegisteredCourse(string StudentID);
ListCourse CourseOfClass(string className);
void writeCoure(string fileName, Course cour);

//Hàm xử lí thời gian
int checkSeme();
int checkSemester(Date cur);

//Hàm xử lí năm học và học kì
NodeSeme* createNodeSeme(Semester sms);
void addNodeSeme(ListSeme& lsm, NodeSeme* ns);	
NodeAca* createNodeAcademy(Academy acm);
void addNodeAcademy(ListAca& lta, NodeAca* aca);
bool checkSemester(int stt, Date start, Date end, NodeAca* CurAcademy);

//Đọc file bảng điểm
void readFileScoreboard(string fileName, Course& crs);

//Tính gpa
double GpaOfSemester(string StudentID, int& numCredit);
double GpaTotal(string StudentID);

#endif
