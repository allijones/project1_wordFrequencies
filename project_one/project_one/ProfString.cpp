/**
* file: ProfString.cpp
* author: Prof. Aars
* course: CSI 1440
* assignment:  project 1
* due date:  2/1/2017
*
* date modified:  1/24/2017
*      - file created
*
* This file contains the implementation of the ProfString class
*/

#include <string>
#include <sstream>
#include "ProfString.h"

using namespace std;

ProfString::ProfString() {
	// sets the initial value of capacity to indicate the there is enough space to store 2 chars
	this->capacity = 2;

	// allocates enough memory to store 2 chars
	data = new char[2];

	// clears the contents of the memory allocated in the previous statement
	data[0] = '\0';
}

ProfString::~ProfString() {
	// returns the memory to the heap when an instance of a ProfString goes out of scope
	delete[] data;
}

ProfString &ProfString::operator =(const ProfString & that) {
	// make sure that the two objects are not the exact same object
	if (this != &that) {
		// declare an integer for iteration through the data arrays
		// must be used to assign the '\0' to the end so it's declared outside of the for loop
		int i = 0;

		// return memory previously allocated back to the heap
		delete[] this->data;


		// assign all values from that to this
		this->capacity = that.capacity;
		this->data = new char[this->capacity];
		for (i = 0; that.data[i] != '\0'; i++) {
			this->data[i] = that.data[i];
		}
		// make sure to store the '\0'
		this->data[i] = '\0';
	}
	//return a reference to the current ProfString instance
	return *this;
}


string ProfString::toString() {
	// instantiates an instance of an output string stream
	ostringstream out;

	// write the data to the stringstream just like any other stream
	// relying on the \0 to print out our char* which is treated differently from other pointers only because
	// it can be used to store c-strings
	out << data;

	// converts the ostringstream to a string and returns a copy of the string
	return out.str();
}

