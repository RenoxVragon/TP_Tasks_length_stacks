#pragma once
#include <iostream>
#include "element.h"

template <class T>
class Stack
{
public:
	Stack();
	Stack(const Stack<T>&);
	~Stack();
	bool is_empty() const;
	void push_back(T);
	T pop_element();
	void clear_stack();
	T* back();
	int get_size() const;
	Stack<T>& operator=(const Stack<T>&);
private:
	Element<T>* tail;
	int size;
	void add_from(Element<T>*);
};

template <class T>
Stack<T>::Stack()
{
	size = 0;
	tail = NULL;
}

template <class T>
Stack<T>::Stack(const Stack<T>& stack)
{
	size = 0;
	tail = NULL;
	if (!stack.is_empty())
		add_from(stack.tail);
}

template <class T>
Stack<T>::~Stack()
{
	clear_stack();
}

template <class T>
bool Stack<T>::is_empty() const
{
	return size == 0;
}

template <class T>
void Stack<T>::push_back(T data)
{
	Element<T>* element = new Element<T>;
	element->data = data;
	element->prev = tail;
	tail = element;
	size++;
}

template <class T>
T Stack<T>::pop_element()
{
	string err = "Стек пустой, нечего извлекать.";
	if (is_empty())
		throw err;
	T data;
	data = tail->data;
	Element<T>* e = tail;
	tail = tail->prev;
	size--;
	delete e;
	return data;
}


template <class T>
void Stack<T>::clear_stack()
{
	while (!is_empty())
		pop_element();
}

template <class T>
T* Stack<T>::back()
{
	return &tail->data;
}

template <class T>
int Stack<T>::get_size() const
{ 
	return size; 
}

template <class T>
void Stack<T>::add_from(Element<T>* element)
{
	if (NULL != element->prev)
		add_from(element->prev);
	push_back(element->data);
}

template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& stack)
{
	if (this == &stack)
		return *this;
	clear_stack();
	if (!stack.is_empty())
		add_from(stack.tail);
}