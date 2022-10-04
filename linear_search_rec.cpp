//Linear Search - recursive approach

//If the size of the array is zero then, return -1, representing that the element is not found. 
//This can also be treated as the base condition of a recursion call.
//Otherwise, check if the element at the current index in the array is equal to the key or
// not i.e, arr[size – 1] == key
//    If equal, then return the index of the found key.

// Time complexity: O(N)
// Auxiliary Space: O(N)

//Code from: https://www.geeksforgeeks.org/linear-search/
 
#include <iostream> //includes input-output stream
using namespace std; //c++ standard library
 
int linearsearch(int arr[], int size, int key)//function to search for the key , receives as parameters
//the array, the size of the array and the key/value to be found
{
    if (size == 0) {//if the size of the array is 0, there are no keys to compare
        return -1; //return -1 because the value was not found
    }
    else if (arr[size - 1] == key) { //if the key is equal to the value in the last index of the array
    //(size-1) then return the index of this value
        // Return the index of found key.
        return size - 1;
    }
    else { //if none of the above is true, call the function again without the last index, which we
    //already tested
        int ans = linearsearch(arr, size - 1, key);
        return ans;
    }
}

int main()
{
    int arr[5] = {5, 15, 6, 8, 4 }; //creating an array of 5 elements
    int key = 8; //creating a key to look for in the array
   
    int ans = linearsearch(arr, 5, key);//calling the linearsearch function and saving the result
    //in the ans variable
    if (ans == -1) { //if ans equals -1, the value was not found in the array
        cout << "The element " << key << " is not found."
             << endl;
    }
    else { //if ans is differrent than -1, the key was found at some position/index
        cout << "The element " << key << " is found at "
             << ans << " index of the given array." << endl;
    }
    return 0;
}
