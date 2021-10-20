#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

class Node {

public:
  int val;  // the value that this node stores
  Node *next; // a pointer to the next node in the list

/******************************************************
** Function: Node default constructor
** Description: when new node is created the constructor initializes it's value and
* next pointer with default values of 0 and NULL
** Parameters: -
** Pre-Conditions: the Node class must exist, new Node has to be created for 
* constructor to work  
** Post-Conditions: value contained in node is initialized with 0, the next pointer
* is initialized with nullptr
******************************************************/ 
  Node(); 

/******************************************************
** Function: Node alternate constructor
** Description: when new node is created with passed parameters the alternate 
* constructor initializes it's value and next pointer with passed values
** Parameters: val and next values that we want our node to be initialized with
** Pre-Conditions: the Node class must exist, new Node has to be created with passed parameters 
* for alternate constructor to work  
** Post-Conditions: value contained in node is initialized with given value, the next pointer
* is initialized with given value
******************************************************/    
  Node(int, Node* );

/******************************************************
** Function: Node destructor
** Description: frees the memory by deleting the next pointer when the 
* node object goes out of scope.
** Parameters: -
** Pre-Conditions: the Node class must exist 
** Post-Conditions: if the next pointer of the node isn't already nullptr then it
* gets deleted, the memory gets freed
******************************************************/  
  ~Node();

};

#endif
