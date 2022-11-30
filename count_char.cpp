//Count uppercase, lowercase, special character and numeric values
//Source code: https://www.geeksforgeeks.org/count-uppercase-lowercase-special-character-numeric-values/
//Time Complexity: O(N), where N is the string length
//Auxiliary Space: O(1)


#include<iostream>
using namespace std;

// Function to count uppercase, lowercase,
// special characters and numbers
void Count(string str) //function to count uppercase, lowercase, special characters and numbers
//in a string. Receives as parameters a single string.
{
	int upper = 0, lower = 0, number = 0, special = 0; //create variable to store the counting
    //of lowercase, uppercase, numbers and special chars, all starting with zero.

	for (int i = 0; i < str.length(); i++) //for every index in the string
	{
		if (str[i] >= 'A' && str[i] <= 'Z') //if the ascii of the value in index i is bigger or
        //equal to 'A'(65) and smaller or equal to 'Z'(90)
			upper++; //add 1 to the counting of uppercase characters
		else if (str[i] >= 'a' && str[i] <= 'z') //if the ascii of the value in index i is bigger or
        //equal to 'a'(97) and smaller or equal to 'z'(122)
			lower++; //add 1 to the counting of lowercase characters
		else if (str[i]>= '0' && str[i]<= '9') //if the ascii of the value in index i is bigger or
        //equal to '0'(48) and smaller or equal to '9'(57)
			number++; //add 1 to the counting of number
		else //if none of the above is true, it can only be a special character
			special++; //add 1 to the counting of special characters
	}
	cout << "Upper case letters: " << upper << endl; //print the total of uppercase characters
	cout << "Lower case letters : " << lower << endl; //print the total lowercase characters
	cout << "Number : " << number << endl; //print the total of numbers
	cout << "Special characters : " << special << endl; //print the total of special characters
}

// Driver function
int main()
{
	string str = "#GeeKs01fOr@gEEks07"; //create a string 
	Count(str); //call the function Count with the string as a parameter
	return 0;
}
