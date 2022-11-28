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
        for (int j = 0; j < n; j++) {
            if (arr[j] < min) {
                min = arr[j];
                index = j;
            }
        }

        // this the condition if we find 0 as minimum
        // element, so it will useless to replace 0 by -(0)
        // for remaining operations
        if (min == 0)
            break;

        // Modify element of array
        arr[index] = -arr[index];
    }

    // Calculate sum of array
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return sum;
}

// Driver code
int main()
{
    int arr[] = { -2, 0, 5, -1, 2 };
    int k = 4;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maximumSum(arr, n, k);
    return 0;
}
