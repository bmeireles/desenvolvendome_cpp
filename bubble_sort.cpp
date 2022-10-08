//Bubble sort

//Time Complexity: O(N2)
//Auxiliary Space: O(1) 

//Code from: https://www.geeksforgeeks.org/bubble-sort/?ref=gcse

// C++ program for implementation
// of Bubble sort
#include <bits/stdc++.h>
using namespace std;
 
// A function to implement bubble sort
void bubbleSort(int arr[], int n)//function bubblesort to order an array, receives as parameters 
//an array, the size n of the array
{
    int i, j;
    for (i = 0; i < n - 1; i++)//for each element of the array
 
        for (j = 0; j < n - i - 1; j++)//for each element of the array minus the i elements already
        //in place
            if (arr[j] > arr[j + 1])//if the value in index j is greater than the value in
            //the next index
                swap(arr[j], arr[j + 1]); //swap both values
}
 
void printArray(int arr[], int size)//function to print an array, receives as parameters an array
//and its size
{
    int i;
    for (i = 0; i < size; i++)//for each element in the array
        cout << arr[i] << " ";//print the value in that index
    cout << endl;
}
 
// Driver code
int main()
{
    int arr[] = { 5, 1, 4, 2, 8}; //creating an array
    int N = sizeof(arr) / sizeof(arr[0]);// finding the size os the array
    bubbleSort(arr, N);//calling the function bubblesort
    cout << "Sorted array: \n";
    printArray(arr, N);//calling the function to print the sorted array
    return 0;
}
// This code is contributed by rathbhupendra