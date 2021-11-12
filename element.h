#pragma once
#include <string>
using namespace std;
template <typename T>
struct Element
{
	T data;
	Element* prev;
};