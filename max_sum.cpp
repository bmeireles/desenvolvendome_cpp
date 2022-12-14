//Maximize array sum after K negations
//Source code: https://www.geeksforgeeks.org/maximize-array-sun-after-k-negation-operations/
//Time Complexity: O(k*n) 
//Auxiliary Space: O(1)

#include <bits/stdc++.h>
using namespace std;

// This function does k operations on array in a way that
// maximize the array sum. index --> stores the index of
// current minimum element for j'th operation
int maximumSum(int arr[], int n, int k)//function to calculate the maximum sum of an array. Receives
//as parameters an array, the size n of the array, and a number k (operations)
{
    // Modify array K number of times
    for (int i = 1; i <= k; i++) { //for every value in the range of k
        int min = INT_MAX; //the minimum value starts with int max. INT_MAX is a macro that specifies
        // that an integer variable cannot store any value beyond this limit. 
        int index = -1; //index variable receives -1

        // Find minimum element in array for current
        // operation and modify it i.e; arr[j] --> -arr[j]
        for (int j = 0; j < n; j++) { //for every element in the array
            if (arr[j] < min) { //if an element in index j is smaller than the minimum
                min = arr[j]; //this element becomes the new minimum
                index = j; //the index variable receives j
            }
        }

        // if we find 0 as minimum
        // element,it will be useless to replace 0 by -(0):
        if (min == 0) //if the minimum is 0, we dont have to replace
            break;

        // Modify element of array
        arr[index] = -arr[index];//the array receives the same element with different signal
    }

    // Calculate sum of array
    int sum = 0; //create variavle sum
    for (int i = 0; i < n; i++) //for every index in the array
        sum += arr[i]; //add the element of that index in the sum
    return sum; //return the sum of all elements
}

// Driver code
int main()
{
    int arr[] = { -2, 0, 5, -1, 2 }; //create an array
    int k = 4; //create k number of operations
    int n = sizeof(arr) / sizeof(arr[0]); //calculate the size of the array
    cout << maximumSum(arr, n, k); //call the function maximumSum and print it
    return 0;
}
