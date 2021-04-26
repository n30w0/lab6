#include "pch.h"
#pragma once
#include "Node.h"
template<typename T>
class BidirectionalCircularList
{
	Node<T> *head;
	int size = 0;
public:
	BidirectionalCircularList(); 
	BidirectionalCircularList(const BidirectionalCircularList &other);  
	BidirectionalCircularList(BidirectionalCircularList &&other); 
	BidirectionalCircularList &operator=(const BidirectionalCircularList &other); 
	BidirectionalCircularList &operator=(BidirectionalCircularList &&other); 
	~BidirectionalCircularList(); 
	int GetSize();
	Node<T> *Find(int number);
	void Push(T element, int number); 
	T Remove(int number);  
	T Peek(int number);  
	bool CheckNoEmptyList();  
	friend ostream & operator << <T>(ostream & stream, const BidirectionalCircularList<T> &a); 
};
template<typename T>
BidirectionalCircularList<T>::BidirectionalCircularList()
	: head(NULL)
{
	head = new Node<T>;
	Node<T> *node = new Node<T>;
	head->next = node;
	head->previous = node;
	node->next = head;
	node->previous = head;
}
template<typename T>
BidirectionalCircularList<T>::~BidirectionalCircularList() 
{
	Node<T> *node = head;
	while (node->next != head)
	{
		node = node->next;
		delete node->previous;
	}
	delete head;
}
template<typename T>
BidirectionalCircularList<T>::BidirectionalCircularList(const BidirectionalCircularList &other) 
{
	Node<T> oldOldNode = other.head;
	head = other.head;
	Node<T> newOldNode = head;
	size = other.size;
	while (oldNode->next != other.head)
	{
		Node<T> *newNewNode;
		newOldNode->next = newNewNode;
		newNewNode->previous = newOldist;
		newOldNode = newOldNode->next;
		newOldNode->data = oldOldNode->data;
	}
	newOldNode->next = head;
	head->previous = newOldNode;
}
template<typename T>
BidirectionalCircularList<T>::BidirectionalCircularList(BidirectionalCircularList &&other) 
{
	head = other.head;
	size = other.size;
	other.head = nullptr;
}
template<typename T>
BidirectionalCircularList<T> &BidirectionalCircularList<T>::operator=(const BidirectionalCircularList &other) 
{
	if (this == &other)
	{
		return *this;
	}
	delete head;
	head = new Node<T>;
	Node<T> *node = head;
	while (node->next != head)
	{
		Node<T> *newNode = new Node<T>;
		Node<T> *oldNode = node->next;
		node->next = newNode;
		newNode->previous = node;
		newNode->data = oldNode->data;
	}
}
template<typename T>
BidirectionalCircularList<T> &BidirectionalCircularList<T>::operator=(BidirectionalCircularList &&other) 
{
	if (this == &other)
	{
		return *this;
	}
	delete head;
	head = other.head;
	other.head = nullptr;
}
template<typename T>
int BidirectionalCircularList<T>::GetSize()
{
	return this->size;
}
template<typename T>
Node<T> *BidirectionalCircularList<T>::Find(int number)
{
	Node<T> *node = head->next;
	for (int i = 0; i < number; i++)
	{
		node = node->next;
	}
	return node;
}
template<typename T>
void BidirectionalCircularList<T>::Push(T element, int number)  
{
	Node<T> *previousNode = this->Find(number);
	Node<T> *nextNode = previousNode->next;
	Node<T> *newNode = new Node<T>;
	newNode->data = element;
	previousNode->next = newNode;
	newNode->previous = previousNode;
	newNode->next = nextNode;
	nextNode->previous = newNode;
	size++;
}
template<typename T>
T BidirectionalCircularList<T>::Remove(int number) 
{
	if (size > 0)
	{
		Node<T> *oldNode = this->Find(number);
		Node<T> *nextNode = oldNode->next;
		Node<T> *previousNode = oldNode->previous;
		T element = oldNode->data;
		nextNode->previous = previousNode;
		previousNode->next = nextNode;
		delete oldNode;
		size--;
		return element;
	}
	return 0;
}
template<typename T>
T BidirectionalCircularList<T>::Peek(int number)  
{
	Node<T> *node = this->Find(number);
	return node->data;
}
template<typename T>
bool BidirectionalCircularList<T>::CheckNoEmptyList()  
{
	return (size > 0);
}
template<typename T>
ostream & operator << (ostream & stream, const BidirectionalCircularList<T> &a) 
{
	BidirectionalCircularList<T> b = a;
	stream << "=====\n";
	for (int i = 0; i < b.size; i++)
	{
		stream << "| " << b.Remove() << "\n";
	}
	stream << "=====\n";
	return stream;
}