#include "Functions.h"

//Ham in
void printStudent(Student st) {
	cout << "MSSV: " << st.studentID << endl;
	cout << "Ho va ten: " << st.fullName << endl;
	cout << "Gioi tinh: " << st.Gender << endl;
	cout << "Ngay sinh: " << st.DoB.day << '/' << st.DoB.month << '/' << st.DoB.year << endl;
	cout << "CCCD/CMND: " << st.socialID << endl;
}
void printListStudent(ListStudent lst) {
	if (lst.Head == NULL) {
		cout << "Chua co hoc sinh." << endl;
		return;
	}
	NodeStudent* nodeSt = lst.Head;
	cout << "----------------------------------------------\n";
	while (nodeSt != NULL) {
		printStudent(nodeSt->sv);
		cout << "----------------------------------------------\n";
		nodeSt = nodeSt->Next;
	}
}
void printClass(Clas cls) {
	cout << "Lop: " << cls.nameClass << endl;
	printListStudent(cls.lst);
}
void printListClass(ListClass lcls) {
	if (lcls.Head == NULL) {
		cout << "Chua co lop hoc." << endl;
		return;
	}
	NodeClass* nodeCls = lcls.Head;
	cout << "\n----------------------------------------------\n";
	cout << "----------------------------------------------\n";

	while (nodeCls != NULL) {
		printClass(nodeCls->cls);
		cout << "----------------------------------------------\n";
		cout << "----------------------------------------------\n\n";
		nodeCls = nodeCls->Next;
	}
}
void printCourse(Course crs) {
	cout << "Ma khoa hoc: " << crs.courseID << endl;
	cout << "Ten khoa hoc: " << crs.courseName << endl;
	cout << "Danh sach hoc sinh trong khoa hoc: " << endl;
	printListStudent(crs.sv);
	cout << "So tin chi: " << crs.acaCrd;
	cout << "So luong sinh vien toi da: " << crs.maxStudent << endl;
	cout << "Giao vien: " << crs.teacher << endl;
	cout << "Lich hoc: " << crs.cld.Day << ':' << crs.cld.Time << endl;
}
void printListCourse(ListCourse lcrs) {
	if (lcrs.Head == NULL) {
		cout << "Chua co khoa hoc." << endl;
		return;
	}
	NodeCourse* nodeCrs = lcrs.Head;
	while (nodeCrs != NULL) {
		cout << "************************************************\n";
		printCourse(nodeCrs->crs);
		cout << "************************************************\n";
		nodeCrs = nodeCrs->Next;
	}
}
void printSemester(Semester smt) {
	cout << "Ngay bat dau: " << smt.begin.day << '/' << smt.begin.month << '/' << smt.begin.year << endl;
	cout << "Ngay ket thuc: " << smt.end.day << '/' << smt.end.month << '/' << smt.end.year << endl;
	printListCourse(smt.lcrs);
}
void printListSemester(ListSeme lsmt) {
	if (lsmt.Head == NULL) {
		cout << "Chua co hoc ky.\n";
		return;
	}
	NodeSeme* nodeSmt = lsmt.Head;
	while (nodeSmt != NULL) {
		cout << "************************************************\n";
		printSemester(nodeSmt->smt);
		cout << "************************************************\n";
		nodeSmt = nodeSmt->Next;
	}
}
void printAca(Academy aca) {
	cout << "Nam hoc: " << aca.begin << '-' << aca.end << endl;
	printListSemester(aca.lsm);
}

void createAcademicYear(int yearBegin) {
	cout << "\nNam hoc: " << yearBegin << " - " << yearBegin + 1 << endl;
}
void swap(string& a, string& b) {
	string tmp = a;
	a = b;
	b = tmp;
}
int chooseClass() {
	int n;
	cout << "Chon loai lop hoc:\n";
	cout << "Nhan 1 de chon APCS muon tao\n";
	cout << "Nhan 2 de chon CLC muon tao\n";
	cout << "Nhan 3 de chon CTT muon tao\n";
	cout << "Nhan 0 de thoat!!!\n";
	do {
		cin >> n;
	} while (n < 0 || n>3);
	return n;
}
bool findSubstring(string mainString, string subString) {
	if (mainString.find(subString) != string::npos) {
		return true;
	}
	else {
		return false;
	}
}


