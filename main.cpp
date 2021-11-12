#include <iostream>
#include <windows.h>
#include <string>
#include "inputs.h"
#include "SetOfStacks.h"
using namespace std;

void task1()
{
	cout << "������� 1." << endl;
	cout << "��������������� ������� �������� �����, ������������, ���������� � �����������������." << endl;
	cout << "��� ������� �� ��� ����������� ����������� ��������� ������� �� 1, ������ ���� 0 ����� ������� �� 1." << endl;
	int x2, x8, x10, x16;
	x2 = process_input_2(INT32_MIN, INT32_MAX);
	count_ones_length(x2);
	x8 = process_input_8(INT32_MIN, INT32_MAX);
	count_ones_length(x8);
	x10 = process_input_10(INT32_MIN, INT32_MAX);
	count_ones_length(x10);
	x16 = process_input_16(INT32_MIN, INT32_MAX);
	count_ones_length(x16);
}

int process_input(int min_range, int max_range)
{
	string str;
	while (1)
	{
		cin >> str;
		if ((str.find_first_not_of("0123456789", 0) == string::npos))
		{
			int input = stoi(str);
			if (input < min_range || input > max_range)
				cout << "������������ ����. ���������� ��� ���: " << endl;
			else
				return input;
		}
		else
			cout << "������������ ����. ���������� ��� ���: " << endl;
	}
}

void menu_print() 
{
	cout << "���� ���������� ��� 2 �������. �������� ����� ����: " << endl;
	cout << "1. �������� �������" << endl;
	cout << "2. ������� �������" << endl;
	cout << "3. �������� ����������" << endl;
	cout << "0. �����" << endl;
}

template <typename T>
void add(SetOfStacks<T>& set) 
{
	cout << "������� ����� ��� ����������: ";
	set.push(process_input((T)INT32_MIN, (T)INT32_MAX));
}

template <typename T>
void pop(SetOfStacks<T>& set) 
{
	try {
		cout << "��������� �����: " << set.pop() << endl;
	}
	catch (string err) {
		cout << err << endl;
	}

}

template <typename T>
void task2(T indicator) 
{
	cout << "������� 2." << endl;
	cout << "������� ����������� � ���������� ������ �� ����� ������������� ����������. ��� ���������� ������ ��������� �����." << endl;
	cout << "������� ������������ �������� � ����� �����: ";
	int n = process_input(1, INT32_MAX);
	SetOfStacks<T> set(n);
	int process = 0;
	while (!process) {
		menu_print();
		int choice = process_input(0, 3);
		switch (choice)
		{
		case 1:
			add(set);
			break;
		case 2:
			pop(set);
			break;
		case 3:
			set.print_info();
			break;
		case 0:
			process = 1;
			break;
		}
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "ru");
	task1();
	task2((int)0);
}