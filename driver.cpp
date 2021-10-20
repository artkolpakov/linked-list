/******************************************************
** Program: linked_list.cpp
** Author: Artem Kolpakov
** Date: 06/06/2021
** Description: That's a program with data structure in it that is a
* finite set of ordered elements (nodes) linked to each other by pointers - linked list.
* Each element of my linked list contains a field with data (int val), as well as a pointer
* (link) to the next element *next. This allows me to efficiently perform the operations of adding
* and removing elements for any position in the sequence. To add elements my program uses push_front
* and push_back functions. I also have a function that inserts a new value in the list at the specified
* index - int insert. My program also allows user to sort the data contained in the linked list in 
* ascending or descending order. Final thing that my program does is counting the total number of prime
* numbers within a linked list.
** Input: My program asks the user for the integers to store in the linked list, asks the user if they
* want those integers to be sorted in ascending or descending order, at the very end asks the user if
* they want to run the program again. The responses to described above prompts are considered to be the input.
** Output: The program prints the current linked list every time when there is an element being added to it,
* the program prints the linked list after the sorting, the program prints the number of prime numbers 
* stored in the linked list, the program prints all the prompts described in the input section.
******************************************************/

#include "linked_list.h"
#include <iostream>
using namespace std;

/******************************************************
** Function: main
** Description: creates a linked list and then performs certain operations by calling
* the needed functions for the linked list depending on the input. If user decides to run
* the program again, then all the nodes are deleted from the linked list, and it gets filled again.
** Parameters: -
** Pre-Conditions: the Linked_List and Node classes must exist
** Post-Conditions: the program runs until the user decides to leave by answering "n" to 
* "Do you want to do this again (y or n)?" prompt
******************************************************/
int main() {
  Linked_List linked_list;
  int choice;
  string again;
  string a_or_d;
  string final_choice = "n";

do{
  if (final_choice == "y"){
    linked_list.delete_all_nodes();
  }
  do{
  cout << "Please enter a number: " ;
  cin >> choice;
  linked_list.push_back(choice);
  // you can also test \/
  // linked_list.push_front(choice);

  cout << "Do you want another num (y or n): ";
  cin >> again;
  if (again == "y"){
    cout << "Current list is: " << endl;
    linked_list.print();
    }
  } while (again == "y");

  cout << "Your final linked list is: " << endl;
  linked_list.print();

  cout << "Sort ascending or descending (a or d)?: ";
  cin >> a_or_d;
  if (a_or_d == "a"){
    linked_list.sort_ascending();
    cout << "Your linked list after sorting is: " << endl;
    linked_list.print();
  }
  if (a_or_d == "d"){
    linked_list.sort_descending();
    cout << "Your linked list after sorting is: " << endl;
    linked_list.print();
  }
  linked_list.check_for_prime();
  cout << "Do you want to do this again (y or n)?: ";
  cin >> final_choice;
}
while (final_choice == "y");

/* TESTING OTHER FUNCTIONS: */

// try this to test the get_length function
/*
  cout << "The length of your list is: " << linked_list.get_length() << endl;
*/

// try this to test the insertion of a new value in the list at the specified index
// note that index works as in the array, starting with 0, not 1
// Please make sure that your list is long enough for the specified index
/*
  cout << "Original linked list: " << endl;
  linked_list.print();
  linked_list.insert(111, 2); // it should appeat at the 3rd position in the list
  cout << "Linked list after the insertion: " << endl;
  linked_list.print();
*/

// try this to test the insertion of a new value at the front of the list, since I only used push_back
/*
  cout << "Original linked list: " << endl;
  linked_list.print();
  linked_list.push_front(111);
  cout << "Original linked list after the insertion: " << endl;
  linked_list.print();
*/

  linked_list.clear();
}