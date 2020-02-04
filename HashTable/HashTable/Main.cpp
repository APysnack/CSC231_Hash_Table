/*

Alan Pysnack || J00643490
CSC 231 || Data Structures
11/14/2019

*/

#include <iostream> 
#include <string> 
#include <conio.h>
#include <fstream>
#include "HashTable.h"
#include "WhoopingCrane.h"

using namespace std;

// main variable/function declarations
bool keepGoing = true;
bool showMenu(HashTable&);
void pressAnyKey();
void readBinary(HashTable&);
void writeBinary(HashTable&);
string wordFormat(string&);

int main() {

	HashTable craneList;

	// reads from the binary file pre-loaded with 6 code-created whooping cranes
	readBinary(craneList);
	

	// displays menu until keepGoing is false
	while (keepGoing == true) {
		// showMenu returns a bool value of false to be stored in keepGoing when user opts out
		// passes in an instance of a hash table containing an array of whooping cranes
		keepGoing = showMenu(craneList);
	}

	return 0;
}

// showMenu function that displays the output menu for the user and executes a switch based on user input
bool showMenu(HashTable& craneList) {

	// function variables
	char userInput = 'N';
	bool reprompt = true;
	bool endprogram = false;
	int choice;

	// outputs list with options for user to choose from
	cout << endl
		<< "---------------------------------------------------------------------\n"
		<< " Select an option from the menu below\n"
		<< " by entering the number of the choice\n"
		<< "---------------------------------------------------------------------\n"
		<< "\t1\tAdd a new whooping crane to the list\n"
		<< "\t2\tSearch for a crane by ID number\n"
		<< "\t3\tDisplay all whooping cranes in an area\n"
		<< "\t4\tRemove a whooping crane from the list\n"
		<< "\t5\tDisplay table with all cranes and locations\n"
		<< "\t6\tEnd program\n"
		<< "---------------------------------------------------------------------\n\n"
		<< "Enter your choice : \n\n";

	// switch statement that executes the case matching the user's input
	cin >> choice;
	switch (choice) {

	//******************************************************************************************//
									// Case 1: Add crane to list
	//******************************************************************************************//

	case 1: {
		// declares & initializes variables before user types in their desired input
		int id = 0;
		double age = 0.0;
		string location;
		string gender;
		string name;
		
		// prompts the user to enter data for a new instance of a whooping crane & stores data in the above variables
		cout << "Please enter the details for this crane: " << endl << endl;
		cout << "5-Digit Identification Number: ";
		cin >> id;
		cout << "Age: ";
		cin >> age;
		cout << "Location: ";
		cin >> location; 
		cout << "Gender: ";
		cin >> gender; 
		cout << "Name: ";
		cin >> name;

		location = wordFormat(location);
		gender = wordFormat(gender);
		name = wordFormat(name);

		// passes the user data into the WhoopingCrane constructor to instantiate a new crane
		WhoopingCrane newCrane(id, age, location, gender, name);

		// adds the above crane into the hash table
		craneList.addCrane(newCrane);

		// rewrites binary file with the new addition
		writeBinary(craneList);

		break;
	}
//******************************************************************************************//
						// Case 2: Search for crane by ID number 
//******************************************************************************************//

	case 2: {

		// Stores user input into idNumber and passes the desired idNumber to the findSpecificCrane()
		// function to find and display the crane the user searched for
		int idNumber;
		cout << endl << "Please enter the 5-digit ID number that you'd like to search for: ";
		cin >> idNumber;
	
		craneList.findSpecificCrane(idNumber);

		break;
	}

//******************************************************************************************//
						// Case 3: Display all cranes in an area
//******************************************************************************************//

	case 3: {
		// Stores user input into a location string and passes desired location to the
		// displaySpecificLocation() function to display all cranes in that location

		string location;
		cout << "Please enter the location you would like to search for: ";
		cin >> location;
		location = wordFormat(location);
		craneList.displaySpecificLocation(location);
		break;
	}
//******************************************************************************************//
						// Case 4: Remove a crane from the list
//******************************************************************************************//
	case 4: {
		// Stores user input in craneID then passes the craneID to the removeCrane() function
		int craneID = 0;
		cout << "Please enter the 5-digit ID for the crane you would like to remove from the list: ";
		cin >> craneID;
		craneList.removeCrane(craneID);
		writeBinary(craneList);
		break;
	}
//******************************************************************************************//
					 // Case 5: Display table with all cranes and locations
//******************************************************************************************//

	case 5: {
		// displays all cranes in the hash table
		craneList.displayTable();
		break;
	}
//******************************************************************************************//
							// Case 6: End Program
//******************************************************************************************//
	case 6: {
		// sets program to stop prompting user and terminate
		cout << endl << "Goodbye." << endl;
		endprogram = true;
		break; 
	}
 //******************************************************************************************//
	// handles the exception in case the user input does not match one of the above cases
//******************************************************************************************//
	default: {
		cout << "That option is currently not available\n";
		pressAnyKey();
		break;
	} // end default
	} // end switch

	  // prompts the user asking if they'd like to see the menu again before displaying
	if (!endprogram) {
		cout << endl << "Would you like to see the menu again? Y/N: ";
		cin >> userInput;
	}

	// if user enters 'N' or 'n', the reprompt boolean is set to false and
	// program begins to terminate
	if (userInput == 'N' || userInput == 'n') {
		reprompt = false;
	}

	return reprompt;
}

//******************************************************************************************//
// pauses program until user enters a key
void pressAnyKey() {
	cout << "Press any key to continue " << endl << endl;
	_getch();
}
//******************************************************************************************//

void readBinary(HashTable& craneList) {
	// assigns string value for file name to variable fileName
	string fileName = "Hash.bin";

	// declares input file stream named inputFile
	ifstream inputFile;

	// opens file with fileName as a binary file
	inputFile.open(fileName, ios::binary);

	// executes if file was successfully opened
	if (inputFile.is_open()) {

		// reads all objects in the HashTable list that are listed on the file
		inputFile.read(reinterpret_cast<char*>(&craneList), sizeof(craneList));

		// closes input file
		inputFile.close();
	}

	// throws an exception in case there was an error reading the file
	else {
		cout << "Could not read file " + fileName << endl;
	}
}
//******************************************************************************************//
void writeBinary(HashTable& craneList) {
	// stores the file name in a string variable named fileName
	string fileName = "Hash.bin";

	// declares output file stream named outputFile
	ofstream outputFile;

	// opens binary file with fileName
	outputFile.open(fileName, ios::binary);

	// executes if the file was successfully opened
	if (outputFile.is_open()) {

		// writes each object on the HashTable list into the binary file, casts as a char*
		outputFile.write(reinterpret_cast<char*>(&craneList), sizeof(craneList));

		// closes file
		outputFile.close();
	}

	// throws an exception in case file was not successfully opened
	else {
		cout << "Could not write file " + fileName << endl;
	}
}

string wordFormat(string& word) {
	// if first letter is uppercase, convert to lowercase
	if (word.at(0) >= 97 && word.at(0) <= 122) {
		word.at(0) = (word.at(0) - 32);
	}

	// for all other letters, change to lowercase
	for (int i = 1; i < word.length(); i++) {
		if (word.at(i) >= 65 && word.at(i) <= 90)
		{
			word.at(i) = (word.at(i) + 32);
		}
	}

	return word;
}