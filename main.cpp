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
#include <iomanip>

using namespace std;

int main() {
	ifstream inFile;
	string fileName;
	StuString stuStr, str2;
	Word word, tempWord;
	char ch;
	char lowCh;
	int amtPunct, amtSpace, amtDigit;
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
		if (!ispunct(ch) && !isspace(ch) && !isdigit(ch)) {
			amtPunct = 0;
			amtSpace = 0;
			amtDigit = 0;
			//make lowercase
			lowCh = tolower(ch);
			//add to StuString
			stuStr.addChar(lowCh);
			//cout << "stuStr: " << stuStr.toString() << endl;
		}
		else if (ispunct(ch)) {
			amtPunct++;
		}
		else if (isspace(ch)) {
			amtSpace++;
		}
		else if (isdigit(ch)) {
			amtDigit++;
		}

		//only set the word if there has been only 1 space or 1 punctuation or 1 digit
		if ((amtPunct == 1 && amtSpace == 0 && amtDigit == 0) || 
			(amtPunct == 0 && amtSpace == 1 && amtDigit == 0) ||
			(amtPunct == 0 && amtSpace == 0 && amtDigit == 1)) {
				wordArr[wordCount].setWord(stuStr);
				wordCount++;
				stuStr.clear();
				str2 = wordArr[wordCount-1].getData();
				//cout << endl;
				/*cout << "Word: " << str2.toString() << endl << endl;

				cout << "wordArr[wordCount-1].getData(): " << wordArr[wordCount-1].getData().toString() << endl;
				cout << "Should get zeros:  " << str2.compare(wordArr[wordCount-1].getData()) << endl;*/
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

	//FIND FREQUENCIES HERE
	//passes
	for (int i = 0; i < wordCount; i++) {
		for (int j = i + 1; j < wordCount; j++) {
			if (wordArr[i].getData().compare(wordArr[j].getData()) == 0) {
				wordArr[i].incrFrequency(wordArr[i].getData());
				wordArr[j].incrFrequency(wordArr[j].getData());
			}
		}
	}

	//Sort the words here
	for (int pass = 1; pass < wordCount; pass++) {
		for (int j = 0; j < wordCount - pass; j++) {
			if (wordArr[pass].getData().compare(wordArr[j].getData())) {
				//swap words
				//store freq. and str of object in tempWord
				tempWord.setFrequency(wordArr[j].getFrequency());
				tempWord.setWord(wordArr[j].getData());

				//replace pass object data with j object data
				wordArr[j].setFrequency(wordArr[j+1].getFrequency());
				wordArr[j].setWord(wordArr[j+1].getData());

				//replace j object data with tempWord object data (pass obj data)
				wordArr[j+1].setFrequency(tempWord.getFrequency());
				wordArr[j+1].setWord(tempWord.getData());
			}
		}
	}

	//PRINT WORDS TEST -- IT WORKS
	for (int i = 0; i < wordCount; i++) {
		cout << setw(15) << left << wordArr[i].getWord().toString() << right << wordArr[i].getFrequency() << endl;
	}
	
	//Housekeeping
	inFile.close();

	//HEAP ERROR when I call this. Why??
	//delete[] wordArr; 

	return 0;
}
