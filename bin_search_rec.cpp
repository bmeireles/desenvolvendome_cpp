//Binary search recursive

//Time Complexity: O(log n)
//Auxiliary Space: O(log n)

//Code from: https://www.geeksforgeeks.org/binary-search/

// C++ program to implement recursive Binary Search
#include <bits/stdc++.h>
using namespace std;
 
// A recursive binary search function. It returns
// location of x in given array arr[l..r] is present,
// otherwise -1
int binarySearch(int arr[], int l, int r, int x)//function to search for the element x in the array,
//receives as parameters an array, the left index, the right index, and the value x.
{
    if (r >= l) {//if the right index is greater or equal to the left index
        int mid = l + (r - l) / 2; //we calculate the middle index
 
        if (arr[mid] == x) //if the value in the middle of the array equals the value of x,
            return mid; //return the index of the middle
 
        if (arr[mid] > x) //if the value in the middle of the array is greater than the value of x,
            return binarySearch(arr, l, mid - 1, x); //we call the function again replacing the right
            //index with mid-1, that way we are ignoring the right half of the array
 
        // Else if the value in the middle of the array is smaller than the value of x, 
        return binarySearch(arr, mid + 1, r, x); //we call the function again replacing the left
        //index with mid+1, that way we are ignoring the left half of the array
    }
 
    return -1; //return -1 if the element was not found in the array
}
 
int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40 }; //creating an array
    int x = 10; //creating an int element
    int n = sizeof(arr) / sizeof(arr[0]); //finding the size of the array
    int result = binarySearch(arr, 0, n - 1, x); //calling the fucntion and saving into the
    //result variable
    (result == -1) //if the result equals -1
        ? cout << "Element is not present in array" //return a message that the element is not present
        : cout << "Element is present at index " << result; //if the result is different than -1,
        //return the index of the element
    return 0;
}