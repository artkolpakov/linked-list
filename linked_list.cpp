#include "linked_list.h"
#include <iostream>
using namespace std;

Linked_List::Linked_List(){
  length = 0;
  head = nullptr;
}

int Linked_List::get_length(){
  return this->length;
}

unsigned int Linked_List::push_front(int new_val){
  length ++;

  Node *new_node = new Node(new_val, head); 
  head = new_node;

  return length;
}

unsigned int Linked_List::push_back(int new_val){
  length ++;

  if (head == nullptr){ //if it's empty
    head = new Node(new_val, nullptr);
  }

  else{
    Node *temp = this-> head; //start from head
    while (temp->next != nullptr){
      temp = temp->next; //scrolling till the very end
    }
    
    //inserting it at the end:
    Node *new_node = new Node(new_val, temp->next); 
    temp-> next = new_node; 
  }
  return length;
}

unsigned int Linked_List::insert(int new_val, unsigned int index){
  length++;
  
   Node *temp = new Node(new_val, NULL); 
   if (index == 0){
     temp->next = this->head;
     head = temp;
     return length;
   }

  else{
  temp = this-> head;
  //temp -> val = new_val;

  int check = index-1;
   for (int i = 0; i< check; i++){
     temp = temp->next;
   }
  
  Node *new_node = new Node(new_val, temp->next); 
  temp-> next = new_node; 
  }

  return length;
}

void Linked_List::print(){
  Node *temp = this->head;
  while (temp != nullptr){
    cout << temp->val << "  ";
    temp = temp->next;
  }
  cout << endl;
}

void Linked_List::clear(){
  delete head;
}

void Linked_List::delete_all_nodes(){
    length = 0;
    Node* next = nullptr;
    Node* temp = head;
 
    while (temp != nullptr){
        next = temp->next;
        free(temp);
        temp = next;
    }
   head = nullptr;
}

Linked_List::Linked_List(const Linked_List& old_list){
  cout << "Invoked the copy constructor!" << endl;
  this-> length = old_list.length;
  this-> head = nullptr;

  Node *temp = old_list.head;
  
  while(temp != nullptr){

      Node *test = new Node(temp->val, temp->next);
      
      if (this->head == nullptr){
        this->head = test;
      }
        temp = temp->next;
      }
}


Linked_List& Linked_List::operator=(const Linked_List& old_list){
  cout << "Invoked the overloaded assignment operator" << endl; 

  this-> length = old_list.length;
  this-> head = nullptr;

  Node *temp = old_list.head;
  
  while(temp != nullptr){
      Node *test = new Node(temp->val, temp->next);
      if (this->head == nullptr){
        this->head = test;
      }
        temp = temp->next;
      }

  return *this;
}

void Linked_List::check_for_prime(){
  int counter = 0;
  bool flag = true; 
  Node *temp = this->head;
  
  while (temp != nullptr){
     // this assignment requires that a negative number is never considered to be prime. 0 and 1 are also not considered as prime numbers
    if (temp->val > 1){ 
      for (int i = 2; i <= temp->val/2; i++){
          if (temp->val % i == 0){ // here we check if there is such number that fully divides our value
          flag = false;    
          break;
          }
        }
      if (flag == true){
        counter++;
        }
      else{ flag = true; }
      }
    temp = temp->next;
  }
  cout << "You have " << counter << " prime number(s) in your list. (that's the total number of prime numbers) " << endl;
}

/* 
merge_sort(head){
  1) check if length <= 1 if so return
  2) split unsorted list in half
  3) first = merge_sort(first half)
  4) second = merge_sort(second half)
  5) merge(first, second)
}
*/

Node* merge_sort(Node* head){
  Node *temp = head;
  int length = 0;
  
  while (temp != nullptr){
    temp = temp -> next;
    length ++;
  }
  if (length <= 1){
    return head;
  }
  temp = head;
  for (int i = 0; i< ((length-1)/2); i++){
     temp = temp -> next;
  }
  Node *second = temp-> next;

  temp-> next = NULL;
  temp = head;

  head = merge_sort(head);
  second = merge_sort(second);

  return merge(head, second);
}

Node* merge(Node* first, Node* second){
    Node* result = nullptr;

    if (first == nullptr){
        return second;
    }
    else if (second == nullptr){
        return first;
    }

    if (first->val <= second->val) {
        result = first;
        result->next = merge(first->next, second);
    }
    else{
        result = second;
        result->next = merge(first, second->next);
    }
    return result;
}

void Linked_List::sort_ascending(){
  if (head == nullptr){
    return;
  }

  head = merge_sort(head);
}


void swap_nodes(Node** head, Node* currX, Node* currY, Node* prevY){
    // make 'currY' as new head
    *head = currY;
 
    prevY->next = currX;
 
    Node* temp = currX->next;
    currX->next = currY->next;
    currY->next = temp;

}

Node* selection_sort(Node* head){
      // if there is only a single node
    if (head->next == NULL){
        return head;
    }
    Node* min = head;
    Node* beforeMin = NULL;

    Node *temp = head;
    while (temp->next != nullptr){
        if (temp->next->val >= min->val) {
          min = temp->next;
          beforeMin = temp;
        }
        temp = temp->next;
    }

    if (min != head){
        swap_nodes(&head, head, min, beforeMin);
    }
 
    // recursively sort the remaining list
    head->next = selection_sort(head->next);
 
    return head;
}

void Linked_List::sort_descending(){
  if (head == nullptr){
    return;
  }
  head = selection_sort(head);
}
