
#include "Functions.h"
int main() {
	node CTT1 = NULL;
	node CTT2 = NULL;
	node CTT3 = NULL;
	node CTT4 = NULL;
	node CTT5 = NULL;
	node CLC01 = NULL;
	node CLC02 = NULL;
	node APCS1 = NULL;
	node APCS2 = NULL;
	ListNode* lst = new ListNode[9];
	lst[0].Head = APCS1;
	lst[1].Head = APCS2;
	lst[2].Head = CLC01;
	lst[3].Head = CLC02;
	lst[4].Head = CTT1;
	lst[5].Head = CTT2;
	lst[6].Head = CTT3;
	lst[7].Head = CTT4;
	lst[8].Head = CTT5;
	createAcademicYear(2023);
	string file_name[] = { "23CTT1.csv", "23CTT2.csv", "23CTT3.csv", "23CTT4.csv", "23CTT5.csv", "23CLC01.csv", "23CLC02.csv", "23APCS1.csv", "23APCS2.csv" };
	int n1 = chooseClass();
	AcaYear aca;
	aca.CTT = new Clas[5];
	aca.CLC = new Clas[2];
	aca.APCS = new Clas[2];
	int sl;
	int n[9];
	Clas* a = createClass(file_name, aca, sl, n1, n);
	Clas cls1;
	if (n1 == 1) {
		/*cout << "\n" << a[0].nameClass << endl;
		cout << "------------" << endl;
		for (int i = 0; i < 5; i++) {
			node tmp = makeNode(a[0].sinhVien[i]);
			addNodeSV(APCS1, tmp);
		}
		printNode(APCS1);
		cout << "\n" << a[1].nameClass << endl;
		cout << "------------" << endl;
		for (int i = 0; i < 5; i++) {
			node tmp = makeNode(a[1].sinhVien[i]);
			addNodeSV(APCS2, tmp);
		}
		printNode(APCS2);*/
		for (int i = 0; i < 2; i++)
		{
			cout << a[i].nameClass << endl;
			cout << "-------------------" << endl;
			for (int j = 0; j < n[i]; j++)
			{
				node temp = makeNode(a[i].sinhVien[j]);
				addNodeSV(lst[i].Head, temp);
			}
			printNode(lst[i].Head);
			cout << "-----------------" << endl << endl;
		}
	}
	else if (n1 == 2) {
		//cout << "\n" << a[0].nameClass << endl;
		//cout << "------------" << endl;
		//for (int i = 0; i < 5; i++) {
		//	node tmp = makeNode(a[0].sinhVien[i]);
		//	addNodeSV(CLC01, tmp);
		//}
		//printNode(CLC01);
		//cout << "\n" << a[1].nameClass << endl;
		//cout << "------------" << endl;
		//for (int i = 0; i < 5; i++) {
		//	node tmp = makeNode(a[1].sinhVien[i]);
		//	addNodeSV(CLC02, tmp);
		//}
		//printNode(CLC02);
		for (int i = 2; i < 4; i++)
		{
			cout << a[i - 2].nameClass << endl;
			cout << "-------------------" << endl;
			for (int j = 0; j < n[i - 2]; j++)
			{
				node temp = makeNode(a[i - 2].sinhVien[j]);
				addNodeSV(lst[i].Head, temp);
			}
			printNode(lst[i].Head);
			cout << "-----------------" << endl << endl;
		}
	}
	else {
		//cout << "\n" << a[0].nameClass << endl;
		//cout << "------------" << endl;
		//for (int i = 0; i < 5; i++) {
		//	node tmp = makeNode(a[0].sinhVien[i]);
		//	addNodeSV(CTT1, tmp);
		//}
		//printNode(CTT1);
		//cout << "\n" << a[1].nameClass << endl;
		//cout << "------------" << endl;
		//for (int i = 0; i < 5; i++) {
		//	node tmp = makeNode(a[1].sinhVien[i]);
		//	addNodeSV(CTT2, tmp);
		//}
		//printNode(CTT2);
		//cout << "\n" << a[2].nameClass << endl;
		//cout << "------------" << endl;
		//for (int i = 0; i < 5; i++) {
		//	node tmp = makeNode(a[2].sinhVien[i]);
		//	addNodeSV(CTT3, tmp);
		//}
		//printNode(CTT3);
		//cout << "\n" << a[3].nameClass << endl;
		//cout << "------------" << endl;
		//for (int i = 0; i < 5; i++) {
		//	node tmp = makeNode(a[3].sinhVien[i]);
		//	addNodeSV(CTT4, tmp);
		//}
		//printNode(CTT4);
		//cout << "\n" << a[4].nameClass << endl;
		//cout << "------------" << endl;
		//for (int i = 0; i < 5; i++) {
		//	node tmp = makeNode(a[4].sinhVien[i]);
		//	addNodeSV(CTT5, tmp);
		//}
		//printNode(CTT5);
		for (int i = 4; i < 9; i++)
		{
			cout << a[i - 4].nameClass << endl;
			cout << "-------------------" << endl;
			for (int j = 0; j < n[i - 4]; j++)
			{
				node temp = makeNode(a[i - 4].sinhVien[j]);
				addNodeSV(lst[i].Head, temp);
			}
			printNode(lst[i].Head);
			cout << "-----------------" << endl << endl;
		}
	}
	Student sv1;
	cout << "\nNhap thong tin sinh vien can them " << ":" << endl;
	inputAStudent(sv1);
	node tmp2 = makeNode(sv1);
	int choice2;

	if (n1 == 1)
	{
		menu3();
		cin >> choice2;
		if (choice2 >= 1 && choice2 <= sl)
		{
			addNodeSV(lst[choice2 - 1].Head, tmp2);
			cout << "\nSau khi them sinh vien moi vao danh sach " << a[choice2-1].nameClass << ":" << endl;
			printNode(lst[choice2 - 1].Head);
		}
	}
	else if (n1 == 2)
	{
		menu2();
		cin >> choice2;
		if (choice2>=1 && choice2<=sl)
		{
			addNodeSV(lst[choice2 - 1+2].Head, tmp2);
			cout << "\nSau khi them sinh vien moi vao danh sach " << a[choice2 - 1].nameClass << ":" << endl;
			printNode(lst[choice2 - 1+2].Head);
		}
	}
	else
	{
		menu1();
		cin >> choice2;
		if (choice2 >= 1 && choice2 <= sl)
		{
			addNodeSV(lst[choice2 - 1 + 4].Head, tmp2);
			cout << "\nSau khi them sinh vien moi vao danh sach " << a[choice2 - 1].nameClass << ":" << endl;
			printNode(lst[choice2 - 1 + 4].Head);
		}
	}
	int hk;
	Semester *smt = new Semester[3];
	cout<<"\n---------------------"<<endl;
	switch(chooseSemester()){
		case 1:{
			nhap3HK(smt, 1);
			xuat3HK(smt, 1);
			break;
		}
		case 2:{
			nhap3HK(smt, 2);
			xuat3HK(smt, 2);
			break;
		}
		case 3:{
			nhap3HK(smt, 3);
			xuat3HK(smt, 3);
			break;
		}
	}
	return 0;
}

