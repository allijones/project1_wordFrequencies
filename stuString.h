#pragma once
/**
* file: stuString.h
* author: Grant Gasser
* course: CSI 1440
* assignment:  project 1
* due date: 2/1/2017
*
* date modified: 1/27/2017
*       - file created
*
* Dont know yet...
*/

#include "ProfString.h"

class StuString : public ProfString {
public:
	/**
	* compare
	*
	* returns < 0 if object is (alphabetically) less than the parameter 
	* returns 0 if the two objects are same
	* returns > 0 if object is greater than the parameter
	*/
	int compare(StuString &);

	/**
	* length
	*
	* returns the number of characters currently stored in the object
	*/
	int length();

	/**
	* clear
	*
	* removes all characters currently stored in the object 
	* (doesn't require re-allocation of memory)
	*/
	void clear();

	/**
	* addChar
	*
	* appends the parameter to the end of the StuString object
	*/
	void addChar(char);
};
