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
	frequency = 1;
}

void Word::incrFrequency(StuString &stuStr) {
	frequency++;
}

void Word::setWord(const StuString &stuStr) {
	str = stuStr;
}

void Word::setFrequency(int f) {
	frequency = f;
}

int Word::getFrequency() {
	return frequency;
}

StuString & Word::getData()
{
	return str;
}
