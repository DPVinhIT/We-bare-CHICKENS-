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
int dayOfMonth(Date d)
{
	if (d.month == 4 || d.month == 6 || d.month == 9 || d.month == 11)
	{
		return 30;
	}
	else if (d.month == 2)
	{
		if (d.year % 400 == 0 || (d.year % 4 == 0 && d.year % 100 != 0))
		{
			return 29;
		}
		return 28;
	}
	return 31;
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

//Hàm xử lí dữ liệu student
NodeStudent* createNodeStudent(Student sv)
{
	NodeStudent* p = new NodeStudent;
	p->sv = sv;
	p->Next = NULL;
	return p;
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
NodeStudent* findStudentByID(ListStudent lst, string ID)
{
	NodeStudent* temp = lst.Head;
	while (temp != NULL)
	{
		if (temp->sv.studentID == ID)
		{
			return temp;
		}
		temp = temp->Next;
	}
	return NULL;
}
void updateNo(ListStudent& lst) {
	NodeStudent* tmp = lst.Head;
	int i = 1;
	while (tmp != NULL) {
		tmp->sv.STT = i;
		i++;
		tmp = tmp->Next;
	}
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
	updateNo(lst);
}
void removeFirst(ListStudent& lst) {
	NodeStudent* tmp = lst.Head;
	if (tmp == NULL) {
		return;
	}
	lst.Head = lst.Head->Next;
	delete tmp;
}
void removeLast(ListStudent& lst) {
	NodeStudent* tmp = lst.Head;
	if (tmp == NULL) return;
	while (tmp->Next != NULL) {
		tmp = tmp->Next;
	}
	tmp = NULL;
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
void removeStudent(ListStudent& lst, int pos) {
	int n = getSize(lst);
	if (pos < 1 || pos > n) {
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
void removeStudent_MSSV(ListStudent& lst, string studentID) {
	NodeStudent* tmp = lst.Head;
	int pos = 1;
	while (tmp != nullptr) {
		if (tmp->sv.studentID == studentID) {
			removeStudent(lst, pos);
			return;
		}
		tmp = tmp->Next;
		pos++;
	}
}
void readFileCSV(string fileName, ListStudent& lst, bool& check)
{
	ifstream fin;
	fin.open(fileName);
	if (!fin.is_open())
	{
		check = false;
		return;
	}
	int tmp = 1;
	while (!fin.eof())
	{
		Student st;
		fin >> st.STT;
		if (tmp == st.STT) {
			tmp++;
		}
		else {
			break;
		}
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
	check = true;
	fin.close();
}
void removeListStudent(ListStudent& lst) {
	if (lst.Head == NULL) return;
	while (lst.Head != NULL) {
		removeFirst(lst);
	}
	lst.Head = NULL;
}

//Hàm xử lí dữ liệu clas
NodeClass* createNodeClass(Clas cls)
{
	NodeClass* p = new NodeClass;
	p->cls = cls;
	p->Next = NULL;
	return p;
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
		if (temp->cls.nameClass == name)
		{
			return temp;
		}
		temp = temp->Next;
	}
	return NULL;
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
void readFileStudent(string fileName[], ListClass& lcls, int n)
{
	for (int i = 0; i < n; i++)
	{
		ifstream fin;
		fin.open(fileName[i]);
		if (!fin.is_open())
		{
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
		fin.close();
	}
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
ListClass lstClsInAYear(ListClass lst, int year)
{
	ListClass lClasInYear;
	NodeClass* lCls = lClasInYear.Head;
	NodeClass* tmp = lst.Head;
	while (tmp != NULL) {
		if ((tmp->cls.nameClass[0] - '0') * 10 + tmp->cls.nameClass[1] - '0' == (CurAcademy->acm.end % 2000) - year) {
			addNodeClass(lClasInYear, createNodeClass(tmp->cls));
		}
		tmp = tmp->Next;
	}
	return lClasInYear;
}

//Hàm xử lí tài khoản
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
void changePasswordInListAccount(ListAccount& lAcc, Account Acc) {
	NodeAccount* nAcc = lAcc.Head;
	while (nAcc != NULL) {
		if (nAcc->acc.username == Acc.username) {
			nAcc->acc = Acc;
			break;
		}
		nAcc = nAcc->Next;
	}
}
void UploadAccount(string fileName, ListAccount& lac) {
	ifstream fin(fileName);
	if (!fin) {
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

//Hàm xử lí khóa hoc
NodeCourse* findCourseByPos(ListCourse lcrs, int pos)
{
	if (pos > countCourse(lcrs)) {
		return NULL;
	}
	NodeCourse* temp = lcrs.Head;
	for (int i = 1; i < pos; i++) {
		temp = temp->Next;
	}
	return temp;
}
NodeCourse* findCourseByID(ListCourse lcrs, string courseID)
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
NodeCourse* createNodeCourse(Course crs)
{
	NodeCourse* tmp = new NodeCourse;
	tmp->crs = crs;
	tmp->Next = NULL;
	return tmp;
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
void removeStudentOfCourse(ListCourse& lcrs, string courseID, string studentID)
{
	NodeCourse* crs = findCourseByID(lcrs, courseID);
	if (crs == NULL)
	{
		return;
	}
	removeStudent_MSSV(crs->crs.sv.lst, studentID);
	updateNo(lcrs.Head->crs.sv.lst);
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
	while (tmp->Next != NULL) {
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
	for (int i = 1; i < pos - 1; i++) {
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
ListCourse RegisteredCourse(string StudentID)
{
	ListCourse Rc;
	Rc.Head = NULL;
	if (CurSemester == NULL)
	{
		return Rc;
	}
	NodeCourse* cr = CurSemester->smt.lcrs.Head;
	while (cr != NULL)
	{
		NodeStudent* stic = cr->crs.sv.lst.Head;
		while (stic != NULL)
		{
			if (stic->sv.studentID == StudentID)
			{
				addNodeCourse(Rc, createNodeCourse(cr->crs));
				break;
			}
			stic = stic->Next;
		}
		cr = cr->Next;
	}
	return Rc;
}
ListCourse CourseOfClass(string className)
{
	ListCourse lcr;
	lcr.Head = NULL;
	if (CurSemester == NULL)
	{
		return lcr;
	}
	NodeCourse* cr = CurSemester->smt.lcrs.Head;
	while (cr != NULL)
	{
		if (cr->crs.sv.nameClass == className)
		{
			addNodeCourse(lcr, createNodeCourse(cr->crs));
		}
		cr = cr->Next;
	}
	return lcr;
}
void writeCoure(string fileName, Course cour)
{
	ofstream fout;
	fout.open(fileName);
	if (!fout.is_open())
	{
		return;
	}
	NodeStudent* st = cour.sv.lst.Head;
	int i = 1;
	while (st != NULL)
	{
		fout << i << ",";
		fout << st->sv.studentID << ",";
		fout << st->sv.fullName << ",";
		fout << st->sv.Gender << ",";
		fout << st->sv.DoB.day << "/";
		fout << st->sv.DoB.month << "/";
		fout << st->sv.DoB.year << ",";
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

//Hàm xử lí thời gian
int checkSeme()
{
	if (CurAcademy == NULL || CurSemester == NULL)
	{
		return 0;
	}
	if (CurTime.day == CurSemester->smt.begin.day && CurTime.month == CurSemester->smt.begin.month && CurTime.year == CurSemester->smt.begin.year) return -1;
	else if (CurTime.day == CurSemester->smt.end.day && CurTime.month == CurSemester->smt.end.month && CurTime.year == CurSemester->smt.end.year) return 1;
	else return 0;
}
int checkSemester(Date cur)
{
	if (cur.day == 1)
	{
		if (cur.month == 9 || cur.month == 2 || cur.month == 7)
		{
			return -1;
		}
	}
	if (cur.month == 1 || cur.month == 6 || cur.month == 8)
	{
		if (cur.day == dayOfMonth(cur))
		{
			return 1;
		}
	}
	return 0;
}

//Hàm xử lí năm học và học kì
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
NodeAca* createNodeAcademy(Academy acm) {
	NodeAca* tmp = new NodeAca;
	tmp->acm = acm;
	tmp->Next = NULL;
	return tmp;
}
void addNodeAcademy(ListAca& lta, NodeAca* aca) {
	if (lta.Head == NULL)
	{
		lta.Head = aca;
		lta.Head->Next = NULL;
		return;
	}
	NodeAca* tmp = lta.Head;
	while (tmp->Next != NULL)
	{
		tmp = tmp->Next;
	}
	tmp->Next = aca;
}
bool checkDateOfSemester(int stt, Date start, Date end)
{
	if (!laNgayHopLe(start) || !laNgayHopLe(end))
	{
		return false;
	}
	if (stt == 1) {
		if ((start.day == 1 && start.month == 9) && (end.day == 31 && end.month == 1)) {
			if (start.year == CurAcademy->acm.begin && end.year == CurAcademy->acm.end) {
				return true;
			}
		}
	}
	else if (stt == 2) {
		if ((start.day == 1 && start.month == 2) && (end.day == 30 && end.month == 6)) {
			if (start.year == CurAcademy->acm.end && end.year == CurAcademy->acm.end) {
				return true;
			}
		}
	}
	else if (stt == 3) {
		if ((start.day == 1 && start.month == 7) && (end.day == 31 && end.month == 8)) {
			if (start.year == CurAcademy->acm.end && end.year == CurAcademy->acm.end) {
				return true;
			}
		}
	}
	return false;
}

//Đọc file bảng điểm
bool readFileScoreboard(string fileName, Course& crs)
{
	ifstream fin;
	fin.open(fileName);
	if (!fin.is_open())
	{
		return false;
	}
	int tmp = 1;
	while (!fin.eof())
	{
		Student temp;
		fin >> temp.STT;
		if (tmp == temp.STT) {
			tmp++;
		}
		else {
			break;
		}
		fin.ignore();
		getline(fin, temp.studentID, ',');
		getline(fin, temp.fullName, ',');
		fin >> temp.regularMark;
		fin.ignore();
		fin >> temp.midtermMark;
		fin.ignore();
		fin >> temp.finalMark;
		fin.ignore();
		fin >> temp.totalMark;
		NodeStudent* st = findStudentByID(crs.sv.lst, temp.studentID);
		if (st != NULL)
		{
			st->sv.totalMark = temp.totalMark;
			st->sv.finalMark = temp.finalMark;
			st->sv.midtermMark = temp.midtermMark;
			st->sv.regularMark = temp.regularMark;
		}
		else
		{
			continue;
		}
	}
	return true;
	fin.close();
}

//Tính gpa
double GpaOfSemester(string StudentID, NodeSeme* smt)
{
	double sum = 0;
	int credit = 0;
	NodeCourse* tmp = smt->smt.lcrs.Head;
	for (NodeCourse* i = tmp; i != NULL; i = i->Next) {
		NodeStudent* studentTmp = i->crs.sv.lst.Head;
		while (studentTmp != NULL) {
			if (studentTmp->sv.studentID == StudentID) {
				if (studentTmp->sv.totalMark < 0 || studentTmp->sv.totalMark>10)
				{
					break;
				}
				sum += 1.0 * studentTmp->sv.totalMark * i->crs.acaCrd;
				credit += i->crs.acaCrd;
				break;
			}
			studentTmp = studentTmp->Next;
		}
	}
	if (credit == 0)
	{
		return 0;
	}
	return 4.0 * sum / (10.0 * credit);
}
double GpaTotal(string StudentID)
{
	double Cgpa = 0;
	int sumCredit = 0;
	NodeAca* aca = ListAcademy.Head;
	while (aca != NULL)
	{
		NodeSeme* sm = aca->acm.lsm.Head;
		while (sm != NULL)
		{
			double gpa = GpaOfSemester(StudentID, sm);
			Cgpa += gpa;
			++sumCredit;
			sm = sm->Next;
		}
		aca = aca->Next;
	}
	return 1.0 * Cgpa / sumCredit;
}
int changeNewDay(Date newdate) {
	if (!laNgayHopLe(newdate))
		return -1;
	if (newdate.year > CurTime.year && newdate.month == 9 && newdate.day == 1) {
		CurAcademy->Next = new NodeAca;
		CurAcademy = CurAcademy->Next;
		CurAcademy->acm.begin = newdate.year;
		CurAcademy->acm.end = newdate.year + 1;
		CurAcademy->Next = NULL;
		CurAcademy->acm.lsm.Head = new NodeSeme;
		CurSemester = CurAcademy->acm.lsm.Head;
		CurSemester->smt.STT = 1;
		CurSemester->smt.begin.day = 1; CurSemester->smt.begin.month = 9; CurSemester->smt.begin.year = newdate.year;
		CurSemester->smt.end.day = 31; CurSemester->smt.end.month = 1; CurSemester->smt.end.year = newdate.year + 1;
		return 1;
	}
	if (CurSemester->smt.STT == 1 && newdate.year > CurTime.year && laNgayHopLe(newdate) && newdate.month >= 2 && newdate.month <= 6) {
		CurSemester->Next = new NodeSeme;
		CurSemester = CurSemester->Next;
		CurSemester->smt.STT = 2;
		CurSemester->smt.begin.day = 1; CurSemester->smt.begin.month = 2; CurSemester->smt.begin.year = newdate.year;
		CurSemester->smt.end.day = 30; CurSemester->smt.end.month = 6; CurSemester->smt.end.year = newdate.year;
		CurSemester->Next = NULL;
		return 1;
	}
	if (CurSemester->smt.STT == 2 && newdate.year == CurTime.year && laNgayHopLe(newdate) && newdate.month >= 7 && newdate.month <= 8) {
		CurSemester->Next = new NodeSeme;
		CurSemester = CurSemester->Next;
		CurSemester->smt.STT = 3;
		CurSemester->smt.begin.day = 1; CurSemester->smt.begin.month = 7; CurSemester->smt.begin.year = newdate.year;
		CurSemester->smt.end.day = 31; CurSemester->smt.end.month = 8; CurSemester->smt.end.year = newdate.year;
		CurSemester->Next = NULL;
		return 1;
	}
	return 0;
}
NodeClass* find_nameClass(ListClass lcls, string nameClass) {
	if (lcls.Head == NULL) return NULL;
	NodeClass* tmp = lcls.Head;
	for (NodeClass* i = tmp; i != NULL; i = i->Next) {
		if (i->cls.nameClass == nameClass) return i;
	}
	return NULL;
}