Clas* createClass(string file_name[], AcaYear& aca, int& sl, int idx, int n[])
{
	string class_name[9];
	for (int i = 0; i < 9; i++) {
		class_name[i] = file_name[i].substr(0, file_name[i].find_last_of("."));
	}
	int j = 0;
	if (idx == 1) {
		sl = 0;
		for (int i = 0; i < 9; i++) {
			if (findSubstring(class_name[i], "APCS")) {
				aca.APCS[sl].nameClass = class_name[i];
				readFileStudent(file_name[i], aca.APCS[sl], n[j]);
				j++;
				sl++;
			}
		}
		return aca.APCS;
	}
	else if (idx == 2) {
		sl = 0;
		for (int i = 0; i < 9; i++) {
			if (findSubstring(class_name[i], "CLC")) {
				aca.CLC[sl].nameClass = class_name[i];
				readFileStudent(file_name[i], aca.CLC[sl], n[j]);
				j++;
				sl++;
			}
		}
		return aca.CLC;
	}
	else if (idx == 3) {
		sl = 0;
		for (int i = 0; i < 9; i++) {
			if (findSubstring(class_name[i], "CTT")) {
				aca.CTT[sl].nameClass = class_name[i];
				readFileStudent(file_name[i], aca.CTT[sl], n[j]);
				j++;
				sl++;
			}
		}
		return aca.CTT;
	}
	return NULL;
}

void printClass(Clas* cls, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << cls[i].nameClass << endl;
		printStudent(cls[i].sinhVien, 5);
		cout << endl;
	}
}
void printStudent(Student*& st, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << st[i].fullName << " " << st[i].firstName << " " << st[i].lastName << endl;
		cout << st[i].studentID << endl;
		cout << st[i].socialID << endl;
		cout << st[i].Gender << endl;
	}
}
node makeNode(Student sv) {
	node tmp = new Node();
	tmp->sv = sv;
	tmp->next = NULL;
	return tmp;
}
void addNodeSV(node& a, node newNode) {
	if (newNode == NULL)
	{
		return;
	}
	if (a == NULL) {
		a = newNode;
		a->next = NULL;
	}
	else {
		newNode->next = a;
		a = newNode;
	}
}
void printNode(node a) {
	while (a != NULL) {
		cout << a->sv.fullName << " " << a->sv.studentID << " " << a->sv.socialID << " " << a->sv.Gender << " "
			<< a->sv.firstName << " " << a->sv.lastName << " " << a->sv.DoB.day << "/" << a->sv.DoB.month << "/" << a->sv.DoB.year << endl;
		a = a->next;
	}
}
void menu1() {
	cout << "\nBan muon them sinh vien vao lop nao? " << endl;
	cout << "\n1. 23CTT1" << endl;
	cout << "\n2. 23CTT2" << endl;
	cout << "\n3. 23CTT3" << endl;
	cout << "\n4. 23CTT4" << endl;
	cout << "\n5. 23CTT5" << endl;
}
void menu2() {
	cout << "\nBan muon them sinh vien vao lop nao? " << endl;
	cout << "\n1. 23CLC01" << endl;
	cout << "\n2. 23CLC02" << endl;
	cout << "\nChon 0 de thoat chuong trinh!" << endl;
}
void menu3() {
	cout << "\nBan muon them sinh vien vao lop nao? " << endl;
	cout << "\n1. 23APCS1" << endl;
	cout << "\n2. 23APCS12" << endl;
	cout << "\nChon 0 de thoat chuong trinh!" << endl;
}
void inputDate(Date& d) {
	cout << "Nhap Ngay Sinh:";
	cin >> d.day >> d.month >> d.year;
}
void inputAStudent(Student& hs) {
	cout << "Nhap MSSV: ";
	cin >> hs.studentID;
	cout << "Nhap ho ten: ";
	cin.ignore();
	getline(cin, hs.fullName);
	cout << "Nhap gioi tinh: ";
	cin >> hs.Gender;
	inputDate(hs.DoB);
	cout << "Nhap so CCCD/CMND: ";
	cin >> hs.socialID;
	splitName(hs);
}
void InputCourse(Course& cou) {
	cout << "Nhap ID khoa hoc: ";
	cin >> cou.courseID;
	cin.ignore();
	cout << "Nhap ten khoa hoc: ";
	getline(cin, cou.courseName);
	cout << "Nhap ten giao vien: ";
	getline(cin, cou.teacher);
	cout << "Nhap so tin chi: ";
	cin >> cou.acaCrd;
	cout << "Nhap so luong hoc sinh toi da: ";
	cin >> cou.maxStudent;
	string Day[6] = { "MON","TUE","WED","THU","FRI","SAT" };
	string Time[4] = { "S1:7h30","S2:9h30","S3:13h30","S4:15h30" };
	cout << "Chon lich hoc\n";
	int chonLich;
	int chonCa;
	do {
		cout << "Nhan 2 de chon THU HAI\n";
		cout << "Nhan 3 de chon THU BA\n";
		cout << "Nhan 4 de chon THU TU\n";
		cout << "Nhan 5 de chon THU NAM\n";
		cout << "Nhan 6 de chon THU SAU\n";
		cout << "Nhan 7 de chon THU BAY\n";
		cin >> chonLich;
	} while (chonLich < 2 || chonLich > 7);

	cou.cld.Day = Day[chonLich - 2];
	do {
		cout << "Nhan 1 de chon ca S1: 7h30\n";
		cout << "Nhan 2 de chon ca S2: 9h30\n";
		cout << "Nhan 3 de chon ca S3: 13h30\n";
		cout << "Nhan 4 de chon ca S4: 15h30\n";
		cin >> chonCa;
	} while (chonCa < 1 || chonCa > 4);
	cou.cld.Time = Time[chonCa - 1];
}
void nhapDate(Semester& smt) {
	cout << "Nhap ngay bat dau: ";
	cin >> smt.begin.day >> smt.begin.month >> smt.begin.year;
	cout << "Nhap ngay ket thuc: ";
	cin >> smt.end.day >> smt.end.month >> smt.end.year;
}
void xuatDate(Semester& smt) {
	cout << " " << smt.begin.day << "/" << smt.begin.month << "/" << smt.begin.year << " - " << smt.end.day << "/" << smt.end.month << "/" << smt.end.year << endl;
}
void nhap3HK(Semester* smt, int i) {
	cout << "\nHoc ky " << i << ": " << endl;
	nhapDate(smt[i-1]);
	cout << "Nhap cac khoa hoc: " << endl;
	for (int j = 0; j < 9; j++)
	{
		smt[i - 1].cou[j].sv.Head = new Node;
		cout << "Khoa hoc thu " << j + 1 << ": \n";
		InputCourse(smt[i - 1].cou[j]);
	}
}
void xuat3HK(Semester* smt, int i) {
	cout << "\n\n--------------------" << endl << endl;
	cout << "Hoc ky " << i << ":";
	xuatDate(smt[i-1]);
}
int chooseSemester() {
	int n;
	cout << "Chon hoc ky muon tao:\n";
	cout << "Nhan 1 de tao hoc ky 1\n";
	cout << "Nhan 2 de tao hoc ky 2\n";
	cout << "Nhan 3 de tao hoc ky 3\n";
	cout << "Nhan 0 de thoat!!!\n";
	do {
		cin >> n;
	} while (n < 0 || n>3);
	return n;
}
nodecs makeNode1(Course x) {
	nodecs tmp = new N_Course();
	tmp->crs = x;
	tmp->next = NULL;
	return tmp;
}
//void addNodeCourse(nodecs &a, Course crs){
	//nodecs tmp = makeNode(crs);
