#ifndef Student_h
#define Student_h

#include"Date.h"
#define MAXLEN 100

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
struct ListNode {
	Node* Head;
};
#endif