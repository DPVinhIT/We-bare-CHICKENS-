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

struct Date {
	int day, month, year;
};
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

struct NodeStudent {
	Student sv;
	NodeStudent* Next;
};
//Danh sach sinh vien
struct ListStudent
{
	NodeStudent* Head;
	ListStudent() : Head(NULL) {}
};
struct Clas
{
	string nameClass;
	ListStudent lst;
};
struct NodeClass {
	Clas cls;
	NodeClass* Next;
};
//Danh sach lop
struct ListClass {
	NodeClass* Head;
	ListClass() : Head(NULL) {}
};
struct Calendar
{
	string Day;
	string Time;
};
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
struct NodeCourse {
	Course crs;
	NodeCourse* Next;
};
//Danh sach khoa hoc
struct ListCourse {
	NodeCourse* Head;
	ListCourse() : Head(NULL) {}
};
struct Semester {
	ListCourse lcrs;
	int STT;
	Date begin;
	Date end;
};
struct NodeSeme
{
	Semester smt;
	NodeSeme* Next;
};
//Danh sach hoc ky
struct ListSeme {
	NodeSeme* Head;
	ListSeme() :Head(NULL) {}
};
struct Academy {
	ListSeme lsm;
	int begin, end;
};
struct NodeAca {
	Academy acm;
	NodeAca* Next;
};
struct ListAca {
	NodeAca* Head;
	ListAca() :Head(NULL) {}
};
struct Account {
	string fullName;
	Date born;
	string gender;
	string username;
	string password;
};
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