// #include <iostream>
// #include <vector>
// #include <random>
// #include <chrono>
// #include <iomanip>
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

void insertionSort(vector<int> &vec, int start_index, int end_index)
{
    for (int i = start_index + 1; i <= end_index; i++)
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
    // for (int i = 1; i < vec.size(); i++)
    // {
    //     int element = vec[i];
    //     int j = i - 1;
    //     while (j >= 0 && vec[j] > element)
    //     {
    //         vec[j + 1] = vec[j];
    //         j--;
    //     }
    //     vec[j + 1] = element;
    // }
}

void merge(vector<int> &vec, int start_index, int mid_index, int end_index)
{
    vector<int> temp_vec;
    int i = start_index;
    int j = mid_index + 1;
    while (i <= mid_index && j <= end_index)
    {
        if (vec[i] <= vec[j])
        {
            temp_vec.push_back(vec[i]);
            i++;
        }
        else
        {
            temp_vec.push_back(vec[j]);
            j++;
        }
    }
    // copy remaining elements from left subarray
    while (i <= mid_index)
    {
        temp_vec.push_back(vec[i]);
        i++;
    }
    // copy remaining elements from right subarray
    while (j <= end_index)
    {
        temp_vec.push_back(vec[j]);
        j++;
    }
    // copy back all elements from temp_vec to vec
    // to get them in their correct positions in the original vector
    for (int i = start_index; i <= end_index; i++)
    {
        vec[i] = temp_vec[i - start_index];
    }
}

void mergeSort(vector<int> &vec, int start_index, int end_index)
{
    // if vector size is 1
    if (start_index >= end_index)
    {
        return;
    }
    int mid_index = (start_index + end_index) / 2;
    mergeSort(vec, start_index, mid_index);
    mergeSort(vec, mid_index + 1, end_index);
    merge(vec, start_index, mid_index, end_index);
}

int median3(vector<int> &vec, int left_index, int right_index)
{
    int center = (left_index + right_index) / 2;
    if (vec[center] < vec[left_index])
    {
        swap(vec[left_index], vec[center]);
    }
    if (vec[right_index] < vec[left_index])
    {
        swap(vec[left_index], vec[right_index]);
    }
    if (vec[right_index] < vec[center])
    {
        swap(vec[center], vec[right_index]);
    }
    swap(vec[center], vec[right_index - 1]); // place pivot at position (right_index - 1)
    return vec[right_index - 1];
}

void Partition(vector<int> &vec, int start_index, int end_index, int pivot_index)
{
    int i = start_index;
    int j = end_index;
    while (i <= j)
    {
        if (vec[i] > vec[pivot_index])
        {
            i++;
        }
        if (vec[j] <= vec[pivot_index])
        {
            j--;
        }
    }
    swap(vec[pivot_index], vec[j]);
}

void quickSort(vector<int> &vec, int start_index, int end_index)
{
    if (start_index + 10 <= end_index)
    {
        int pivot = median3(vec, start_index, end_index);
        int i = start_index, j = end_index - 1;
        for (;;)
        {
            while (vec[++i] < pivot)
            {
            }
            while (pivot < vec[--j])
            {
            }
            if (i < j)
            {
                swap(vec[i], vec[j]);
            }
            else
            {
                break;
            }
        }
        swap(vec[i], vec[end_index - 1]);
        quickSort(vec, start_index, i - 1);
        quickSort(vec, i + 1, end_index);
    }
    else
    {
        insertionSort(vec, start_index, end_index);
    }
}

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
    // cout << "Enter value of K for quick-insertion sort: ";
    // cin >> K;

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

    // vector<int> insertion_vec(vec);
    // auto start = high_resolution_clock::now();
    // insertionSort(insertion_vec);
    // auto stop = high_resolution_clock::now();
    // auto insertion_duration = duration_cast<microseconds>(stop - start);
    // cout << "Insertion sort: ";
    // print_vector(insertion_vec);
    // cout << endl;

    // vector<int> merge_vec(vec);
    // start = high_resolution_clock::now();
    // mergeSort(merge_vec, 0, merge_vec.size() - 1);
    // stop = high_resolution_clock::now();
    // auto merge_duration = duration_cast<microseconds>(stop - start);
    // cout << "Mergesort: ";
    // print_vector(merge_vec);
    // cout << endl;

    vector<int> quick_vec(vec);
    // start = high_resolution_clock::now();
    quickSort(quick_vec, 0, quick_vec.size() - 1);
    // stop = high_resolution_clock::now();
    // auto quick_duration = duration_cast<microseconds>(stop - start);
    cout << "Quicksort: ";
    print_vector(quick_vec);
    cout << endl;

    // vector<int> quick_insertion_vec(vec);
    // start = high_resolution_clock::now();
    // quickInsertionSort(quick_insertion_vec, K);
    // stop = high_resolution_clock::now();
    // auto quick_insertion_duration = duration_cast<microseconds>(stop - start);
    // cout << "Quick-insertion sort: ";
    // print_vector(quick_insertion_vec);
    // cout << endl;

    // cout << setw(20) << "Runtimes" << endl;
    // cout << left << setw(20) << "Insertion sort:" << right << setw(10) << fixed << setprecision(3) << insertion_duration.count() / 1000.0 << "ms" << endl;
    // cout << left << setw(20) << "Mergesort:" << right << setw(10) << fixed << setprecision(3) << merge_duration.count() / 1000.0 << "ms" << endl;
    // cout << left << setw(20) << "Quicksort:" << right << setw(10) << fixed << setprecision(3) << quick_duration.count() / 1000.0 << "ms" << endl;
    // cout << left << setw(20) << "Quick-insertion sort:" << right << setw(9) << fixed << setprecision(3) << quick_insertion_duration.count() / 1000.0 << "ms" << endl;

    return 0;
}