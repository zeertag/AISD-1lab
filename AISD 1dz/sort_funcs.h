#pragma once
#include <iostream>
#include <locale>
#include <ctime>

using namespace std;


class Sorts
{
	int N;
	int up_limit, down_limit;
public:
	void set_params(int size, int top, int down);
	void generate();
	void print(int* numbers);

};