#pragma once

#include <iostream>

template<typename T>
class LinkedListRingBuffer
{
public:
	struct Node
	{
		Node* next;
		T value;
	};

	LinkedListRingBuffer();
	~LinkedListRingBuffer();

	bool EnQueue(T value);

	T DeQueue();

	bool IsEmpty();

	void OutputInfo();

private:
	size_t _count = 0;
	Node* _head = nullptr;
	Node* _tail = nullptr;
};
