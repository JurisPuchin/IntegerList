/** @file IntegerListLinked.h written by JP and ES and AL on 28July2015
 * @brief This is the header file for the IntegerListLinked class. */
#ifndef __INTEGERLISTLINKED__H__
#define __INTEGERLISTLINKED__H__

#include "Node.h"

/** \brief Integer list that is stored in a Linked %List.
 *
 *   <h1>Integer %List Linked</h1>
 *   <h2>July 28, 2015
 *   CSC 340 Summer 2015
 *   Team Members: Juris Puchin, Emil Santos, and Alvin Lu.
 *   </h2>
 *   This program implements an integer list container class. Data is stored in a linked list and
 *   can be accessd the head. The size of the array is automatically
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

class IntegerListLinked
{
    private:
        Node<int>* head;
        int length;
    public:
        IntegerListLinked();
        ~IntegerListLinked();
        void push(int value);
        int pop();
        void pushEnd(int value);
        int popEnd();
        int getLength();
        int getElement(int element);
        void sort();
};

#endif
