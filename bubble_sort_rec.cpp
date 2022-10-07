//Bubble sort recursive

//Time Complexity: O(n²)
//Auxiliary Space: O(n)

//Code from: https://www.geeksforgeeks.org/recursive-bubble-sort/

//C++ code for recursive bubble sort algorithm
#include <iostream>
using namespace std;

void bubblesort(int arr[], int n)//function to order an array, receives as parameters an array
//and the size of the array n
{
    if (n == 0 || n == 1)//if the size of the array is 0 or 1, there is nothing to be ordered
    {
        return;
    }
    for (int i = 0; i < n - 1; i++) //if the size of the array is greater than n, we will go
    //through each element
    {
        if (arr[i] > arr[i + 1])//if the value in the index is greater than the value in the next index
        {
            swap(arr[i], arr[i + 1]);//swap these two elements
        }
    }
    bubblesort(arr, n - 1);//call the function again without the last element of the array
}
int main()
{
    int arr[5] = {2, 5, 1, 6, 9}; //creating an array
    bubblesort(arr, 5); //calling the function bubblesort
    for (int i = 0; i < 5; i++)//for every element in the array, print it
    {
        cout << arr[i] << " ";
    }
    return 0;
}
//code contributed by pragatikohli