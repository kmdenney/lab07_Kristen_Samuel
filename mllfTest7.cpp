#include "linkedListFuncs.h"
#include "moreLinkedListFuncs.h"
#include "tddFuncs.h"
#include <iostream>
using namespace std;

int main() {
  
  LinkedList emptyList = {NULL,NULL};
  insertNodeToSortedList(&emptyList, 5);
  ASSERT_EQUALS("[5]->null", linkedListToString(&emptyList));

  int oneNum[1] = {42};
  LinkedList * oneList = arrayToLinkedList(oneNum, 1);
  insertNodeToSortedList(oneList, 50);
  ASSERT_EQUALS("[42]->[50]->null", linkedListToString(oneList));
  insertNodeToSortedList(oneList, 45);
  ASSERT_EQUALS("[42]->[45]->[50]->null", linkedListToString(oneList));
  insertNodeToSortedList(oneList, 44);
  ASSERT_EQUALS("[42]->[44]->[45]->[50]->null", linkedListToString(oneList));
  insertNodeToSortedList(oneList, 3);
  ASSERT_EQUALS("[3]->[42]->[44]->[45]->[50]->null",
		linkedListToString(oneList));
  
  return 0;
}

