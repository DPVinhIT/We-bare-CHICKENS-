#include "Functions.h"

bool laNgayHopLe(Date t) 
{
	if (t.year < 0 || t.month < 1 || t.month > 12)
		return false;

	switch (t.month) {
	case 4:
	case 6:
	case 9:
	case 11:
		return (t.day >= 1 && t.day <= 30);
	case 2:
		if ((t.year % 4 == 0 && t.year % 100 != 0) || (t.year % 400 == 0))
			return (t.day >= 1 && t.day <= 29);
		else
			return (t.day >= 1 && t.day <= 28);
	default:
		return (t.day >= 1 && t.day <= 31);
	}
}
void createAca(Academy acd) {
	cout << "\nNhap nam bat dau: ";
	cin >> acd.begin;
	cout << "\nNhap nam ket thuc: ";
	cin >> acd.end;
	cout << "\nNam hoc: " << acd.begin << " - " << acd.end << endl;
}
int chooseClass() {
	int n;
	cout << "Chon lop ban muon them sinh vien: \n";
	cout << "1. 23CTT1\n";
	cout << "1. 23CTT2\n";
	cout << "1. 23CTT3\n";
	cout << "1. 23CTT4\n";
	cout << "1. 23CTT5\n";
	cout << "1. 23CLC01\n";
	cout << "1. 23CLC02\n";
	cout << "1. 23APCS1\n";
	cout << "1. 23APCS2\n";
	do {
		cin >> n;
	} while (n < 0 || n>9);
	return n;
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
		int tmp = 1;
		while (!fin.eof())
		{
			Student st;
			fin >> st.STT;
			if (st.STT != tmp) {
				break;
				fin.close();
			}
			tmp++;
			fin.ignore();
			getline(fin, st.studentID, ',');
			getline(fin, st.fullName, ',');
			getline(fin, st.Gender, ',');
			fin >> st.DoB.day;
			fin.ignore();
			fin >> st.DoB.month;
			fin.ignore();
			fin >> st.DoB.year;
			fin.ignore();
			getline(fin, st.socialID, '\n');
			splitName(st);
			addNodeStudent(lst, createNodeStudent(st));
		}
		Clas cls;
		cls.nameClass = fileName[i].substr(0, fileName[i].find_first_of('.'));
		cls.lst.Head = new NodeStudent;
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
	getline(cin, st.fullName);
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
void writeCoure(string fileName, Course cour)
{
	ofstream fout;
	fout.open(fileName);
	if (!fout.is_open())
	{
		cout << "Tao file khong thanh cong" << endl;
		return;
	}
	NodeStudent* st = cour.sv.Head;
	int i = 1;
	while (st != NULL)
	{
		fout << i << ";";
		fout << st->sv.studentID << ";";
		fout << st->sv.fullName << ";";
		fout << st->sv.Gender << ";";
		fout << st->sv.DoB.day << "/";
		fout << st->sv.DoB.month << "/";
		fout << st->sv.DoB.year << ";";
		fout << st->sv.socialID;
		if (st->Next != NULL)
		{
			fout << endl;
		}
		st = st->Next;
		i++;
	}
	fout.close();
}
void removeStudent(ListStudent& lst, int pos) {
	int n = getSize(lst);
	if (pos < 1 || pos > n) {
		cout << "Vi tri khong hop le!\n";
		return;
	}

	NodeStudent* tmp = lst.Head;
	if (pos == 1) {
		removeFirst(lst);
		return;
	}

	if (pos == n) {
		removeLast(lst);
		return;
	}

	for (int i = 1; i < pos - 1; i++) {
		tmp = tmp->Next;
	}

	NodeStudent* nodeToDelete = tmp->Next;
	tmp->Next = nodeToDelete->Next;
	delete nodeToDelete;
}
void removeStudent_MSSV(ListStudent& lst) {
	string MSSV;
	cout << "\nSinh vien ban muon xoa co MSSV la: ";
	cin >> MSSV;
	NodeStudent* tmp = lst.Head;
	int pos = 1;

	while (tmp != nullptr) {
		if (tmp->sv.studentID == MSSV) {
			removeStudent(lst, pos);
			return;
		}
		tmp = tmp->Next;
		pos++;
	}

	cout << "Khong tim thay sinh vien co MSSV: " << MSSV << endl;
}
void inputPersonScore(Student& psc) {
	cout << "\nSTT: ";
	cin >> psc.STT;
	cout << "\nMSSV: ";
	cin >> psc.studentID;
	cout << "\nFull Name: ";
	getline(cin, psc.fullName);
	cout << "\nRegular Mark: ";
	cin >> psc.regularMark;
	cout << "\nMidterm Mark: ";
	cin >> psc.midtermMark;
	cout << "\nFinal Mark: ";
	cin >> psc.finalMark;
	cout << "\nTotal Mark: ";
	cin >> psc.totalMark;
}
void printListStudentScore(Course crs) {
	NodeStudent* lstScr = crs.sv.Head;
	cout << "----------------------------------------------------------------------------------------------\n";
	cout << "| " << setw(5) << left << "STT" << "| " << setw(12) << left << "MSSV" << "| " << setw(25) << left << "Full name" << "| " << setw(14) << left << "Regular Mark" << "| " << setw(9) << "Midterm" << "| " << setw(7) << "Final" << "| " << setw(7) << "Total" << "|" << endl;
	cout << "----------------------------------------------------------------------------------------------\n";
	while (lstScr != NULL) {
		cout << "| " << setw(5) << left << lstScr->sv.STT << "| " << setw(12) << left << lstScr->sv.studentID << "| " << setw(25) << left << lstScr->sv.fullName << "| " << setw(14) << left << lstScr->sv.regularMark << "| " << setw(9) << lstScr->sv.midtermMark << "| " << setw(7) << lstScr->sv.finalMark << "| " << setw(7) << lstScr->sv.totalMark << "|" << endl;
		lstScr = lstScr->Next;
	}
}
void printListCourseScore(Course crs) {
	cout << "Khoa hoc: " << crs.courseName << endl;
	NodeStudent* lstScr = crs.sv.Head;
	cout << "----------------------------------------------------------------------------------------------\n";
	cout << "| " << setw(5) << left << "STT" << "| " << setw(12) << left << "MSSV" << "| " << setw(25) << left << "Full name" << "| " << setw(14) << left << "Regular Mark" << "| " << setw(9) << "Midterm" << "| " << setw(7) << "Final" << "| " << setw(7) << "Total" << "|" << endl;
	cout << "----------------------------------------------------------------------------------------------\n";
	while (lstScr != NULL) {
		cout << "| " << setw(5) << left << lstScr->sv.STT << "| " << setw(12) << left << lstScr->sv.studentID << "| " << setw(25) << left << lstScr->sv.fullName << "| " << setw(14) << left << lstScr->sv.regularMark << "| " << setw(9) << lstScr->sv.midtermMark << "| " << setw(7) << lstScr->sv.finalMark << "| " << setw(7) << lstScr->sv.totalMark << "|" << endl;
		lstScr = lstScr->Next;
	}
}
void printClassScore(Clas cls) {
	cout << "Lop: " << cls.nameClass << endl;
	NodeStudent* lstScr = cls.lst.Head;
	cout << "----------------------------------------------------------------------------------------------\n";
	cout << "| " << setw(5) << left << "STT" << "| " << setw(12) << left << "MSSV" << "| " << setw(25) << left << "Full name" << "| " << setw(14) << left << "Regular Mark" << "| " << setw(9) << "Midterm" << "| " << setw(7) << "Final" << "| " << setw(7) << "Total" << "|" << endl;
	cout << "----------------------------------------------------------------------------------------------\n";
	while (lstScr != NULL) {
		cout << "| " << setw(5) << left << lstScr->sv.STT << "| " << setw(12) << left << lstScr->sv.studentID << "| " << setw(25) << left << lstScr->sv.fullName << "| " << setw(14) << left << lstScr->sv.regularMark << "| " << setw(9) << lstScr->sv.midtermMark << "| " << setw(7) << lstScr->sv.finalMark << "| " << setw(7) << lstScr->sv.totalMark << "|" << endl;
		lstScr = lstScr->Next;
	}
}
void PersonalScore(ListCourse lcs) {
	string MSSV;
	cout << "\nNhap MSSV cua sinh vien ban muon xem diem: ";
	cin >> MSSV;
	NodeCourse* tmp = lcs.Head;
	while (tmp != NULL) {
		if (tmp->crs.sv.Head->sv.studentID == MSSV) {
			printListStudentScore(tmp->crs);
		}
		tmp = tmp->Next;
	}
}
int PrintScore() {
	int n;
	cout << "Chon lop ban muon xem diem: \n";
	cout << "1. 23CTT1\n";
	cout << "2. 23CTT2\n";
	cout << "3. 23CTT3\n";
	cout << "4. 23CTT4\n";
	cout << "5. 23CTT5\n";
	cout << "6. 23CLC01\n";
	cout << "7. 23CLC02\n";
	cout << "8. 23APCS1\n";
	cout << "9. 23APCS2\n";
	do {
		cin >> n;
	} while (n < 0 || n>9);
	return n;
}
void printScoreClass(ListCourse lcr, ListClass lcs) {
	int n = PrintScore();
	NodeCourse* tmp = lcr.Head;
	NodeClass* tmp1 = lcs.Head;
	for (int i = 1; i < n; i++) {
		tmp1 = tmp1->Next;
	}
	cout << tmp1->cls.nameClass << endl;
	NodeStudent* tmp3 = tmp1->cls.lst.Head;
	for (NodeCourse* i = tmp; i != NULL; i = i->Next) {
		for (NodeStudent* j = tmp3; j != NULL; j = j->Next) {
			if (i->crs.sv.Head->sv.studentID == tmp3->sv.studentID) {
				cout << "Khoa hoc da tham gia: " << i->crs.courseName << endl;
				cout << "MSSV: " << i->crs.sv.Head->sv.studentID << endl;
				cout << "FullName: " << i->crs.sv.Head->sv.fullName << endl;
				cout << "Total Mark: " << i->crs.sv.Head->sv.totalMark << endl;
			}
		}
	}
}
NodeAccount* createNodeAccount(Account acc) {
	NodeAccount* p = new NodeAccount;
	p->acc = acc;
	p->Next = NULL;
	return p;
}
void addNodeAccount(ListAccount& lac, NodeAccount* acc) {
	if (lac.Head == NULL)
	{
		lac.Head = acc;
		lac.Head->Next = NULL;
		return;
	}
	NodeAccount* temp = lac.Head;
	while (temp->Next != NULL)
	{
		temp = temp->Next;
	}
	temp->Next = acc;
}
void UploadAccount(string fileName, ListAccount& lac) {
	ifstream fin(fileName);
	if (!fin) {
		cout << "\nKhong the mo file " << fileName << endl;
		return;
	}
	string line;
	while (getline(fin, line)) {
		Account acc;
		stringstream ss(line);
		getline(ss, acc.username, ',');
		getline(ss, acc.password, ',');
		getline(ss, acc.fullName, ',');
		ss >> acc.born.day;
		ss.ignore();
		ss >> acc.born.month;
		ss.ignore();
		ss >> acc.born.year;
		ss.ignore();
		getline(ss, acc.gender, '\n');
		addNodeAccount(lac, createNodeAccount(acc));
	}
	fin.close();
}

void printListAccount(ListAccount lac) {
	NodeAccount* tmp = lac.Head;
	while (tmp != NULL) {
		cout << tmp->acc.username << endl;
		cout << tmp->acc.password << endl;
		tmp = tmp->Next;
	}
}
NodeAccount* Login(ListAccount lac, string user, string pass)
{
	NodeAccount* tmp = lac.Head;
	while (tmp != NULL) {
		if (tmp->acc.username == user && tmp->acc.password == pass) {
			return tmp;
		}
		tmp = tmp->Next;
	}
	return NULL;
}
void printInforOfCrs(Course crs) {
	cout << "Khoa hoc: " << crs.courseName << endl;
	cout << "ID: " << crs.courseID << endl;
	cout << "Giao vien: " << crs.teacher << endl;
	cout << "So hoc sinh toi da: " << crs.maxStudent;
	cout << "Lich hoc: " << crs.cld.Day << '/' << crs.cld.Time << endl;
}
void printTheStudentCourses(string mssv, ListCourse lstCrs) {
	NodeCourse* nCrs = lstCrs.Head;
	while (nCrs != NULL) {
		NodeStudent* nStd = nCrs->crs.sv.Head;
		while (nStd != NULL) {
			if (nStd->sv.studentID == mssv) {
				printInforOfCrs(nCrs->crs);
				cout << "---------------------------------\n";
			}
			nStd = nStd->Next;
		}
		nStd = nStd->Next;
	}
}

int countStudent(ListStudent lStd) 
{
	if (lStd.Head == NULL) {
		return 0;
	}
	NodeStudent* tmp = lStd.Head;
	int cnt = 0;
	while (tmp != NULL) {
		cnt += 1;
		tmp = tmp->Next;
	}
	return cnt;
}

int countClass(ListClass lCls) 
{
	if (lCls.Head == NULL) {
		return 0;
	}
	NodeClass* tmp = lCls.Head;
	int cnt = 0;
	while (tmp != NULL) {
		cnt += 1;
		tmp = tmp->Next;
	}
	return cnt;
}

NodeStudent* findStudentByPos(ListStudent lStd, int pos) 
{
	if (pos > countStudent(lStd)) {
		return NULL;
	}
	NodeStudent* nStd = lStd.Head;
	for (int i = 1; i < pos; i++) {
		nStd = nStd->Next;
	}
	return nStd;
}

NodeClass* findClassByPos(ListClass lcls, int pos)
{
	if (pos > countClass(lcls))
	{
		return NULL;
	}
	NodeClass* temp = lcls.Head;
	for (int i = 1; i < pos; i++)
	{
		temp = temp->Next;
	}
	return temp;
}

NodeClass* findClassByName(ListClass lcls, string name)
{
	if (lcls.Head == NULL)
	{
		return NULL;
	}
	NodeClass* temp = lcls.Head;
	while (temp != NULL)
	{
		if (temp->cls.nameClass==name)
		{
			return temp;
		}
		temp = temp->Next;
	}
	return NULL;
}

void readFileCSV(string fileName, Clas& cls,bool &check)
{
	ifstream fin;
	fin.open(fileName);
	if (!fin.is_open())
	{
		check = false;
		return;
	}
	while (!fin.eof())
	{
		Student st;
		fin >> st.STT;
		fin.ignore();
		getline(fin, st.studentID, ',');
		getline(fin, st.fullName, ',');
		getline(fin, st.Gender, ',');
		fin >> st.DoB.day;
		fin.ignore();
		fin >> st.DoB.month;
		fin.ignore();
		fin >> st.DoB.year;
		fin.ignore();
		getline(fin, st.socialID, '\n');
		splitName(st);
		addNodeStudent(cls.lst, createNodeStudent(st));
	}
	fin.close();
}

ListClass lstClsInAYear(ListClass lst, int year)
{
	ListClass lClasInYear;
	lClasInYear.Head = NULL;
	NodeClass* lCls = lClasInYear.Head;
	NodeClass* tmp = lst.Head;
	while (tmp != NULL) {
		if (tmp->cls.nameClass[1] == '4' - year) {
			addNodeClass(lClasInYear, createNodeClass(tmp->cls));
		}
		tmp = tmp->Next;
	}
	return lClasInYear;
}

int check_Seme(Semester smt, Date cur) 
{
	if (cur.day == smt.begin.day && cur.month == smt.begin.month && cur.year == smt.begin.year) return -1;
	else if (cur.day == smt.end.day && cur.month == smt.end.month && cur.year == smt.end.year) return 1;
	else return 0;
}

void changePassword(Account& acc) {
	string newPassword;
	cout << "Nhap mat moi: \n";
	cin >> newPassword;
	while (newPassword == acc.password) {
		cout << "Mat khau moi trung voi mat khau cu\n";
		cout << "Nhap mat moi: \n";
		cin >> newPassword;
	}
	acc.password = newPassword;
}
void changePasswordInListAccount(ListAccount& lAcc, Account Acc) {
	changePassword(Acc);
	NodeAccount* nAcc = lAcc.Head;
	while (nAcc != NULL) {
		if (nAcc->acc.username == Acc.username) {
			nAcc->acc = Acc;
			break;
		}
		nAcc = nAcc->Next;
	}
}

int countCourse(ListCourse lCrs)
{
	int cnt = 0;
	NodeCourse* tmp = lCrs.Head;
	while (tmp != NULL) {
		cnt++;
		tmp = tmp->Next;
	}
	return cnt;
}

NodeCourse* findCourseByPos(ListCourse lcrs, int pos)
{
	if (pos > countCourse(lcrs)) {
		return NULL;
	}
	NodeCourse* temp = lcrs.Head;
	for (int i = 1; i < pos; i++) {
		temp=temp->Next;
	}
	return temp;
}

NodeSeme* createNodeSeme(Semester sms)
{
	NodeSeme* tmp = new NodeSeme();
	tmp->smt = sms;
	tmp->Next = NULL;
	return tmp;
}
void addNodeSeme(ListSeme& lsm, NodeSeme* ns)
{
	if (lsm.Head == NULL)
	{
		lsm.Head = ns;
		lsm.Head->Next = NULL;
		return;
	}
	NodeSeme* tmp = lsm.Head;
	while (tmp->Next != NULL)
	{
		tmp = tmp->Next;
	}
	tmp->Next = ns;
}

NodeCourse* createNodeCourse(Course crs)
{
	NodeCourse* tmp = new NodeCourse;
	tmp->crs = crs;
	tmp->Next = NULL;
	return tmp;
}

NodeCourse* findCourseByID(ListCourse lcrs,string courseID)
{
	NodeCourse* temp = lcrs.Head;
	if (lcrs.Head == NULL)
	{
		return NULL;
	}
	while (temp != NULL)
	{
		if (temp->crs.courseID == courseID)
		{
			return temp;
		}
		temp = temp->Next;
	}
	return NULL;
}

void addNodeCourse(ListCourse& lcrs, NodeCourse* crs)
{
	if (lcrs.Head == NULL)
	{
		lcrs.Head = crs;
		lcrs.Head->Next = NULL;
		return;
	}
	NodeCourse* temp = lcrs.Head;
	while (temp->Next != NULL)
	{
		temp = temp->Next;
	}
	temp->Next = crs;
}

NodeStudent* check_Course_and_MSSV(ListCourse lcr, string IDcourse, string MSSV) 
{
	NodeCourse* tmp1 = lcr.Head;
	while (tmp1 != NULL) {
		if (tmp1->crs.courseID == IDcourse) {
			NodeStudent* tmp2 = tmp1->crs.sv.Head;
			while (tmp2 != NULL) {
				if (tmp2->sv.studentID == MSSV) {
					return tmp2;
				}
				tmp2 = tmp2->Next;
			}
		}
		tmp1 = tmp1->Next;
	}
	return NULL;
}

void removeStudentOfCourse(ListCourse& lcrs, string courseID, string studentID)
{
	NodeStudent* dele = check_Course_and_MSSV(lcrs, courseID, studentID);
	if (dele == NULL)
	{
		return;
	}
	NodeCourse* crs = findCourseByID(lcrs, courseID);
	NodeStudent* temp = crs->crs.sv.Head;
	if (temp == dele)
	{
		temp = temp->Next;
		crs->crs.sv.Head = temp;
		delete dele;
		return;
	}
	while (temp->Next != NULL)
	{
		if (temp->Next == dele)
		{
			break;
		}
		temp = temp->Next;
	}
	temp->Next = dele->Next;
	delete dele;
	dele= NULL;
}

void inputScore_Student(ListCourse& lcr, string IDcourse, string MSSV) 
{
	NodeStudent* tmp = check_Course_and_MSSV(lcr, IDcourse, MSSV);
	if (tmp == NULL) {
		return;
	}
	cin >> tmp->sv.regularMark >> tmp->sv.midtermMark >> tmp->sv.finalMark >> tmp->sv.totalMark;
}
void removeFirst(ListCourse& lcr) 
{
	NodeCourse* tmp = lcr.Head;
	if (tmp == NULL) {
		return;
	}
	lcr.Head = lcr.Head->Next;
	delete tmp;
}
void removeLast(ListCourse& lcr) 
{
	NodeCourse* tmp = lcr.Head;
	NodeCourse* tmp1 = lcr.Head;
	if (tmp == NULL) return;
	while (tmp->Next!= NULL) {
		tmp1 = tmp;
		tmp = tmp->Next;
	}
	delete tmp;
	tmp1->Next = NULL;
}
void removeCourse(ListCourse& lcr, int pos)
{
	int n = countCourse(lcr);
	if (pos < 1 || pos > n) {
		cout << "Vi tri khong hop le!\n";
		return;
	}
	NodeCourse* tmp = lcr.Head;
	if (pos == 1) {
		removeFirst(lcr);
		return;
	}

	if (pos == n) {
		removeLast(lcr);
		return;
	}
	for (int i = 1; i < pos-1; i++) {
		tmp = tmp->Next;
	}
	NodeCourse* nodeToDelete = tmp->Next;
	tmp->Next = nodeToDelete->Next;
	delete nodeToDelete;
}
void removeCourse_IDCourse(ListCourse& lcr, string IDcourse) 
{
	NodeCourse* tmp = lcr.Head;
	int pos = 1;

	while (tmp != NULL) {
		if (tmp->crs.courseID == IDcourse) {
			removeCourse(lcr, pos);
			return;
		}
		tmp = tmp->Next;
		pos++;
	}
	cout << "Khong tim thay khoa hoc co ID: " << IDcourse << endl;
}

//void changePassword(Account& acc) 
//{
//	string newPassword;
//	cout << "Nhap mat moi: \n";
//	cin >> newPassword;
//	while (newPassword == acc.password) {
//		cout << "Mat khau moi trung voi mat khau cu\n";
//		cout << "Nhap mat moi: \n";
//		cin >> newPassword;
//	}
//	acc.password = newPassword;
//}
//void changePasswordInListAccount(ListAccount& lAcc, Account Acc) 
//{
//	changePassword(Acc);
//	NodeAccount* nAcc = lAcc.Head;
//	while (nAcc != NULL) {
//		if (nAcc->acc.username == Acc.username) {
//			nAcc->acc = Acc;
//			break;
//		}
//		nAcc = nAcc->Next;
//	}
//}
