#include "Functions.h"
void createAca(Academy acd){
	cout<<"\nNhap nam bat dau: ";
	cin>>acd.begin;
	cout<<"\nNhap nam ket thuc: ";
	cin>>acd.end;
	cout<<"\nNam hoc: "<<acd.begin<<" - "<<acd.end<<endl;
}
int chooseClass(){
	int n;
	cout<<"Chon lop ban muon them sinh vien: \n";
	cout<<"1. 23CTT1\n";
	cout<<"1. 23CTT2\n";
	cout<<"1. 23CTT3\n";
	cout<<"1. 23CTT4\n";
	cout<<"1. 23CTT5\n";
	cout<<"1. 23CLC01\n";
	cout<<"1. 23CLC02\n";
	cout<<"1. 23APCS1\n";
	cout<<"1. 23APCS2\n";
	do {
		cin >> n;
	} while (n < 0 || n>9);
	return n;
}
int chooseSemester(){
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
void inputPersonScore(Student &psc){
	cout<<"\nSTT: "; 
	cin>>psc.STT;
	cout<<"\nMSSV: ";
	cin>>psc.studentID;
	cout<<"\nFull Name: ";
	getline(cin, psc.fullName);
	cout<<"\nRegular Mark: ";
	cin>>psc.regularMark;
	cout<<"\nMidterm Mark: ";
	cin>>psc.midtermMark;
	cout<<"\nFinal Mark: ";
	cin>>psc.finalMark;
	cout<<"\nTotal Mark: ";
	cin>>psc.totalMark;
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
void PersonalScore(ListCourse lcs){
	string MSSV;
	cout<<"\nNhap MSSV cua sinh vien ban muon xem diem: ";
	cin>>MSSV;
	NodeCourse* tmp = lcs.Head;
	while(tmp != NULL){
		if(tmp->crs.sv.Head->sv.studentID == MSSV){
			printListStudentScore(tmp->crs);
		}
		tmp=tmp->Next;
	}
}
int PrintScore(){
	int n;
	cout<<"Chon lop ban muon xem diem: \n";
	cout<<"1. 23CTT1\n";
	cout<<"2. 23CTT2\n";
	cout<<"3. 23CTT3\n";
	cout<<"4. 23CTT4\n";
	cout<<"5. 23CTT5\n";
	cout<<"6. 23CLC01\n";
	cout<<"7. 23CLC02\n";
	cout<<"8. 23APCS1\n";
	cout<<"9. 23APCS2\n";
	do {
		cin >> n;
	} while (n < 0 || n>9);	
	return n;
}
void printScoreClass(ListCourse lcr, ListClass lcs){
	int n = PrintScore();
	NodeCourse* tmp = lcr.Head;
	NodeClass* tmp1 = lcs.Head;
	for(int i = 1; i<n; i++){
		tmp1=tmp1->Next;
	}
	cout<<tmp1->cls.nameClass<<endl;
	NodeStudent* tmp3 = tmp1->cls.lst.Head;
	for(NodeCourse* i = tmp; i!=NULL; i=i->Next){
		for(NodeStudent* j = tmp3; j!=NULL; j=j->Next){
			if(i->crs.sv.Head->sv.studentID == tmp3->sv.studentID){
			cout<<"Khoa hoc da tham gia: "<<i->crs.courseName<<endl;
			cout<<"MSSV: "<< i->crs.sv.Head->sv.studentID<<endl;
			cout<<"FullName: "<< i->crs.sv.Head->sv.fullName<<endl;
			cout<<"Total Mark: "<<i->crs.sv.Head->sv.totalMark<<endl;
			}
		}
	}
}
NodeAccount* createNodeAccount(Account acc){
	NodeAccount* p = new NodeAccount;
	p->acc=acc;
	p->Next=NULL;
	return p;
}
void addNodeAccount(ListAccount& lac,NodeAccount* acc){
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
        getline(ss, acc.username,',');
        getline(ss, acc.password,',');
        addNodeAccount(lac, createNodeAccount(acc));
    }
    fin.close();
}

void printListAccount(ListAccount lac){
	NodeAccount* tmp = lac.Head;
	while(tmp!=NULL){
		cout<<tmp->acc.username<<endl;
		cout<<tmp->acc.password<<endl;
		tmp=tmp->Next;
	}
}
bool Login(ListAccount lac, string user, string pass){
    bool find = false;
    NodeAccount* tmp = lac.Head;
    while(tmp!=NULL){
        if(tmp->acc.username==user && tmp->acc.password==pass){
        	find = true;
        	return find;
		}
		tmp=tmp->Next;
	}
	return find;
}