#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(){
	DLIST list = createList();
	insertFront(list,4);
	insertFront(list,3);
	insertFront(list,2);
	insertFront(list,1);
	display(list);

	insertBack(list,5);
	insertBack(list,6);
	insertBack(list,7);
	insertBack(list,8);
	insertAt(list,0,8);	
	display(list);
	
	deleteFront(list);	
	display(list);
	
	deleteBack(list);
	display(list);
	
	deleteAt(list,4);
	display(list);
	
	sort(list);
	display(list);

	deleteElement(list,2);
	display(list);

	insertAt(list,3,2);
	insertAt(list,3,2);
	insertAt(list,6,4);
	insertAt(list,6,4);
	display(list);

	removeConsecutiveDuplicates(list);
	display(list);


	return 0;
}