/** @file IntegerListVector.h written by JP and ES and AL on 28July2015
* @brief This is the header file for the IntegerListVector class. */
#ifndef __INTEGERLISTVECTOR__H__
#define __INTEGERLISTVECTOR__H__

#include <vector>
using namespace std;

/** \brief Integer list that is stored in a Vector.
 *
 *   <h1>Integer %List Vector</h1>
 *   <h2>July 28, 2015
 *   CSC 340 Summer 2015
 *   Team Members: Juris Puchin, Emil Santos, and Alvin Lu.
 *   </h2>
 *   This program implements an integer list container class. Data is stored in a Vector and
 *   can be accessd using Vector member functions. The size of the vector is automatically
 *   adjusted as new elements are added or removed. The table of available mehtods is attached below.
 *
 *  <center>
 *  |   IntegerList    |
 *  |------------------|
 *  | -int *list       |
 *  | -int length      |
 *  | +push(value:int):void|
 *  | +pop():int      |
 *  | +pushEnd(value:int): void|
 *  | +popEnd():int|
 *  | +getLength():int|
 *  | +getElement(element:int):int|
 *  </center>
 */
class IntegerListVector{
private:
	vector<int> *list;
	int length;
public:
	IntegerListVector();
     ~IntegerListVector();
	void push(int value);
	int pop();
	void pushEnd(int value);
	int popEnd();
	int getLength();
	int getElement(int element);
    void sort();
};

#endif



























