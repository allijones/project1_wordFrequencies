/**
* file: main.cpp
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
#include "ProfString.h"
#include "stuString.h"
#include <iostream>
#include <ctype.h>

using namespace std;

int main() {
	StuString str;
	char ch;

	//read in characters
	while (cin.get(ch)) {
		//add character to the StuString array if not punctuation/whitespace
		if (!ispunct(ch) && !isspace(ch)) {
			str.addChar(ch);
		}
	}

	return 0;
}