#include <cmath>
#include <algorithm>
#include <iostream>

#include "IntroSort.h"

template<typename T>
void IntroSort::Swap(T* x, T* y)
{
	T temp = *x;
	*x = *y;
	*y = temp;
}

template<typename T, typename Compare>
void IntroSort::Sort(T* first, T* last, Compare comp)
{
	size_t depth_limit = 2 * std::log(last - first);
	//size_t depth_limit = 0;

	QuicksortWithImprovements(first, last, comp, depth_limit);
}

template<typename T, typename Compare>
T* IntroSort::MiddleOfThree(T* a, T* b, T* c, Compare comp)
{
	if (comp(*a, *b))
	{
		if (comp(*b, *c))
			return b;
		else if (comp(*a, *c))
			return c;
		else
			return a;
	}
	else
	{
		if (comp(*a, *c))
			return a;
		else if (comp(*b, *c))
			return c;
		else
			return b;
	}
}

template<typename T, typename Compare>
T* IntroSort::Partition(T* i, T* j, T* median, Compare comp)
{
	i--;
	j++;

	while (1)
	{
		do
			i++;
		while (comp(*i, *median));

		do
			j--;
		while (comp(*median, *j));

		if (i >= j)
			return j;

		Swap(i, j);
	}
}

template<typename T, typename Compare>
void IntroSort::InsertionSort(T* first, T* last, Compare comp)
{
	size_t size = last - first;

	for (size_t i = 1; i < size; i++)
	{
		T key = *(first + i);
		T* j = (first + (i - 1));

		while (comp(key, *j) && j - first >= 0)
		{
			*(j + 1) = *j;
			--j;
		}
		*(j + 1) = key;
	}
}

template<typename T, typename Compare>
void IntroSort::QuicksortWithImprovements(T* first, T* last, Compare comp, size_t depth_limit)
{
	while (first < last - 1)
	{
		int size = last - first;

		if (size < 16)
		{
			InsertionSort(first, last, comp);
			return;
		}

		if (depth_limit == 0)
		{
			//std::make_heap(first, last + 1, comp);
			//std::sort_heap(first, last + 1, comp);
			Heapsort(first, last, comp);
			return;
		}

		T* pivot = MiddleOfThree(first, first + size / 2, last - 1, comp);

		T* partitionPoint = Partition(first, last - 1, pivot, comp);

		if (partitionPoint - first < last - 1 - partitionPoint)
		{
			QuicksortWithImprovements(first, partitionPoint + 1, comp, depth_limit);
			first = partitionPoint + 1;
		}
		else
		{
			QuicksortWithImprovements(partitionPoint + 1, last, comp, depth_limit);
			last = partitionPoint + 1;
		}
	}
}

template<typename T, typename Compare>
void IntroSort::Heapsort(T* first, T* last, Compare comp)
{
	size_t size = last - first;

	for (int i = size / 2 - 1; i >= 0; i--)
	{
		Heapify(first, size, i, comp);
	}
		
	for (int i = size - 1; i > 0; i--) 
	{
		Swap(first, first + i);

		Heapify(first, i, 0, comp);
	}
}

template<typename T, typename Compare>
void IntroSort::Heapify(T* first, size_t size, size_t root, Compare comp)
{
	
	size_t l_root = root; 
	size_t left = 2 * l_root + 1;
	size_t right = 2 * l_root + 2;

	/*if (comp(left, size) && !comp(first + left, first + l_root))
		l_root = left;

	if (comp(right, size) && !comp(first + right, first + l_root))
		l_root = right;*/

	if (left < size && !comp(*(first + left), *(first + l_root)))
		l_root = left;

	if (right < size && !comp(*(first + right), *(first + l_root)))
		l_root = right;

	
	if (l_root != root) {
		Swap(first + root, first + l_root);

		Heapify(first, size, l_root, comp);
	}
}