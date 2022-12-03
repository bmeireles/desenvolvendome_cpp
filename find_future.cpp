//Queries to find the future closest date
//Source code: https://www.geeksforgeeks.org/queries-to-find-the-future-closest-date/
//https://www.geeksforgeeks.org/sort-an-array-of-string-of-dates-in-ascending-order/
//Time Complexity: O((N*log N) + (Q*log N)) 
//Auxiliary Space: O(1)

#include <bits/stdc++.h>
using namespace std;


//String example: "24 06 2017"
// pos:            0123456789
//Comparator function to sort an array of dates
bool comp(string a, string b) //function to compare strings, returns a boolean value(true or false).
//Receives as parameters 2 strings
{
	// Comparing the years
	string str1 = a.substr(6, 4); //str1 is going to be a substring, extracted from string a, starting
	//at position 6 with 4 values
	string str2 = b.substr(6, 4); //str2 is going to be a substring, extracted from string b, starting
	//at position 6 with 4 values
	if (str1.compare(str2) != 0) { //if str1 is different from str2
		if (str1.compare(str2) < 0) //if str1 is smaller as compared to string 2
			return true; 
		return false;
	}

	// Comparing the months
	string month_a = a.substr(3, 2); //month_a is going to be a substring, extracted from a, starting
	//at position 3 with 2 values
	string month_b = b.substr(3, 2); //month_b is going to be a substring, extracted from b, starting
	//at position 3 with 2 values
    if (month_a.compare(month_b) < 0) //if month_a is smaller compared to month_b
		return true;
	return false;


	// Comparing the days
	string day_a = a.substr(0, 2); //day_a is going to be a substring, extracted from a, starting
	//at position 0 with 2 values
	string day_b = b.substr(0, 2); //day_b is going to be a substring, extracted from b, starting
	//at position 0 with 2 values
	if (day_a.compare(day_b) < 0) //if day_a is smaller compared to day_b
		return true;
	return false;
}

// Utility function to print the contents of the array
void printDates(string dates[], int n)
{
	for (int i = 0; i < n; i++) {
		cout << dates[i] << endl;
	}
}

// Function to print the next closest date
string nextClosestDate(string arr[], string q, int n) //n is the size of the array
{
	// Perform the Binary search to answer the queries
	int l = 0, r = n - 1; //variables for the left and right indexes
	int ind = -1; //variable for the final index that will be returned as the result. Starts
	//with -1, because if there is no modification inside the while loop, it will be the same

	// Iterate until l <= r
	while (l <= r) {
		// Find middle m
		int m = (l + r) / 2;
		
		// Comparator function call
		int c = comp(q, arr[m]);
		
		// If comp function returns 0, next closest date is found
		if (c == 0) {
			ind = m;
			break;
		}
		
		// If comp function returns less than 0, search in the left half
		else if (c < 0) {
			r = m - 1;
			ind = m;
		}
		
		// If comp function returns greater than 0, search in the right half
		else {
			l = m + 1;
		}
	}
	
	// Return the result
	if (ind == -1) {  // if index is -1, no date was found to be the nearest
		return "-1";
	}
	else {
		return arr[ind]; //return the nearest date
	}
}

void performQueries(string arr[], string Q[], int k, int n) { //k is the size of Q[]
	for (int i = 0; i < k; i++) {
		string result = nextClosestDate(arr, Q[i],n);
		if (result == "-1") {
			cout << "No closest date found for: " << result << endl;
		}
		else {
			cout << "The closest date found for the query "<< Q[i]<< " is: " << result << endl;
		}
		//cout << dates[i] << endl;
	}
}

// Driver code
int main()
{
	//create a string with dates
	string dates[] = { "24 07 2017", "25 07 2017", "11 06 1996", "01 01 2019", "12 08 2005", "01 01 1997" };
	int n = sizeof(dates) / sizeof(dates[0]); //calculte the size of the string
	//create a string with queries
	string Q[] = { "01 07 2019", "15 10 2017", "24 01 1996"};
	int k = sizeof(Q) / sizeof(Q[0]); //calculte the size of the string

	// Sort the dates
	sort(dates, dates + n, comp); //call the function sort to order the array, using the comp
	//function as a measurement to order

	// Print the sorted dates
	printDates(dates, n);

	performQueries(dates, Q, k, n);
}
