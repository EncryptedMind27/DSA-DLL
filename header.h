#ifndef HEADER_H
#define HEADER_H
#include <stdlib.h>
#include <stdio.h>

typedef int element;
typedef struct dnode{
	element data;
	struct dnode* next;
	struct dnode* prev;
}*DNODE;
typedef struct dlist{
	int size;
	DNODE head;
	DNODE tail;
}*DLIST;

DLIST createList();
void insertFront(DLIST,element);
void insertBack(DLIST,element);
void insertAt(DLIST,element,int);
void deleteFront(DLIST);
void deleteBack(DLIST);
void deleteAt(DLIST,int);
void deleteElement(DLIST,element);
void removeConsecutiveDuplicate(DLIST);
void sortDLL(DLIST);
DLIST mergeList(DLIST,DLIST);
void addZeroBeforeAndAfterX(DLIST,element);
void deleteLastOccurence(DLIST,element);
void removeEveryXthNode(DLIST,int);
void display(DLIST);


#endif