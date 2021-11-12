#include <iostream>
#include <windows.h>
#include <string>
#include "inputs.h"
#include "SetOfStacks.h"
using namespace std;

void task1()
{
	cout << "Задание 1." << endl;
	cout << "Последовательно введите двоичное число, восьмеричное, десятичное и шестнадцатиричное." << endl;
	cout << "Для каждого из них посчитается максимально возможная цепочка из 1, причем один 0 будет поменян на 1." << endl;
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
				cout << "Некорректный ввод. Попробуйте еще раз: " << endl;
			else
				return input;
		}
		else
			cout << "Некорректный ввод. Попробуйте еще раз: " << endl;
	}
}

void menu_print() 
{
	cout << "Меню управления для 2 задания. Выберите пункт меню: " << endl;
	cout << "1. Добавить элемент" << endl;
	cout << "2. Удалить элемент" << endl;
	cout << "3. Получить информацию" << endl;
	cout << "0. Выход" << endl;
}

template <typename T>
void add(SetOfStacks<T>& set) 
{
	cout << "Введите число для добавления: ";
	set.push(process_input((T)INT32_MIN, (T)INT32_MAX));
}

template <typename T>
void pop(SetOfStacks<T>& set) 
{
	try {
		cout << "Извлечено число: " << set.pop() << endl;
	}
	catch (string err) {
		cout << err << endl;
	}

}

template <typename T>
void task2(T indicator) 
{
	cout << "Задание 2." << endl;
	cout << "Задание заключается в построении стопок из чисел ограниченного количества. При заполнении стопки создается новая." << endl;
	cout << "Введите максимальное значение в одном стеке: ";
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