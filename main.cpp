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
	int wordCap = 2, wordCount = 0;

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

	//dynamically allocate array of Words 
	Word *wordArr = new Word[wordCap]; 

	while (inFile.get(ch)) {
		if (!ispunct(ch) && !isspace(ch)) {
			amtPunct = 0;
			amtSpace = 0;
			//make lowercase
			lowCh = tolower(ch);
			//add to StuString
			stuStr.addChar(lowCh);
			cout << "stuStr: " << stuStr.toString() << endl;
		}
		else if (ispunct(ch)) {
			amtPunct++;
		}
		else if (isspace(ch)) {
			amtSpace++;
		}

		//only set the word if there has been only 1 space or 1 punctuation
		if ((amtPunct == 1 && amtSpace == 0) || (amtPunct == 0 && amtSpace == 1)) {
			cout << "Length of StuString about to be added to words: " << stuStr.length() << endl;
			wordArr[wordCount].setWord(stuStr);
			wordCount++;
			stuStr.clear();
			str2 = wordArr[wordCount-1].getData();
			cout << endl;
			cout << "Word: " << str2.toString() << endl << endl;
		}

		if (wordCount == wordCap) {
			//temp pointer to Word array so as to not lot as address when need to copy
			Word *temp = wordArr;

			//double word capacity
			wordCap *= 2;

			wordArr = new Word[wordCap];

			//copy values
			for (int i = 0; i < wordCount; i++) {
				wordArr[i] = temp[i];
			}

			delete[] temp;
		}
	}

	//PRINT WORDS TEST -- IT WORKS
	for (int i = 0; i < wordCount; i++) {
		cout << wordArr[i].getWord().toString() << endl;
	}
	cout << endl;
	cout << "DONE." << endl;
	
	//Housekeeping
	inFile.close();

	//HEAP ERROR when I call this. Why??
	//delete[] wordArr; 

	return 0;
}
