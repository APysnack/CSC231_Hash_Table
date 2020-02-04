#pragma once

#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

#ifndef WHOOPINGCRANE_H
#define WHOOPINGCRANE_H

class WhoopingCrane {

public:
	// declaration of public functions
	WhoopingCrane();
	WhoopingCrane(int, double, string, string, string);
	~WhoopingCrane();

	// getters
	int getCraneID() const;
	double getCraneAge() const;
	string getCraneLocation() const;
	string getCraneGender() const;
	string getCraneName() const;

	// setters
	void setCraneID(int);
	void setCraneAge(double);
	void setCraneLocation(string);
	void setCraneGender(string);
	void setCraneName(string); 


private:
	// private member variables for each instance of the WhoopingCrane class
	int craneID;
	double craneAge;
	string craneName;
	string craneLocation;
	string craneGender;
};

#endif 

