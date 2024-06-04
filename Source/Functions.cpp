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
