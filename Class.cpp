#include"Class.h"

void readFileStudent(char fileName[], Clas& Lop, int& n)
{
	n = 0;
	ifstream fin;
	fin.open(fileName);
	if (!fin.is_open())
	{
		cout << "Mo file khong thanh cong" << endl;
		return;
	}
	string temp;
	while (!fin.eof())
	{
		getline(fin, temp);
		n++;
	}
	fin.seekg(0,ios::beg);
	Lop.sinhVien = new Student[n];
	fin.ignore(3);
	for (int i = 0; i < n; i++)
	{
		getline(fin, Lop.sinhVien[i].studentID, '-');
		getline(fin, Lop.sinhVien[i].fullName, '-');
		getline(fin, Lop.sinhVien[i].Gender, '-');
		fin.ignore();
		fin >> Lop.sinhVien[i].DoB.day;
		fin.ignore();
		fin >> Lop.sinhVien[i].DoB.month;
		fin.ignore();
		fin >> Lop.sinhVien[i].DoB.year;
		fin.ignore();
		getline(fin, Lop.sinhVien[i].socialID, '\n');
	}
	fin.close();
	cout << "Doc file thanh cong" << endl;
}
