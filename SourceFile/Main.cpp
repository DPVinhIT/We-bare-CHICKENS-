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
	createAcademicYear(2023);
	string file_name[] = { "23CTT1.csv", "23CTT2.csv", "23CTT3.csv", "23CTT4.csv", "23CTT5.csv", "23CLC01.csv", "23CLC02.csv", "23APCS1.csv", "23APCS2.csv" };
	int n1 = chooseClass();
	AcaYear aca;
	aca.CTT = new Clas[5];
	aca.CLC = new Clas[2];
	aca.APCS = new Clas[2];
	int sl;
	Clas* a= createClass(file_name, aca, sl, n1);
	Clas cls1;
	if(n1==1){
	cout<<"\n"<<a[0].nameClass<<endl;
	cout<<"------------"<<endl;
	for(int i = 0; i<5; i++){
		node tmp = makeNode(a[0].sinhVien[i]);
		addNodeSV(APCS1, tmp);
	}
	printNode(APCS1);
	cout<<"\n"<<a[1].nameClass<<endl;
	cout<<"------------"<<endl;
	for(int i = 0; i<5; i++){
		node tmp = makeNode(a[1].sinhVien[i]);
		addNodeSV(APCS2, tmp);
	}
	printNode(APCS2);
	}
	else if(n1==2){
	cout<<"\n"<<a[0].nameClass<<endl;
	cout<<"------------"<<endl;
	for(int i = 0; i<5; i++){
		node tmp = makeNode(a[0].sinhVien[i]);
		addNodeSV(CLC01, tmp);
	}
	printNode(CLC01);
	cout<<"\n"<<a[1].nameClass<<endl;
	cout<<"------------"<<endl;
	for(int i = 0; i<5; i++){
		node tmp = makeNode(a[1].sinhVien[i]);
		addNodeSV(CLC02, tmp);
	}
	printNode(CLC02);
	}
	else{
	cout<<"\n"<<a[0].nameClass<<endl;
	cout<<"------------"<<endl;
	for(int i = 0; i<5; i++){
		node tmp = makeNode(a[0].sinhVien[i]);
		addNodeSV(CTT1, tmp);
	}
	printNode(CTT1);
	cout<<"\n"<<a[1].nameClass<<endl;
	cout<<"------------"<<endl;
	for(int i = 0; i<5; i++){
		node tmp = makeNode(a[1].sinhVien[i]);
		addNodeSV(CTT2, tmp);
	}
	printNode(CTT2);
	cout<<"\n"<<a[2].nameClass<<endl;
	cout<<"------------"<<endl;
	for(int i = 0; i<5; i++){
		node tmp = makeNode(a[2].sinhVien[i]);
		addNodeSV(CTT3, tmp);
	}
	printNode(CTT3);
	cout<<"\n"<<a[3].nameClass<<endl;
	cout<<"------------"<<endl;
	for(int i = 0; i<5; i++){
		node tmp = makeNode(a[3].sinhVien[i]);
		addNodeSV(CTT4, tmp);
	}
	printNode(CTT4);
	cout<<"\n"<<a[4].nameClass<<endl;
	cout<<"------------"<<endl;
	for(int i = 0; i<5; i++){
		node tmp = makeNode(a[4].sinhVien[i]);
		addNodeSV(CTT5, tmp);
	}
	printNode(CTT5);
	}
	Student sv1;
	cout<<"\nNhap thong tin sinh vien can them "<<":"<<endl;
	inputAStudent(sv1);
	node tmp2 = makeNode(sv1);
	int choice2;
	if(n1==1){
		menu3();
		cin>>choice2;
		switch(choice2){
			case 1:{
				addNodeSV(APCS1, tmp2);
				cout<<"\nSau khi them sinh vien moi vao danh sach "<<a[0].nameClass<<":"<<endl;
				printNode(APCS1);
				break;
			}
			case 2:{
				addNodeSV(APCS2, tmp2);
				cout<<"\nSau khi them sinh vien moi vao danh sach "<<a[1].nameClass<<":"<<endl;
				printNode(APCS2);
				break;
			}
			
			
		}
	}
	else if(n1==2){
		menu2();
		cin>>choice2;
		switch(choice2){
			case 1:{
				addNodeSV(CLC01, tmp2);
				cout<<"\nSau khi them sinh vien moi vao danh sach "<<a[0].nameClass<<":"<<endl;
				printNode(CLC01);
				break;
			}
			case 2:{
				addNodeSV(CLC02, tmp2);
				cout<<"\nSau khi them sinh vien moi vao danh sach "<<a[1].nameClass<<":"<<endl;
				printNode(CLC02);
				break;
			}
			
			
		}
	}else{
		menu1();
		cin>>choice2;
		switch(choice2){
			case 1:{
				addNodeSV(CTT1, tmp2);
				cout<<"\nSau khi them sinh vien moi vao danh sach "<<a[0].nameClass<<":"<<endl;
				printNode(CTT1);
				break;
			}
			case 2:{
				addNodeSV(CTT2, tmp2);
				cout<<"\nSau khi them sinh vien moi vao danh sach "<<a[1].nameClass<<":"<<endl;
				printNode(CTT2);
				break;
			}
			case 3:{
				addNodeSV(CTT3, tmp2);
				cout<<"\nSau khi them sinh vien moi vao danh sach "<<a[2].nameClass<<":"<<endl;
				printNode(CTT3);
				break;
			}
			case 4:{
				addNodeSV(CTT4, tmp2);
				cout<<"\nSau khi them sinh vien moi vao danh sach "<<a[3].nameClass<<":"<<endl;
				printNode(CTT4);
				break;
			}
			case 5:{
				addNodeSV(CTT5, tmp2);
				cout<<"\nSau khi them sinh vien moi vao danh sach "<<a[4].nameClass<<":"<<endl;
				printNode(CTT5);
				break;
			}
	}
	
}
	return 0;
}

 
