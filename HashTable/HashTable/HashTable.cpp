#include <cstdlib>
#include <string>
#include <iostream>
#include "HashTable.h"
#include "WhoopingCrane.h"
#include <fstream>

using namespace std;

//****************************************************************************************//
// Default constructor
//****************************************************************************************//
HashTable::HashTable() {
	
}

//****************************************************************************************//
// Destructor
//****************************************************************************************//
HashTable::~HashTable() {

}

//****************************************************************************************//
// generates an index number N, the object will be stored in the N'th index of the array
//****************************************************************************************//
int HashTable::generateHashIndex(int idNumber) {

	// divides the idNumber by the table size and uses the remainder as the index value
	int index = (idNumber % tableSize);

	// initializes a counter to 0
	int count = 0;

	// checks to see if the index value already contains an element in the array
	while (isOccupied(index)) {
		// implements quadratic probing to search for an empty index value within the array
		index = index + pow(count, 2);
		count++;

		// if the index value is greater than the size of the array, wraps around to the beginning of the array
		if (index > tableSize) {
			index = 0;
		}
	}

	return index;
}

//****************************************************************************************//
// adds a crane to the table
//****************************************************************************************//
void HashTable::addCrane(WhoopingCrane& newCrane)
{	
	// uses the generateHashIndex() function to determine the index the crane should be stored in
	int index = generateHashIndex(newCrane.getCraneID());

	// stores crane in the hash table in the above specified index
	hashArray[index] = newCrane;
}

//****************************************************************************************//
// displays all elements in the index, excludes index values that are empty
//****************************************************************************************//
void HashTable::displayTable() {
	for (int i = 0; i < tableSize; i++) {

		if (hashArray[i].getCraneID() != 0) {
			cout << endl << "ID Number: " << hashArray[i].getCraneID() << endl;
			cout << "Name: " << hashArray[i].getCraneName() << endl;
			cout << "Age: " << hashArray[i].getCraneAge() << endl;
			cout << "Position in Array: " << i << endl;
			cout << "Crane Location: " << hashArray[i].getCraneLocation() << endl;
		}
	}
}

//****************************************************************************************//
// checks to see if the index value is occupied and returns true or false
//****************************************************************************************//
bool HashTable::isOccupied(int index) {
	bool occupied = true;

	// if specified index is empty, return false
	if (hashArray[index].getCraneID() == 0) {
		occupied = false;
	}

	return occupied;
}

//****************************************************************************************//
// finds a specific crane in the table and outputs its information
//****************************************************************************************//
void HashTable::findSpecificCrane(int craneID) {
	// calls the searchTable() function to find the index value the crane is stored in
	int index = searchTable(craneID);

	// searchTable() returns -1 if crane is not found. Informs the user that this ID could not be found
	if (index == -1) {
	
		cout << endl << "The ID Number you entered could not be found." <<
			" Please verify that the number you entered was correct" << endl;
	}

	// if found: outputs the crane's information
	else {
		cout << endl << "This Crane's ID Number: " << hashArray[index].getCraneID() << endl;
		cout << "Name: " << hashArray[index].getCraneName() << endl;
		cout << "Age: " << hashArray[index].getCraneAge() << endl;
		cout << "Location: " << hashArray[index].getCraneLocation() << endl;
		cout << "Gender: " << hashArray[index].getCraneGender() << endl;
	}
} // end findSpecificCrane()

//****************************************************************************************//
// Searches the HashTable for a specified craneID
//****************************************************************************************//
int HashTable::searchTable(int craneID) {
	int index = (craneID % tableSize);
	int count = 0;

	// note: Warning 6385 is a false positive since the size of the index (as defined by the modulus operator) 
	// can never exceed the tableSize. 
	while (hashArray[index].getCraneID() != craneID && index != -1) {

		// count tracks the number of collisions and is raised to the 2nd power through each iteration to perform
		// quadratic probing
		index = index + pow(count, 2);
		count++;

		// wraps around to the beginning (index 0) if the index exceeds the number of total indices in the array
		if (index > tableSize) {
			index = 0;
		}

		// returns -1 if the search is unsuccessful
		if (count > tableSize) {
			index = -1;
		}
	}

	return index;
}
//****************************************************************************************//
//					Displays all cranes at a specific location
//****************************************************************************************//
void HashTable::displaySpecificLocation(string location) {

	bool found = false;

	for (int i = 0; i < tableSize; i++) {

		if (hashArray[i].getCraneID() != 0 && hashArray[i].getCraneLocation() == location) {
			cout << endl << hashArray[i].getCraneID();
			found = true;
		}	
	} // end for loop

	if (!found) {
		cout << endl << "No cranes are listed in this location. " << endl;
	}
}

//****************************************************************************************//
//							Removes Crane from the List
//****************************************************************************************//
void HashTable::removeCrane(int craneID) {
	int index = searchTable(craneID);

	if (index == -1) {
		cout << endl << "This ID Number could not be located" << endl;
	}
	
	else {
		hashArray[index].setCraneID(0);
		hashArray[index].setCraneAge(0.0);
		hashArray[index].setCraneGender(" ");
		hashArray[index].setCraneLocation(" ");

		cout << endl << "Crane has been removed from the list" << endl;
	}
}