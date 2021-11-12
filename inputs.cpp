#include "inputs.h"

int process_input_10(int min_range, int max_range)
{
	cout << "Ввод десятичного числа." << endl;
	string str;
	while (1)
	{
		cin >> str;
		if ((str.find_first_not_of("0123456789", 0) == string::npos) || (str.length() > 10))
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

int process_input_2(int min_range, int max_range)
{
	cout << "Ввод двоичного числа." << endl;
	string str;
	while (1)
	{
		cin >> str;
		if (str.find_first_not_of("01", 0) == string::npos)
		{
			int x210 = 0;
			int temp;
			string temp_str;
			for (int i = 0; i < str.length(); i++)
			{
				temp_str = str[i];
				temp = stoi(temp_str);
				x210 += temp * pow(2, str.length() - i - 1);
			}
			if (x210 < min_range || x210 > max_range)
				cout << "Некорректный ввод. Попробуйте еще раз: " << endl;
			else
				return x210;
		}
		else
			cout << "Некорректный ввод. Попробуйте еще раз: " << endl;
	}
}

int process_input_8(int min_range, int max_range)
{
	cout << "Ввод восьмеричного числа." << endl;
	string str;
	while (1)
	{
		cin >> str;
		if (str.find_first_not_of("01234567", 0) == string::npos)
		{
			int x810 = 0;
			int temp;
			string temp_str;
			for (int i = 0; i < str.length(); i++)
			{
				temp_str = str[i];
				temp = stoi(temp_str);
				x810 += temp * pow(8, str.length() - i - 1);
			}
			if (x810 < min_range || x810 > max_range)
				cout << "Некорректный ввод. Попробуйте еще раз: " << endl;
			else
				return x810;
		}
		else
			cout << "Некорректный ввод. Попробуйте еще раз: " << endl;
	}
}

int process_input_16(int min_range, int max_range)
{
	cout << "Ввод шестнадцатиричного числа." << endl;
	string str;
	while (1)
	{
		cin >> str;
		if (str.find_first_not_of("0123456789abcdefABCDEF", 0) == string::npos)
		{
			int x1610 = 0;
			int temp = 0;
			string temp_str = "";
			for (int i = 0; i < str.length(); i++)
			{
				if ((str[i] < 48) || (str[i] > 57))
				{
					if ((str[i] == 'a') || (str[i] == 'A'))
						x1610 += 10 * pow(16, str.length() - i - 1);
					if ((str[i] == 'b') || (str[i] == 'B'))
						x1610 += 11 * pow(16, str.length() - i - 1);
					if ((str[i] == 'c') || (str[i] == 'C'))
						x1610 += 12 * pow(16, str.length() - i - 1);
					if ((str[i] == 'd') || (str[i] == 'D'))
						x1610 += 13 * pow(16, str.length() - i - 1);
					if ((str[i] == 'e') || (str[i] == 'E'))
						x1610 += 14 * pow(16, str.length() - i - 1);
					if ((str[i] == 'f') || (str[i] == 'F'))
						x1610 += 15 * pow(16, str.length() - i - 1);
				}
				else
				{
					temp_str = str[i];
					temp = stoi(temp_str);
					x1610 += temp * pow(16, str.length() - i - 1);
				}
			}
			if (x1610 < min_range || x1610 > max_range)
				cout << "Некорректный ввод. Попробуйте еще раз: " << endl;
			else
				return x1610;
		}
		else
			cout << "Некорректный ввод. Попробуйте еще раз: " << endl;
	}
}

void count_ones_length(int number)
{
	const int max_bits = 32;
	int max_count = 0, current_ones = 0, last_ones = 0;
	for (int i = 0; i < max_bits; i++) {
		if ((number & 1) == 1)
			current_ones++;
		if ((number & 1) == 0 || i == max_bits - 1) {
			max_count = max(max_count, min(max_bits, last_ones + current_ones + 1));
			last_ones = current_ones;
			current_ones = 0;
		}
		number >>= 1;
	}
	std::cout << "Количество подряд идущих единиц = " << max_count << std::endl;
}