#include<stdio.h>
#include<string.h>
struct salary
{
	float basicPay;
	float bonus;
	float deduction;
};

struct employee
{
	int id;
	char name[20];
	struct salary s;
};

void calculateNetSalary(struct salary s)
{
	float netSalary = s.basicPay + s.bonus - s.deduction;
	printf("\nEmployee Net Salary = %.2f\n", netSalary);
}

void employeeSalaryDetails(struct employee e)
{
	printf("\nEmployee ID = %d\n", e.id);
	printf("Employee Name = %s\n", e.name);
	printf("Employee Basic Pay = %.2f\n", e.s.basicPay);
	printf("Employee Salary Bonus = %.2f\n", e.s.bonus);
	printf("Employee Salary Deduction = %.2f\n", e.s.deduction);
}

int main()
{
	int i;
	int choice;
	struct employee e;
	printf("Enter Employee ID: ");
	scanf("%d", &e.id);
	getchar();
	printf("Enter Employee Name: ");
	fgets(e.name, sizeof(e.name), stdin);
	e.name[strcspn(e.name, "\n")] = '\0';
	printf("Enter Employee Basic Pay: ");
	scanf("%f", &e.s.basicPay);
	printf("Enter Employee Salary Bonuses: ");
	scanf("%f", &e.s.bonus);
	printf("Enter Employee Salary Deductions: ");
	scanf("%f", &e.s.deduction);
	do
	{
		printf("\nEnter Your Choice:\n");
		printf("1. Calculate Employee Net Salary\n");
		printf("2. Display Employee Salary Details\n");
		printf("3. Exit\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				calculateNetSalary(e.s);
				break;
			case 2:
				employeeSalaryDetails(e);
				break;
			case 3:
				break;
			default:
				printf("Invalid Choice Input\n");
		}
	} while(choice != 3);
	return 0;
}
