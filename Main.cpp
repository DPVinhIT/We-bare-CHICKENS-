#include"Functions.h"

int main() {
	string file_name[] = { "23CTT1.txt", "23CTT2.txt", "23CTT3.txt", "23CTT4.txt", "23CTT5.txt", "23CLC01.txt", "23CLC02.txt", "23APCS1.txt", "23APCS2.txt" };
	int n1 = chooseClass();
	AcaYear aca = createAcademicYear(2023);
	int sl;
	Clas* a= createClass(file_name, aca, sl, n1);
	printAcaYear(aca);
		return 0;
}
