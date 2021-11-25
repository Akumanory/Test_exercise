#include "LinkedListRingBuffer.h"

template<typename T>
LinkedListRingBuffer<T>::LinkedListRingBuffer()
{
	_count = 0;
}

template<typename T>
LinkedListRingBuffer<T>::~LinkedListRingBuffer()
{
	while (_head != _tail)
	{
		Node* temp = _head;
		_head = _head->next;
		free(temp);
	}
	free(_head);
}

template<typename T>
bool LinkedListRingBuffer<T>::EnQueue(T value)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->value = value;
	
	if (IsEmpty())
	{
		node->next = node;
		_head = node;
		_tail = node;
		_count++;
	}
	else
	{
		_tail->next = node;
		_tail = node;
		node->next = _head;
		_count++;
	}

	return true;
}

template<typename T>
T LinkedListRingBuffer<T>::DeQueue()
{
	if (IsEmpty())
	{
		return T();
	}

	T value = _head->value;
	Node* temp = _head;
	_head = _head->next;
	free(temp);
	_count--;

	return value;
}

template<typename T>
bool LinkedListRingBuffer<T>::IsEmpty()
{
	return _count == 0;
}

template<typename T>
void LinkedListRingBuffer<T>::OutputInfo()
{
	std::cout << "Count: " << _count << std::endl;

	std::cout << "Elements in buffer" << std::endl;

	Node* temp = _head;

	for (size_t i = 0; i < _count; i++)
	{
		std::cout << temp->value << std::endl;
		temp = temp->next;
	}
}
