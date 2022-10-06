//Bubble sort recursive

//Time Complexity: O(n²)
//Auxiliary Space: O(n)

//Code from: https://www.geeksforgeeks.org/recursive-bubble-sort/

//C++ code for recursive bubble sort algorithm
#include <iostream>
using namespace std;
void bubblesort(int arr[], int n)
{
    if (n == 0 || n == 1)
    {
        return;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }
    bubblesort(arr, n - 1);
}
int main()
{
    int arr[5] = {2, 5, 1, 6, 9};
    bubblesort(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
//code contributed by pragatikohli