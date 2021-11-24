#include <iostream>

#include "ArrayRingBuffer.h"

template<typename T>
ArrayRingBuffer<T>::ArrayRingBuffer(size_t size)
{
	_size = size;
	_values = (T*)malloc(sizeof(T) * _size);
	_head = 0;
	_tail = 0;
	_count = 0;
};

template<typename T>
ArrayRingBuffer<T>::~ArrayRingBuffer()
{
	free(_values);
}

template<typename T>
bool ArrayRingBuffer<T>::EnQueue(T value)
{
	if (IsBufferFull())
	{
		return false;
	}

	_values[_tail] = value;
	_count++;
	_tail = (_tail + 1) % _size;

	return true;
}

template<typename T>
T ArrayRingBuffer<T>::DeQueue()
{
	if (IsBufferEmpty())
	{
		return T();
	}

	T result = std::move(_values[_head]);
	_head = (_head + 1) % _size;
	_count--;

	return result;
}

template<typename T>
bool ArrayRingBuffer<T>::IsBufferEmpty()
{
	return _count == 0;
}

template<typename T>
bool ArrayRingBuffer<T>::IsBufferFull()
{
	return _count == _size;
}

template<typename T>
size_t ArrayRingBuffer<T>::BufferSize()
{
	return _size;
}

template<typename T>
size_t ArrayRingBuffer<T>::Count()
{
	return _count;
}

template<typename T>
void ArrayRingBuffer<T>::OutputInfo()
{
	std::cout << "Count: " << _count << std::endl;
	std::cout << "Size: " << _size << std::endl;
	std::cout << "Head: " << _head << std::endl;
	std::cout << "Tail: " << _tail << std::endl;

	std::cout << "Elements in buffer" << std::endl;
	for (size_t i = 0; i < _count; i++)
	{
		std::cout << _values[(_head + i) % _size] << std::endl;
	}
}
