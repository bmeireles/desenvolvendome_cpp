//Minimum product subset of an array
//Source code: https://www.geeksforgeeks.org/minimum-product-subset-array/
//Time Complexity: O(n) 
//Auxiliary Space: O(1)


#include <bits/stdc++.h>
using namespace std;

int minProductSubset(int a[], int n) //function to calculate the minimum product subset of an
//array. Receives as parameters an array and the size n of the array
{
    if (n == 1) //if there is only one element in the array, there is no calcutation to make
        return a[0]; //return the single element as the minimum product

    // Find count of negative numbers, count of zeros,
    // maximum valued negative number, minimum valued
    // positive number and product of non-zero numbers
    int max_neg = INT_MIN, min_pos = INT_MAX, count_neg = 0,
        count_zero = 0, prod = 1;
    
    for (int i = 0; i < n; i++) { //for every index in the array
        if (a[i] == 0) { //if the element in index i is 0, we dont multiply
            count_zero++; //add 1 in the counting of zeros
            continue;
        }
        // Count negatives and keep track of maximum valued
        // negative.
        if (a[i] < 0) { //if the element in index i is smaller than 0, it is a negative number
            count_neg++; //add 1 in the counting of negatives
            max_neg = max(max_neg, a[i]); //the maximum negative variable receives the maximum
            //number between the current max neg and the element in index i
        }
        // Track minimum positive number of array
        if (a[i] > 0) //if the element in index i is bigger than 0, it is a positive number
            min_pos = min(min_pos, a[i]); //the minimum positive variable receives the minimum
            //number between the current min pos and the element in index i
        prod = prod * a[i]; //the product becomes the previous product times the element in index i
    }
    // If there are all zeros or no negative number present
    if (count_zero == n || (count_neg == 0 && count_zero > 0)) //if the counting of 0 is equal to
    //the total of elements, or the counting of negatives is equal to 0 and the counting of zeros is
    //bigger than 0, then the minimum product is 0.
        return 0;
    // If there are all positive
    if (count_neg == 0 && count_zero == 0) //if there is no negative number or zeros, it can only
    //be positive
        return min_pos;

    // If there are even number of negative numbers and
    // count_neg not 0
    if (!(count_neg & 1) && count_neg != 0)
        // Otherwise result is product of all non-zeros
        // divided by maximum valued negative.
        prod = prod / max_neg;
    return prod;
}

int main()
{
    int a[] = { -1, -1, -2, 4, 3 }; //create an array
    int n = sizeof(a) / sizeof(a[0]); //calculate the size of the array
    cout << minProductSubset(a, n); //call the function and print the result
    return 0;
}

