#pragma once
#include <iostream>
#include <locale>
#include <ctime>

using namespace std;


class Sorts
{
	int N;
public:
	Sorts(int N);
	void print(int* numbers);
	int* selection_sort(int* numbers);
	int* insertion_sort(int* numbers);
	int* bubble_sort(int* numbers);
	int* merge_sort(int* numbers, int size);
	int* shell_sort(int* numbers, int* gaps, int l_gaps);
	int* quick_sort(int* numbers, int size);
	int* quick_sort_back(int* numbers, int size);
	int* heap_sort(int* numbers);

};