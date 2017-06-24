/*  @file IntegerList.cpp 7/24/15 by MHS and JP
 *  @brief This file implements the main method
 * for testing all the corresponding IntegerList classes.
 */
#include "List.h"
#include "IntegerListArray.h"
#include "IntegerListLinked.h"
#include "IntegerListSorted.h"
#include "IntegerListVector.h"
#include "Node.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
/**
 * This main method tests all the IntegerList methods(list, IntegerListVector, 
 * IntegerListArray, etc).  An IntegerList is populated and the values printed 
 * out to the console.
 */
int main()
{
    //LOGO
    cout << "  __  __ _  ____  ____  ___  ____  ____       " << endl;
    cout << " (  )(  ( \\(_  _)(  __)/ __)(  __)(  _ \\      " << endl;
    cout << "  )( /    /  )(   ) _)( (_ \\ ) _)  )   /      " << endl;
    cout << " (__)\\_)__) (__) (____)\\___/(____)(__\\_)      " << endl;
    cout << "           __    __  ____  ____               " << endl;
    cout << "          (  )  (  )/ ___)(_  _)              " << endl;
    cout << "          / (_/\\ )( \\___ \\  )(                " << endl;
    cout << "          \\____/(__)(____/ (__)               " << endl;

    // list template class
    cout << "========================================" << endl;
    cout << "Testing List" << endl;
    cout << "========================================" << endl;
    List<char> list;
    srand(time(NULL));

    cout << "\n--- Testing List<char> ---" <<endl;
    //test push() and pushEnd()
    cout << "\npush()x15, pushEnd()x15: \n" <<endl;
    for(int i = 15; i >= 1 ; i--)
    {
        list.push(rand()%50+50);
        list.pushEnd(rand()%50+50);
    }

    cout << "length: " << list.getLength() << endl;
    for (int i = 0 ; i < list.getLength(); i++)
    {
        cout << "list[" << i << "]: " << list.getElement(i) << endl;
    }

    //test sort()
    list.sort();
    cout << endl << "sorted:" << endl;
    for (int i = 0 ; i < list.getLength(); i++)
    {
        cout << "list[" << i << "]: " << list.getElement(i) << endl;
    }

    //test pop() and popEnd()
    for(int i = 0; i < 12; i++)
    {
        list.popEnd();
        list.pop();
    }

    cout << "\npop()x12, popEnd()x12: \n" <<endl;
    cout << "length: " << list.getLength() << endl;
    for (int i = 0 ; i < list.getLength(); i++){
        cout << "list[" << i << "]: " << list.getElement(i) << endl;
    }

    List<int> listInt;
    srand(time(NULL));

    cout << "\n---Testing List<int>---" <<endl;
    //test push() and pushEnd()
    cout << "\npush()x15, pushEnd()x15: \n" <<endl;
    for(int i = 15; i >= 1 ; i--)
    {
        listInt.push(rand()%50+50);
        listInt.pushEnd(rand()%50+50);
    }

    cout << "length: " << listInt.getLength() << endl;
    for (int i = 0 ; i < listInt.getLength(); i++)
    {
        cout << "list[" << i << "]: " << listInt.getElement(i) << endl;
    }

    //test sort()
    listInt.sort();
    cout << endl << "sorted:" << endl;
    for (int i = 0 ; i < listInt.getLength(); i++)
    {
        cout << "list[" << i << "]: " << listInt.getElement(i) << endl;
    }

    //test pop() and popEnd()
    for(int i = 0; i < 12; i++)
    {
        listInt.popEnd();
        listInt.pop();
    }

    cout << "\npop()x12, popEnd()x12: \n" <<endl;
    cout << "length: " << listInt.getLength() << endl;
    for (int i = 0 ; i < listInt.getLength(); i++){
        cout << "list[" << i << "]: " << listInt.getElement(i) << endl;
    }

    // list array class
    cout << "========================================" << endl;
    cout << "Testing Integer List Array" << endl;
    cout << "========================================" << endl;
    IntegerListArray listArray;

    //test push() and pushEnd()
    cout << "\npush()x15, pushEnd()x15: \n" <<endl;
    for(int i = 15; i >= 1 ; i--)
    {
        listArray.push(rand()%100);
        listArray.pushEnd(rand()%100);
    }

    cout << "length: " << listArray.getLength() << endl;
    for (int i = 0 ; i < listArray.getLength(); i++)
    {
        cout << "list[" << i << "]: " << listArray.getElement(i) << endl;
    }

    //test sort()
    listArray.sort();
    cout << endl << "sorted:" << endl;
    for (int i = 0 ; i < listArray.getLength(); i++)
    {
        cout << "list[" << i << "]: " << listArray.getElement(i) << endl;
    }

    //test pop() and popEnd()
    for(int i = 0; i < 12; i++)
    {
        listArray.popEnd();
        listArray.pop();
    }

    cout << "\npop()x12, popEnd()x12: \n" <<endl;
    cout << "length: " << listArray.getLength() << endl;
    for (int i = 0 ; i < listArray.getLength(); i++){
        cout << "list[" << i << "]: " << listArray.getElement(i) << endl;
    }
    
    //linked list class
    cout << "========================================" << endl;
    cout << "Testing Integer Linked List" << endl;
    cout << "========================================" << endl;

    IntegerListLinked listLinked;

    //test push() and pushEnd()
    cout << "\npush()x15, pushEnd()x15: \n" <<endl;
    for(int i = 15; i >= 1 ; i--)
    {
        listLinked.push(rand()%100);
        listLinked.pushEnd(rand()%100);
    }

    cout << "length: " << listLinked.getLength() << endl;
    for (int i = 0 ; i < listLinked.getLength(); i++)
    {
        cout << "list[" << i << "]: " << listLinked.getElement(i) << endl;
    }

    //test sort()
    listLinked.sort();
    cout << endl << "sorted:" << endl;
    for (int i = 0 ; i < listLinked.getLength(); i++)
    {
        cout << "list[" << i << "]: " << listLinked.getElement(i) << endl;
    }

    //test pop() and popEnd()
    for(int i = 0; i < 12; i++)
    {
        listLinked.popEnd();
        listLinked.pop();
    }

    cout << "\npop()x12, popEnd()x12: \n" <<endl;
    cout << "length: " << listLinked.getLength() << endl;
    for (int i = 0 ; i < listLinked.getLength(); i++){
        cout << "list[" << i << "]: " << listLinked.getElement(i) << endl;
    }
    

    //Sorted Linked List
    cout << "========================================" << endl;
    cout << "Testing Integer Sorted Linked List" << endl;
    cout << "========================================" << endl;
    IntegerListSorted listSorted;

    //test insert()
    cout << "\nlength: " << listSorted.getLength() << endl;
    cout << "\ninsert()x25\n" <<endl;
    for(int i = 0 ; i < 25 ; i++)
    {

        listSorted.insert(rand()%100); 
    }

    cout << "length: " << listSorted.getLength() << endl;
    for(int i = 0 ; i < listSorted.getLength() ; i++)
    {
        cout << "list[" << i << "]: " << listSorted.getElement(i) << endl;
    }

    //test remove()
    cout << "\nremove()x20\n" <<endl;
    for(int i = 0 ; i < 20 ; i++)
    {

        listSorted.remove(0); 
    }
    cout << "length: " << listSorted.getLength() << endl;
    for(int i = 0 ; i < listSorted.getLength() ; i++)
    {
        cout << "list[" << i << "]: " << listSorted.getElement(i) << endl;
    }
    
    //Integer Vector List
    cout << "========================================" << endl;
    cout << "Testing Integer List Vector" << endl;
    cout << "========================================" << endl;
    IntegerListVector listVector;

    //test push() and pushEnd()
    cout << "\npush()x15, pushEnd()x15: \n" <<endl;
    for(int i = 15; i >= 1 ; i--)
    {
        listVector.push(rand()%100);
        listVector.pushEnd(rand()%100);
    }

    cout << "length: " << listVector.getLength() << endl;
    for (int i = 0 ; i < listVector.getLength(); i++)
    {
        cout << "list[" << i << "]: " << listVector.getElement(i) << endl;
    }

    //test sort()
    listVector.sort();
    cout << endl << "sorted:" << endl;
    for (int i = 0 ; i < listVector.getLength(); i++)
    {
        cout << "list[" << i << "]: " << listVector.getElement(i) << endl;
    }

    //test pop() and popEnd()
    for(int i = 0; i < 12; i++)
    {
        listVector.popEnd();
        listVector.pop();
    }

    cout << "\npop()x12, popEnd()x12: \n" <<endl;
    cout << "length: " << listVector.getLength() << endl;
    for (int i = 0 ; i < listVector.getLength(); i++){
        cout << "list[" << i << "]: " << listVector.getElement(i) << endl;
    }
    cout << "========================================" << endl;
}