/**
* file: stuString.cpp
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
#include <iostream>

//doesn't allow call to str unless I take away the const
int StuString::compare(StuString &str) {
   int val = 0;
   int i = 0;
   int dif = 0;
   bool done = false;

   while (!done && i < this->length() && i < str.length()) {
      if (this->data[i] < str.data[i]) {
         val = this->data[i] - str.data[i];
         done = true;
      }
      else if (this->data[i] > str.data[i]) {
         val = this->data[i] - str.data[i];
         done = true;
      }
      i++;
   }

   return val;
}

int StuString::length() {
   int count = 0;

   while (data[count] != '\0') {
      count++;
   }

   return count;
}

//clears StuString for the next string/word
void StuString::clear() {
   data[0] = '\0';
}

//need to dynamically resize in here
void StuString::addChar(char c) {
   //to clean up code in rest of function
   int length = this->length();
   int oldCap = this->capacity;
   //cout << "Length: " << length << endl;
   //cout << "Cap: " << oldCap << endl;

   //double capacity
   if (length + 1 == oldCap) {
      //temporary pointer so as not to lose address of init array when copying
      char *temp = data;

      //double capacity of char array
      this->capacity *= 2;
      data = new char[this->capacity];

      //copy values of old array into new array
      for (int i = 0; i < oldCap; i++) {
         data[i] = temp[i];
      }

      delete[] temp;
   }

   //add the character and null after it
   data[length] = c;
   data[length + 1] = '\0';
}
