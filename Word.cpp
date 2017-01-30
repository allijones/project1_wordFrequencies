/**
* file: Word.cpp
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

#include "Word.h"
#include "stuString.h"

Word::Word() {
	frequency = 0;
}

bool Word::incrFrequency(const StuString &stuStr) {
	bool increment = false;

	
	return increment;
}

void Word::setWord(const StuString &stuStr) {
	str = stuStr;
}

//for testing
StuString Word::getWord() {
	return str;
}

void Word::setFrequency(int) {

}

int Word::getFrequency() {
	return frequency;
}

StuString & Word::getData()
{
	return str;
}

//bubble sort
void Word::sortWords() {

}
