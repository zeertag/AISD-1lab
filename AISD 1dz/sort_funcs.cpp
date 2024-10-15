#include "sort_funcs.h"

void Sorts::set_params(int size, int top, int down)
{
	N = size;
	up_limit = top;
	down_limit = down;
}

void Sorts::generate()
{
	int* numbers = new int[N];
	for (int i = 0; i < N; i++)
		numbers[i] = rand() % (up_limit - down_limit + 1) + down_limit;
    print(numbers);
}

void Sorts::print(int* numbers)
{
    cout << "[";
    for (int i = 0; i < N; i++)
    {
        cout << numbers[i];
        if (i != N - 1)
            cout << ", ";
        else
            cout << "]\n";
    }
}
