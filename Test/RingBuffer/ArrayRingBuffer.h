#pragma once

template<typename T>
class ArrayRingBuffer
{
public:
	ArrayRingBuffer(size_t size);
	~ArrayRingBuffer();

	bool EnQueue(T value);
	T DeQueue();

	bool IsBufferEmpty();
	bool IsBufferFull();

	size_t BufferSize();
	size_t Count();

	void OutputInfo();


private:
	T* _values = nullptr;
	size_t _head  = 0;
	size_t _tail  = 0;
	size_t _count = 0;
	size_t _size  = 0;
};