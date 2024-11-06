#include <stdlib.h>
#include <stdio.h>
#include "header.h"

int main(){
	DLIST list = createList();
	insertFront(list,1);
	insertFront(list,3);
	insertFront(list,4);
	insertBack(list,0);
	insertAt(list,2,3);
	display(list);

	deleteFront(list);
	display(list);

	deleteBack(list);
	display(list);

	deleteAt(list,2);
	display(list);

	insertFront(list,7);
	insertFront(list,9);
	insertFront(list,5);
	insertBack(list,7);
	insertBack(list,7);
	display(list);

	deleteElement(list,7);
	display(list);

	insertAt(list,9,3);
	insertBack(list,1);
	insertFront(list,2);
	insertFront(list,1);
	insertFront(list,6);
	insertFront(list,8);
	insertFront(list,7);
	insertFront(list,1);
	display(list);

	removeConsecutiveDuplicate(list);
	display(list);

	sortDLL(list); 
	display(list);

	removeConsecutiveDuplicate(list);
	display(list);

	DLIST list1 = createList();
	DLIST list2 = createList();

	insertBack(list1,1);
	insertBack(list1,2);
	insertBack(list1,3);
	insertBack(list1,4);
	insertBack(list1,5);
	display(list1);

	insertFront(list2,9);
	insertFront(list2,8);
	insertFront(list2,7);
	insertFront(list2,6);
	display(list2);

	DLIST mergedList = mergeList(list1,list2);
	display(mergedList);
	display(list2);

	insertBack(list,3);
	addZeroBeforeAndAfterX(list,3);
	display(list);

	deleteLastOccurence(list,1);
	display(list);

	removeEveryXthNode(list,3);
	display(list);

	printf("Occurence[0]: %d\n",occurenceElement(list,0));

	pairwiseSwap(list);
	display(list);

	return 0;
}