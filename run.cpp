// #include <iostream>
// #include <vector>
// #include <random>
// #include <chrono>
// #include <iomanip>
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

void insertionSort(vector<int> &vec)
{
    for (int i = 1; i < vec.size(); i++)
    {
        int element = vec[i];
        int j = i - 1;
        while (j >= 0 && vec[j] > element)
        {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = element;
    }
}

// void mergeSort(vector<int> &vec)
// {
// }

// void quickSort(vector<int> &vec)
// {
//     if (vec.size() > 10)
//     {
//     }
//     else
//     {
//         insertionSort(vec);
//     }
// }

// void quickSortwithK(vector<int> &vec, int K)
// {
//     if (vec.size() > K)
//     {
//     }
//     return;
// }

// void quickInsertionSort(vector<int> &vec, int K)
// {
//     quickSortwithK(vec, K);
//     insertionSort(vec);
// }

const void print_vector(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main()
{
    int N, K;
    cout << "How many random naturals do you want in your array? ";
    cin >> N;
    cout << "Enter value of K for quick-insertion sort: ";
    cin >> K;

    vector<int> vec;
    vec.reserve(N);

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, N);

    // running a do-while loop to prevent inserting duplicate random numbers in array
    do
    {
        int element = dist(gen);
        if (find(vec.begin(), vec.end(), element) == vec.end())
        {
            vec.push_back(element);
        }
    } while (vec.size() < N);

    cout << "Original array: ";
    print_vector(vec);
    cout << endl;

    vector<int> insertion_vec(vec);
    auto start = high_resolution_clock::now();
    insertionSort(insertion_vec);
    auto stop = high_resolution_clock::now();
    auto insertion_duration = duration_cast<microseconds>(stop - start);
    cout << "Insertion sort: ";
    print_vector(insertion_vec);
    cout << endl;

    // vector<int> merge_vec(vec);
    // start = high_resolution_clock::now();
    // mergeSort(merge_vec);
    // stop = high_resolution_clock::now();
    // auto merge_duration = duration_cast<microseconds>(stop - start);
    // cout << "Mergesort: ";
    // print_vector(merge_vec);
    // cout << endl;

    // vector<int> quick_vec(vec);
    // start = high_resolution_clock::now();
    // quickSort(quick_vec);
    // stop = high_resolution_clock::now();
    // auto quick_duration = duration_cast<microseconds>(stop - start);
    // cout << "Quicksort: ";
    // print_vector(quick_vec);
    // cout << endl;

    // vector<int> quick_insertion_vec(vec);
    // start = high_resolution_clock::now();
    // quickInsertionSort(quick_insertion_vec, K);
    // stop = high_resolution_clock::now();
    // auto quick_insertion_duration = duration_cast<microseconds>(stop - start);
    // cout << "Quick-insertion sort: ";
    // print_vector(quick_insertion_vec);
    // cout << endl;

    cout << setw(20) << "Runtimes" << endl;
    cout << left << setw(20) << "Insertion sort:" << right << setw(10) << fixed << setprecision(3) << insertion_duration.count() / 1000.0 << "ms" << endl;
    // cout << left << setw(20) << "Mergesort:" << right << setw(10) << fixed << setprecision(3) << merge_duration.count() / 1000.0 << "ms" << endl;
    // cout << left << setw(20) << "Quicksort:" << right << setw(10) << fixed << setprecision(3) << quick_duration.count() / 1000.0 << "ms" << endl;
    // cout << left << setw(20) << "Quick-insertion sort:" << right << setw(9) << fixed << setprecision(3) << quick_insertion_duration.count() / 1000.0 << "ms" << endl;

    return 0;
}