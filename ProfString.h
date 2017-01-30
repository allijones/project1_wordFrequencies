/**
* file: ProfString.h
* author: Prof. Aars
* course: CSI 1440
* assignment:  project 1
* due date: 2/1/2017
*
* date modified: 1/24/2017
*       - file created
*
* ProfString is a dynamically allocated c-string.  It stores a char array that must be terminated with a '\0' and
* an integer that stores the number of slots available to store a char.
*/

#ifndef PROFSTRING_H
#define PROFSTRING_H

#include <string>

using namespace std;

class ProfString {
protected:
	char *data;
	int capacity;

public:
	/**
	* default constructor
	*
	* This function sets the capacity to 2, allocates space for 2 characters, and clears the character array.
	*/
	ProfString();

	/**
	* destructor
	*
	* This function returns memory stored by object back to the heap
	*/
	~ProfString();

	/**
	* overloaded assignment operator
	*
	* This function allows a ProfString object to be assigned the value of another ProfString object.
	*
	* Parameters:
	*      that:  a constant reference to a ProfString object
	*
	*  Output:
	*      return:  a reference to the current ProfString instance
	*/
	ProfString &operator =(const ProfString &that);

	/**
	* toString
	*
	* This fucntion returns a string representation of a ProfString object
	*
	* Output:
	*     return:  a string representation of the current ProfString instance
	*/
	string toString();
};

#endif //WORDCOUNT2_PROFSTRING_H
