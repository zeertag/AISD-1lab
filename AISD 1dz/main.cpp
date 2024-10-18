#include <iostream>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <fstream>
#include "sort_funcs.h"

using namespace std;

ofstream rnd, d_9_1, d_bck, srtd;

int l_gaps = 0;
int up_limit = 10000000;
int down_limit = -1000000;

int* generate(int* numbers, int N, int top, int down)
{
    for (int i = 0; i < N; i++)
    {
        numbers[i] = rand() % (top - down + 1) + down;
    }
    return numbers;
}

int* reverse(int* arr, int len)
{
    int* a = new int[len] {};
    for (int i = 0; i < len; i++)
    {
        a[i] = arr[len - 1 - i];
    }
    return a;
}

int* shell_gaps(int* gaps, int N)
{
    int k = 1;
    int gap = N / pow(2, k);
    while (gap > 1)
    {
        gap = N / pow(2, k);
        gaps[k - 1] = gap;
        k++;
    }
    l_gaps = k - 1;
    return gaps;
}

int* hibbard_gaps(int* gaps, int N)
{
    int k = 1;
    int gap = pow(2, k) - 1;
    while (gap < N / 2)
    {
        gaps[k - 1] = gap;
        k++;
        gap = pow(2, k) - 1;
    }
    l_gaps = k - 1;
    gaps = reverse(gaps, l_gaps);
    return gaps;
}

int* pratt_gaps(int* gaps, int N)
{
    int i = 0, j = 0, k = 0;
    while (1)
    {
        int value = pow(2, i) * pow(3, j);
        if (value > N / 2)
        {
            if (j == 0)
                break;
            i++;
            j = 0;
        }
        else
        {
            gaps[k] = value;
            k++;
            j++;
        }
    }
    l_gaps = k;
    return gaps;
}

const int L_N = 19;
int lens[L_N]{ 10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000, 200000,
                       300000, 400000, 500000, 600000, 700000, 800000, 900000, 1000000 };


