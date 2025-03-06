#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
  //split into 2 output lists 
  //maintain the relative ordering of items 
  //smaller -->pointer to head of new singly linked list <= pivot 
  if (head == NULL){ //end of list 
    smaller = NULL; 
    larger = NULL; 
    return; //stop recursing
  }
  Node* next = head->next;  //keeps access of remaining list 
  
  if (head->val <= pivot){
    smaller = head; //smaller points to head 
    llpivot(next, smaller->next, larger, pivot); //keep moving forward
  } 
  else {
    larger = head;
    llpivot(next, smaller, larger->next, pivot); 
  }
  //set head to null at the end
  head = NULL; 
}


