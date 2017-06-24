/** @file ListExceptions.h written by JP and ES and AL on 28July2015
 * @brief This is the header file for the exceptions classed usded by the vatious %lists. */
#ifndef __LISTEXCEPTIONS_H__
#define __LISTEXCEPTIONS_H__
#include <exception>

using namespace std;

/** \brief Returns an exception if there is no element available
*  
*
*/
class emptyElementException: public exception
{
	public: virtual const char* what() const throw();
};

/** \brief Returns an exception if the requested elemenent is nonexistent
*
*/
class deleteElementException: public exception
{
	public: virtual const char* what() const throw();
};

/** \brief Returns an exception if an element is requested for insertion while the list is empty.
*
*/

class emptyListException: public exception
{
	public: virtual const char* what() const throw();
};

/** \brief Returns an exception if there is no memory left for allocation.
*
*/
class unavailableMemoryException: public exception
{
	public: virtual const char* what() const throw();
};

/** \brief Returns an exception when the list length is negative.
*
*/
class negativeLengthException: public exception
{
    public: virtual const char* what() const throw();
};

/** \brief Returns an exception when the list tail is nonexistent
*
*/
class missingTailException: public exception
{
    public: virtual const char* what() const throw();
};

/** \brief Returns an exception when the list head is nonexistent
*
*/
class missingHeadException: public exception
{
    public: virtual const char* what() const throw();
};

/** \brief Returns an exception when the list has insufficient elements to be removed.
*
*/
class listTooShortException: public exception
{
    public: virtual const char* what() const throw();
};

/** \brief Returns an exception when a negative element index is requested from the list
*
*/
class negativeElementException: public exception
{
    public: virtual const char* what() const throw();
};

/** \brief Returns an exception when the requested element is out of the list range
*
*/
class elementOutOfRangeException: public exception
{
    public: virtual const char* what() const throw();
};

#endif