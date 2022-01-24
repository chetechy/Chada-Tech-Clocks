/*
 * Clocks.cpp
 *
 * Date: 1/23/2022
 * Author: LaNise Essick
 */

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

//Function to display the time of the system whenever the user wishes.
void displayClock(tm* ltm)
{
	// Compute PM or AM.This is required as by default the format is 24 - hour
	int hour = ltm->tm_hour - 12;
	string meridiem;

	if (hour < 0) { //negative means between 12 midnight and 12 noon(not included)
		meridiem = "AM";
		hour += 12; //increase the number of hours by 12 as now the hour is negative and we add 12 to it.
	}
	else {
		meridiem = "PM"; //it is more than 12 Noon, hence the time will be PM
	}
	if (hour == 0) { //handle the case of 12 Noon, when the 24 hour time is 12:00:00
		hour = 12;
	}
    cout << "***************************\t***************************\n";
	cout << "*      12-Hour Clock      *\t*      24-Hour Clock      *\n";
	cout << "*\t" << hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << " " << meridiem << "\t  *\t*\t" 
		 << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << meridiem << "\t  *\n";
	cout << "***************************\t***************************\n";
}

int main()
{
	// Function declarations
	time_t now = time(0); //create a time object and initialize it to the current time. Returns the time in milliseconds from Jan 1, 1971
	//tm is a struct type used to manipulate the time object and to acces the hour, min and sec separately.
	tm* ltm = localtime(&now);//get local time for local timezone
	displayClock(ltm);//Display the time intially

	//user menu
	int userInput = 0;
	do{
		cout << "\n";
		cout << "***********************" << endl;
		cout << "* 1 - Add One Hour    *" << endl;
		cout << "* 2 - Add One Minute  *" << endl;
		cout << "* 3 - Add One Second  *" << endl;
		cout << "* 4 - Exit Program    *" << endl;
		cout << "***********************" << endl;
		cin >> userInput;
	    // allows the user to enter options 1-4
		if (userInput == 1)
		{
			ltm->tm_hour = (ltm->tm_hour + 1) % 12; //Add one hour to the time object
			cout << "\033[2J\033[1;1H"; //clear the screen before displaying the next time
			displayClock(ltm); //display the time
			cout << "You have successfully added one hour. " << endl;

		}
		else if (userInput == 2)
		{
			ltm->tm_min = (ltm->tm_min + 1) % 60; //Add one minute to the time object
			cout << "\033[2J\033[1;1H"; //clear the screen before displaying the next time
			displayClock(ltm); //display the time
			cout << "You have successfully added one minute. " << endl;
		}
		else if (userInput == 3)
		{
			ltm->tm_sec = (ltm->tm_sec + 1) % 60; //Add one second to the time object
			cout << "\033[2J\033[1;1H"; //clear the screen before displaying the next time
			displayClock(ltm); //display the time
			cout << "You have successfully added one second. " << endl;
		}
		else if (userInput == 4)
			{
			    cout << "Quitting!" << endl;
				exit(0); //exits program
			}
		else
		{
			cout << "Incorrect Choice. Try Again!" << endl; 
		}
		
	} while (userInput != 4);
}





