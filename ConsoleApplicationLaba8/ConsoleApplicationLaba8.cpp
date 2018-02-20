// ConsoleApplicationLaba8.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string> 
#include <fstream>
#include <stdio.h>

using namespace std;

struct Account {
	string name;
	string surname;
	int groop;
	double mark;
};
void saveN(int	&number_of_student);
void readN(int	&number_of_student);
void showList(Account *arr_of_students, int	number_of_student);
int addList(Account *arr_of_students, int	&);
int deleteList(Account *arr_of_students, int &);
int createList(Account *arr_of_students, int	number_of_student);
int individualExemple(Account *arr_of_students, int	number_of_student, int	&number_of_studenti);
void saveSpis(Account *arr_of_students, int	number_of_student);
void readSpis(Account *arr_of_students, int	number_of_student);
void saveNM(int	&number_of_studenti);

int  main()
{
	Account arr_of_students[100];
	int number_of_student = 0;
	int number_of_studenti = 0;
	readN(number_of_student);
	readSpis(arr_of_students, number_of_student);
	int choise;

	while (true) {

		system("cls");
		cout << "Menu work with the list of students(when you don't 0 - you don't save created) " << endl;
		cout << "1 - Show all accounts " << endl;
		cout << "2 - Add accounts" << endl;
		cout << "3 - Delete accounts" << endl;
		cout << "4 - Create accounts " << endl;
		cout << "5 - Individual exemple " << endl;
		cout << "0 - Exit (Save)" << endl;
		cout << "Do your choise :";

		cin >> choise;

		switch (choise)
		{
		case 1:system("cls"); showList(arr_of_students, number_of_student); system("pause"); break;
		case 2:system("cls"); addList(arr_of_students, number_of_student);  break;
		case 3:system("cls"); deleteList(arr_of_students, number_of_student);  break;
		case 4:system("cls"); createList(arr_of_students, number_of_student);  break;
		case 5:system("cls"); individualExemple(arr_of_students, number_of_student, number_of_studenti);;  break;
		case 0: saveN(number_of_student); saveSpis(arr_of_students, number_of_student); return 1;
		}
	}
}


int  addList(Account *arr_of_students, int	&number_of_student)
{
	int choise;
	showList(arr_of_students, number_of_student);
	cout << endl;
	cout << "              Adding        " << endl;
	while (true) {

		cout << "Continue - push 1 ; Exit to main - push 2 " << endl;
		cout << "Do your choise :";
		cin >> choise;
		switch (choise)
		{
		case 1:break;
		case 2:return 1;
		}
		if (choise == 1) { break; }
	}
	system("cls");
	cout << "Adding account " << endl;
	cout << "Enter your surname :";
	cin >> arr_of_students[number_of_student].surname;
	cout << "Enter your name :";
	cin >> arr_of_students[number_of_student].name;
	cout << "Enter your groop :";
	cin >> arr_of_students[number_of_student].groop;
	cout << "Enter your mark :";
	cin >> arr_of_students[number_of_student].mark;

	number_of_student++;

	system("cls");
	cout << "The upload was successful!" << endl;
	system("pause");
	return 1;

}

void showList(Account *arr_of_students, int	number_of_student)
{
	int i = 0;
	string t1; t1 = "Surname";
	string t2; t2 = "Name";
	string t3; t3 = "Groop";
	string t4; t4 = "Mark";
	cout << "List of students :" << endl;
	if (number_of_student == 0) { cout << "!The list is empty!" << endl; }
	cout << "  " << t1 << " \t" << t2 << " \t" << t3 << " \t" << t4 << " \t" << endl;
	for (i; i < number_of_student; i++)
	{
		cout << i + 1 << ". " << arr_of_students[i].surname << " \t" << arr_of_students[i].name << " \t" << arr_of_students[i].groop << " \t" << arr_of_students[i].mark << " \t" << endl;
	}
}

int deleteList(Account *arr_of_students, int &number_of_student)
{
	int choise;


	int number;
	showList(arr_of_students, number_of_student);
	cout << endl;
	while (true) {

		cout << "Continue - push 1 ; Exit to main - push 2 " << endl;
		cout << "Do your choise :";
		cin >> choise;
		switch (choise)
		{
		case 1:break;
		case 2:return 1;
		}
		if (choise == 1) { break; }
	}
	cout << "Enter the number of student,whom you want to delete : ";
	cin >> number;
	if (number > number_of_student || number <= 0) { cout << "This does not exist!!!" << endl; system("pause"); }
	else {
		for (int i = 0; i < number_of_student; i++) {

			arr_of_students[number - 1 + i] = arr_of_students[number + i];
		}
		number_of_student--;

		system("cls");
		cout << "Removal was successful!" << endl;
		system("pause");

	}
	return 1;
}

