#ifndef Struct_h
#define Struct_h
#include<iostream>
#include<fstream>
#include<string.h>
#include<string>
#define MAXLEN 100
using namespace std;

struct Date {
	int day, month, year;
};

struct Student {
	string studentID;
	string firstName, lastName, fullName;
	string Gender;
	Date DoB;
	string socialID;
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
	ListStudent sv;
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
#endif
