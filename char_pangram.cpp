//Missing characters to make a string pangram
//Source code: https://www.geeksforgeeks.org/missing-characters-make-string-pangram/
//Time Complexity: O(n) 
//Auxiliary Space: O(1)


#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26; //a constant with the maximum number of characters

string missingChars(string str) //function to find the missing characters to make a string pangram.
//Receives as paramenters a string, and returns another string with the missing characters.
{
	// A boolean array to store characters
	// present in string.
	bool present[MAX_CHAR] = {false}; //we create a boolean array, each index represent a letter
    //of the alphabet, and each value (true or false) reprsents if the letter is present in the 
    //given string. All values starts with false.

	// Traverse string and mark characters
	// present in string.
	for (int i=0; i<str.length(); i++) //for each index in the given string
	{
		if (str[i] >= 'a' && str[i] <= 'z') //if the value in index i is bigger or equal to a
        //and smaller or equal to z
			present[str[i]-'a'] = true; //mark as true the corresponding letter in the present
            //array
		else if (str[i] >= 'A' && str[i] <= 'Z') //if the value in index i is bigger or equal to
        //A and smaller or equal to Z
			present[str[i]-'A'] = true; //mark as true the corresponding letter in the present
            //array
            //the operation str[i] - 'a' returns a number, which is the result of the subtraction 
            //of the ascii's values from each character. Example: 'b' - 'a' = 98 - 97 = 1
	}

	// Store missing characters in alphabetic
	// order.
	string res = ""; //create string to store the result
	for (int i=0; i<MAX_CHAR; i++) //for each index in the present array
		if (present[i] == false) //if if the value in the index i is marked as false
			res.push_back((char)(i+'a')); //push the corresponding letter to the res string
            //char(i + 'a') will transform the values in ascii in a character. 
            //Example: char(i + 'a') = char(1 + 97) = char(98) = 'b'

	return res; //return the result with the missing characters
}

// Driver program
int main()
{
	string str = "The quick brown fox jumps " //create a string to find the missing characters
				"over the dog";
	cout << missingChars(str); //call the function missingChars and print the result
	return 0;
}	
