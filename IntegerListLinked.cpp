/**@file written by Alvin Lu and Juris Puchin and Emil Santos on 22July2015
 * @brief This file contains the implementation of IntegerList class using linkedlist class*/

#include "IntegerListLinked.h"
#include "Node.h"
#include "ListExceptions.h"
#include <iostream>
#include <cstdlib>
using namespace std;

/**
 *  Standard constructor which creates an empty list.
 *
 */
IntegerListLinked::IntegerListLinked()
{
    length = 0;
    head = NULL;
}

/**
 *  Standard destructor which deletes the list and all of its nodes.
 *
 */
IntegerListLinked::~IntegerListLinked()
{
    if (length > 0)
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
void IntegerListLinked::push(int value)
{
    //checks if length is valid by making sure it is not equal or less than zero.
    try {
        if (length < 0){
            negativeLengthException newException;
            //throw negativeLengthException;
        	throw newException;
        }
    }
    catch (exception& e)
    {
        cout << "Exception: " << e.what() << '\n';
        exit(EXIT_FAILURE);
    }
    
    //if length is 0, the creation of the first node is instantiated
    if (length == 0)
    {
        try
        {
            head = new Node<int>();
            head->next = NULL;
            head->value = value;
        }
        catch (exception& e)
        {
            cout << "Exception: " << e.what() << '\n';
            exit(EXIT_FAILURE);
        }
    }
    //the value into a new instantiated node that pointers to the previous first node.
    else
    {
        try
        {
            Node<int>* tmp = head;
            head = new Node<int>();
            head->next = tmp;
            head->value = value;
        }
        catch (exception& e)
        {
            cout << "Exception: " << e.what() << '\n';
            exit(EXIT_FAILURE);
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
int IntegerListLinked::pop()
{
    try {
        if (length <= 0){
            listTooShortException newException;
            //throw listTooShortException;
            throw newException;
        }
    }
    catch (exception& e)
    {
        cout << "Exception: " << e.what() << '\n';
        exit(EXIT_FAILURE);
    }
    
    try {
        if (head == NULL){
            missingHeadException newException;
            //throw missingHeadException;
            throw newException;
        }
    }
    catch (exception& e)
    {
        cout << "Exception: " << e.what() << '\n';
        exit(EXIT_FAILURE);
    }
    
    int answer = head->value;
    Node<int>* tmpPointer = head;
    head = head->next;
    delete tmpPointer;
    
    length = length - 1;
    
    return answer;
}

/**
 *  Inserts an integer value to the back of the list.
 *  The length of the list is automatically increased by one.
 *
 *  \param value This integer value will be inserted into the back of the list.
 */
void IntegerListLinked::pushEnd(int value)
{
    try
    {
        if (length < 0){
            // if the length is less than zero, throw exception.
            negativeLengthException newException;
            //throw negativeLengthException;
            throw newException;
        }
    }
    catch (exception& e)
    {
        cout << "Exception: " << e.what() << '\n';
        exit(EXIT_FAILURE);
    }
    if (length == 0)
    {
        try
        {
            head = new Node<int>();
            head->next = NULL;
            head->value = value;
        } catch (exception& e)
        {
            cout << "Exception: " << e.what() << '\n';
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        try {
            Node<int>* currentNode = head;
            
            for(int i = 0; i < length - 1; i++){
                currentNode = currentNode->next;
            }
            
            Node<int>* tmpNode = new Node<int>();
            tmpNode->next = currentNode->next;
            tmpNode->value = value;
            currentNode->next = tmpNode;
        }
        catch (exception& e)
        {
            cout << "Exception: " << e.what() << '\n';
            exit(EXIT_FAILURE);
 
        }
        //tail = tail->next;
    }
    length = length + 1;
}

/**
 *  Removes and returns the element at the end of the list.
 *  The list's length is reduced by one.
 *
 *  \returns The integer value removed from the tail of the list.
 */
int IntegerListLinked::popEnd()
{
    try
    {
        if (length <= 0){
            listTooShortException newException;
            //throw listTooShortException;
            throw newException;
        }
    }
    catch (exception& e)
    {
        cout << "Exception: " << e.what() << '\n';
        exit(EXIT_FAILURE);
    }
        Node<int>* currentNode = head;
    
    for(int i = 0; i < length - 2; i++){
        currentNode = currentNode->next;
    }
    Node<int>* tmpNode = currentNode->next;
    currentNode->next = currentNode->next->next;
    int answer = tmpNode->value;
    delete tmpNode;
    length = length - 1;
    if (length == 0)
    {
        head = NULL;
    }
    return answer;
}

/**
 *  Returns the current length of the list.
 *
 *  \returns Current list length.
 */
int IntegerListLinked::getLength()
{
    return length;
}

/**
 *  Returns the integer value at the specified location of the list.
 *
 *  \param element The location of the desired element in the list.
 *  \returns The integer value at a specified location of the list.
 */
int IntegerListLinked::getElement(int element)
{
    try
    {
        if (element < 0){
            negativeElementException newException;
            //throw negativeElementException;
            throw newException;
        }
    }
    
    catch (exception& e)
    {
        cout << "Exception: " << e.what() << '\n';
        exit(EXIT_FAILURE);
    }
    
    try
    {
        if (element >= length){
            elementOutOfRangeException newException;
            //throw elementOutOfRangeException;
            throw newException;
        }
    }
    catch (exception& e)
    {
        cout << "Exception: " << e.what() << '\n';
        exit(EXIT_FAILURE);
    }
    
    Node<int>* currentNode = head;
    for (int i = 0; i < element; i++)
    {
        currentNode = currentNode->next;
    }
    int answer = currentNode->value;
    return answer;
}

/**
 *  Sorts the list in ascending order using bubble sort.
 */
void IntegerListLinked::sort()
{
    bool swapped_something = false;
    int unsorted = length - 1;
    if (length > 1)
    {
        do {
            swapped_something = false;
            Node<int>* currentNode = head;
            Node<int>* previousNode = NULL;
            for (int i = 0; i < unsorted; i++)
            {
                if (currentNode->value > currentNode->next->value)
                {
                    //Swap the two elements
                    Node<int>* tempNode = currentNode->next;
                    currentNode->next = (currentNode->next->next);
                    tempNode->next = (currentNode);
                    if (i == 0) {
                        head = tempNode;
                    }
                    else
                    {
                        previousNode->next = (tempNode);
                    }
                    //Record that a change was made
                    currentNode = tempNode;
                    swapped_something = true;
                }
                previousNode = currentNode;
                currentNode = currentNode->next;
            }
            unsorted = unsorted - 1;
        }
        while (swapped_something);
    }
}
