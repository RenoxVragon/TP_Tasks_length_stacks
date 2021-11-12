#pragma once
#pragma once
#include "stack.h"

template <class T>
class SetOfStacks
{
public:
	SetOfStacks();
	SetOfStacks(int _max_size);
	~SetOfStacks();
	bool is_empty() const;
	void push(T);
	T pop();
	void print_info() const;
	void clear();
private:
	Stack<Stack<T>> data;
	int max_size;
	int size;
};

template <class T>
SetOfStacks<T>::SetOfStacks()
{
	max_size = 3;
	size = 0;
}

template <class T>
SetOfStacks<T>::SetOfStacks(int _max_size)
{
	max_size = _max_size;
	size = 0;
}

template <class T>
SetOfStacks<T>::~SetOfStacks()
{
	clear();
}

template <class T>
bool SetOfStacks<T>::is_empty() const
{
	Stack<T>* back = this->data.back();
	return back->is_empty();
}

template <class T>
void SetOfStacks<T>::push(T data)
{
	if (this->data.is_empty())
		this->data.push_back(Stack<T>());
	Stack<T>* back = this->data.back();
	if (back->get_size() < max_size)
		back->push_back(data);
	else {
		this->data.push_back(Stack<T>());
		back = this->data.back();
		back->push_back(data);
	}
	size++;
}

template <class T>
T SetOfStacks<T>::pop()
{
	std::string err = "Стек из стеков пустой, нечего извлекать.";
	if (data.is_empty())
		throw err;
	Stack<T>* back = this->data.back();
	T tmp = back->pop_element();
	if (back->is_empty())
		data.pop_element();
	size--;
	return tmp;
}

template <class T>
void SetOfStacks<T>::print_info() const
{
	cout << "Информация о сете стеков: " << endl;
	cout << "Максимальное количество элементов в стеке = " << max_size << endl;
	cout << "Количество элементов = " << size << endl;
	cout << "Количество стеков = " << data.get_size() << endl;
}

template <class T>
void SetOfStacks<T>::clear()
{
	while (!data.is_empty()) {
		Stack<T> back = data.pop_element();
		back.clear_stack();
	}
}