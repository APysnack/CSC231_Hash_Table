#include "WhoopingCrane.h"
#include <string>

// default constructor for WhoopingCrane class
WhoopingCrane::WhoopingCrane() {
	craneAge = 0.0;
	craneID = 00000;
}

// destructor
WhoopingCrane::~WhoopingCrane() {

}


// overloaded constructor that receives user values to assign as member data
WhoopingCrane::WhoopingCrane(int ID, double age, string location, string gender, string name) {
	craneID = ID;
	craneAge = age;
	craneLocation = location;
	craneGender = gender;
	craneName = name;

}

// basic accessor function 
string WhoopingCrane::getCraneName() const {
	return craneName;
}

// basic accessor function 
int WhoopingCrane::getCraneID() const {
	return craneID;
}

// basic accessor function 
double WhoopingCrane::getCraneAge() const {
	return craneAge;
}

// basic accessor function 
string WhoopingCrane::getCraneLocation() const {
	return craneLocation;
}

// basic accessor function 
string WhoopingCrane::getCraneGender() const {
	return craneGender;
}

// basic mutator function 
void WhoopingCrane::setCraneID(int ID) {
	craneID = ID;
}

// basic mutator function 
void WhoopingCrane::setCraneAge(double age) {
	craneAge = age;
}

// basic mutator function 
void WhoopingCrane::setCraneLocation(string location) {
	craneLocation = location;
}

// basic mutator function 
void WhoopingCrane::setCraneGender(string gender) {
	craneGender = gender;
}

// basic mutator function 
void WhoopingCrane::setCraneName(string name) {
	craneName = name;
}