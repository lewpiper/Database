//Database Lab
//Lew Piper III | Palomar ID 011263249

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
FILE *fpwrite;
FILE *fpread;

//Function Prototypes 
void strsub(char buf[], char sub[], int start, int end);
void readFile();

//Struct
typedef struct {
	char first[8];
	char initial[2];
	char last[10];
	char street[17];
	char city[12];
	char state[3];
	char zip[6];
	int age;
	char sex[2];
	int tenure;
	double salary;
} data;


//Main Function
int main(int argc, char *argv[]) {
	fpwrite = fopen("csis.txt", "w");
	
	readFile();
	
	fclose(fpwrite);
	return 0;
}

//Substring fucntion from the book
void strsub(char buf[], char sub[], int start, int end) {
	int i;
	int j;
	
	for (j = 0, i = start; i <= end; i++, j++) {
		sub[j] = buf[i];
	}
	sub[j] = '\0';
}

//Part B
void print_employee(data* employee) {
	printf("%s %s %s %s %s %s %s %d %s %d %.2f\n", employee->first, employee->initial, employee->last
						   , employee->street, employee->city, employee->state
						   , employee->zip, employee->age, employee->sex, employee->tenure
						   , employee->salary);
						
	fprintf(fpwrite,"%s %s %s %s %s %s %s %d %s %d %.2f\n", employee->first, employee->initial, employee->last
	   , employee->street, employee->city, employee->state
	   , employee->zip, employee->age, employee->sex, employee->tenure
	   , employee->salary);
}


//Part A
void readFile() {
	int count = 0;
	data employees[MAX];
	
	//Open file for reading
	if(!(fpread = fopen("payfile.txt", "r"))){
		printf("File %s could not be opened. \n", "payfile.txt");
		fprintf(fpwrite,"File %s could not be opened. \n", "payfile.txt");
		exit(1);
	}
	
	//Reads in file
	while (!feof(fpread)) {
		char buf[MAX+2];
		char agebuf[4];
		char tenurebuf[2];
		char salarybuf[7];
		fgets(buf, /*count=*/MAX, fpread);
		strsub(buf, employees[count].first, 0, 6);
		strsub(buf, employees[count].initial, 8, 8);
		strsub(buf, employees[count].last, 10, 18);
		strsub(buf, employees[count].street, 19, 34);
		strsub(buf, employees[count].city, 37, 47);
		strsub(buf, employees[count].state, 49, 50);
		strsub(buf, employees[count].zip, 52, 56);
		strsub(buf, agebuf, 58, 59);
		strsub(buf, employees[count].sex, 61, 61);
		strsub(buf, tenurebuf, 63, 63);
		strsub(buf, salarybuf, 65, 71);
		employees[count].age = atoi(agebuf);
		employees[count].tenure = atoi(tenurebuf);
		employees[count].salary = atof(salarybuf);
		++count;
	}
	
	printf("Part B:\n");
	fprintf(fpwrite, "Part B:\n");
	for (int i = 0; i < count; ++i) {
		data* employee = &employees[i];
		print_employee(employee);
	}
	
}





