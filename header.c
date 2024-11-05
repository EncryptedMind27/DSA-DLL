#include "header.h"

DLIST createList(){
	DLIST list = (DLIST)malloc(sizeof(struct dlist));
	if(list == NULL){
		printf("List Allocation Failed!\n");
		exit(1);
	}

	list->head = NULL;
	list->tail = NULL; 
	list->size = 0;

	return list;
}

void insertFront(DLIST list, element data){
	DNODE node = (DNODE)malloc(sizeof(struct dnode));
	if(node == NULL){
		printf("Node Allocation Failed!\n");
		exit(1); 	
	}
	node->data = data;
	node->prev = NULL;
	if(list->size == 0){
		list->head = node;
		list->tail = node; 
		node->next = NULL;
	} else {
		node->next = list->head;
		list->head->prev = node;
		list->head = node;
	}
	list->size++;
}

void insertBack(DLIST list, element data){
	DNODE node = (DNODE)malloc(sizeof(struct dnode));
	if(node == NULL){
		printf("Node Allocation Failed!\n");
		exit(1);
	}
	node->data = data;
	node->next = NULL;
	if(list->size == 0){
		list->head = node;
		list->tail = node;
		node->prev = NULL;
	} else {
		node->prev = list->tail;
		list->tail->next = node;
		list->tail = node;
	}
	list->size++;
}

void insertAt(DLIST list, element data, int pos){
	if(pos == 1){
		insertFront(list,data);
	} else if(pos > list->size){
		insertBack(list,data); 
	} else {
		DNODE node = (DNODE)malloc(sizeof(struct dnode));
		if(node == NULL){ 
			printf("Node Allocation Failed!\n");
			exit(1);
		}

		DNODE temp = list->head;
		while(--pos)
			temp = temp->next;
		node->data = data;
		node->next = temp;
		node->prev = temp->prev;

		temp->prev->next = node;
		temp->prev = node;
		list->size++;
	}
}

void deleteFront(DLIST list){
	DNODE temp = list->head;
	list->head = temp->next;
	list->head->prev = NULL;
	list->size--;

	free(temp);
	temp = NULL;
}

void deleteBack(DLIST list){
	DNODE temp = list->tail;
	list->tail = temp->prev;
	list->tail->next = NULL;
	list->size--;

	free(temp);
	temp = NULL;
}

void deleteAt(DLIST list, int pos){
	if(pos == 1){
		deleteFront(list);
	} else if(pos == list->size){
		deleteBack(list);
	} else {
		DNODE temp = list->head;
		while(--pos)
			temp = temp->next;

		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;

		list->size--;

		free(temp);
		temp = NULL;
	}
}

void deleteElement(DLIST list, element data) {
    DNODE current = list->head;

    while(current != NULL) {
        if(current->data == data){
            DNODE toDelete = current; 
            if(toDelete->prev != NULL){
                toDelete->prev->next = toDelete->next;
            }else{   
                list->head = toDelete->next;
            }

            if(toDelete->next != NULL){
                toDelete->next->prev = toDelete->prev;
            } else{               
                list->tail = toDelete->prev;
            }

            current = toDelete->next; 
            free(toDelete); 
            list->size--; 
        } else{
            current = current->next; 
        }
    }
}


void sortDLL(DLIST list){
	DNODE temp = list->head;
	element arr[list->size];
	for(int i=0;i<list->size;i++){
		arr[i] = temp->data;
		temp = temp->next;
	}
	for(int i=0;i<list->size-1;i++){
		int hold = i;
		for(int j=i;j<list->size;j++){
			if(arr[j]<arr[hold])
				hold = j;
		}
		element eTemp = arr[i];
		arr[i] = arr[hold];
		arr[hold] = eTemp;
	}
	temp = list->head;
	for(int i=0;i<list->size;i++){
		temp->data = arr[i];
		temp = temp->next;
	}
}

void removeConsecutiveDuplicate(DLIST list){
	DNODE current = list->head;
	while(current != NULL && current->next != NULL){
		if(current->data == current->next->data){
			DNODE duplicate = current->next;
			current->next = duplicate->next;
			if(duplicate->next != NULL){
				duplicate->next->prev = current;
			} else {
				list->tail = current; 
			}
			free(duplicate);
			duplicate = NULL;
			list->size--;
		} else {
			current = current->next;
		}
	}
}

DLIST mergeList(DLIST list1, DLIST list2){
	list1->tail->next = list2->head;
	list2->head->prev = list1->tail;

	list1->size += list2->size;

	list2->head = NULL;
	list2->tail = NULL;
	list2->size = 0;
	return list1;
}

void display(DLIST list){
	DNODE temp = list->head;
	printf("[%d]: ",list->size);
	while(temp != NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}
