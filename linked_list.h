#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include "node.h"
using namespace std;

/******************************************************
** Function: merge_sort
** Description: The linked list to be sorted is split into two parts
* of approximately the same size; Each of the resulting parts is sorted separately, by the same algorithm;
* two ordered lists of half size are concatenated into one and sorted using merge function
** Parameters: it uses the head of our linked list
** Pre-Conditions: the function has to be called with passed Node pointer head in order to work
** Post-Conditions: the linked list is sorted in ascending order if this function is called
******************************************************/ 
Node* merge_sort(Node* );

/******************************************************
** Function: merge
** Description: function that takes two lists, each of which is sorted in increasing order,
* and merges the two together into one list which is in ascending order. 
** Parameters: two ordered lists of half size (first and second)
** Pre-Conditions: has to be called in order to work
** Post-Conditions: returns the new list, which is made by splicing together the nodes of the
* first two lists
* Citation: https://www.geeksforgeeks.org/merge-sort-for-linked-list/
******************************************************/ 
Node* merge(Node* , Node* );

/******************************************************
** Function: selection_sort
** Description: Algorithm steps: 1) find the number of the minimum value in the current list
* 2) swap this value with the value of the first unsorted position using the swap_nodes function 
* (the swap is not needed if the minimum element is already at this position) now we sort the tail
* of the list, excluding already sorted elements from consideration
** Parameters: it uses the head of our linked list
** Pre-Conditions: the function has to be called with passed Node pointer head in order to work
** Post-Conditions: the linked list is sorted in descending order if this function is called
* Citation: https://www.geeksforgeeks.org/recursive-selection-sort-singly-linked-list-swapping-node-links/
******************************************************/ 
Node* selection_sort(Node* );

/******************************************************
** Function: swap_nodes
** Description: Given a linked list and two keys in it, this function swaps the nodes for two given keys.
** Parameters: a linked list head, head reference and two keys in the list
** Pre-Conditions: the function has to be called in order to work
** Post-Conditions: If function is called the nodes are be swapped by changing links. 
* Citation: https://www.geeksforgeeks.org/recursive-selection-sort-singly-linked-list-swapping-node-links/
******************************************************/ 
void swap_nodes(Node**, Node*, Node*, Node*);

