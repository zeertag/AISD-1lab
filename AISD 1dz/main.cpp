#include <iostream>
#include <locale>
#include <ctime>
#include "sort_funcs.h"

using namespace std;

int N = 10;
int* numbers = new int[N] {};

void generate()
{
    for (int i = 0; i < N; i++)
    {
        numbers[i] = rand() % 200 - 100;
    }
}

void swap(int i, int j)
{
    int tmp = numbers[i];
    numbers[i] = numbers[j];
    numbers[j] = tmp;
}

void insertion_sort()
{
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (numbers[i] > numbers[j])
                swap(i, j);
        }
    }
}

int check()
{
    for (int i = 0; i < N - 1; i++)
    {
        if (numbers[i] > numbers[i + 1])
            return 0;
    }
    return 1;
}

void rand_sort()
{
    if (check() == 0)
    {
        int x = 0;
        while (1)
        {
            for (int i = 0; i < N; i++)
            {
                int j = rand() % N;
                swap(i, j);
            }
            if (check() == 1)
                break;
        }
    }
}

void print()
{
    cout << "[";
    for (int i = 0; i < N; i++)
    {
        cout << numbers[i];
        if (i != N - 1)
            cout << ", ";
        else
            cout << "]";
    }
}

int main()
{
    Sorts s;
    s.set_params(10, 2000, -1000);
    for (int i = 0; i < 10; i++)
        s.generate();
    //setlocale(LC_ALL, "RU");
    //srand(time(NULL));

    ////сортировка вставкой
    //generate();
    //print();
    //insertion_sort();
    //cout << endl;
    //print();

    //cout << endl << endl;

    ////рандомом
    //generate();
    //print();
    //rand_sort();
    //cout << endl;
    //print();
}