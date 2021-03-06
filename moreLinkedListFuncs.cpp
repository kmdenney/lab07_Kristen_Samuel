#include <cassert>
#include "linkedList.h"
#include "linkedListFuncs.h"

// list: ptr to a linked list of Node (each with int data, and Node * next)
// Return a pointer to node with the largest value.
// You may assume list has at least one element  
// If more than one element has largest value, 
//  break tie by returning a pointer to the one the occurs
//  earlier in the list, i.e. closer to the head

Node * pointerToMax(LinkedList *list) {

  // Code may assume that these assertions are true;
  //  so does not need to do error checking for these conditions.
  assert(list!=NULL);
  assert(list->head != NULL);
  Node * max = list->head;
  Node * iter = new Node;
  for(iter = list->head; iter != NULL; iter = iter->next) {
    if(iter->data > max->data) {
      max = iter;
    }
  }

  return max;
}

// list: ptr to a linked list of Node (each with int data, and Node * next)
// Return a pointer to node with the smallest value.  
// You may assume list has at least one element
// If more than one element has smallest value, 
//  break tie by returning a pointer to the one the occurs
//  earlier in the list, i.e. closer to the head


Node * pointerToMin(LinkedList *list) {

  // Code may assume that these assertions are true;
  //  so does not need to do error checking for these conditions.

  assert(list!=NULL);
  assert(list->head != NULL);
  Node * min = list->head;
  Node * iter = new Node;
  for(iter = list->head; iter != NULL; iter = iter->next) {
    if(iter->data < min->data) {
      min = iter;
    }
  }

  return min; // STUB!  Replace this line with correct code

}

// list: ptr to a linked list of Node (each with int data, and Node * next)
// Return the largest value in the list.
// This value may be unique, or may occur more than once
// You may assume list has at least one element

int largestValue(LinkedList *list) {

  // Code may assume that these assertions are true;
  //  so does not need to do error checking for these conditions.

  assert(list!=NULL);
  assert(list->head != NULL);
  Node * max = list->head;
  Node * iter = new Node;
  for(iter = list->head; iter != NULL; iter = iter->next){
    if(iter->data > max->data){
      max = iter;
    }
  }

  return max->data;

}

// list: ptr to a linked list of Node (each with int data, and Node * next)
// Return the smallest value in the list.
// This value may be unique, or may occur more than once
// You may assume list has at least one element

int smallestValue(LinkedList *list) {
  // Code may assume that these assertions are true;
  //  so does not need to do error checking for these conditions.

  assert(list!=NULL);
  assert(list->head != NULL);
  Node * min = list->head;
  Node * iter = new Node;
  for(iter = list->head; iter != NULL; iter = iter->next){
    if(iter->data < min->data){
      min = iter;
    }
  }

  return min->data;

}

// list: ptr to a linked list of Node (each with int data, and Node * next)
// Return the sum of all values in the list.
// You may assume that list is not NULL
// However, the list may be empty (i.e. list->head may be NULL)
//  in which case your code should return 0.

int sum(LinkedList * list) {
  // Code may assume that these assertions are true;
  //  so does not need to do error checking for these conditions.

  assert(list!=NULL);
  int sum = 0;
  Node * iter = new Node;
  for(iter = list->head; iter != NULL; iter = iter->next){
    sum = sum + iter->data;
  }

  return sum;
}

// list: ptr to a linked list of Node (each with int data, and Node * next)
// value: int value of the node to delete
// Delete the Node with the given value in a recursive way. 
// Use a helper function that performs the recursion

void deleteNodeRecursively(LinkedList * list, int value){
  
}

// list: ptr to a linked list of Node (each with int data, and Node * next)
// value: int value of the node to delete
// Delete the Node with the given value using loops. 

void deleteNodeIteratively(LinkedList * list, int value){
  if(list->head == 0){
    return;
  }

  if(list->head->data == value) {
    Node * p = list->head->next;
    delete list->head;
    list->head = p;
    if(p == 0){
      list->tail = p;
    }
    return;
  }

  if(list->head->data != value && list->head->next == 0){
    return;
  }

  Node * prev = list->head;
  Node * curr = prev->next;
  Node * temp = curr->next;
  while(curr->data != value && curr != 0) {
    prev = prev->next;
    curr = curr->next;
    if(temp == 0){
      return;
    }
    temp = temp->next;
  }
  delete curr;
  prev->next = temp;
  if(prev->next == 0){
    list->tail = prev->next;
  }
}


// list: ptr to a linked list of Node (each with int data, and Node * next)
// Nodes in the linked list are expected to be in sorted ascending order
// value: int value of the node to insert
// Insert a new node in the linked list with the given value at the right spot
// The final linked list should have all its nodes in sorted ascending order
void insertNodeToSortedList(LinkedList * list, int value){
  Node * temp;
  Node * prev;

  temp = list->head;
  prev = list->head;
  
  while(temp != 0 && temp->data < value){
    prev = temp;
    temp = temp->next;
  }

  Node * tempNode = new Node;
  tempNode->data = value;
  tempNode->next = temp;
  
  if(list->head == 0){
    list->head = tempNode;
    list->tail = tempNode;
    return;
  }
  if(tempNode->next == list->head){
    list->head = tempNode;
  }
  else{
    prev->next = tempNode;
  }
  
  if(tempNode->next == 0){
    list->tail = tempNode;
  }
}
