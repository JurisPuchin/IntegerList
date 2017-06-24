/**@file written by Alvin Lu and Juris Puchin and Emil Santos on 22July2015
 * @brief This file contains the implementation of IntegerList class using sorted linked list*/

#include "IntegerListSorted.h"
#include "Node.h"
#include "ListExceptions.h"
#include <iostream>
#include <cstdlib>
#include <exception>

using namespace std;

/**
 *  Standard constructor which creates an empty list.
 *
 */
IntegerListSorted::IntegerListSorted()
{
    length = 0;
    head = NULL;
}

/**
 *  Standard destructor which deletes the list and all of its nodes.
 *
 */
IntegerListSorted::~IntegerListSorted()
{
    if(length > 0)
    {
        Node<int>* currentNode = head;
        
        for (int i = 0; i < length; i++)
        {
            Node<int>* tmpNode = currentNode;
            currentNode = currentNode->next;
            delete tmpNode;
        }
    }
}

/**
 *  Inserts the specified integer value into the front of the list.
 *  The length of the list is automatically adjusted to accommodate the new data element.
 *
 *  \param value This integer element will be added to the front of the list.
 */
void IntegerListSorted::insert(int value) {
    
    try{
        if(length < 0){
            emptyListException newException;
            throw newException;
        }
    }
    catch(exception& e){
        cout << "Exception: " << e.what() << endl;
    }
    
    if (length == 0){
        head = new Node<int>();
        head->next = NULL;
        head->value = value;
    }else if (head->value >= value){
        Node<int>* tmp = head;
        head = new Node<int>();
        head->next = tmp;
        head->value = value;
    }else{
        Node<int>* currentNode = head;
        bool insertionComplete = 0;
        for (int i = 0; i < (length - 1); i++){
            
            if (currentNode->next->value >= value){
                //Insert node
    
                try{
                    Node<int>* tmpPointer = currentNode->next;
                    currentNode->next = new Node<int>();
                    currentNode->next->next = tmpPointer;
                    currentNode->next->value = value;
                }catch (exception& e){
                    cout << "Exception: " << e.what() << endl;
                    return;
                }
                insertionComplete = 1;
                break;
  
            }
            
            currentNode = currentNode->next;
        }
        if (!insertionComplete){
            //Insert at end if not inserted already

            Node<int>* tmp = currentNode;
            currentNode = new Node<int>();
            currentNode->next = NULL;
            currentNode->value = value;
            tmp->next = currentNode;
             
        }
    }
    length = length + 1;
}

/**
 *  Removes and returns the integer value at the front of the list.
 *  The list's length is automatically reduced by one.
 *
 *  \returns Integer value removed from the front of the list.
 */
void IntegerListSorted::remove(int index)
{
    try{
        if(index < 0){
            deleteElementException newException;
            throw newException;
        }
    }catch(exception& e){
        cout << "Exception: " << e.what() << endl;
    }
    
    try{
        if(index > length){
            deleteElementException newException;
            throw newException;
        }
    }catch(exception& e){
        cout << "Exception: " << e.what() << endl;
    }
    
    if (index == 0){
        Node<int>* tmpPointer = head;
        head = head->next;

        delete tmpPointer;
    }else{
        Node<int>* currentNode = head;
        for (int i = 0; i < index - 1; i++){
            currentNode = currentNode->next;
        }
        Node<int>* tmpPointer = currentNode->next;

        currentNode->next = (currentNode->next->next);
        delete tmpPointer;
    }
    
    length = length - 1;
}

/**
 *  Returns the number of elements in the list with a given integer value.
 *
 *  \param value Look for this value in the list.
 *  \returns The number of times the given value occurs in the list.
 */
int IntegerListSorted::valueCount(int value)
{
    int answer = 0;
    Node<int>* currentNode = head;
    for (int i = 0; i < length; i++)
    {
        if (currentNode->value == value)
        {
            answer = answer + 1;
        } else if (currentNode->value > value)
        {
            break;
        }
        currentNode = currentNode->next;
    }
    return answer;
}

/**
 *  Finds the first index at which a given value occurs. Returns -1 if not found.
 *
 *  \param value Find this value in the list.
 *  \returns The smallest index at which requested value occurs.
 */
int IntegerListSorted::valueIndex(int value)
{
    int answer = -1;
    Node<int>* currentNode = head;
    for (int i = 0; i < length; i++)
    {
        if (currentNode->value == value)
        {
            answer = i;
            break;
        }
        currentNode = currentNode->next;
    }
    return answer;
}

/**
 *  Returns the current length of the list.
 *
 *  \returns Current list length.
 */
int IntegerListSorted::getLength()
{
    return length;
}

/**
 *  Returns the integer value at the specified location of the list.
 *
 *  \param element The location of the desired element in the list.
 *  \returns The integer value at a specified location of the list.
 */
int IntegerListSorted::getElement(int element)
{
    try
    {
        if(element < 0)
        {
            emptyElementException newException;
            throw newException;
        }
    }
    catch(exception& e)
    {
        cout << "Exception: " << e.what() << endl;
        return 0;
    }
    try
    {
        if(element >= length)
        {
            emptyElementException newException;
            throw newException;
        }
    }
    catch(exception& e)
    {
        cout << "Exception: " << e.what() << endl;
        return 0;
    }
    Node<int>* currentNode = head;
    for (int i = 0; i < element; i++)
    {
        currentNode = currentNode->next;
    }
    int answer = currentNode->value;
    return answer;
}