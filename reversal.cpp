//Reversal algorithm for right rotation of an array
//Source code: https://www.geeksforgeeks.org/reversal-algorithm-right-rotation-array/
//Time Complexity: O(n), as we are using a while loop to traverse N times.
//Auxiliary Space: O(1), as we are not using any extra space.


#include <bits/stdc++.h>

/*Function to reverse arr[]
from index start to end*/
void reverseArray(int arr[], int start, int end) //function to reverse an array.
//Receives as parameters an array, the start and end of the array.
{
	while (start < end) //while the start is smaller than the end
	{
		std::swap(arr[start], arr[end]); //swap the element in the start index with the element 
        //in the end index
		start++; //change the start position to one index forward
		end--; //change the end position to one index backward
	}
}

/* Function to right rotate arr[]
of size n by d */
void rightRotate(int arr[], int d, int n) //function to right rotate an array. Receives as
//parameters an array, the size n of the array and the last d elements of the array to be
//rotated to the beginning
{
	// Usually, d is smaller or equal to n. If in case d>n,this will give segmentation fault. 
    //We modify d so we can handle larger values:
	d=d%n; //d becomes the remainder of the division of d by n

	reverseArray(arr, 0, n-1); //reverse the array completely from start to end
	reverseArray(arr, 0, d-1); //the d elements are already positioned in the beginning, but not
    //in the right order, so we reverse the array from to d-1
	reverseArray(arr, d, n-1); //the other elements are not in the right sequence, so we reverse
    //them, from d to n-1
}

/* function to print an array */
void printArray(int arr[], int size) 
{
	for (int i = 0; i < size; i++) //for every index in the array
		std::cout << arr[i] << " "; //print the element of the array in index i
}

// driver code
int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; //create an array
	
	int n = sizeof(arr)/sizeof(arr[0]); //calculate de size of the array
	int k = 3; //choose the number of elements to be reversed
	
	rightRotate(arr, k, n); //call the function to rotate the array
	printArray(arr, n); //call the function to print the array

	return 0;
}
