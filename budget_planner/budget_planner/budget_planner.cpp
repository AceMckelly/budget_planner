// budget_planner.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

double income;
char item[20][10]; 
double expense[10];
double electrical;
double phone;
double transport;
char check_yes;
double netcash;
double savings;
double days;


int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Please enter your total income for the month: ";
	cin >> income;
	cout << "Please enter Electrical expenese: ";
	cin >> electrical;
	cout << "Please enter Phone expenese: ";
	cin >> phone;
	cout << "Please enter Transportation expenese: ";
	cin >> transport;
	int i = 0;
	do{
		cout << "Do you have any other expneses? y/n";
		cin >> check_yes;
		if (check_yes == 'y'){
			cout << "Enter the expense name: ";
			cin >> item[i];
			cout << "Enter the amount: ";
			cin >> expense[i];
		}
		i++;
	} while (check_yes == 'y');
	netcash = income - (electrical + phone + transport);
	for (int x = 0; x < i; x++){
		netcash = netcash - expense[x];
	}
	cout << "You have $" << netcash << " left\n";
	if (netcash>0){
		cout << "How much would you like to save: ";
		cin >> savings;
		cout << "You have $" << netcash - savings << " available\n";
		cout << "How many days until your next income: ";
		cin >> days;
		cout << "You can probably spand $" << (netcash - savings) / days << " a day\n";
		if (((netcash - savings) / days) < 10){
			cout << "Do you think you can survive? Should I call home?\n";
		}
	}
	system("pause");
	return 0;
}


