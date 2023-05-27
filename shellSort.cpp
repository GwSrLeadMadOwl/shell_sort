// Shell Sort in C++ programming
#include <iostream>
#include <chrono>
using namespace std;

// Shell sort
void shellSort(int array[], int n)
{
    // Rearrange elements at each n/2, n/4, n/8, ... intervals
    for (int interval = n / 2; interval > 0; interval /= 2)
    {
        for (int i = interval; i < n; i += 1)
        {
            int temp = array[i];
            int j;
            for (j = i; j >= interval && array[j - interval] > temp; j -= interval)
            {
                array[j] = array[j - interval];
            }
            array[j] = temp;
        }
    }
}

// Print an array
void printArray(int array[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

// Driver code
int main()
{
    int data[] = {57, 96, 67, 69, 23, 28, 33, 83, 71, 48, 39, 99, 9, 99, 75, 81, 57, 61, 7, 38, 67, 59, 70, 73, 65, 85, 66, 11, 88, 89, 47, 34, 45, 4, 47, 38, 65, 30, 95, 16, 10, 83, 97, 73, 42, 99, 60, 71, 91, 47, 66, 38, 45, 14, 73, 50, 5, 99, 90, 21, 25, 54, 54, 84, 1, 24, 0, 70, 56, 94, 44, 64, 26, 88, 34, 44, 100, 48, 45, 6, 59, 53, 73, 98, 0, 2, 97, 42, 76, 78, 81, 37, 62, 30, 3, 26, 5, 61, 20, 44, 5, 41, 29, 64, 52, 31, 97, 91, 20, 38, 40, 21, 32, 94, 70, 53, 33, 46, 42, 81};

    int size = sizeof(data) / sizeof(data[0]);
    auto start_time = std::chrono::high_resolution_clock::now();
    shellSort(data, size);
    auto current_time = std::chrono::high_resolution_clock::now();
    cout << "Sorted array: \n";
    printArray(data, size);

    std::cout << "Program has been running for "
              << std::chrono::duration_cast<std::chrono::nanoseconds>(current_time - start_time).count()
              << " nanosec" << std::endl;
}