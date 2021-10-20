#include "node.h"
#include <iostream>
using namespace std;

Node::Node(){
  this-> val = 0;
  next = nullptr;
}

Node::Node(int val, Node *next){
  this-> val = val;
  this-> next = next;
}

Node::~Node(){
  if (next != nullptr){
  delete next;
  }
}