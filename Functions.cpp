#include"Functions.h"
//in ra màn hình học sinh
void printStudent(Student* st, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << st[i].studentID << '-'<< st[i].fullName << '-' << st[i].Gender << '-' 
			<< st[i].DoB.day << '/' << st[i].DoB.month << '/' << st[i].DoB.year << '-' << st[i].socialID << endl;
	}
}
//in ra màn hình thông tin năm học
void printAcaYear(AcaYear aca) {
	cout << "Nam hoc: " << aca.nienKhoa << '\n';
	printClass(aca.APCS, 2);
	printClass(aca.CLC, 2);
	printClass(aca.CTT, 5);
}
