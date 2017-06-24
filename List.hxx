/**@file List.hxx written by Alvin Lu and Juris Puchin and Emil Santos on 22July2015
 * @brief This file contains the implementation of template List class based on linked %list.*/
#ifndef __LIST_HXX__
#define __LIST_HXX__

#include "List.h"
#include "Node.h"
#include "ListExceptions.h"
#include <iostream>
#include <cstdlib>
#include <exception>

using namespace std;

/**
 *  \brief Standard constructor which creates an empty list.
 *
 */
template <typename T>
List<T>::List()
{
    length = 0;
    head = NULL;
}

/**
 *  \brief Standard destructor which deletes the list and all of its nodes.
 *
 */
template <typename T>
List<T>::~List()
{
    if (length > 0)
    {
        Node<T>* currentNode = head;
        for (int i = 0; i < length; i++)
        {
            Node<T>* tmpNode = currentNode;
            currentNode = currentNode->next;
            delete tmpNode;
        }
    }
}

/**
 *  \brief Inserts the specified value into the front of the list.
 *
 *  The length of the list is automatically adjusted to accommodate the new data element.
 *
 *  \param value This element will be added to the front of the list.
 */
template <typename T>
void List<T>::push(T value)
{
    try 
    {
        if (length < 0) {
        	negativeLengthException newException;
            throw newException;
        }
    } 
    catch (exception& e)
    {
        cout << "Exception: " << e.what() << '\n';
        exit(-1);
    }
    try
    {
        Node<T>* tmp = head;
        head = new Node<T>();
        head->next = tmp;
        head->value = value;
    }
    catch (exception& e)
    {
        cout << "Exception: " << e.what() << '\n';
        exit(-1);
    }
    length = length + 1;
}

/**
 *  \brief Removes and returns the value at the front of the list.
 *
 *  The list's length is automatically reduced by one.
 *
 *  \returns Value removed from the front of the list.
 */
template <typename T>
T List<T>::pop()
{
    try 
    {
        if (length <= 0) 
        {
        	listTooShortException newException;
            throw newException;
        }
    }
    catch (exception& e)
    {
        cout << "Exception: " << e.what() << '\n';
        exit(-1);
    }

    try 
    {
        if (head == NULL) 
        {
        	missingHeadException newException;
            throw newException;
        }
    }
    catch (exception& e)
    {
        cout << "Exception: " << e.what() << '\n';
        exit(-1);
    }

    int answer = head->value;
    Node<T>* tmpPointer = head;
    head = head->next;
    delete tmpPointer;
    
    length = length - 1;

    return answer;
}

/**
 *  \brief Inserts a value to the back of the list.
 *
 *  The length of the list is automatically increased by one.
 *
 *  \param value This value will be inserted into the back of the list.
 */
template <typename T>
void List<T>::pushEnd(T value)
{
    try
    {
        if (length < 0) 
        {
        	negativeLengthException newException;
            throw newException;
        }
    }
    catch (exception& e)
    {
        cout << "Exception: " << e.what() << '\n';
        exit(-1);
    }

    if (length == 0)
    {
        try
        {
            head = new Node<T>();
            head->next = NULL;
            head->value = value;
        } 
        catch (exception& e)
        {
            exit(-1);
        }
    }
    else
    {
        Node<T>* tailNode = head;
        for (int i = 0; i < length - 1; i++) 
        {
            tailNode = tailNode->next;
        }
        try 
        {
            tailNode->next = new Node<T>();
            tailNode = tailNode->next;
            tailNode->value = value;
            tailNode->next = NULL;
        }
        catch (exception& e)
        {
            exit(-1);
        }
    }
    length = length + 1;
}

/**
 *  \brief Removes and returns the element at the end of the list.
 *
 *  The list's length is reduced by one.
 *
 *  \returns The value removed from the tail of the list.
 */
template <typename T>
T List<T>::popEnd()
{
    try
    {
        if (length < 1) 
        {
        	listTooShortException newException;
            throw newException;
        }
    }
    catch (exception& e)
    {
        cout << "Exception: " << e.what() << '\n';
        exit(-1);
    }

    T answer = head->value;

    if (length == 1)
    {
        delete head;
        head = NULL;
    }
    else
    {
        Node<T>* newTailNode = head;
        for (int i = 0; i < length - 2; i++) 
        {
            newTailNode = newTailNode->next;
        }
        answer = newTailNode->next->value;
        delete newTailNode->next;
        newTailNode->next = NULL;
    }

    length = length - 1;

    return answer;
}

/**
 *  \brief Returns the current length of the list.
 *
 *  \returns Current list length.
 */
template <typename T>
int List<T>::getLength()
{
    return length;
}

/**
 *  \brief Returns the value at the specified location of the list.
 *
 *  \param element The location of the desired element in the list.
 *  \returns The value at a specified location of the list.
 */
template <typename T>
T List<T>::getElement(int element)
{
    try
    {
        if (element < 0) 
        {
        	negativeElementException newException;
            throw newException;
        }
    }
    catch (exception& e)
    {
        cout << "Exception: " << e.what() << '\n';
        exit(-1);
    }

    try
    {
        if (element >= length)
        {
        	elementOutOfRangeException newException;
            throw newException;
        }
    }
    catch (std::exception &e)
    {
        cout << "Exception: " << e.what() << '\n';
        exit(-1);
    }

    Node<T>* currentNode = head;
    for (int i = 0; i < element; i++)
    {
        currentNode = currentNode->next;
    }

    int answer = currentNode->value;
    return answer;
}

/**
 *  \brief Sorts the list in ascending order using bubble sort. (Use with CAUTION)
 *  
 *  WARNING: this only makes sense for some <T> types. Make sure the ">" comparison 
 *  operator is meaningfully defined.
 */
template <typename T>
void List<T>::sort()
{
    bool swapped_something = false;
    int unsorted = length - 1;
    if (length > 1)
    {
        do {
            swapped_something = false;
            Node<T>* currentNode = head;
            Node<T>* previousNode = NULL;
            for (int i = 0; i < unsorted; i++)
            {
                if (currentNode->value > currentNode->next->value)
                {
                    //Swap the two elements
                    Node<T>* tempNode = currentNode->next;
                    currentNode->next = (currentNode->next->next);
                    tempNode->next = currentNode;
                    if (i == 0) {
                        head = tempNode;
                    }
                    else
                    {
                        previousNode->next = tempNode;
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

#endif