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
* The driver for the Word, ProfString, and Student classes.
* The program reads a set of characters from stdin and returns the 
* words in alphabetical order and their frequency, ignoring whitespace 
* and punctuation
*/

#include "Word.h"
#include "stuString.h"
#include <iostream>
#include <ctype.h>
#include <iomanip>
#include <fstream>

using namespace std;

int main() {
   StuString stuStr, str2;
   Word word, tempWord;
   char ch;
   char lowCh;
   int amtPunct, amtSpace;
   int wordCap = 2, wordCount = 0, amtWords = 0;
   bool empty = false;

   //dynamically allocate array of Words 
   Word *wordArr = new Word[wordCap];

   //read in character by character
   while (cin.get(ch)) {
      if (!ispunct(ch) && !isspace(ch)) {
         amtPunct = 0;
         amtSpace = 0;
         //make lowercase
         lowCh = tolower(ch);
         //add to StuString
         stuStr.addChar(lowCh);
      }
      else if (ispunct(ch)) {
         amtPunct++;
      }
      else if (isspace(ch)) {
         amtSpace++;
      }

      //only set the word if there has been only 1 space or 1 punctuation or 1 digit
      if (amtSpace == 1) {
         wordArr[wordCount].setWord(stuStr);
         wordCount++;
         stuStr.clear();
         str2 = wordArr[wordCount - 1].getData();
      }

      //dbl size of Word array here, using a temporary pointer to retain address
      if (wordCount == wordCap) {
         Word *temp = wordArr;

         //double word capacity
         wordCap *= 2;

         wordArr = new Word[wordCap];

         //copy values
         for (int i = 0; i < wordCount; i++) {
            wordArr[i] = temp[i];
         }

         //return memory to HEAP
         delete[] temp;
      }
   }

   //Find the frequencies here if we have matching words, use compare to tell
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
         if (wordArr[j].getData().compare(wordArr[j+1].getData()) > 0) {
            //swap words
            //store freq. and StuString of jth object in tempWord
            tempWord.setFrequency(wordArr[j].getFrequency());
            tempWord.setWord(wordArr[j].getData());

            //replace jth object data with jth+1 object data
            wordArr[j].setFrequency(wordArr[j + 1].getFrequency());
            wordArr[j].setWord(wordArr[j + 1].getData());

            //replace jth+1 object data with tempWord object data (jth obj data)
            wordArr[j + 1].setFrequency(tempWord.getFrequency());
            wordArr[j + 1].setWord(tempWord.getData());
         }
      }
   }

   //print words, making sure not to print same word twice
   for (int i = 0; i < wordCount; i++) {
      //print first word because it can't be a duplicate
      if (i == 0) {
         cout << setw(15) << left << wordArr[i].getData().toString() << right << wordArr[i].getFrequency() << endl;
         amtWords = wordArr[i].getFrequency();
      } else if(wordArr[i].getData().compare(wordArr[i - 1].getData()) != 0) {
         //only printing if word has not been printed already
         cout << setw(15) << left << wordArr[i].getData().toString() << right << wordArr[i].getFrequency() << endl;
         amtWords = wordArr[i].getFrequency();
      }
   }

   cout << endl;
   cout << "array size: " << wordCap << endl;

   return 0;
}
