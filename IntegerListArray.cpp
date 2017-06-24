/**@file written by Juris Puchin and Emil Santos on 28July2015
* @brief This file contains the implementation of IntegerList class*/

#include "IntegerListArray.h"
#include "ListExceptions.h"
#include <iostream>
#include <cstdlib>

using namespace std;

/**
*  Standard constructor which initializes private variables '*list' and 'length' to null.
*
*/
IntegerListArray::IntegerListArray() {
	length = 0;
	list = 0;
}

/**
*  Standard destructor which deletes the list and all of its nodes.
*
*/
IntegerListArray::~IntegerListArray(){
	delete[] list;
}

/**
*  Inserts the specified integer value into the front of the list.
*  The length of the list is automatically adjusted to accommodate the new data element.
*
*  \param value This integer element will be added to the front of the list.
*/
void IntegerListArray::push(int value){

	try {
		if (!(length >= 0)){
			negativeLengthException newException;
			throw newException;
		}
	} catch (exception& e) {
		cout << "Exception: " << e.what() << '\n';
		exit (EXIT_FAILURE);
	}

	length += 1;
	int *temp_array = new int[length];
	if (length >0){
		for(int i = 1; i < length; i++){
			temp_array[i] = list[i-1];
		}
	}
	delete[] list;
	list = temp_array;
	list[0] = value;
}

/**
*  Removes and returns the integer value at the front of the list.
*  The list's length is automatically reduced by one.
*
*  \returns Integer value removed from the front of the list.
*/
int IntegerListArray::pop(){
	try {
		if (!(length > 0)){
			listTooShortException newException;
			throw newException;
		}
	} catch (exception& e) {
		cout << "Exception: " << e.what() << '\n';
		exit (EXIT_FAILURE);
	}

	try {
		if (!(list[length] >= 0)){
			missingHeadException newException;
	 		throw newException;
	 	}
	} catch (exception& e) {
		cout << "Exception: " << e.what() << '\n';
		exit (EXIT_FAILURE);
	}

	int answer = 0;
	answer = list[0];
	length -= 1;
	int *temp_array = new int[length];
	if(length != 0){
		for(int i = 0; i < length; i++){
			temp_array[i] = list[i+1];
		}
	}
	delete[] list;
	list = temp_array;
	return answer;
}

/**
*  Inserts an integer value to the back of the list.
*  The length of the list is automatically increased by one.
*
*  \param value This integer value will be inserted into the back of the list.
*/
void IntegerListArray::pushEnd(int value){

	try {
		if (!(length >= 0)){
			negativeLengthException newException;
	 		throw newException;
	 	}
	} catch (exception& e) {
		cout << "Exception: " << e.what() << '\n';
		exit (EXIT_FAILURE);
	}

	length += 1;
	int *temp_array = new int[length];
	if(length > 0){
		for(int i = 0; i < length - 1; i++){
			temp_array[i] = list[i];
		}
	}
	delete[] list;
	list = temp_array;
	list[length-1] = value;
}

/**
*  Removes and returns the element at the end of the list.
*  The list's length is reduced by one.
*  
*  \returns The integer value removed from the tail of the list.
*/
int IntegerListArray::popEnd(){
	try {
		if (!(length > 0)){
			listTooShortException newException;
			throw newException;
		}
	} catch (exception& e) {
		cout << "Exception: " << e.what() << '\n';
		exit (EXIT_FAILURE);
	}

	try {
		if (!(list[length] >= 0)){
			missingTailException newException;
	 		throw newException;
	 	}
	} catch (exception& e) {
		cout << "Exception: " << e.what() << '\n';
		exit (EXIT_FAILURE);
	}

	int answer = 0;
	length -= 1;
	answer = list[length];
	int *temp_array = new int[length];
	if(length != 0){
		for(int i = 0; i < length; i++){
			temp_array[i] = list[i];
		}
	}
	delete[] list;
	list = temp_array;
	return answer;
}

/**
*  Returns the current length of the list.
*
*  \returns Current list length.
*/
int IntegerListArray::getLength(){
	return length;
}

/**
*  Returns the integer value at the specified location of the list.
*  
*  \param element The location of the desired element in the list.
*  \returns The integer value at a specified location of the list.
*/
int IntegerListArray::getElement(int element){
	try {
		if (!(element >= 0)){
			negativeElementException newException;
	 		throw newException;
	 	}
	} catch (exception& e) {
		cout << "Exception: " << e.what() << '\n';
		exit (EXIT_FAILURE);
	}

	try {
		if (!(element <= length)){
			elementOutOfRangeException newException;
	 		throw newException;
	 	}
	} catch (exception& e) {
		cout << "Exception: " << e.what() << '\n';
		exit (EXIT_FAILURE);
	}
	return list[element];
}

/**
*  Sorts the list in ascending order using bubble sort.
*/
void IntegerListArray::sort(){
	bool swapped_something = false;
	int unsorted = length - 1;
	if (length > 1) {
		do {
			swapped_something = false;
			for (int i = 0; i < unsorted; i++) {
				if (list[i] > list[i+1]) {
					//Swap the two elements
					int temp = list[i];
					list[i] = list[i+1];
					list[i+1] = temp;
					//Record that a change was made
					swapped_something = true;
				}
			}
			unsorted = unsorted - 1;
		} while (swapped_something);
	}	
}












