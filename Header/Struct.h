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
//Sinh viên
struct Student {
	string studentID;
	string firstName, lastName, fullName;
	string Gender;
	Date DoB;
	string socialID;
};

struct Node {
	Student sv;
	Node* next;
};
struct ListSinhVien
{
	Node* Head;
};
//Lớp
struct Clas
{
	string nameClass;
	Student* sinhVien;
};
//Năm học
struct AcaYear
{
	Semester* sem = new Semester[3];
	Clas* APCS;
	Clas* CLC;
	Clas* CTT;
};



//Lịch học
struct calendar
{
	string Day;
	string Time;
};
//Khóa học
struct Course
{
	string courseID;
	string courseName;
	ListSinhVien sv;
	string teacher;
	int acaCrd;
	int maxStudent;
	calendar cld;
};
struct N_Course {
	Course crs;
	N_Course* next;
};
struct Semester {
	Course* cou;
	Date begin;
	Date end;
};

#endif
