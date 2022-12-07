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

/*
string searchList(string array[], int numElems, string value) { //function to to through the array
//and find the closest value. Receives as parameters an array, the number of elements in the array,
//and the value we want to look for in the array
    int diff = abs(stoi(array[0].substr(6,4)) - stoi(value.substr(6,4))); //the difference value starts with the first value of
	//the array minus the value we want to find. The smaller the difference, the closest they are.
	int idx = 0; //variable to save the index of the value in the array
	int i = 0;
    for (int i; i < numElems; i++) { //for every value in the array
        if (abs(stoi(array[i]) - stoi(value)) < diff) { //if the difference between the the element in the list 
		//and the value is smaller than the current difference
            diff = abs(stoi(array[i]) - stoi(value)); //save that value as the new difference
            idx = i; //save the index of the element in the array
        }
    }
    return array[idx]; //return the closest element
}
*/


// Function to print the next closest date
string nextClosestDate(string arr[], string q, int n) //n is the size of the array
{
	//Compare years: find the closest year in the array
	//Go through the array again with the closest year
	// - If there is more than one value for the same year, compare month between these elements
	// - - Find the closest value for the month between the selected elements based on years
	// - - - If there is only one value, return this element as the closest
	// - - - If there is more than one element, compare day between these elements
	// - If there is only one value, return this element

	//Compare years: find the closest year in the array
	int diff = abs(stoi(arr[0].substr(6,4)) - stoi(q.substr(6,4))); //the difference value starts with the first value of
	//the array minus the value we want to find. The smaller the difference, the closest they are.
	cout << "Substring of the year from array: " << stoi(arr[0].substr(6,4))<< endl;
	cout << "Substring of the year from q: " << stoi(q.substr(6,4))<< endl;
	cout << "Substring of the difference: " << diff << endl;


	int idx = 0; //variable to save the index of the value in the array
	int i = 0; //first i
    for (int i; i < n; i++) { //for every value in the array
        if (abs(stoi(arr[i].substr(6,4)) - stoi(q.substr(6,4))) < diff) { //if the difference between the the element in the list 
		//and the value is smaller than the current difference
            diff = abs(stoi(arr[i].substr(6,4)) - stoi(q.substr(6,4))); //save that value as the new difference
            idx = i; //save the index of the element in the array
        }
    }
    //arr[idx]; // the closest element according to the year
	string closest_year = arr[idx].substr(6,4); //the closest year
	cout << "Closest year: " << closest_year << endl;

	//Go through the array again with the closest year
	string years_arr[n];
	i = 0; //second i
	for (int i; i < n; i++) {
		if (arr[i].substr(6,4) == closest_year) {
			years_arr[i] = arr[i];
		}
		cout << "years_array in index " << i << " is:"<< years_arr[i] << endl;
	}

	// - If there is only one value, return this element
	int size_years = sizeof(years_arr)/sizeof(years_arr[0]);
	cout << "Size of the years_arr: " << size_years << endl;

	if (size_years == 1) { //if there is only one element, this is the closest of all
		return years_arr[0]; //return the closest date
	}
	else {//If there is more than one value for the same year, compare month between these elements
		int diff_month = abs(stoi(years_arr[0].substr(3,2)) - stoi(q.substr(3,2))); //the difference value starts with the first value of
		//the array minus the value we want to find. The smaller the difference, the closest they are.
		int idx_month = 0; //variable to save the index of the value in the array
		i = 0; //third i
   		for (int i; i < size_years; i++) { //for every value in the array
       		if (abs(stoi(years_arr[i].substr(3,2)) - stoi(q.substr(3,2))) < diff_month) { //if the difference between the the element in the list 
			//and the value is smaller than the current difference
           		diff_month = abs(stoi(years_arr[i].substr(3,2)) - stoi(q.substr(3,2))); //save that value as the new difference
            	idx_month = i; //save the index of the element in the array
        	}
    	}

		//years_arr[idx_month]; // the closest element according to the year and month
		string closest_month = years_arr[idx_month].substr(3,2); //the closest month

		//Go through the array again with the closest month
		string months_arr[n];
		i = 0; //fourth i
		for (int i; i < n; i++) {
			if (years_arr[i].substr(3,2) == closest_month) {
				months_arr[i] = years_arr[i];
			}
		}

		// - If there is only one value, return this element
		int size_months = sizeof(months_arr)/sizeof(months_arr[0]);
		if (size_months == 1) { //if there is only one element, this is the closest of all
			return months_arr[0]; //return the closest date
		}
		else {//If there is more than one value for the same year, compare month between these elements
			int diff_day = abs(stoi(months_arr[0].substr(0,2)) - stoi(q.substr(0,2))); //the difference value starts with the first value of
			//the array minus the value we want to find. The smaller the difference, the closest they are.
			int idx_day = 0; //variable to save the index of the value in the array
			i = 0; //fifth i
   			for (int i; i < size_months; i++) { //for every value in the array
       			if (abs(stoi(months_arr[i].substr(0,2)) - stoi(q.substr(0,2))) < diff_day) { //if the difference between the the element in the list 
				//and the value is smaller than the current difference
           			diff_day = abs(stoi(months_arr[i].substr(0,2)) - stoi(q.substr(0,2))); //save that value as the new difference
            		idx_day = i; //save the index of the element in the array
        		}
    		}
			return months_arr[idx_day]; // the closest element according to the year, month and day

		}

	}

	/*
	// Perform the Binary search to answer the queries
	int l = 0, r = n - 1; //variables for the left and right indexes
	int ind = -1; //variable for the final index that will be returned as the result. Starts
	//with -1, because if there is no modification inside the while loop, it will be the same

	// Iterate until l <= r
	while (l <= r) {
		// Find middle m
		int m = (l + r) / 2;
		
		// Comparator function call
		int c = comp(q, arr[m]); //comp returns true or false
		
		// If comp function returns 0, next closest date is found
		if (c == 0) { //modify to: if c == true, date is the same
			ind = m;
			break;
		}
		
		// If comp function returns less than 0, search in the left half
		else if (c < 0) { //modify to: if c == false, compare year
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

	*/
}

void performQueries(string arr[], string Q[], int k, int n) { //k is the size of Q[]
	for (int i = 0; i < k; i++) {
		string result = nextClosestDate(arr, Q[i],n);
		cout << "The closest date found for the query "<< Q[i]<< " is: " << result << endl;

		/*
		if (result == "-1") {
			cout << "No closest date found for: " << result << endl;
		}
		else {
			cout << "The closest date found for the query "<< Q[i]<< " is: " << result << endl;
		}
		*/

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

	//There is a mistake in the binary search, because the comp function retuns a boolean value,
	//not an integer. So I have to find another way to search in the array (maybe linear search).

	//I could also change the comp function to return an integer instead of a boolean value, but
	//I have to check if the sort function accepts. (cant do that)
}
