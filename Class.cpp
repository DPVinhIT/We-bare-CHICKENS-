#include"Class.h"
//đọc file lưu là class
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
//khởi tạo lớp học từ tệp đã nhập
Clas* createClass(string file_name[], AcaYear& aca, int& sl, int idx)
{
	int n;
	string class_name[9];
	for (int i = 0; i < 9; i++) {
		class_name[i] = file_name[i].substr(0, file_name[i].find_last_of("."));
	}
	int j = 0;
	if (idx == 1) {
		aca.APCS = new Clas[2];
		for (int i = 0; i < 9; i++) {
			if (findSubstring(class_name[i], "APCS")) {
				aca.APCS[j].nameClass = class_name[i];
				readFileStudent(file_name[i], aca.APCS[j], n);
				j++;
			}
		}
		return aca.APCS;
	}
	else if (idx == 2) {
		aca.CLC = new Clas[2];
		for (int i = 0; i < 9; i++) {
			if (findSubstring(class_name[i], "CLC")) {
				aca.CLC[j].nameClass = class_name[i];
				readFileStudent(file_name[i], aca.CLC[j], n);
				j++;
			}
		}
		return aca.CLC;
	}
	else if (idx == 3) {
		aca.CTT = new Clas[5];
		for (int i = 0; i < 9; i++) {
			if (findSubstring(class_name[i], "CTT")) {
				aca.CTT[j].nameClass = class_name[i];
				readFileStudent(file_name[i], aca.CTT[j], n);
				j++;
			}
		}
		return aca.CTT;
	}
}
//do khớp chuỗi con
bool findSubstring(string mainString, string subString) {
	if (mainString.find(subString) != string::npos) {
		return true;
	}
	else {
		return false;
	}
}
//in ra màn hình lớp học
void printClass(Clas* cls, int n)
{
	if (cls == NULL) {
		return;
	}
	for (int i = 0; i < n; i++)
	{
		cout <<"Lop: "<< cls[i].nameClass << endl;
		printStudent(cls[i].sinhVien, 5);
		cout << endl;
	}
}