class Linked_List {
private:
  unsigned int length;
  Node *head;

public:

/******************************************************
** Function: Linked_List default constructor
** Description: when new Linked List is created the constructor initializes it's length and
* head pointer with default values of 0 and NULL
** Parameters: -
** Pre-Conditions: the Linked_List class must exist, new Linked List has to be created for 
* constructor to work 
** Post-Conditions: length contained in Linked List is initialized with 0, the head pointer
* is initialized with nullptr
******************************************************/ 
  Linked_List();

/******************************************************
** Function: get_length
** Description: we need this function in order to gain access to the private member of
* a Linked_List: int length, which is the number of nodes contained in the list
** Parameters: -
** Pre-Conditions: the Linked_List class must exist
** Post-Conditions: returns the int value of private member variable length
******************************************************/
  int get_length();

/******************************************************
** Function: get_length
** Description: outputs a list of all integers contained within the list
** Parameters: -
** Pre-Conditions: the Linked_List and Node classes must exist
** Post-Conditions: all the int values stored in our linked list are printed when
* this function is called
******************************************************/
  void print();

/******************************************************
** Function: push_back
** Description: this function inserts a new value at the back of our linked list
* and also returns the new length of the list
** Parameters: int new_val – the value that we want to insert
** Pre-Conditions: the Linked_List and Node classes must exist
** Post-Conditions: when this function is called there is a new value, which is passed as
* a function parameter, inserted at the back of our linked list, the length of the list
* gets increased by 1
******************************************************/
  unsigned int push_back(int);

/******************************************************
** Function: push_front
** Description: this function inserts a new value at the front of the list, it also
* returns the new length of the list
** Parameters: int new_val – the value that we want to insert
** Pre-Conditions: the Linked_List and Node classes must exist
** Post-Conditions: when this function is called there is a new value, which is passed as
* a function parameter, inserted at the front of our linked list, the length of the list gets
* increased by 1
******************************************************/
  unsigned int push_front(int); 

/******************************************************
** Function: insert
** Description: this function inserts a new value in the list at the specified index,
* which is passed as a function parameter and also returns the new length of the list
** Parameters: unsigned int index - the desired position for insertion
** Pre-Conditions: the Linked_List and Node classes must exist
** Post-Conditions: when this function is called there is a new value, which is passed as
* a function parameter, inserted at the specified index (which is also passed as a function parameter)
* of our linked list, the length of the list gets increased by 1
******************************************************/
  unsigned int insert(int , unsigned int );

/******************************************************
** Function: clear
** Description: this function frees the memory, deletes the head
** Parameters: -
** Pre-Conditions: the Linked_List and Node classes must exist
** Post-Conditions: when this function is called, the memory is freed,
* since all the dynamically allocated memory (head) is deallocated and deleted
******************************************************/
  void clear();

/******************************************************
** Function: delete_all_nodes
** Description: this function deletes the entire linked list,
* namely it removes all of the nodes from it and sets length equal to 0
** Parameters: -
** Pre-Conditions: the Linked_List and Node classes must exist
** Post-Conditions: when this function is called, it iterates through the linked
* list and deletes all the nodes one by one. Then our linked list becomes empty 
* Citation: https://www.geeksforgeeks.org/write-a-function-to-delete-a-linked-list/
******************************************************/
  void delete_all_nodes();

/******************************************************
** Function: Linked_List class copy constructor 
** Description: makes a 'deep' copy of an old Linked_List when we 
* create a new class Linked_List and instantly set it equal to 
* the old Linked_List class
** Parameters: old Linked_List class 
** Pre-Conditions: Linked_List class must exist
** Post-Conditions: a deep copy of old Linked_List is made
*****************************************************/
  Linked_List(const Linked_List&);

/******************************************************
** Function: Linked_List class overloaded assignment operator
** Description: makes a 'deep' copy of an old Linked_List when we 
* create a new class Linked_List and at some point set it equal to 
* the old Linked_List class
** Parameters: old Linked_List
** Pre-Conditions: Linked_List class must exist
** Post-Conditions: a deep copy of old Linked_List is made
*****************************************************/
  Linked_List& operator=(const Linked_List&);

/******************************************************
** Function: sort_ascending
** Description: sorts the linked list in ascending order by using the Merge sort algoritm and
* calling the other functions that are defined in linked_list.cpp file
** Parameters: -
** Pre-Conditions: the Linked_List and Node classes must exist
** Post-Conditions: the head node is changed if the data at the original head is not the
* smallest value in the linked list. The linked list is changed in the way that the values
* it contains now are stored in the ascending order
*****************************************************/
  void sort_ascending();

/******************************************************
** Function: sort_descending
** Description: sorts the linked list in descending order by using the a recursive Selection Sort
* algorithm and calling the other functions that are defined in linked_list.cpp file
** Parameters: -
** Pre-Conditions: the Linked_List and Node classes must exist
** Post-Conditions: the head node is changed if the data at the original head is not the
* highest value in the linked list. The linked list is changed in the way that the values
* it contains now are stored in the descending order
*****************************************************/
  void sort_descending();

/******************************************************
** Function: check_for_prime
** Description: this function counts the number of prime numbers within a Linked_List.
* (A negative number is never considered to be prime in our case.)
** Parameters: -
** Pre-Conditions: the Linked_List and Node classes must exist
** Post-Conditions: when this function is called, it iterates through the linked
* list and checks if there are values greater than 1 that are not a product of two
* smaller natural numbers. Then calculates the total of prime numbers stored in the list
* and prints it
*****************************************************/
  void check_for_prime();

  void list_revese();
};


#endif