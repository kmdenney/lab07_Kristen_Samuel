#include "linkedListFuncs.h"
#include "moreLinkedListFuncs.h"
#include "tddFuncs.h"
#include <iostream>
using namespace std;

int main() {

  LinkedList emptyList = {NULL,NULL};
  deleteNodeIteratively(&emptyList, 123);
  ASSERT_EQUALS(0,sum(&emptyList));

  int oneNum[1] = {42};
  LinkedList * oneList = arrayToLinkedList(oneNum, 1);
  deleteNodeIteratively(oneList, 14);
  ASSERT_EQUALS("[42]->null", linkedListToString(oneList));
  deleteNodeIteratively(oneList, 42);
  ASSERT_EQUALS(0,sum(oneList));

  int twoNum[2] = {42, 57};
  LinkedList * twoList = arrayToLinkedList(twoNum, 2);
  deleteNodeIteratively(twoList, 14);
  ASSERT_EQUALS("[42]->[57]->null", linkedListToString(twoList));
  deleteNodeIteratively(twoList, 57);
  ASSERT_EQUALS("[42]->null", linkedListToString(twoList));
  
  

  int threeNums[3]={42,57,61};
  LinkedList *list = arrayToLinkedList(threeNums,3);
  deleteNodeIteratively(list, 61);
  ASSERT_EQUALS("[42]->[57]->null", linkedListToString(list));
  

  return 0;
}