//	if(a==NULL){
	//	a = tmp;
	//}
	//tmp->next = a;
//	a = tmp;
//}

void addStudentCour(Course& cour, Student sv)
{
	node p = makeNode(sv);
	addNodeSV(cour.sv.Head,p);
}

void readStudentCour(string fileName, Course& cour)
{
	ifstream fin;
	fin.open(fileName);
	if (!fin.is_open())
	{
		cout << "Mo file khong thanh cong" << endl;
		return;
	}
	Student temp;
	string temp1;
	int n = 0;
	while (!fin.eof())
	{
		getline(fin, temp1);
		n++;
	}
	fin.seekg(0, ios::beg);
	for(int i=0;i<n-1;i++)
	{
		getline(fin, temp.studentID, ';');
		getline(fin, temp.fullName, ';');
		getline(fin, temp.Gender, ';');
		fin.ignore();
		fin >> temp.DoB.day;
		fin.ignore();
		fin >> temp.DoB.month;
		fin.ignore();
		fin >> temp.DoB.year;
		fin.ignore();
		getline(fin, temp.socialID, '\n');
		splitName(temp);
		addStudentCour(cour, temp);
	}
	fin.close();
}

void printCour(Course cou)
{
	cout <<"Ten khoa hoc: "<< cou.courseName << endl;
	cout <<"ID: "<< cou.courseID << endl;
	cout << "Giao vien: " << cou.teacher << endl;
	cout <<"So luong toi da: "<< cou.maxStudent << endl;
	cout << "So tin chi: " << cou.acaCrd << endl;
	cout << "Ngay hoc: " << cou.cld.Day<<endl<<"Thoi gian: " << cou.cld.Time << endl;
	Node* temp = cou.sv.Head;
	while (temp != NULL)
	{
		printNode(temp);
	}
}
