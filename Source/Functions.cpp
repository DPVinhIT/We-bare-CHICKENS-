#include "Functions.h"

NodeStudent* createNodeStudent(Student sv)
{
	NodeStudent* p = new NodeStudent;
	p->sv = sv;
	p->Next = NULL;
	return p;
}
NodeClass* createNodeClass(Clas cls)
{
	NodeClass* p = new NodeClass;
	p->cls = cls;
	p->Next = NULL;
	return p;
}
void addNodeStudent(ListStudent& lst, NodeStudent* st)
{
	if (lst.Head == NULL)
	{
		lst.Head = st;
		lst.Head->Next = NULL;
		return;
	}
	NodeStudent* temp = lst.Head;
	while (temp->Next != NULL)
	{
		temp = temp->Next;
	}
	temp->Next = st;
}
void addNodeClass(ListClass& lcls, NodeClass* cls)
{
	if (lcls.Head == NULL)
	{
		lcls.Head = cls;
		lcls.Head->Next = NULL;
		return;
	}
	NodeClass* temp = lcls.Head;
	while (temp->Next != NULL)
	{
		temp = temp->Next;
	}
	temp->Next = cls;
}
void readFileStudent(string fileName[], ListClass& lcls)
{
	for (int i = 0; i < 9; i++)
	{
		ifstream fin;
		fin.open(fileName[i]);
		if (!fin.is_open())
		{
			cout << "Mo file khong thanh cong" << endl;
			return;
		}
		ListStudent lst;
		lst.Head = NULL;
		while (!fin.eof())
		{
			Student st;
			getline(fin, st.studentID, ';');
			getline(fin, st.fullName, ';');
			getline(fin, st.Gender, ';');
			fin.ignore();
			fin >> st.DoB.day;
			fin.ignore();
			fin >> st.DoB.month;
			fin.ignore();
			fin >> st.DoB.year;
			fin.ignore();
			getline(fin, st.socialID, '\n');
			addNodeStudent(lst, createNodeStudent(st));
		}
		Clas cls;
		cls.nameClass = fileName[i].substr(0, fileName[i].find_first_of('.'));
		cls.lst .Head=new NodeStudent;
		cls.lst = lst;
		addNodeClass(lcls, createNodeClass(cls));
	}

}
//Ham nhap
Student inputStudent() {
	Student st;
	cout << "Nhap MSSV: ";
	cin >> st.studentID;
	cin.ignore();
	cout << "Nhap ho va ten: ";
	getline(cin,st.fullName);
	cout << "Nhap gioi tinh: ";
	cin >> st.Gender;
	cout << "Nhap ngay sinh: \n";
	cout << "Nhap ngay: ";
	cin >> st.DoB.day;
	cout << "Nhap thang: ";
	cin >> st.DoB.month;
	cout << "Nhap nam: ";
	cin >> st.DoB.year;
	cout << "Nhap CCCD/CMND: ";
	cin >> st.socialID;
	return st;
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
		cout << "Nhan 3 de chon THU Ba\n";
		cout << "Nhan 4 de chon THU TU\n";
		cout << "Nhan 5 de chon THU NAM\n";
		cout << "Nhan 6 de chon THU SAU\n";
		cout << "Nhan 7 de chon THU BAY\n";
		//cout << "Nhan 1 de THOAT!!!\n";
		cin >> chonLich;
	} while (chonLich < 2 || chonLich > 7);
	cou.cld.Day = Day[chonLich - 2];
	do {
		cout << "Nhan 1 de chon ca S1: 7h30\n";
		cout << "Nhan 2 de chon ca S2: 9h30\n";
		cout << "Nhan 3 de chon ca S3: 13h30\n";
		cout << "Nhan 4 de chon ca S4: 15h30\n";
		//cout << "Nhan 1 de THOAT!!!\n";
		cin >> chonCa;
	} while (chonCa < 1 || chonCa > 4);
	cou.cld.Time = Time[chonCa - 1];
}
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

