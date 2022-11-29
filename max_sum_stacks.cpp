//Maximum sum of 3 stacks
//Source code: https://www.geeksforgeeks.org/find-maximum-sum-possible-equal-sum-three-stacks/
//Time Complexity : O(n1 + n2 + n3) where n1, n2 and n3 are sizes of three stacks.
//Auxiliary space: O(1) because using constant space for variables

#include <bits/stdc++.h>
using namespace std;

// Returns maximum possible equal sum of three stacks
// with removal of top elements allowed
int maxSum(int stack1[], int stack2[], int stack3[], int n1, 
		int n2, int n3) //function to find the maximum possible equal sum of 3 stacks. Receives as 
        //parameters 3 stacks/arrays, and the size of each one.
{
	int sum1 = 0, sum2 = 0, sum3 = 0; //variables for the sum of elements of eacch stack

	// Finding the initial sum of stack1.
	for (int i = 0; i < n1; i++) //for every index in stack 1
		sum1 += stack1[i]; //the sum receives the element in index i, calculating the total sum
        //of the stack

	// Finding the initial sum of stack2.
	for (int i = 0; i < n2; i++) //for every index in stack 2
		sum2 += stack2[i]; //the sum receives the element in index i, calculating the total sum
        //of the stack

	// Finding the initial sum of stack3.
	for (int i = 0; i < n3; i++) //for every index in stack 3
		sum3 += stack3[i]; //the sum receives the element in index i, calculating the total sum
        //lof the stack

	// As given in question, first element is top
	// of stack..
	int top1 = 0, top2 = 0, top3 = 0; //creating variables for the first element of each stack
	while (1) {
		// If any stack is empty
		if (top1 == n1 || top2 == n2 || top3 == n3) //if all stacks have 0 elements, the maximum
        //sum is 0
			return 0;

		// If sum of all three stack are equal.
		if (sum1 == sum2 && sum2 == sum3) //if the sum of stack 1 is equal to stack 2 and 3, we 
        //already have the maximum sum
			return sum1;

		// Finding the stack with maximum sum and
		// removing its top element.
		if (sum1 >= sum2 && sum1 >= sum3) //if sum of stack 1 is bigger or equal to stack 2 and
        //sum of stack 1 is also bigger than stack 3, then we have to remove the first element of
        //stack 1 to calculate again
			sum1 -= stack1[top1++]; //the sum of stack 1 becomes the previous sum minus the top element
		else if (sum2 >= sum1 && sum2 >= sum3) //if sum of stack 2 is bigger or equal to stack 1 and
        //sum of stack 2 is also bigger than stack 3, then we have to remove the first element of
        //stack 2 to calculate again
			sum2 -= stack2[top2++]; //the sum of stack 2 becomes the previous sum minus the top element
		else if (sum3 >= sum2 && sum3 >= sum1) //if sum of stack 3 is bigger or equal to stack 2 and
        //sum of stack 3 is also bigger than stack 1, then we have to remove the first element of
        //stack 3 to calculate again
			sum3 -= stack3[top3++]; //the sum of stack 3 becomes the previous sum minus the top element
	}
}

// Driven Program
int main()
{
	int stack1[] = { 3, 2, 1, 1, 1 }; //create stack 1
	int stack2[] = { 4, 3, 2 }; //create stack 2
	int stack3[] = { 1, 1, 4, 1 }; //create stacck 3

	int n1 = sizeof(stack1) / sizeof(stack1[0]); //calculate the size of stack 1
	int n2 = sizeof(stack2) / sizeof(stack2[0]); //calculate the size of stack 2
	int n3 = sizeof(stack3) / sizeof(stack3[0]); //calculate the size of stack 3

	cout << maxSum(stack1, stack2, stack3, n1, n2, n3) //call the function maxSum and print the result
		<< endl;
	return 0;
}
