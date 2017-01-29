/**
* file: Word.h
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

#ifndef WORD_H
#define WORD_H

#include "stuString.h"
#include <string>

using namespace std;

class Word {
private:
	StuString str;
	int frequency;
public:
	/**
	* default constructor
	*
	* Sets all member variables to appropriate values
	*/
	Word();

	/**
	* incrFrequency
	*
	* determines if the frequency should be updated and updates if necessary.
	*    returns true if frequency is updated and false otherwise
	*/
	bool incrFrequency(const StuString &);

	/**
	* setWord
	*
	* assignes the value of the parameter to the value of the data of the object
	*    that called the function
	*/
	void setWord(const StuString &);

	/**
	* setFrequency
	*
	* assigns the frequency to the value of the parameter
	*/
	void setFrequency(int);

	/**
	* getFrequency
	*
	* returns a copy of the frequency
	*/
	int getFrequency();

	/**
	* getData
	*
	* returns a reference to data
	*/
	StuString &getData();
};

#endif //WORD_H
