#include "Functions.h"

int main() {
	
	Academy acd;
	ListClass cls;
	string fileName[] = { "23CTT1.csv", "23CTT2.csv", "23CTT3.csv", "23CTT4.csv", "23CTT5.csv", "23CLC01.csv",
	"23CLC02.csv", "23APCS1.csv", "23APCS2.csv" };
	readFileStudent(fileName, cls);
	printListClass(cls);
	return 0;
}
