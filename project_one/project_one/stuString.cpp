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

#include "stuString.h"

int StuString::compare(const StuString &str){
	int val;

	
	return val;
}

int StuString::length(){
	int count = 0;

	while (data[count] != '\0') {
		count++;
	}

	return count;
}

void StuString::clear(){
	data[0] = '\0';
}

void StuString::addChar(char c){
	data[this->length + 1] = c;
}
