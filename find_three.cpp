//Find the largest three distict elements in an array
//Source code: https://www.geeksforgeeks.org/find-the-largest-three-elements-in-an-array/

//Method 1:
//Time Complexity: O(n)
//Auxiliary Space: O(1)
#include <bits/stdc++.h>
using namespace std;

// Function to print three largest elements
void print3largest_1(int arr[], int arr_size) //function to find the three largest elements in 
//an array. Receives as parameters an array, and the size of the array
{
	int first, second, third; //create variables to store the first, second and third largest numbers

	// There should be atleast three elements
	if (arr_size < 3) //if the array size is smaller than 3,then we dont have 3 numbers to compare
	{
		cout << " Invalid Input "; //print message of invalid array
		return; 
	}

	third = first = second = INT_MIN; //the variables of the numbers are initialized with the
    //macro int min
	for(int i = 0; i < arr_size; i++) //for every index in the array
	{
		// If current element is
		// greater than first
		if (arr[i] > first) //if the element in index i is bigger than the element in first,
        //it is the new biggest number
		{
			third = second; //so we substitute the third for the second; the third variable receives
            //the second element
			second = first; //the second variable receives the element in the first
			first = arr[i]; //and the first variable receives the element in index i
		}

		// If arr[i] is in between first
		// and second then update second
		else if (arr[i] > second && arr[i] != first) //if the element in index i is bigger than
        //the second and is different than the first, it will become the new second value
		{
			third = second; //so the third varible receives the previous second value
			second = arr[i]; //and the second variable receives the element in index i
		}

		else if (arr[i] > third && arr[i] != second) //if the element in index i is bigger than the
        //third and different than the second, it will become the new third
			third = arr[i]; //so the third variable receives the element in index i
	}

	cout << "Three largest elements are "
		<< first << " " << second << " "
		<< third << endl; //print the 3 elements in sequence
}

// Driver code
int main()
{
	int arr[] = { 12, 13, 1, 10, 34, 11 }; //create an array
	int n = sizeof(arr) / sizeof(arr[0]); //calculate the size of the array
	
	print3largest_1(arr, n); //call the function with the array and size as a parameter
	return 0;
}

//--------------------------------------------------------
//Method 2:
//Time Complexity: O(n log n)
//Auxiliary Space: O(1)


#include <bits/stdc++.h>
using namespace std;

void find3largest_2(int arr[], int n)//function to find the three largest elements in 
//an array. Receives as parameters an array, and the size of the array
{
	sort(arr, arr + n); // function sort() uses Tuned Quicksort with avg. case Time
    // complexity = O(nLogn). Now the array is sorted.

	int check = 0, count = 1; //varibales to store the checked value and the counting
    //of numbers printed
	for (int i = 1; i <= n; i++) { //for every index in the array
		if (count < 4) { //if count is smaller than 4, we can proceed , because we want to 
        //print only the 3 largest numbers. Because the array is sorted, the largest numbers
        //are the last ones.
			if (check != arr[n - i]) { //if the value in check is different than the value in
            //n-i index 
				// to handle duplicate values
				cout << arr[n - i] << " "; //print the element in this index
				check = arr[n - i]; //assign this element to check
				count++; // add 1 in count, so we know how many numbers were printed so far
			}
		}
		else
			break;
	}
}

// Driver code
int main()
{
	int arr[] = { 12, 45, 1, -1, 45, 54, 23, 5, 0, -10 }; //create an array
	int n = sizeof(arr) / sizeof(arr[0]); //calculate the size of the array
	find3largest_2(arr, n); //call the function with the parameters created
}


