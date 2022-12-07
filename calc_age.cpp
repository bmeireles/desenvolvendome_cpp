//Program to calculate age
//Source code: https://www.geeksforgeeks.org/program-calculate-age/
//Time Complexity: O(1)
//Auxiliary Space: O(1)


#include <stdio.h>
#include <stdlib.h>

// function to calculate current age
void findAge(int current_date, int current_month, int current_year, int birth_date,int birth_month,
 int birth_year) //function to calculate the current age. Receives as parameters the current date,
 //month and year, and birthdate, month and year
{
	// days of every month, from january to december
	int month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	// if birth date is greater than current date, then do not count this month and add 30
	// to the date so as to subtract the date and get the remaining days
	if (birth_date > current_date) { //if birth date is greater than current date
		current_date = current_date + month[birth_month - 1]; //current date becomes the current
        //value, plus the number of days in the birth month
		current_month = current_month - 1; //remove 1 from the current month
	}

	// if birth month exceeds current month, then do not count this year and add 12 to the month so
	// that we can subtract and find out the difference
	if (birth_month > current_month) { //if birthmonth is greater than current month
		current_year = current_year - 1; //remove 1 from the current year
		current_month = current_month + 12; //current month becomes the current value plus 12 (the
        //number of subsequent months)
	}

	// calculate date, month, year
	int calculated_date = current_date - birth_date; 
	int calculated_month = current_month - birth_month;
	int calculated_year = current_year - birth_year;

	// print the present age
	printf("Present Age\nYears: %d Months: %d Days:"
		" %d\n",
		calculated_year, calculated_month,
		calculated_date);
}

// driver code to check the above function
int main()
{
	// current dd// mm/yyyy //initialize variables for the current date, month and year
	int current_date = 7;
	int current_month = 12;
	int current_year = 2017;

	// birth dd// mm// yyyy //initialize variables for the birthdate, month and year
	int birth_date = 16;
	int birth_month = 12;
	int birth_year = 2009;

	// function call to print age
	findAge(current_date, current_month, current_year,
			birth_date, birth_month, birth_year); //call function to calculate the age
	return 0;
}
