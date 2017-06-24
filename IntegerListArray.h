/** @file IntegerListArray.h written by JP and ES and AL on 28July2015
* @brief This is the header file for the IntegerListArray class. */
#ifndef __INTEGERLISTARRAY__H__
#define __INTEGERLISTARRAY__H__

/** \brief Integer list that is stored in an Array.

 *   <h1>Integer %List Array</h1>
 *   <h2>July 28, 2015
 *   CSC 340 Summer 2015
 *   Team Members: Juris Puchin, Emil Santos, and Alvin Lu.
 *   </h2>
 *   This program implements an integer list container class. Data is stored in a dynamic array and
 *   can be accessd from both head or tail (as in Deque). The size of the array is automatically
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
class IntegerListArray{
private:
	int *list;
	int length;
public:
	IntegerListArray();
     ~IntegerListArray();
	void push(int value);
	int pop();
	void pushEnd(int value);
	int popEnd();
	int getLength();
    int getElement(int element);
    void sort();
};

#endif
