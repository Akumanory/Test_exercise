#pragma once

class IntroSort
{
public:
	template<typename T, typename Compare>
	static void Sort(T* first, T* last, Compare comp);

private:
	template<typename T>
	static void Swap(T* x, T* y);

	template<typename T, typename Compare>
	static T* MiddleOfThree(T* a, T* b, T* c, Compare comp);

	template<typename T, typename Compare>
	static T* Partition(T* i, T* j, T* median, Compare comp);

	template<typename T, typename Compare>
	static void InsertionSort(T* first, T* last, Compare comp);

	template<typename T, typename Compare>
	static void QuicksortWithImprovements(T* first, T* last, Compare comp, size_t depth_limit);

	template<typename T, typename Compare>
	static void Heapsort(T* first, T* last, Compare comp);

	template<typename T, typename Compare>
	static void Heapify(T* first, size_t size, size_t root, Compare comp);
};