//
//remove student
void removeFirst(ListStudent& lst) {
	NodeStudent* tmp = lst.Head;
	if (tmp == NULL) {
		return;
	}
	tmp = tmp->Next;
}
void removeLast(ListStudent& lst) {
	NodeStudent* tmp = lst.Head;
	if (tmp == NULL) return;
	while (tmp->Next->Next != NULL) {
		tmp = tmp->Next;
	}
	tmp->Next = NULL;
}
int getSize(ListStudent lst) {
	NodeStudent* tmp = lst.Head;
	int cnt = 0;
	while (tmp != NULL) {
		++cnt;
		tmp = tmp->Next;
	}
	return cnt;
}

void removeStudent(ListStudent& lst, int pos) {
	NodeStudent* tmp = lst.Head;
	if (pos == 1) {
		removeFirst(lst);
		return;
	}
	int n = getSize(lst);
	if (pos == n) {
		removeLast(lst);
		return;
	}
	for (int i = 1; i < pos - 1; i++) {
		tmp = tmp->Next;
	}
	tmp->Next = tmp->Next->Next;
}
void removeStudent_MSSV(ListStudent& lst) {
	string MSSV;
	int n = getSize(lst);
	NodeStudent* tmp = lst.Head;
	cout << "\nSinh vien ban muon xoa co MSSV la: ";
	cin >> MSSV;
	for (int i = 1; i <= n; i++) {
		if (tmp->sv.studentID == MSSV) {
			removeStudent(lst, i);
		}
	}
}
//cap nhat khoa hoc
void updateCourse(Course& crs) {
	int choose;
	do {
		cout << "Chon thong tin muon cap nhat\n";
		cout << "1. Ma khoa hoc\n";
		cout << "2. Ten khoa hoc\n";
		cout << "3. Danh sach sinh vio vien\n";
		cout << "4. Ten giao vien: \n";
		cout << "5. So tin chi\n";
		cout << "6. So hoc sinh to da\n";
		cout << "7. Lich hoc\n";
		cout << "0. THOAT!!!!\n";
		cout << "Nhap lua chon: ";
		cin >> choose;
	} while (choose > 7 || choose < 0);
	switch (choose) {
	case 0: {
		break;
	}
	case 1: {
		cout << "Cap nhat ma khoa hoc: \n";
		cout << "Nhap ma khoa hoc: ";
		cin >> crs.courseID;
		break;
	}
	case 2: {
		cout << "Cap nhat ten khoa hoc: \n";
		cout << "Nhap ten khoa hoc: ";
		cin >> crs.courseName;
		break;
	}
	case 3: {
		cout << "Cap nhat danh sach sinh vien: \n";
		int chon;
		do {
			cout << "Chon thao tac voi danh sach sinh vien: \n";
			cout << "1. Them mot sinh vien trong danh sach\n";
			cout << "2. Xoa mot sinh vien trong danh sach\n";
			cout << "0. THOAT!!!\n";
			cin >> chon;
		} while (chon < 0 || chon > 2);
		if (chon == 1) {
			Student sv = inputStudent();
			addNodeStudent(crs.sv, createNodeStudent(sv));
		}
		if (chon == 2) {
			removeStudent_MSSV(crs.sv);
		}
		break;
	}
	case 4: {
		cout << "Cap nhat ten giao vien: \n";
		cout << "Nhap ten giao vien: ";
		cin >> crs.teacher;
		break;
	}
	case 5: {
		cout << "Cap nhat so tin chi: \n";
		cout << "Nhap tin chi: ";
		cin >> crs.acaCrd;
		break;
	}
	case 6: {
		cout << "Cap nhat so sinh vien to da: \n";
		cout << "Nhap so sinh vien to da: ";
		cin >> crs.maxStudent;
		break;
	}
	case 7: {
		cout << "Cap nhat lich hoc: \n";
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

		crs.cld.Day = Day[chonLich - 2];
		do {
			cout << "Nhan 1 de chon ca S1: 7h30\n";
			cout << "Nhan 2 de chon ca S2: 9h30\n";
			cout << "Nhan 3 de chon ca S3: 13h30\n";
			cout << "Nhan 4 de chon ca S4: 15h30\n";
			cin >> chonCa;
		} while (chonCa < 1 || chonCa > 4);
		crs.cld.Time = Time[chonCa - 1];
		break;
	}
	}
}
