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
	printClass(a, 2);	
	}         
	else if(n1==2){
		printClass(a, 2);
	}           
	else{
	    printClass(a, 5);
	}
	for(int i = 0; i<5; i++){
		node tmp = makeNode(aca.CTT[0].sinhVien[i]);
		addNode(CTT1, tmp);
	}
	Student sv1;
	addStudent(sv1);
	node tmp2 = makeNode(sv1);
	addNode(CTT1, tmp2);
	printNode(CTT1);
	//menu();         
	//int choice2; cin>>choice2;
	//switch(choice2){
		//case 1:{
			//break;
		//}
	//}

	return 0;
}

