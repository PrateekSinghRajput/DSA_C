/*Q2. Create an employee structure with the following members
empid, employee name, salary, year of joining etc.
Accept the data for certain no. o of employees and find their total,
average, max, min salary.
Also find out the employees with maximum, minimum service,use a
function to find service for each employee element in the array. */

#include <stdio.h>

#define CURRENT_YEAR 2025


union ID_Proof {
char aadhar[20];
char passport[20];
char voterID[20];
};

struct Employee {
int empid;
char name[50];
float salary;
unsigned int year_of_joining;
int age;
char gender; 

union ID_Proof id_proof;
int id_type; 
};

int get_service_years(int joining_year) {
return CURRENT_YEAR - joining_year;
}

void salary_stats(struct Employee emp[], int count) {
float total = 0, max = emp[0].salary, min = emp[0].salary;
int max_emp = 0, min_emp = 0;

for (int i = 0; i < count; i++) {
total += emp[i].salary;

if (emp[i].salary > max) {
max = emp[i].salary;
max_emp = i;
}
if (emp[i].salary < min) {
min = emp[i].salary;
min_emp = i;
}
}

printf("\nTotal Salary: %.2f\n", total);
printf("Average Salary: %.2f\n", total / count);
printf("Max Salary: %.2f (Employee: %s)\n", max, emp[max_emp].name);
printf("Min Salary: %.2f (Employee: %s)\n", min, emp[min_emp].name);
}

void service_stats(struct Employee emp[], int count) {
int max_service = get_service_years(emp[0].year_of_joining);
int min_service = max_service, max_emp = 0, min_emp = 0;

for (int i = 1; i < count; i++) {
int service = get_service_years(emp[i].year_of_joining);
if (service > max_service) {
max_service = service;
max_emp = i;
}


if (service < min_service) {
min_service = service;
min_emp = i;
}
}

printf("\nMax Service: %d years (Employee: %s)\n", max_service, emp[max_emp].name);
printf("Min Service: %d years (Employee: %s)\n", min_service, emp[min_emp].name);
}

int main() {
int n;
unsigned int temp;
unsigned int MAX_EMPLOYEES =1000;

printf("Enter number of employees 0 - 1000 \n");
scanf("%d", &n);


struct Employee employees[n];


for (int i = 0; i < n; i++) {
printf("\nEnter details for Employee %d:\n", i + 1);

printf("Enter Employee ID (0-1000): ");

scanf("%u",&temp);
employees[i].empid = temp;

//scanf("%d", &employees[i].empid);


printf("Enter Name: ");
scanf(" %[^\n]", employees[i].name);

printf("Enter Salary: ");
scanf("%f", &employees[i].salary);

printf("Enter Year of Joining: ");
scanf("%d", &employees[i].year_of_joining);

printf("Enter Age (18-65): ");
scanf("%d", &employees[i].age);

printf("Enter Gender (M/F): ");
scanf(" %c", &employees[i].gender);

printf("Select ID Proof (1-Aadhar, 2-Passport, 3-Voter ID): ");
scanf("%d", &employees[i].id_type);

printf("Enter ID Number: ");
if (employees[i].id_type == 1)
scanf("%s", employees[i].id_proof.aadhar);
else if (employees[i].id_type == 2)
scanf("%s", employees[i].id_proof.passport);
else
scanf("%s", employees[i].id_proof.voterID);
}


printf("\nEmployee Details:\n");

for (int i = 0; i < n; i++) {
printf("\nEmployee %d:\n", i + 1);
printf("ID: %d, Name: %s, Salary: %.2f, Year of Joining: %d, Age: %d, Gender: %c\n",
employees[i].empid, employees[i].name, employees[i].salary,
employees[i].year_of_joining, employees[i].age, employees[i].gender);
printf("Years of Service: %d\n", get_service_years(employees[i].year_of_joining));
}


salary_stats(employees, n);
service_stats(employees, n);

return 0;
}

	

