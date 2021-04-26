#include "pch.h"
#pragma once
#include "QueueBase.h"
template<typename T>
class QueueBasedOnArray : public QueueBase<T>
{
	T *array;
	int count;
	int end = 0, start = 0, size = 0;
public:
	QueueBasedOnArray(int count); 
	QueueBasedOnArray(const QueueBasedOnArray &other);  
	QueueBasedOnArray(QueueBasedOnArray &&other); 
	QueueBasedOnArray &operator=(const QueueBasedOnArray &other); 
	QueueBasedOnArray &operator=(QueueBasedOnArray &&other);
	~QueueBasedOnArray(); 
	int GetSize();

	void Push(T element) override  
	{
		if (size < count)
		{
			array[end] = element;
			end = (end + 1) % count;
			size++;
		}
	};

	T Pop() override 
	{
		if (size > 0)
		{
			T element = array[start];
			start = (start + 1) % count;
			size--;
			return element;
		}
		return 0;
	};

	T Peek() override  
	{
		return array[start];
	};

	bool CheckNoEmptyQueue() override  
	{
		return (size > 0);
	}

	friend ostream & operator << <T>(ostream & stream, const QueueBasedOnArray<T> &a); 
};
template<typename T>
QueueBasedOnArray<T>::QueueBasedOnArray(int count)
	: count(count)
{
	array = new T[count];
}
template<typename T>
QueueBasedOnArray<T>::~QueueBasedOnArray()
{
	delete[] array;
}
template<typename T>
QueueBasedOnArray<T>::QueueBasedOnArray(const QueueBasedOnArray &other)
{
	array = new T[other.count];
	count = other.count;
	end = other.end;
	start = other.start;
	size = other.size;
	for (int i = 0; i < count; ++i)
	{
		array[i] = other.array[i];
	}
}
template<typename T>
QueueBasedOnArray<T> &QueueBasedOnArray<T>::operator=(const QueueBasedOnArray &other)
{
	if (this == &other)
	{
		return *this;
	}
	delete[] array;
	array = new T[other.count];
	count = other.count;
	for (int i = 0; i < count; ++i)
	{
		array[i] = other.array[i];
	}
}
template<typename T>
QueueBasedOnArray<T> &QueueBasedOnArray<T>::operator=(QueueBasedOnArray &&other)
{
	if (this == &other)
	{
		return *this;
	}
	delete[] array;
	array = other.array;
	count = other.count;
	other.array = nullptr;
}
template<typename T>
QueueBasedOnArray<T>::QueueBasedOnArray(QueueBasedOnArray &&other)
{
	array = other.array;
	count = other.count;
	other.array = nullptr;
}
template<typename T>
int QueueBasedOnArray<T>::GetSize()
{
	return this->size;
};
template<typename T>
ostream & operator << (ostream & stream, const QueueBasedOnArray<T> &a)
{
	QueueBasedOnArray<T> b = a;
	stream << "=====\n";
	for (int i = 0; i < b.count; i++)
	{
		stream << "| " << b.Pop() << "\n";
	}
	stream << "=====\n";
	return stream;
}