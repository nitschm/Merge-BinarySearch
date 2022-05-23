#include <iostream>
using namespace std;

void stars(int x);
void merge(int array[], int const left, int const mid, int const right);
void mergeSort(int array[], int const begin, int const end);
void printArray(int A[], int size);
int binarySearch(const int list[], int length, const int& item);

int main()
{
    int num1 = 0;
    bool nonnegative = true;
    int const SIZE = 8;
    int arr[SIZE];
    int arr_size = 8;
    int search = 0;
    int pos = 0;

    while (nonnegative == true)
    {
        cout << "Please input a nonnegative integer: ";
        cin >> num1;

        if (num1 > 0)
            nonnegative = false;
    }
    
    cout << endl;

    stars(num1);

    cout << endl;

    cout << "Please enter eight integers to add to the array: \n";

    for (int i = 0; i < SIZE; i++)
        cin >> arr[i];
    
    cout << "\nGiven array is \n";
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    cout << "\n\nSorted array is \n";
    printArray(arr, arr_size);

    cout << "\n\nPlease enter a number to search for in the array: ";
    cin >> search;

    pos = binarySearch(arr, arr_size, search);

    if (pos != -1)
        cout << search << " found at position " << pos << endl;
    else
        cout << search << " is not in the list" << endl;

    return 0;
}

void stars(int x)
{
    if (x == 0)
    {
        return;
    }
    else
    {
        for (int i = 1; i <= x; i++)
            cout << "*";
        cout << endl;

        stars(x - 1);

        for (int i = 1; i <= x; i++)
            cout << "*";
        cout << endl;
    }
}

//Merge
void merge(int array[], int const left, int const mid, int const right)
{
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;

    // Create temp arrays
    int* leftArray = new int[subArrayOne],
        * rightArray = new int[subArrayTwo];

    // Copy dta to temp arrays leftArray[] and rightArray[]
    for (int i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    int indexOfSubArrayOne = 0, // Initial index of first sub-array
        indexOfSubArrayTwo = 0; // Initial index of second sub-array
    int indexOfMergedArray = left; // Initial index of merged array

    // Merge the temp arrays back into array[left...right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
 
    // Copy the remainaing elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

//MergeSort
void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return; // Returns recursively

    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

//Displays the array
void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
}

//Binary search
int binarySearch(const int list[], int length, const int& item)
{
    int first = 0, mid, last = length - 1;

    bool found = false;

    while (first <= last && !found)
    {
        mid = (first + last) / 2;

        if (list[mid] == item)
            found = true;
        else if (list[mid] > item)
            last = mid - 1;
        else
            first = mid + 1;
    }

    if (found)
        return mid;
    else
        return -1;

}