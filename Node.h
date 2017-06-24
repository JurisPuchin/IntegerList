/** @file Node.h AL and JP and ES on 22July2015
 * @brief This is the header file for the Node class. */
#ifndef __NODE__H__
#define __NODE__H__

/** \brief contains %Node object data members
 * 
 *   <h1>Node</h1>
 *   <h2>July 28, 2015
 *   CSC 340 Summer 2015
 *   Team Members: Juris Puchin, Emil Santos, and Alvin Lu.
 *   </h2>
 *   This program implements an integer list container class. Data is stored in a node object
 *   which contains a template value depending on what data type the user wants and a pointer
 *   that points to the next node object.
 *
 *  <center>
 *  |   Node    |
 *  |------------------|
 *  | +T value       |
 *  | +Node *next      |
 *  </center>
 */

template <typename T>
class Node{
public:
    T value;
    Node* next;
};

#endif