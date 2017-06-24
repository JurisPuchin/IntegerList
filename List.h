/** \mainpage
 *   <h1>In Class Project 2</h1>
 *   <h2>July 24, 2015
 *   CSC 340 Summer 2015
 *   Team Members: Alvin Lu, Juris Puchin and Emil Santos.
 *   </h2>
 *   This project implements a number of list container classes.
 *   The Following classes have been implemented: 
 *    <center>
 *  | Class Name  | Description |
 *  |--------------------|--------------|
 *  | IntegerListArray   | Array based implementation. |
 *  | IntegerListLinked  | Linked list based implementation. |
 *  | IntegerListSorted  | Always sorted linked list implementation. |
 *  | IntegerListVector  | Vector based implementation. |
 *  | List               | Link list based template implementation. |
 *  </center>
 *  <h3>1.IntegerListArray: Array based implementation.</h3>
 *  <h3>2.IntegerListLinked: Linked list based implementation. </h3>
 *  <h3>3.IntegerListSorted: Always sorted linked list implementation. </h3>
 *  <h3>4.IntegerListVector: Vector based implementation. </h3>
 *  <h3>5.List: Link list based template implementatino. </h3>
 *
 */


/** @file List.h written by AL and JP and ES on 24July2015
 * @brief This is the header file for the List class. */
#ifndef __LIST__H__
#define __LIST__H__

#include "Node.h"

using namespace std;

/** \brief LinkedList that can accept any object type.
 *
 *   <h1>Template Based %List Class</h1>
 *   <h2>July 24, 2015
 *   CSC 340 Summer 2015
 *   Team Members: Alvin Lu and Juris Puchin and Emil Santos.
 *   </h2>
 *   This is a template list container class. Data is stored in a linked list and
 *   can be accessd from both head or tail (as in Deque). The size of the linked list is automatically
 *   adjusted as new elements are added or removed. The table of available mehtods is attached below.
 *
 *  <center>
 *  |   List    |
 *  |------------------|
 *  | -Node<T>* head       |
 *  | -int length      |
 *  | +push(value:T):void|
 *  | +pop():int      |
 *  | +pushEnd(value:T): void|
 *  | +popEnd():T|
 *  | +getLength():T|
 *  | +getElement(element:int):T|
 *  | +sort():void|
 *  </center>
 */
template <class T>
class List{
private:
	Node<T>* head;
	int length;
public:
	List();
	~List();
	void push(T value);
	T pop();
	void pushEnd(T value);
	T popEnd();
	int getLength();
	T getElement(int element);
	void sort();
};

#include "List.hxx"

#endif
