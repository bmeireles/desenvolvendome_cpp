//Counting sort

//Time Complexity: O(n+k) where n is the number of elements in the input array
// and k is the range of input. 
//Auxiliary Space: O(n+k)

//Code from: https://www.geeksforgeeks.org/counting-sort/

// C++ Program for counting sort
#include <bits/stdc++.h>
#include <string.h>
using namespace std;
#define RANGE 255

void countSort(char arr[]) //function to order the array, receives as parameter an array
{
    char output[strlen(arr)];// create an array the same size as the original, to receive
    //the sorted values
  
    int count[RANGE + 1], i; //create an array named count to store the count of individual characters
    memset(count, 0, sizeof(count)); //memset is a function that can be used to fill an array,
    //making each of the indexes in the count array receive the value 0.
  
    for (i = 0; arr[i]; ++i)//for every index in arr[]
        ++count[arr[i]]; //add +1 in the count array,in the index number equal
        //to the arr[] element
  
    // Change count[i] so that count[i] now contains actual
    // position of this character in output array
    for (i = 1; i <= RANGE; ++i)//for every number in range
        count[i] += count[i - 1]; //use this number as index of count, and the new value of count
        //will be count + the previous index element. This is necessary to adjust the positions
        //of the elements in the output array
  
    // Build the output character array
    for (i = 0; arr[i]; ++i) { //for every index in arr[]
        output[count[arr[i]] - 1] = arr[i]; //the output array in its index () is the value of
        //arr[i]
        --count[arr[i]]; //-1 from the counting array of the number inserted, because we already
        //inserted this number in the output array
    }
  
    /* 
    For Stable algorithm 
    for (i = sizeof(arr)-1; i>=0; --i) 
    { 
        output[count[arr[i]]-1] = arr[i]; 
        --count[arr[i]]; 
    } 
      
    For Logic : See implementation 
    */
  
    // Copy the output array to arr, so that arr now
    // contains sorted characters
    for (i = 0; arr[i]; ++i) //for every index in arr[]
        arr[i] = output[i]; //arr[i] receives the value of the output array in the same index
}
  
// Driver  code
int main()
{
    char arr[] = "geeksforgeeks"; //create an array
  
    countSort(arr); //call the function with the array to be sorted
  
    cout << "Sorted character array is " << arr; //print the sorted array
    return 0;
}
  
// This code is contributed by rathbhupendra