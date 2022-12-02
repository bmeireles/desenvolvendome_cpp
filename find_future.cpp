//Queries to find the future closest date
//Source code: https://www.geeksforgeeks.org/queries-to-find-the-future-closest-date/
//https://www.geeksforgeeks.org/sort-an-array-of-string-of-dates-in-ascending-order/
//Time Complexity: O((N*log N) + (Q*log N)) 
//Auxiliary Space: O(1)

#include <bits/stdc++.h>
using namespace std;

// C++ program to sort the dates in a string array


//String example: "24 06 2017"
// pos:            0123456789

// Comparator function to sort an array of dates
bool comp(string a, string b) //function to compare strings, returns a boolean value(true or false).
//Receives as parameters 2 strings
{
	// Comparing the years
	string str1 = a.substr(6, 4);
	string str2 = b.substr(6, 4);
	if (str1.compare(str2) != 0) {
		if (str1.compare(str2) < 0)
			return true;
		return false;
	}

	// Comparing the months
	string month_a = a.substr(3, 2);
	string month_b = b.substr(3, 2);
    if (month_a.compare(month_b) < 0)
		return true;
	return false;


	// Comparing the days
	string day_a = a.substr(0, 2);
	string day_b = b.substr(0, 2);
	if (day_a.compare(day_b) < 0)
		return true;
	return false;
}

// Utility function to print the contents
// of the array
void printDates(string dates[], int n)
{
	for (int i = 0; i < n; i++) {
		cout << dates[i] << endl;
	}
}

// Driver code
int main()
{
	string dates[] = { "24 07 2017", "25 07 2017", "11 06 1996",
					"01 01 2019", "12 08 2005", "01 01 1997" };
	int n = sizeof(dates) / sizeof(dates[0]);

	// Order the months
	sort_months();

	// Sort the dates
	sort(dates, dates + n, comp);

	// Print the sorted dates
	printDates(dates, n);
}
