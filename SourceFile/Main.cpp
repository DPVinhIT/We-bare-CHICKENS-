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
	string file_name[] = { "23CTT1.txt", "23CTT2.txt", "23CTT3.txt", "23CTT4.txt", "23CTT5.txt", "23CLC01.txt", "23CLC02.txt", "23APCS1.txt", "23APCS2.txt" };
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
		addNode(APCS1, tmp);
	}
	printNode(APCS1);
	cout<<"\n"<<a[1].nameClass<<endl;
	cout<<"------------"<<endl;
	for(int i = 0; i<5; i++){
		node tmp = makeNode(a[1].sinhVien[i]);
		addNode(APCS2, tmp);
	}
	printNode(APCS2);
	}
	else if(n1==2){
	cout<<"\n"<<a[0].nameClass<<endl;
	cout<<"------------"<<endl;
	for(int i = 0; i<5; i++){
		node tmp = makeNode(a[0].sinhVien[i]);
		addNode(CLC01, tmp);
	}
	printNode(CLC01);
	cout<<"\n"<<a[1].nameClass<<endl;
	cout<<"------------"<<endl;
	for(int i = 0; i<5; i++){
		node tmp = makeNode(a[1].sinhVien[i]);
		addNode(CLC02, tmp);
	}
	printNode(CLC02);
	}
	else{
	cout<<"\n"<<a[0].nameClass<<endl;
	cout<<"------------"<<endl;
	for(int i = 0; i<5; i++){
		node tmp = makeNode(a[0].sinhVien[i]);
		addNode(CTT1, tmp);
	}
	printNode(CTT1);
	cout<<"\n"<<a[1].nameClass<<endl;
	cout<<"------------"<<endl;
	for(int i = 0; i<5; i++){
		node tmp = makeNode(a[1].sinhVien[i]);
		addNode(CTT2, tmp);
	}
	printNode(CTT2);
	cout<<"\n"<<a[2].nameClass<<endl;
	cout<<"------------"<<endl;
	for(int i = 0; i<5; i++){
		node tmp = makeNode(a[2].sinhVien[i]);
		addNode(CTT3, tmp);
	}
	printNode(CTT3);
	cout<<"\n"<<a[3].nameClass<<endl;
	cout<<"------------"<<endl;
	for(int i = 0; i<5; i++){
		node tmp = makeNode(a[3].sinhVien[i]);
		addNode(CTT4, tmp);
	}
	printNode(CTT4);
	cout<<"\n"<<a[4].nameClass<<endl;
	cout<<"------------"<<endl;
	for(int i = 0; i<5; i++){
		node tmp = makeNode(a[4].sinhVien[i]);
		addNode(CTT5, tmp);
	}
	printNode(CTT5);
	}
	Student sv1;
	cout<<"\nNhap thong tin sinh vien can them: "<<endl;
	inputAStudent(sv1);
	node tmp2 = makeNode(sv1);
	int choice2;
	if(n1==1){
		menu3();
		cin>>choice2;
		switch(choice2){
			case 1:{
				addNode(APCS1, tmp2);
				cout<<"\nSau khi them sinh vien moi vao danh sach: "<<a[0].nameClass<<endl;
				printNode(APCS1);
				break;
			}
			case 2:{
				addNode(APCS2, tmp2);
				cout<<"\nSau khi them sinh vien moi vao danh sach: "<<a[1].nameClass<<endl;
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
				addNode(CLC01, tmp2);
				cout<<"\nSau khi them sinh vien moi vao danh sach: "<<a[0].nameClass<<endl;
				printNode(CLC01);
				break;
			}
			case 2:{
				addNode(CLC02, tmp2);
				cout<<"\nSau khi them sinh vien moi vao danh sach: "<<a[1].nameClass<<endl;
				printNode(CLC02);
				break;
			}
			
			
		}
	}else{
		menu1();
		cin>>choice2;
		switch(choice2){
			case 1:{
				addNode(CTT1, tmp2);
				cout<<"\nSau khi them sinh vien moi vao danh sach: "<<a[0].nameClass<<endl;
				printNode(CTT1);
				break;
			}
			case 2:{
				addNode(CTT2, tmp2);
				cout<<"\nSau khi them sinh vien moi vao danh sach: "<<a[1].nameClass<<endl;
				printNode(CTT2);
				break;
			}
			case 3:{
				addNode(CTT3, tmp2);
				cout<<"\nSau khi them sinh vien moi vao danh sach: "<<a[2].nameClass<<endl;
				printNode(CTT3);
				break;
			}
			case 4:{
				addNode(CTT4, tmp2);
				cout<<"\nSau khi them sinh vien moi vao danh sach: "<<a[3].nameClass<<endl;
				printNode(CTT4);
				break;
			}
			case 5:{
				addNode(CTT5, tmp2);
				cout<<"\nSau khi them sinh vien moi vao danh sach: "<<a[4].nameClass<<endl;
				printNode(CTT5);
				break;
			}
	}
	return 0;
}
}

 
