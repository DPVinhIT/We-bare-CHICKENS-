#ifndef Struct_h
#define Struct_h

#define MAXLEN 100
#include<iostream>
#include<windows.h>
#include<fstream>
#include<stdio.h>
#include<conio.h>
#include<string>
#include<string.h>
#include<iomanip>
#include <fcntl.h>
#include <io.h>
#include <sstream>
using namespace std;
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS

//Ngày
struct Date {
	int day, month, year;
};
//Sinh viên
struct Student {
	int STT;
	string studentID;
	string firstName, lastName, fullName;
	string Gender;
	Date DoB;
	string socialID;
	double totalMark;
	double finalMark;
	double midtermMark;
	double regularMark;
};
//Danh sach sinh vien
struct NodeStudent {
	Student sv;
	NodeStudent* Next;
};
struct ListStudent
{
	NodeStudent* Head;
	ListStudent() : Head(NULL) {}
};
//Lớp học
struct Clas
{
	string nameClass;
	ListStudent lst;
};
//Danh sach lop hoc
struct NodeClass {
	Clas cls;
	NodeClass* Next;
};
struct ListClass {
	NodeClass* Head;
	ListClass() : Head(NULL) {}
};
//Thời gian học
struct Calendar
{
	string Day;
	string Time;
};
//Khóa học
struct Course
{
	string courseID;
	string courseName;
	string className;
	Clas sv;
	string teacher;
	int acaCrd;
	int maxStudent;
	Calendar cld;
};
//Danh sach kha hoc
struct NodeCourse {
	Course crs;
	NodeCourse* Next;
};
struct ListCourse {
	NodeCourse* Head;
	ListCourse() : Head(NULL) {}
};
//Học kì
struct Semester {
	ListCourse lcrs;
	int STT;
	Date begin;
	Date end;
};
//Danh sach hoc ky
struct NodeSeme
{
	Semester smt;
	NodeSeme* Next;
};
struct ListSeme {
	NodeSeme* Head;
	ListSeme() :Head(NULL) {}
};
//Năm học
struct Academy {
	ListSeme lsm;
	int begin, end;
};
//Danh sach nam hoc
struct NodeAca {
	Academy acm;
	NodeAca* Next;
};
struct ListAca {
	NodeAca* Head;
	ListAca() :Head(NULL) {}
};
//Tài khoản
struct Account {
	string fullName;
	Date born;
	string gender;
	string username;
	string password;
};
//Danh sach tai khoan
struct NodeAccount {
	Account acc;
	NodeAccount* Next;
};
struct ListAccount {
	NodeAccount* Head;
	ListAccount() :Head(NULL) {}
};

extern Date CurTime;
extern ListAccount LStaff;
extern ListAccount LStudent;
extern ListAca ListAcademy;
extern ListClass Freshman;
extern ListClass Sophomore;
extern ListClass Junior;
extern ListClass Senior;
extern NodeAca* CurAcademy;
extern NodeSeme* CurSemester;

#endif
