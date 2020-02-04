#pragma once

#include <cstdlib>
#include <string>
#include <iostream>
#include "WhoopingCrane.h"
#include <fstream>

using namespace std;

#ifndef HASHTABLE_H
#define HASHTABLE_H

class HashTable {

public:
	// declares all public functions
	HashTable();
	~HashTable();
	bool isOccupied(int index);
	int generateHashIndex(int idNumber);
	int searchTable(int craneID);
	void addCrane(WhoopingCrane& newCrane);
	void displayTable();
	void findSpecificCrane(int craneID);
	void displaySpecificLocation(string location);
	void removeCrane(int craneID);

private:
	// private member variable that sets the size of the HashTable
	static const int tableSize = 19;

	// declares a hashArray of the above table size which will be used to store all WhoopingCrane objects
	WhoopingCrane hashArray[tableSize];

};

#endif
