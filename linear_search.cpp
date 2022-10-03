//Linear Search 

//Iterative approach:
// Time complexity: O(N)
// Auxiliary Space: O(1)

//Recursive approach:
// Time complexity: O(N)
// Auxiliary Space: O(N)

// C++ code to linearly search x in arr[]. If x
// is present then return its location, otherwise
// return -1
 
#include <iostream> //includes input-output stream
using namespace std; //c++ standard library

//-------------------------------
//Iterative solution:
 
int search(int arr[], int N, int x) //function to iterate through the array, receives as parameters
//an array, the sie of the array N, and the number X we would like to find.
{
    int i; //creating a variable for iteration
    for (i = 0; i < N; i++) //for every i in N
        if (arr[i] == x) //if the value in the index i of the array equals x
            return i; //return the index
    return -1; //if x is not found in the iteration, return -1
}

int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40 }; //creating an array
    int x = 10; //creating a number to search in the array 
    int N = sizeof(arr) / sizeof(arr[0]); //finding the size of the array
 
    // Function call
    int result = search(arr, N, x); //result receives the return of the function search()
    (result == -1) //ternary comparison: is result equal to -1 ?
        ? cout << "Element is not present in array" //if yes, return this message
        : cout << "Element is present at index " << result; //if no, return this message and the index
    return 0;
}

//---------------------------------------------------
//Recursive solution: