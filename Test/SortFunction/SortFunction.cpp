#include <iostream>

#include "IntroSort.h"

int main()
{
	 int arr[17] = {7, 12, 65, 23, 1, 4, 8, 13, 0, 10, 77, 67, 128, 6, 99, 4535, 400};
	 int size = sizeof(arr) / sizeof(arr[0]);

	  for (auto &&i : arr)
	  {
	      std::cout << i << " ";
	  }
	  std::cout << std::endl;

	  IntroSort::Sort(arr, arr + size, [](int a, int b) { return a < b; });

	  for (auto&& i : arr)
	  {
		  std::cout << i << " ";
	  }
	  std::cout << std::endl;
}

/*
???????? ???????:

?????? ???????? ?????????? ????? ???? ????? ? ??????. ?.?. ?????? ???????? ?? ????????? ??????? ???????.
??? ????? ??????? ???? ???????? ??????????? ?????????? ?? ?????????? ?????????? ???  ????????? IntroSort.
Intro sort ???????? ???: ?????????? ?????????? ? ?????????? ????????? Quicsort, ???? ??????? ???????? ??????? ??
???????? 2 * log(size of array), ????? ?????????? ????????????? ?? Insertionsort ???? ?????????? ???????? ? ??????? ?????? 16.
????????? ?????? ??????? ?????????????? ??????????? ???????? ?????? ?????? ????????? Quicksort ??????? ???????? O(n^2) ?? O(nlog(n)).
??? ?? ???????? ???????? Quicksort ???????? ??????????? ???????????? ?? ????????? ?????? ????????.

????????? ??????????? ?????????? ?????????? ?????????? ????????? ??????????? ???????? ?????? ???? ? ??????????? ??????? ??????? ??????????? ??????????.

*/