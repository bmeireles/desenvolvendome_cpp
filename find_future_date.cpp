//Queries to find the future closest date
//Source code: https://www.geeksforgeeks.org/queries-to-find-the-future-closest-date/
//Time Complexity: O((N*log N) + (Q*log N)) 
//Auxiliary Space: O(1)


#include <bits/stdc++.h>

using namespace std;

vector<string> tokenize(string s, string del) //function to separate a string s by the delimiter del. Receives
//as inputs the string s and the delimiter. Returns a vector with all the new strings.
{
	vector<string> res; //create a vector of strings to save the result
	int start, end = -1 * del.size(); //declares variables for the start and the end of the string. End is initialized
	//with 
	do { //starts a do-while loop, which will continue to execute the code inside the loop until the condition 
	//in the while is false
		start = end + del.size(); //start variable receives the value of end plus the size of the delimiter
		end = s.find(del, start); //uses the find method to locate the position of the delimiter in the input 
		//string, starting from the index start. The value of "end" is set to the index of the first occurrence
		// of the delimiter in the input string.
		res.push_back(s.substr(start, end - start)); //uses the substring method to extract the substrings from
		//the input string, between the delimiter position. The method push_back is used to add the substrings
		//to the vector res.
	} while (end != -1); //the loop will continue as long as the value of end is not -1, which means the delimiter
	//was found in the input string
	return res; //return the vector with the substrings
}

// Comparator function to compare the two dates
int comp(string s, string t) //function to compare 2 dates, receives as parameters a string with a date s
//and another string t with a date. Returns 0 if the dates are the same, and if they are different,
//returns the difference in years, months or days.
{

	// Split the dates strings when a "/" found
	vector<string> ss = tokenize(s, "/"); //ss is a vector of substrings from s, which were separated by /
	vector<string> tt = tokenize(t, "/"); //tt is a vector of substrings from t, which were separated by /

	int date1[3]; //declare a list to save the date 1
	int date2[3]; //declare a list to save the date 2
	//index 0: day
	//index 1: month
	//index 2: year

	// Store the dates in form of arrays
	for (int i = 0; i < 3; i++) { //for every index in the arrays of dates
		date1[i] = stoi(ss[i]); //the index i in date1 receives the value from ss, transforming
		// the string to a integer
		date2[i] = stoi(tt[i]); //the index i in date2 receives the value from tt, transforming
		// the string to a integer
	}

	// If years are not same
	if (date1[2] != date2[2]) { //if year in date1 is different from year in date2
		return date1[2] - date2[2]; //return the difference between the 2 years
	}

	// If months are not same
	else if (date1[1] != date2[1]) { //if month in date1 is different from month in date2
		return date1[1] - date2[1]; //return the difference between the 2 months
	}

	// If days are not same
	else if (date1[0] != date2[0]) { //if day in date1 is differennt from day in date2
		return date1[0] - date2[0]; //return the difference between the 2 days
	}

	// If the two dates are the same, return 0
	return 0; 
}

// Function to print the next closest date
string nextClosestDate(vector<string> arr, string q)
{
	// Sort date array
	sort(arr.begin(), arr.end(), comp);

	// Perform the Binary search
	// to answer the queries
	int l = 0, r = arr.size() - 1;
	int ind = -1;

	// Iterate until l <= r
	while (l <= r) {

		// Find mid m
		int m = (l + r) / 2;

		// Comparator function call
		int c = comp(q, arr[m]);

		// If comp function return 0
		// next closest date is found
		if (c == 0) {
			ind = m;
			break;
		}

		// If comp function return
		// less than 0, search in
		// the left half
		else if (c < 0) {
			r = m - 1;
			ind = m;
		}

		// If comp function return
		// greater than 0, search
		// in the right half
		else {
			l = m + 1;
		}
	}

	// Return the result
	if (ind == -1) {
		return "-1";
	}
	else {
		return arr[ind];
	}
}

void performQueries(vector<string> arr, vector<string> Q)
{
	// Traverse the queries of date
	for (int i = 0; i < Q.size(); i++) { //for every querie in Q

		// Function Call
		cout << nextClosestDate(arr, Q[i]) << endl; //call the function to find the closest date of Q[i] in the array
		//arr[]
	}
}

// Driver Code
int main()
{
	// Given array of dates
	vector<string> arr = { "22/4/1233", "1/3/633",
						"23/5/56645", "4/12/233" }; //declare a vector of strings with the dates

	// Given Queries
	vector<string> Q
		= { "23/3/4345", "4/4/34234234", "12/3/2" }; //vector of strings with queries

	// Function Call
	performQueries(arr, Q); //call the function with the parameters
}



