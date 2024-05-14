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
	string ho;
	string ten;
	string dem;
	for (int i = 0; i < n; i++)
	{
		ho = st[i].fullName.substr(0, st[i].fullName.find_first_of(" "));
		dem = st[i].fullName.substr(st[i].fullName.find_first_of(" "), st[i].fullName.find_last_of(" "));
		ten = dem.substr(dem.find_last_of(" "), dem.length());
		cout << st[i].fullName << " "<<ho<<""<<ten<<endl;
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
void menu(){
	cout<<"\nBan muon them sinh vien vao lop nao? "<<endl;
	cout<<"\n1. 23CTT1"<<endl;
	cout<<"\n2. 23CTT2"<<endl;
	cout<<"\n3. 23CTT3"<<endl;
	cout<<"\n4. 23CTT4"<<endl;
	cout<<"\n5. 23CTT5"<<endl;
	cout<<"\n6. 23CLC01"<<endl;
	cout<<"\n7. 23CLC02"<<endl;
	cout<<"\n8. 23APCS1"<<endl;
	cout<<"\n9. 23APCS12"<<endl;
	cout<<"\nChon 0 de thoat chuong trinh!"<<endl;
}
void addStudent(Student &a){
	cout<<"\nNhap ho ten";
	cin>>a.fullName;
	cout<<"\nNhap MSSV: ";
	cin>>a.studentID;
}

