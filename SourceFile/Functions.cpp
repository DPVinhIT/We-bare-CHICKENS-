#include "Functions.h"
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

Clas* createClass(string file_name[], AcaYear& aca, int& sl, int idx )
{
	int n;
	string class_name[9];
	for (int i = 0; i < 9; i++) {
		class_name[i] = file_name[i].substr(0, file_name[i].find_last_of("."));
	}
	
	if (idx == 1) {
		int sl=0;
		for (int i = 0; i < 9; i++) {
			if (findSubstring(class_name[i], "APCS")) {
				aca.APCS[sl].nameClass = class_name[i];
				readFileStudent(file_name[i], aca.APCS[sl], n);
				sl++;
			}
		}
		return aca.APCS;
	}
	else if (idx == 2) {
		int sl=0;
		for (int i = 0; i < 9; i++) {
			if (findSubstring(class_name[i], "CLC")) {
				aca.CLC[sl].nameClass = class_name[i];
				readFileStudent(file_name[i], aca.CLC[sl], n);
				sl++;
			}
		}
		return aca.CLC;
	}
	else if (idx == 3) {
		int sl=0;
		for (int i = 0; i < 9; i++) {
			if (findSubstring(class_name[i], "CTT")) {
				aca.CTT[sl].nameClass = class_name[i];
				readFileStudent(file_name[i], aca.CTT[sl], n);
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
void printStudent(Student* st, int n)
{
	string dem;
	for (int i = 0; i < n; i++)
	{
		st[i].firstName = st[i].fullName.substr(0, st[i].fullName.find_first_of(" "));
		dem = st[i].fullName.substr(st[i].fullName.find_first_of(" "), st[i].fullName.find_last_of(" "));
		st[i].lastName = dem.substr(dem.find_last_of(" "), dem.length());
		cout << st[i].fullName << " "<<st[i].firstName<<""<<st[i].lastName<<endl;
		cout << st[i].studentID << endl;
		cout << st[i].socialID << endl;
		cout << st[i].Gender << endl;
	}
}
node makeNode(Student sv){
	node tmp = new Node();
	tmp->sv = sv;
	tmp->next = NULL;
	return tmp;
}
void addNode(node &a, node newNode){
	if(a==NULL){
		a = newNode;
	}
	else{
		newNode->next = a;
		a = newNode;
	}
}
void printNode(node a){
	while(a!=NULL){
		cout << a->sv.fullName <<" "<< a->sv.studentID<<" "<< a->sv.socialID<<" "<< a->sv.Gender<<endl;
		a=a->next;
	}
}
void menu1(){
	cout<<"\nBan muon them sinh vien vao lop nao? "<<endl;
	cout<<"\n1. 23CTT1"<<endl;
	cout<<"\n2. 23CTT2"<<endl;
	cout<<"\n3. 23CTT3"<<endl;
	cout<<"\n4. 23CTT4"<<endl;
	cout<<"\n5. 23CTT5"<<endl;
}
void menu2(){
	cout<<"\nBan muon them sinh vien vao lop nao? "<<endl;
	cout<<"\n1. 23CLC01"<<endl;
	cout<<"\n2. 23CLC02"<<endl;
	cout<<"\nChon 0 de thoat chuong trinh!"<<endl;
}
void menu3(){
	cout<<"\nBan muon them sinh vien vao lop nao? "<<endl;
	cout<<"\n1. 23APCS1"<<endl;
	cout<<"\n2. 23APCS12"<<endl;
	cout<<"\nChon 0 de thoat chuong trinh!"<<endl;
}
void inputDate(Date& d) {
	cout << "Nhap ngay: \n";
	cin >> d.day;
	cout << "Nhap thang: \n";
	cin >> d.month;
	cout << "Nhap nam: \n";
	cin >> d.year;
}
void inputAStudent(Student& hs) {
	cout << "Nhap MSSV: \n";
	cin >> hs.studentID;
	cout << "Nhap ho ten: \n";
	cin.ignore();
	getline(cin, hs.fullName);
	cout << "Nhap gioi tinh: \n";
	cin >> hs.Gender;
	cout << "Nhap ngay sinh: \n";
	inputDate(hs.DoB);
	cout << "Nhap so can CCCD/CMND: \n";
	cin >> hs.socialID;
}

