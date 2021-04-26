#pragma once
#include "iostream"
#include "conio.h"
using namespace std;
template<typename T>
struct Node
{
	T data;
	Node<T> *previous, *next;
};