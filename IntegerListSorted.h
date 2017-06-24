/** @file IntegerListSorted.h written by JP and ES and AL on 28July2015
 * @brief This is the header file for the IntegerListSorted class. */
#ifndef __INTEGERLISTSORTED__H__
#define __INTEGERLISTSORTED__H__

#include "Node.h"

/** \brief Integer list that is always sorted.
 *
 *   <h1>Integer %List Sorted</h1>
 *   <h2>July 28, 2015
 *   CSC 340 Summer 2015
 *   Team Members: Juris Puchin, Emil Santos, and Alvin Lu.
 *   </h2>
 *
 *   This program implements an integer list container class. Data is stored in a 
 *   sorted linked list. The class allows for deletion and insertion of elements, but the list
 *   will remains sorted in ascending order. The size of the lined list is automatically
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

class IntegerListSorted{
private:
    Node<int>* head;
    int length;
public:
    IntegerListSorted();
    ~IntegerListSorted();
    void insert(int value);
    void remove(int index);
    int valueCount(int value);
    int valueIndex(int value);
    int getElement(int element);
    int getLength();
};

#endif