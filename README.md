# linked-list
linked list implementation (C++)
author's name: Artem Kolpakov 
date: 06/06/2021

Here is important information about my linked list program:
      First of all, I want to mention that the description of how all of my functions work/what they are doing when called is specified in the header files
      above each of the functions. In this file I will provide a description of the program (how my entire program works) and some additional information.
      There are 6 total files that I am using in my program: 1,2) node.cpp and node.h: my linked list is represented by a pointer to the first node of the
      linked list. The first node is called the head. If the linked list is empty, then the value of the head is NULL. Each node in a list consists of at 
      least two parts: value (int) - the value that this node stores and pointer to the next node in the list. Node class has default constructor and
      alternate constructor (that helps us to do the proper initialization) as well as destructor. 3,4) linked_list.cpp and linked_list.h: the linked list
      itself - consists of elements of the same type (Node), linked with help of pointers. Each item in the list has a pointer to the next item.
      The last item in the list points to nullptr. The element to which there is no pointer is the first (head) element of my list.
      The link in each node (next) points to the next node in the list. The functions contained in linked_list.cpp add can insert a new value to our list,
      sort the nodes in ascending/descending order, print the list, free the memory, get the length of our list, get the number of prime numbers stored in our list.
      sort_descending() function is implemented using a recursive Selection Sort algorithm. 5) driver.cpp - serves as the driver for my entire program, it creates a linked list and then performs certain operations by calling the needed functions for the linked list
      depending on the input. If user decides to run the program again, then all the nodes are deleted from the linked list, and it gets filled again.
      6) Makefile - the file that we use to compile the entire program by simply typing make, this time I used the "magic makefile". In my linked_list.h header
      file I cited the "geeksforgeeks" website, I used the content of "geeksforgeeks" website to implement 3 of my functions (Node* merge(Node* , Node* ),
      Node* selection_sort(Node* ), void delete_all_nodes() ). However, it doesn't mean that I simply copied the code from there, the code shown there was adapted
      and changed by me for my program. In my driver.cpp file starting from line 52 you can test some other functions that are not used
      in my program (they are commented out). The instructions are provided there, uncomment it separately when testing.