int main()
{
    srand(time(NULL));
    int l_tst = 0;

    for (int h = 1; h < 10; h++)
    {

        cout << h << endl;
        if (h < 4 || h == 5 || h == 8 || h == 9)
            l_tst = 10;

        else
            l_tst = L_N;

        switch (h)
        {
        case 1:
            rnd.open("Test_data\\insertion_sort\\random1.txt");
            d_9_1.open("Test_data\\insertion_sort\\90_10 1.txt");
            d_bck.open("Test_data\\insertion_sort\\back1.txt");
            srtd.open("Test_data\\insertion_sort\\sorted1.txt");
            break;
        case 2:
            rnd.open("Test_data\\selection_sort\\random2.txt");
            d_9_1.open("Test_data\\selection_sort\\90_10 2.txt");
            d_bck.open("Test_data\\selection_sort\\back2.txt");
            srtd.open("Test_data\\selection_sort\\sorted2.txt");
            break;
        case 3:
            rnd.open("Test_data\\bubble_sort\\random3.txt");
            d_9_1.open("Test_data\\bubble_sort\\90_10 3.txt");
            d_bck.open("Test_data\\bubble_sort\\back3.txt");
            srtd.open("Test_data\\bubble_sort\\sorted3.txt");
            break;
        case 4:
            rnd.open("Test_data\\merge_sort\\random4.txt");
            d_9_1.open("Test_data\\merge_sort\\90_10 4.txt");
            d_bck.open("Test_data\\merge_sort\\back4.txt");
            srtd.open("Test_data\\merge_sort\\sorted4.txt");
            break;
        case 5:
            rnd.open("Test_data\\shell_shell_sort\\random5.txt");
            d_9_1.open("Test_data\\shell_shell_sort\\90_10 5.txt");
            d_bck.open("Test_data\\shell_shell_sort\\back5.txt");
            srtd.open("Test_data\\shell_shell_sort\\sorted5.txt");
            break;
        case 6:
            rnd.open("Test_data\\quick_sort\\random6.txt");
            d_9_1.open("Test_data\\quick_sort\\90_10 6.txt");
            d_bck.open("Test_data\\quick_sort\\back6.txt");
            srtd.open("Test_data\\quick_sort\\sorted6.txt");
            break;
        case 7:
            rnd.open("Test_data\\heap_sort\\random7.txt");
            d_9_1.open("Test_data\\heap_sort\\90_10 7.txt");
            d_bck.open("Test_data\\heap_sort\\back7.txt");
            srtd.open("Test_data\\heap_sort\\sorted7.txt");
            break;
        case 8:
            rnd.open("Test_data\\shell_hibbard_sort\\random8.txt");
            d_9_1.open("Test_data\\shell_hibbard_sort\\90_10 8.txt");
            d_bck.open("Test_data\\shell_hibbard_sort\\back8.txt");
            srtd.open("Test_data\\shell_hibbard_sort\\sorted8.txt");
            break;
        case 9:
            rnd.open("Test_data\\shell_pratt_sort\\random9.txt");
            d_9_1.open("Test_data\\shell_pratt_sort\\90_10 9.txt");
            d_bck.open("Test_data\\shell_pratt_sort\\back9.txt");
            srtd.open("Test_data\\shell_pratt_sort\\sorted9.txt");
            break;
        }

        switch (h)
        {
        case 1:
            rnd << "Test for Selection Sort random\n";
            break;
        case 2:
            rnd << "Test for Insertion Sort random\n";
            break;
        case 3:
            rnd << "Test for Bubble Sort random\n";
            break;
        case 4:
            rnd << "Test for Merge Sort random\n";
            break;
        case 5:
            rnd << "Test for Shell Sort (shell gaps) random\n";
            break;
        case 6:
            rnd << "Test for Quick Sort random\n";
            break;
        case 7:
            rnd << "Test for Heap Sort random\n";
            break;
        case 8:
            rnd << "Test for Shell Sort (hibbard gaps) random\n";
            break;
        case 9:
            rnd << "Test for Shell Sort (pratt gaps) random\n";
            break;
        }

        for (int i = 0; i < l_tst; i++)
        {
            rnd << "\nArray length is " << lens[i] << endl;

            int N = lens[i];
            Sorts s(N);

            int* numbers = new int[N] {};
            int* gaps = new int[N] {};

            for (int k = 0; k < 10; k++)
            {
                numbers = generate(numbers, N, up_limit, down_limit);

                auto start = chrono::steady_clock::now();
                auto end = chrono::steady_clock::now();
                auto t = chrono::duration_cast<chrono::milliseconds>(end - start);


                switch (h)
                {
                case 1:
                    start = chrono::steady_clock::now();
                    numbers = s.selection_sort(numbers);
                    end = chrono::steady_clock::now();
                    break;
                case 2:
                    start = chrono::steady_clock::now();
                    numbers = s.insertion_sort(numbers);
                    end = chrono::steady_clock::now();
                    break;
                case 3:
                    start = chrono::steady_clock::now();
                    numbers = s.bubble_sort(numbers);
                    end = chrono::steady_clock::now();
                    break;
                case 4:
                    start = chrono::steady_clock::now();
                    numbers = s.merge_sort(numbers, N);
                    end = chrono::steady_clock::now();
                    break;
                case 5:
                    gaps = shell_gaps(gaps, N);
                    start = chrono::steady_clock::now();
                    numbers = s.shell_sort(numbers,gaps,l_gaps);
                    end = chrono::steady_clock::now();
                    break;
                case 6:
                    start = chrono::steady_clock::now();
                    numbers = s.quick_sort(numbers, N);
                    end = chrono::steady_clock::now();
                    break;
                case 7:
                    start = chrono::steady_clock::now();
                    numbers = s.heap_sort(numbers);
                    end = chrono::steady_clock::now();
                    break;
                case 8:
                    gaps = hibbard_gaps(gaps, N);
                    start = chrono::steady_clock::now();
                    numbers = s.shell_sort(numbers, gaps, l_gaps);
                    end = chrono::steady_clock::now();
                    break;
                case 9:
                    gaps = pratt_gaps(gaps, N);
                    Sorts g(l_gaps);
                    gaps = g.heap_sort(gaps);
                    start = chrono::steady_clock::now();
                    numbers = s.shell_sort(numbers, gaps, l_gaps);
                    end = chrono::steady_clock::now();
                    break;
                }

                t = chrono::duration_cast<chrono::milliseconds>(end - start);
                rnd << t.count() / 1000 << "." << t.count() % 1000 << endl;
            }

            delete[] numbers;
            delete[] gaps;
        }

        rnd.close();

        switch (h)
        {
        case 1:
            d_bck << "Test for Selection Sort back\n";
            break;
        case 2:
            d_bck << "Test for Insertion Sort back\n";
            break;
        case 3:
            d_bck << "Test for Bubble Sort back\n";
            break;
        case 4:
            d_bck << "Test for Merge Sort back\n";
            break;
        case 5:
            d_bck << "Test for Shell Sort (shell gaps) back\n";
            break;
        case 6:
            d_bck << "Test for Quick Sort back\n";
            break;
        case 7:
            d_bck << "Test for Heap Sort back\n";
            break;
        case 8:
            d_bck << "Test for Shell Sort (hibbard gaps) back\n";
            break;
        case 9:
            d_bck << "Test for Shell Sort (pratt gaps) back\n";
            break;
        }

        for (int i = 0; i < l_tst; i++)
        {
            d_bck << "\nArray length is " << lens[i] << endl;

            int N = lens[i];
            Sorts s(N); 

            int* numbers_back = new int[N] {};
            int* gaps = new int[N] {};

            for (int k = 0; k < 10; k++)
            {
                numbers_back = generate(numbers_back, N, up_limit, down_limit);
                numbers_back = s.quick_sort_back(numbers_back, N);

                auto start = chrono::steady_clock::now();
                auto end = chrono::steady_clock::now();
                auto t = chrono::duration_cast<chrono::milliseconds>(end - start);

                switch (h)
                {
                case 1:
                    start = chrono::steady_clock::now();
                    numbers_back = s.selection_sort(numbers_back);
                    end = chrono::steady_clock::now();
                    break;
                case 2:
                    start = chrono::steady_clock::now();
                    numbers_back = s.insertion_sort(numbers_back);
                    end = chrono::steady_clock::now();
                    break;
                case 3:
                    start = chrono::steady_clock::now();
                    numbers_back = s.bubble_sort(numbers_back);
                    end = chrono::steady_clock::now();
                    break;
                case 4:
                    start = chrono::steady_clock::now();
                    numbers_back = s.merge_sort(numbers_back, N);
                    end = chrono::steady_clock::now();
                    break;
                case 5:
                    gaps = shell_gaps(gaps, N);
                    start = chrono::steady_clock::now();
                    numbers_back = s.shell_sort(numbers_back, gaps, l_gaps);
                    end = chrono::steady_clock::now();
                    break;
                case 6:
                    start = chrono::steady_clock::now();
                    numbers_back = s.quick_sort(numbers_back, N);
                    end = chrono::steady_clock::now();
                    break;
                case 7:
                    start = chrono::steady_clock::now();
                    numbers_back = s.heap_sort(numbers_back);
                    end = chrono::steady_clock::now();
                    break;
                case 8:
                    gaps = hibbard_gaps(gaps, N);
                    start = chrono::steady_clock::now();
                    numbers_back = s.shell_sort(numbers_back, gaps, l_gaps);
                    end = chrono::steady_clock::now();
                    break;
                case 9:
                    gaps = pratt_gaps(gaps, N);
                    Sorts g(l_gaps);
                    gaps = g.heap_sort(gaps);
                    start = chrono::steady_clock::now();
                    numbers_back = s.shell_sort(numbers_back, gaps, l_gaps);
                    end = chrono::steady_clock::now();
                    break;
                }
                t = chrono::duration_cast<chrono::milliseconds>(end - start);
                d_bck << t.count() / 1000 << "." << t.count() % 1000 << endl;
            }

            delete[] numbers_back;
            delete[] gaps;
        }

        d_bck.close();

        switch (h)
        {
        case 1:
            d_9_1 << "Test for Selection Sort 90_10\n";
            break;
        case 2:
            d_9_1 << "Test for Insertion Sort 90_10\n";
            break;
        case 3:
            d_9_1 << "Test for Bubble Sort 90_10\n";
            break;
        case 4:
            d_9_1 << "Test for Merge Sort 90_10\n";
            break;
        case 5:
            d_9_1 << "Test for Shell Sort (shell gaps) 90_10\n";
            break;
        case 6:
            d_9_1 << "Test for Quick Sort 90_10\n";
            break;
        case 7:
            d_9_1 << "Test for Heap Sort 90_10\n";
            break;
        case 8:
            d_9_1 << "Test for Shell Sort (hibbard gaps) 90_10\n";
            break;
        case 9:
            d_9_1 << "Test for Shell Sort (pratt gaps) 90_10\n";
            break;
        }

        for (int i = 0; i < l_tst; i++)
        {
            d_9_1 << "\nArray length is " << lens[i] << endl;

            int N = lens[i]; 
            Sorts s(N); 

            int size_90_10 = N * 0.9;
            int size_10 = N - size_90_10;
            int* numbers_90_10 = new int[N] {};
            int* help_90_10 = new int[size_90_10] {};    
            int* gaps = new int[N] {};


            for (int k = 0; k < 10; k++)
            {
                help_90_10 = generate(help_90_10, size_90_10, up_limit, down_limit);
                help_90_10 = s.quick_sort(help_90_10, size_90_10);
                for (int j = 0; j < size_90_10; j++)
                    numbers_90_10[j] = help_90_10[j];
                help_90_10 = generate(help_90_10, size_10, up_limit, down_limit);
                for (int j = size_90_10; j < N; j++)
                    numbers_90_10[j] = help_90_10[j - size_90_10];

                auto start = chrono::steady_clock::now();
                auto end = chrono::steady_clock::now();
                auto t = chrono::duration_cast<chrono::milliseconds>(end - start);

                switch (h)
                {
                case 1:
                    start = chrono::steady_clock::now();
                    numbers_90_10 = s.selection_sort(numbers_90_10);
                    end = chrono::steady_clock::now();
                    break;
                case 2:
                    start = chrono::steady_clock::now();
                    numbers_90_10 = s.insertion_sort(numbers_90_10);
                    end = chrono::steady_clock::now();
                    break;
                case 3:
                    start = chrono::steady_clock::now();
                    numbers_90_10 = s.bubble_sort(numbers_90_10);
                    end = chrono::steady_clock::now();
                    break;
                case 4:
                    start = chrono::steady_clock::now();
                    numbers_90_10 = s.merge_sort(numbers_90_10, N);
                    end = chrono::steady_clock::now();
                    break;
                case 5:
                    gaps = shell_gaps(gaps, N);
                    start = chrono::steady_clock::now();
                    numbers_90_10 = s.shell_sort(numbers_90_10, gaps, l_gaps);
                    end = chrono::steady_clock::now();
                case 6:
                    start = chrono::steady_clock::now();
                    numbers_90_10 = s.quick_sort(numbers_90_10, N);
                    end = chrono::steady_clock::now();
                    break;
                case 7:
                    start = chrono::steady_clock::now();
                    numbers_90_10 = s.heap_sort(numbers_90_10);
                    end = chrono::steady_clock::now();
                    break;
                case 8:
                    gaps = hibbard_gaps(gaps, N);
                    start = chrono::steady_clock::now();
                    numbers_90_10 = s.shell_sort(numbers_90_10, gaps, l_gaps);
                    end = chrono::steady_clock::now();
                    break;
                case 9:
                    gaps = pratt_gaps(gaps, N);
                    Sorts g(l_gaps);
                    gaps = g.heap_sort(gaps);
                    start = chrono::steady_clock::now();
                    numbers_90_10 = s.shell_sort(numbers_90_10, gaps, l_gaps);
                    end = chrono::steady_clock::now();
                    break;
                }
                t = chrono::duration_cast<chrono::milliseconds>(end - start);
                d_9_1 << t.count() / 1000 << "." << t.count() % 1000 << endl;
            }

            delete[] numbers_90_10;
            delete[] help_90_10;
            delete[] gaps;
        }

        d_9_1.close();

        switch (h)
        {
        case 1:
            srtd << "Test for Selection Sort for sorted\n";
            break;
        case 2:
            srtd << "Test for Insertion Sort for sorted\n";
            break;
        case 3:
            srtd << "Test for Bubble Sort for sorted\n";
            break;
        case 4:
            srtd << "Test for Merge Sort for sorted\n";
            break;
        case 5:
            srtd << "Test for Shell Sort (shell gaps) for sorted\n";
            break;
        case 6:
            srtd << "Test for Quick Sort for sorted\n";
            break;
        case 7:
            srtd << "Test for Heap Sort for sorted\n";
            break;
        case 8:
            srtd << "Test for Shell Sort (hibbard gaps) for sorted\n";
            break;
        case 9:
            srtd << "Test for Shell Sort (pratt gaps) for sorted\n";
            break;
        }

        for (int i = 0; i < l_tst; i++)
        {
            srtd << "\nArray length is " << lens[i] << endl;

            int N = lens[i];
            Sorts s(N);

            int* numbers_sorted = new int[N] {};
            int* gaps = new int[N] {};


            for (int k = 0; k < 10; k++)
            {
                for (int g = 0; g < N; g++)
                {
                    numbers_sorted[g] = g;
                }

                auto start = chrono::steady_clock::now();
                auto end = chrono::steady_clock::now();
                auto t = chrono::duration_cast<chrono::milliseconds>(end - start);

                switch (h)
                {
                case 1:
                    start = chrono::steady_clock::now();
                    numbers_sorted = s.selection_sort(numbers_sorted);
                    end = chrono::steady_clock::now();
                    break;
                case 2:
                    start = chrono::steady_clock::now();
                    numbers_sorted = s.insertion_sort(numbers_sorted);
                    end = chrono::steady_clock::now();
                    break;
                case 3:
                    start = chrono::steady_clock::now();
                    numbers_sorted = s.bubble_sort(numbers_sorted);
                    end = chrono::steady_clock::now();
                    break;
                case 4:
                    start = chrono::steady_clock::now();
                    numbers_sorted = s.merge_sort(numbers_sorted, N);
                    end = chrono::steady_clock::now();
                    break;
                case 5:
                    gaps = shell_gaps(gaps, N);
                    start = chrono::steady_clock::now();
                    numbers_sorted = s.shell_sort(numbers_sorted, gaps, l_gaps);
                    end = chrono::steady_clock::now();
                case 6:
                    start = chrono::steady_clock::now();
                    numbers_sorted = s.quick_sort(numbers_sorted, N);
                    end = chrono::steady_clock::now();
                    break;
                case 7:
                    start = chrono::steady_clock::now();
                    numbers_sorted = s.heap_sort(numbers_sorted);
                    end = chrono::steady_clock::now();
                    break;
                case 8:
                    gaps = hibbard_gaps(gaps, N);
                    start = chrono::steady_clock::now();
                    numbers_sorted = s.shell_sort(numbers_sorted, gaps, l_gaps);
                    end = chrono::steady_clock::now();
                    break;
                case 9:
                    gaps = pratt_gaps(gaps, N);
                    Sorts g(l_gaps);
                    gaps = g.heap_sort(gaps);
                    start = chrono::steady_clock::now();
                    numbers_sorted = s.shell_sort(numbers_sorted, gaps, l_gaps);
                    end = chrono::steady_clock::now();
                    break;
                }
                t = chrono::duration_cast<chrono::milliseconds>(end - start);
                srtd << t.count() / 1000 << "." << t.count() % 1000 << endl;
            }

            delete[] numbers_sorted;
            delete[] gaps;
        }
        srtd.close();
    }
}