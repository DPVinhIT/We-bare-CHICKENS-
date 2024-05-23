#include"Class.h"

void splitName(Student& st)
{
	int first, last;
	if (st.fullName.find(" ") == string::npos)
	{
		return;
	}
	first = st.fullName.find(" ");
	last = st.fullName.find_last_of(" ");
	st.lastName = st.fullName.substr(0, first);
	st.firstName = st.fullName.substr(last + 1);
}

void readFileStudent(string fileName, Clas& Lop, int& n)
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
	fin.seekg(0, ios::beg);
	Lop.sinhVien = new Student[n];

	for (int i = 0; i < n; i++)
	{
		getline(fin, Lop.sinhVien[i].studentID, ';');
		getline(fin, Lop.sinhVien[i].fullName, ';');
		getline(fin, Lop.sinhVien[i].Gender, ';');
		fin.ignore();
		fin >> Lop.sinhVien[i].DoB.day;
		fin.ignore();
		fin >> Lop.sinhVien[i].DoB.month;
		fin.ignore();
		fin >> Lop.sinhVien[i].DoB.year;
		fin.ignore();
		getline(fin, Lop.sinhVien[i].socialID, '\n');
		splitName(Lop.sinhVien[i]);
	}
	fin.close();
}