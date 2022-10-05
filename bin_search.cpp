//Binary search

//Time Complexity: O(log n)
//Auxiliary Space: O(1)

//Code from: https://www.geeksforgeeks.org/binary-search/

// C++ program to implement iterative Binary Search
#include <bits/stdc++.h>
using namespace std;
 
// A iterative binary search function. It returns
// location of x in given array arr[l..r] if present,
// otherwise -1
int binarySearch(int arr[], int l, int r, int x)//function to search for the element x, receives as
//parameters an array, the left element, teh right element and the element x to be found.
{
    while (l <= r) { //we create a loop to go though the array, and the condition to continue
    // the loop is while the left element is smaller or equal to the right one
        int m = l + (r - l) / 2; //the middle elem. is going to be the left plus (right minus left)
        //divided by two
 
        // Check if x is present at mid
        if (arr[m] == x)//if the value in the middle of the array is the element x we are looking for
            return m; //return the index of the middle 
 
        // If x greater, ignore left half
        if (arr[m] < x)//if the value in the middle of the array is smaller than the element x
            l = m + 1; //now the left index is the middle + 1, this way we are ignoring the first
            //half of the array (the left side)
 
        // If x is smaller, ignore right half
        else //if the value in the middle of the array is greater than x
            r = m - 1; //the right index receives the middle + 1, this way we are ignoring the 
            //right half of the array
    }
 
    // if we reach here, then element was
    // not present
    return -1;//the element x was not found in the array
}
 
int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40 }; //creating an array
    int x = 10; //creating an int element
    int n = sizeof(arr) / sizeof(arr[0]);//finding the size of the array
    int result = binarySearch(arr, 0, n - 1, x);//calling the function and saving into the 
    //result variable
    (result == -1)
        ? cout << "Element is not present in array"
        : cout << "Element is present at index " << result;
    return 0;
}