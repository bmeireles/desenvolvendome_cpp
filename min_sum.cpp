//Minimum sum by choosing minimum pairs from array
//Source code: https://www.geeksforgeeks.org/minimum-sum-choosing-minimum-pairs-array/
//Time Complexity : O(n) in finding the smallest element of the array
//Auxiliary Space: O(1)

#include <bits/stdc++.h>
using namespace std;

// Returns minimum possible sum in
// array B[]
int minSum(int A[], int n) //function to calculate the minimum possible sum in array B. Receives as
//parameters an arraya A, and the size n of the array
{
    int min_val = *min_element(A, A+n); //minimum value receives the minimum element between the 
    //beginning and end of the array
    return (min_val * (n-1)); //returns the minimum sum, which is the minimum value times n-1
}

// driver function
int main()
{
    int A[] = { 3, 6, 2, 8, 7, 5}; //create an array
    int n = sizeof(A)/ sizeof (A[0]); //calculate the size of the array
    cout << minSum(A, n); //calls the function minSum and print the result
    return 0;
}