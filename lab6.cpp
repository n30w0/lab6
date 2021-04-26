#include "pch.h"
#pragma once
#include "QueueBase.h"
#include "123.cpp"
template<typename T>
class QueueBasedOnBidirectionalCircularList : public QueueBase<T>
{
	BidirectionalCircularList<T> *Queue;
	int count;
public:
	QueueBasedOnBidirectionalCircularList(int count)
		: Queue(), count(count) { }
	QueueBasedOnBidirectionalCircularList(const QueueBasedOnBidirectionalCircularList &other) 
	{
		Queue = other.Queue;
		count = other.count;
	}
	QueueBasedOnBidirectionalCircularList(QueueBasedOnBidirectionalCircularList &&other)
	{
		Queue = other.Queue;
		count = other.count;
	}
	QueueBasedOnBidirectionalCircularList<T> &operator=(const QueueBasedOnBidirectionalCircularList &other)
	{
		if (this == &other)
		{
			return *this;
		}
		count = other.count;
		Queue = other.Queue;
	}
	QueueBasedOnBidirectionalCircularList<T> &operator=(QueueBasedOnBidirectionalCircularList &&other)
	{
		if (this == &other)
		{
			return *this;
		}
		count = other.count;
		Queue = other.Queue;
	}

	~QueueBasedOnBidirectionalCircularList();

	void Push(T element) override 
	{
		if (Queue->GetSize() < count)
		{
			Queue->Push(element, Queue->GetSize());
		}
	}

	T Pop() override 
	{
		return Queue->Remove(1);
	}

	T Peek() override  
	{
		return Queue->Peek(1);
	}

	bool CheckNoEmptyQueue() override  
	{
		return Queue->CheckNoEmptyList();
	}

	friend ostream & operator << <T>(ostream & stream, const QueueBasedOnBidirectionalCircularList<T> &a); 
};
template<typename T>
QueueBasedOnBidirectionalCircularList<T>::~QueueBasedOnBidirectionalCircularList()
{
	delete Queue;
}
template<typename T>
ostream & operator << (ostream & stream, const QueueBasedOnBidirectionalCircularList<T> &a) 
{
	QueueBasedOnBidirectionalCircularList<T> b = a;
	stream << "=====\n";
	for (int i = 0; i < b.count; i++)
	{
		stream << "| " << b.Pop() << "\n";
	}
	stream << "=====\n";
	return stream;
}