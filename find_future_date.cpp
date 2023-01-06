//Queries to find the future closest date
//Source code: https://www.geeksforgeeks.org/queries-to-find-the-future-closest-date/
//Time Complexity: O((N*log N) + (Q*log N)) 
//Auxiliary Space: O(1)


#include <bits/stdc++.h>

using namespace std;

vector<string> tokenize(string s, string del)
{
	vector<string> res;
	int start, end = -1 * del.size();
	do {
		start = end + del.size();
		end = s.find(del, start);
		res.push_back(s.substr(start, end - start));
	} while (end != -1);
	return res;
}

// Comparator function to compare
// the two dates
int comp(string s, string t)
{

	// Split the dates strings
	// when a "/" found
	vector<string> ss = tokenize(s, "/");
	vector<string> tt = tokenize(t, "/");

	int date1[3];
	int date2[3];

	// Store the dates in form
	// of arrays
	for (int i = 0; i < 3; i++) {
		date1[i] = stoi(ss[i]);
		date2[i] = stoi(tt[i]);
	}

	// If years are not same
	if (date1[2] != date2[2]) {
		return date1[2] - date2[2];
	}

	// If months are not same
	else if (date1[1] != date2[1]) {
		return date1[1] - date2[1];
	}

	// If days are not same
	else if (date1[0] != date2[0]) {
		return date1[0] - date2[0];
	}

	// If two date is same
	return 0;
}

// Function to print the next
// closest date
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
	for (int i = 0; i < Q.size(); i++) {

		// Function Call
		cout << nextClosestDate(arr, Q[i]) << endl;
	}
}

// Driver Code
int main()
{
	// Given array of dates
	vector<string> arr = { "22/4/1233", "1/3/633",
						"23/5/56645", "4/12/233" };

	// Given Queries
	vector<string> Q
		= { "23/3/4345", "4/4/34234234", "12/3/2" };

	// Function Call
	performQueries(arr, Q);
}