int createList(Account *arr_of_students, int	number_of_student)
{
	int choise;
	showList(arr_of_students, number_of_student);
	cout << endl;
	while (true) {

		cout << "Continue - push 1 ; Exit to main - push 2 " << endl;
		cout << "Do your choise :";
		cin >> choise;
		switch (choise)
		{
		case 1:break;
		case 2:return 1;
		}
		if (choise == 1) { break; }
	}
	int number;
	cout << "Creating student data " << endl;
	cout << "Enter the number of student, whom you want to create : ";
	cin >> number;
	if (number > number_of_student || number <= 0) { cout << "This does not exist!!!" << endl; system("pause"); }
	else {
		cout << "Enter your name :";
		cin >> arr_of_students[number - 1].name;
		cout << "Enter your surname :";
		cin >> arr_of_students[number - 1].surname;
		cout << "Enter your groop :";
		cin >> arr_of_students[number - 1].groop;
		cout << "Enter your mark :";
		cin >> arr_of_students[number - 1].mark;

		system("cls");
		cout << "Create was successful!" << endl;
		system("pause");
	}return 1;
}

int individualExemple(Account *arr_of_students, int number_of_student, int &number_of_studenti) {

	char mark[20];
	int choise;
	while (true) {
		system("cls");
		cout << "Continue - push 1 ; Exit to main - push 2 " << endl;
		cout << "Do your choise :";
		cin >> choise;
		switch (choise)
		{
		case 1:break;
		case 2:return 1;
		}
		if (choise == 1) { break; }
	}
	double s_mark;
	int w_groop;

	cout << "Enter number of groop :";
	cin >> w_groop;
	cout << " !!!! You are write mark and you will take list of student, mark which more than your mark !!!!" << endl;
	cout << "Enter mark of student :";
	cin >> s_mark;

	ofstream file1;
	file1.open("Mark.txt");

	for (int i = 0; i < number_of_student; i++) {
		if (w_groop == arr_of_students[i].groop) {
			if (arr_of_students[i].mark >= s_mark) {
				cout << i + 1 << ". " << arr_of_students[i].surname << " \t" << arr_of_students[i].name << " \t" << arr_of_students[i].groop << " \t" << arr_of_students[i].mark << " \t" << endl;

				file1 << arr_of_students[i].surname << endl;
				file1 << arr_of_students[i].name << endl;
				sprintf_s(mark, "%d", arr_of_students[i].groop);
				file1 << mark << endl;
				sprintf_s(mark, "%lf", arr_of_students[i].mark);
				file1 << mark << endl;

				number_of_studenti++;

			}
		}
		else { cout << "This groop is not found!!!" << endl; }

	}file1.close();
	saveNM(number_of_studenti);
	system("pause");
	return 1;
}

void saveN(int	&number_of_student) {

	char str[10];
	ofstream file;
	file.open("Number.txt");
	sprintf_s(str, "%d", number_of_student);
	file << str;
	file.close();
}

void readN(int	&number_of_student) {

	char str6[10];
	ifstream file;
	file.open("Number.txt");
	file >> str6;
	number_of_student = atoi(str6);
	file.close();

}

void saveSpis(Account *arr_of_students, int	number_of_student) {

	char str5[10];
	char str1[100];
	ofstream file;
	file.open("Students.txt");

	for (int i = 0; i < number_of_student; i++)
	{
		file << arr_of_students[i].surname << endl;
		file << arr_of_students[i].name << endl;
		sprintf_s(str5, "%d", arr_of_students[i].groop);
		file << str5 << endl;
		sprintf_s(str1, "%lf", arr_of_students[i].mark);
		file << str1 << endl;


	}
	file.close();
}

void readSpis(Account *arr_of_students, int	number_of_student) {

	char str5[20];
	char str1[20];
	ifstream file;
	file.open("Students.txt");
	for (int i = 0; i < number_of_student; i++)
	{
		file >> arr_of_students[i].surname;
		file >> arr_of_students[i].name;

		file >> str5;
		arr_of_students[i].groop = atoi(str5);

		file >> str1;
		arr_of_students[i].mark = atof(str1);

	}
	file.close();

}

void saveNM(int	&number_of_studenti) {

	char str3[10];
	ofstream file2;
	file2.open("NumberMark.txt");
	sprintf_s(str3, "%d", number_of_studenti);
	file2 << str3;
	file2.close();
	number_of_studenti = 0;

}

