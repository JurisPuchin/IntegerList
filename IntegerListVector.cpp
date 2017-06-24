/**@file written by Juris Puchin and Emil Santos on 28July2015
* @brief This file contains the implementation of IntegerList class using vector class*/

#include "IntegerListVector.h"
#include "ListExceptions.h"
#include <cstdlib>
#include <iostream>

using namespace std;

/**
*  Standard constructor which creates an empty list.
*
*/
IntegerListVector::IntegerListVector(){
	length = 0;
	list = new vector<int>();
}

/**
*  Standard destructor which deletes the list and all of its nodes.
*
*/
IntegerListVector::~IntegerListVector(){
	if (length > 0){
		list->erase (list->begin(), list->begin());
	}
}

/**
*  Inserts the specified integer value into the front of the list.
*  The length of the list is automatically adjusted to accommodate the new data element.
*
*  \param value This integer element will be added to the front of the list.
*/
void IntegerListVector::push(int value){
	try {
		if (length < 0){
			negativeLengthException newException;
	 		throw newException;
	 	}
	} catch (exception& e) {
		cout << "Exception: " << e.what() << '\n';
		exit (EXIT_FAILURE);
	}

	vector<int>::iterator firstElement;
	try {
	firstElement = list->begin();
	list->insert(firstElement, value);
	}catch (exception& e) {
		cout << "Exception: " << e.what() << '\n';
	}

	length+=1;
}

/**
*  Removes and returns the integer value at the front of the list.
*  The list's length is automatically reduced by one.
*
*  \returns Integer value removed from the front of the list.
*/
int IntegerListVector::pop(){
	try {
		if (length <= 0){
			listTooShortException newException;
			throw newException;
		}
	} catch (exception& e) {
		cout << "Exception: " << e.what() << '\n';
		exit (EXIT_FAILURE);
	}

	int answer = list->front();
	vector<int>::iterator firstElement;
	firstElement = list->begin();
	list->erase(firstElement);
	length -= 1;
	return answer;
}

/**
*  Inserts an integer value to the back of the list.
*  The length of the list is automatically increased by one.
*
*  \param value This integer value will be inserted into the back of the list.
*/
void IntegerListVector::pushEnd(int value){
	try {
		if (length < 0){
			negativeLengthException newException;
	 		throw newException;
	 	}
	} catch (exception& e) {
		cout << "Exception: " << e.what() << '\n';
		exit (EXIT_FAILURE);
	}

	try{
	list->push_back(value);
	}catch (exception& e) {
		cout << "Exception: " << e.what() << '\n';
	}
	length +=1;
}

/**
*  Removes and returns the element at the end of the list.
*  The list's length is reduced by one.
*  
*  \returns The integer value removed from the tail of the list.
*/
int IntegerListVector::popEnd(){
	try {
		if (length <= 0){
			listTooShortException newException;
			throw newException;
		}
	} catch (exception& e) {
		cout << "Exception: " << e.what() << '\n';
		exit (EXIT_FAILURE);
	}

	int answer = list->back();
	vector<int>::iterator lastElement;
	lastElement = list->end() - 1;
	list->erase(lastElement);
	length -= 1;
	return answer;
}

/**
*  Returns the current length of the list.
*
*  \returns Current list length.
*/
int IntegerListVector::getLength(){
	return length;
}

/**
*  Returns the integer value at the specified location of the list.
*  
*  \param element The location of the desired element in the list.
*  \returns The integer value at a specified location of the list.
*/
int IntegerListVector::getElement(int element){
	try {
		if (element < 0){
			negativeElementException newException;
	 		throw newException;
	 	}
	} catch (exception& e) {
		cout << "Exception: " << e.what() << '\n';
		exit (EXIT_FAILURE);
	}

	try {
		if (element >= length){
			elementOutOfRangeException newException;
	 		throw newException;
	 	}
	} catch (exception& e) {
		cout << "Exception: " << e.what() << '\n';
		exit (EXIT_FAILURE);
	}

	int answer = list->at(element);
	return answer;
}

/**
*  Sorts the list in ascending order using bubble sort.
*/
void IntegerListVector::sort() {
	bool swapped_something = false;
	int unsorted = length - 1;
	if (length > 1) {
		do {
			swapped_something = false;
			for (int i = 0; i < unsorted; i++) {
				if (list->at(i) > list->at(i+1)) {
					//Swap the two elements
					int temp = list->at(i);
					list->at(i) = list->at(i+1);
					list->at(i+1) = temp;
					//Record that a change was made
					swapped_something = true;
				}
			}
			unsorted = unsorted - 1;
		} while (swapped_something);
	}
}