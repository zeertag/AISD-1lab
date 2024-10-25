#include "sort_funcs.h"

Sorts::Sorts(int N)
{
    this->N = N;
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

int* Sorts::selection_sort(int* numbers)
{
    for (int i = 0; i < N - 1; i++)
    {
        int min_num = numbers[i];
        int pos = i;
        for (int j = i + 1; j < N; j++)
        {
            if (numbers[j] < min_num)
            {
                pos = j;
                min_num = numbers[j];
            }
        }
        if (min_num != numbers[i])
            swap(numbers[i], numbers[pos]);
    }
    return numbers;
}

int* Sorts::insertion_sort(int* numbers)
{
    for (int i = 0; i < N; i++)
    {
        int num = numbers[i];
        int j = i;
        while (j >= 1 && numbers[j - 1] > num)
        {
            numbers[j] = numbers[j - 1];
            j--;
        }
        numbers[j] = num;
    }
    return numbers;
}

int* Sorts::bubble_sort(int* numbers)
{
    for (int i = 0; i < N; i++)
    {
        bool flag = 0;
        for (int j = 0; j < N - 1 - i; j++)
        {
            if (numbers[j] > numbers[j + 1])
            {
                flag = 1;
                swap(numbers[j], numbers[j + 1]);
            }
        }
        if (!flag)
            return numbers;
    }
    return numbers;
}

int* merge(int* A, int lenA, int* B, int lenB)
{
    int* merged = new int[lenA + lenB];
    int i = 0, j = 0, k = 0;

    while (i < lenA && j < lenB)
    {
        if (A[i] <= B[j])
            merged[k++] = A[i++];
        else
            merged[k++] = B[j++];
    }

    while (i < lenA)
        merged[k++] = A[i++];

    while (j < lenB)
        merged[k++] = B[j++];

    return merged;
}

int* Sorts::merge_sort(int* numbers, int size)
{
    if (size <= 1) {
        int* result = new int[size];
        for (int i = 0; i < size; i++) {
            result[i] = numbers[i];
        }
        return result;
    }

    int mid = size / 2;

    int* A = merge_sort(numbers, mid);
    int* B = merge_sort(numbers + mid, size - mid);

    int* merged = merge(A, mid, B, size - mid);

    delete[] A;
    delete[] B;

    return merged;
}

int* Sorts::shell_sort(int* numbers, int* gaps, int l_gaps)
{
    int gap;
    for (int i = 0; i < l_gaps; i++)
    {
        gap = gaps[i];
        for (int j = gap; j < N; j += gap)
        {
            int a = numbers[j];
            int k = j;
            while (k >= gap && numbers[k - gap] > a)
            {
                numbers[k] = numbers[k - gap];
                k -= gap;
            }
            numbers[k] = a;
        }
    }
    return numbers;
}

int* Sorts::quick_sort(int* numbers, int size)
{
    if (size <= 1)
        return numbers;

    int pivot = numbers[rand() % size];
    int l_len = 0, m_len = 0, r_len = 0;

    int* l_arr = new int[size];
    int* m_arr = new int[size];
    int* r_arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        if (numbers[i] < pivot)
            l_arr[l_len++] = numbers[i];
        else if (numbers[i] > pivot)
            r_arr[r_len++] = numbers[i];
        else
            m_arr[m_len++] = numbers[i];
    }

    int* sorted_left = quick_sort(l_arr, l_len);
    int* sorted_right = quick_sort(r_arr, r_len);

    int* result = new int[size];
    copy(sorted_left, sorted_left + l_len, result);
    copy(m_arr, m_arr + m_len, result + l_len);
    copy(sorted_right, sorted_right + r_len, result + l_len + m_len);

    delete[] l_arr;
    delete[] m_arr;
    delete[] r_arr;

    return result;
 }

int* Sorts::quick_sort_back(int* numbers, int size)
{
    if (size <= 1)
        return numbers;

    int pivot = numbers[0];
    int l_len = 0, m_len = 0, r_len = 0;

    int* l_arr = new int[size];
    int* m_arr = new int[size];
    int* r_arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        if (numbers[i] > pivot)
            l_arr[l_len++] = numbers[i];
        else if (numbers[i] < pivot)
            r_arr[r_len++] = numbers[i];
        else
            m_arr[m_len++] = numbers[i];
    }

    int* sorted_left = quick_sort_back(l_arr, l_len);
    int* sorted_right = quick_sort_back(r_arr, r_len);

    int* result = new int[size];
    copy(sorted_left, sorted_left + l_len, result);
    copy(m_arr, m_arr + m_len, result + l_len);
    copy(sorted_right, sorted_right + r_len, result + l_len + m_len);

    delete[] l_arr;
    delete[] m_arr;
    delete[] r_arr;

    return result;
}


int* heapify(int* arr, int len_arr, int i = 0)
{
    int biggest_num = i;
    int num_l = 2 * i + 1;
    int num_r = 2 * i + 2;
    if (num_l < len_arr && arr[biggest_num] < arr[num_l])
        biggest_num = num_l;
    if (num_r < len_arr && arr[biggest_num] < arr[num_r])
        biggest_num = num_r;
    if (biggest_num != i)
    {
        swap(arr[i], arr[biggest_num]);
        heapify(arr, len_arr, biggest_num);
    }
    return arr;
}

int* Sorts::heap_sort(int* numbers)
{
    if (N <= 1)
        return numbers;
    for (int i = N; i > -1; i--)
        numbers = heapify(numbers, N, i);
    for (int i = N - 1; i > 0; i--)
    {
        swap(numbers[i], numbers[0]);
        heapify(numbers, i, 0);
    }
    return numbers;
}
