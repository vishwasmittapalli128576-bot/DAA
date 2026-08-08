#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace chrono;

// Bubble Sort
void bubbleSort(vector<int>& arr)
{
    int n = arr.size();

    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }
}

// Selection Sort
void selectionSort(vector<int>& arr)
{
    int n = arr.size();

    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        swap(arr[i], arr[minIndex]);
    }
}

// Insertion Sort
void insertionSort(vector<int>& arr)
{
    int n = arr.size();

    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// Merge function
void mergeArrays(vector<int>& arr, int left, int mid, int right)
{
    vector<int> leftPart(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> rightPart(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0, j = 0, k = left;

    while (i < leftPart.size() && j < rightPart.size())
    {
        if (leftPart[i] <= rightPart[j])
            arr[k++] = leftPart[i++];
        else
            arr[k++] = rightPart[j++];
    }

    while (i < leftPart.size())
        arr[k++] = leftPart[i++];

    while (j < rightPart.size())
        arr[k++] = rightPart[j++];
}

// Merge Sort
void mergeSort(vector<int>& arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        mergeArrays(arr, left, mid, right);
    }
}

// Partition function for Quick Sort
int partitionArray(vector<int>& arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);

    return i + 1;
}

// Quick Sort
void quickSort(vector<int>& arr, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partitionArray(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

// Function to display array
void displayArray(const vector<int>& arr)
{
    for (int value : arr)
        cout << value << " ";

    cout << "\n";
}

// Function to measure sorting time
template <typename SortFunction>
long long measureTime(vector<int> arr, SortFunction sortFunction)
{
    auto start = high_resolution_clock::now();

    sortFunction(arr);

    auto stop = high_resolution_clock::now();

    return duration_cast<microseconds>(stop - start).count();
}

int main()
{
    const int n = 100;

    vector<int> originalArray(n);

    srand(static_cast<unsigned int>(time(nullptr)));

    // Generate random numbers
    for (int i = 0; i < n; i++)
        originalArray[i] = rand() % 1000;

    cout << "========================================\n";
    cout << "       SORTING ALGORITHM ANALYSIS       \n";
    cout << "========================================\n";
    cout << "Number of Elements: " << n << "\n\n";

    cout << "Original Array:\n";
    displayArray(originalArray);

    cout << "\n----------------------------------------\n";
    cout << "Sorting Time Comparison\n";
    cout << "----------------------------------------\n";

    // Bubble Sort
    long long bubbleTime = measureTime(originalArray,
        [](vector<int>& arr)
        {
            bubbleSort(arr);
        });

    cout << left << setw(20)
         << "Bubble Sort:"
         << bubbleTime << " microseconds\n";

    // Selection Sort
    long long selectionTime = measureTime(originalArray,
        [](vector<int>& arr)
        {
            selectionSort(arr);
        });

    cout << left << setw(20)
         << "Selection Sort:"
         << selectionTime << " microseconds\n";

    // Insertion Sort
    long long insertionTime = measureTime(originalArray,
        [](vector<int>& arr)
        {
            insertionSort(arr);
        });

    cout << left << setw(20)
         << "Insertion Sort:"
         << insertionTime << " microseconds\n";

    // Merge Sort
    long long mergeTime = measureTime(originalArray,
        [](vector<int>& arr)
        {
            mergeSort(arr, 0, arr.size() - 1);
        });

    cout << left << setw(20)
         << "Merge Sort:"
         << mergeTime << " microseconds\n";

    // Quick Sort
    long long quickTime = measureTime(originalArray,
        [](vector<int>& arr)
        {
            quickSort(arr, 0, arr.size() - 1);
        });

    cout << left << setw(20)
         << "Quick Sort:"
         << quickTime << " microseconds\n";

    cout << "----------------------------------------\n";

    return 0;
}
