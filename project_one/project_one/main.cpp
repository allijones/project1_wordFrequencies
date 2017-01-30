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
#include "stuString.h"
#include <iostream>
#include <ctype.h>
#include <fstream>

using namespace std;

int main() {
	ifstream inFile;
	string fileName;
	StuString stuStr, str2;
	Word word;
	char ch;
	char lowCh;
	int amtPunct, amtSpace;

	//Test for file open
	do {
		cout << "Enter Name of File: ";
		cin >> fileName;

		inFile.clear(); 
		inFile.open(fileName.c_str());

		if (!inFile) {
			cout << "Error: File Not Open." << endl;
		}

	} while (!inFile);

	//dynamically allocate array of Words? What size? 
	//Word *word = new Word[]; 

	while (inFile.get(ch)) {
		if (!ispunct(ch) && !isspace(ch)) {
			amtPunct = 0;
			amtSpace = 0;
			//make lowercase
			lowCh = tolower(ch);
			//add to StuString
			stuStr.addChar(lowCh);
			cout << "stuStr: " << stuStr.toString() << endl;
		} else if(ispunct(ch)) {
			amtPunct++;
		} else if(isspace(ch)){
			amtSpace++;
		}

		//only set the word if there has been only 1 space or 1 punctuation
		if ((amtPunct == 1 && amtSpace == 0) || (amtPunct == 0 && amtSpace == 1)) {
			word.setWord(stuStr);
			stuStr.clear();
         str2 = word.getData();
         cout << endl;
         cout << "Word: " << str2.toString() << endl << endl;
		}
	}

   cout << endl;
	cout << "DONE." << endl;
	//Housekeeping
	inFile.close();
	//delete?
	//delete[] word;

	return 0;
}
