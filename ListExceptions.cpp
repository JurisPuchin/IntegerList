#ifndef __LISTEXCEPTIONS_CPP__
#define __LISTEXCEPTIONS_CPP__

#include <exception>
#include "ListExceptions.h"
using namespace std;

/** \brief Returns "The element requested is not available." error message.
*  \returns "The element requested is not available."
*/
const char* emptyElementException::what() const throw(){
	return "The element requested is not available.";
}

/** \brief Returns "The element requested to be deleted does not exist." error message.
* \returns "The element requested to be deleted does not exist."
*/
const char* deleteElementException::what() const throw(){
	return "The element requested to be deleted does not exist.";
}

/** \brief Returns "The element requested to be inserted cannot be place for the list is less than 0." error message.
* \returns "The element requested to be inserted cannot be place for the list is less than 0."
*/
const char* emptyListException::what() const throw(){
	return "The element requested to be inserted cannot be place for the list is less than 0.";
}

/** \brief Returns "There is no more memory left to be allocated for the new node." error message.
* \returns "There is no more memory left to be allocated for the new node."
*/
const char* unavailableMemoryException::what() const throw(){
	return "There is no more memory left to be allocated for the new node.";
}

/** \brief Returns "List length can not be negative." error message.
* \returns "List length can not be negative."
*/
const char* negativeLengthException::what() const throw() {
    return "List length can not be negative.";
}

/** \brief Returns "No tail pointer. This ususally happens when trying to pop from an empty list." error message.
* \returns "No tail pointer. This ususally happens when trying to pop from an empty list."
*/
const char* missingTailException::what() const throw() {
    return "No tail pointer. This ususally happens when trying to pop from an empty list.";
}

/** \brief Returns "No head pointer. This ususally happens when trying to pop from an empty list." error message.
* \returns "No head pointer. This ususally happens when trying to pop from an empty list."
*/
const char* missingHeadException::what() const throw() {
    return "No head pointer. This ususally happens when trying to pop from an empty list.";
}

/** \brief Returns "List does not have any elements to remove." error message.
* \returns "List does not have any elements to remove."
*/
const char* listTooShortException::what() const throw() {
    return "List does not have any elements to remove.";
}

/** \brief Returns "Element index must be a positive integer." error message.
* \returns "Element index must be a positive integer."
*/
const char* negativeElementException::what() const throw() {
    return "Element index must be a positive integer.";
}

/** \brief Returns "Requested element index is outside of list." error message.
* \returns "Requested element index is outside of list."
*/
const char* elementOutOfRangeException::what() const throw() {
    return "Requested element index is outside of list.";
}

#endif