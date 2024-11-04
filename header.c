#include "header.h"

DLIST createList(){
	DLIST list = (DLIST)malloc(sizeof(struct dlist));
	if(list == NULL){
		printf("List Allocation Failed!");
		exit(1);
	}
	list->size = 0;
	list->tail = NULL;
	list->head = NULL;
	return list;
}

void insertFront(DLIST list, element data){
	DNODE node = (DNODE)malloc(sizeof(struct dnode));
	if(node == NULL){
		printf("Node Allocation Failed!");
		exit(1);
	}

	node->data = data;
	node->prev = NULL;

	if(list->size == 0){
		node->next = NULL;
		list->head = node;
		list->tail = node;
	}else{
		node->next = list->head;
		list->head->prev = node;
		list->head = node;
	}
	list->size++;
}

void insertBack(DLIST list, element data){
	DNODE node = (DNODE)malloc(sizeof(struct dnode));
	if(node == NULL){
		printf("Node Allocation Failed!");
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

void insertAt(DLIST list, element data, int position){
	DNODE node = (DNODE)malloc(sizeof(struct dnode));
	if(node == NULL){
		printf("Node Allocation Failed!");
		exit(1);
	}

	if(position == 1){
		insertFront(list,data);
	} else if(position > list->size){
		insertBack(list,data);
	} else {
		node->data = data;
		DNODE temp = list->head;
		while(--position)
			temp = temp->next;

		temp->prev->next = node;
		node->prev = temp->prev;

		temp->prev = node;
		node->next = temp;
		list->size++;
	}
}

void deleteFront(DLIST list){
	DNODE temp = list->head;
	list->head->next->prev = NULL;
	list->head = list->head->next;
	list->size--;

	free(temp);
	temp = NULL;
}

void deleteBack(DLIST list){
	DNODE temp = list->tail;
	list->tail->prev->next = NULL;
	list->tail = list->tail->prev;
	list->size--;

	free(temp);
	temp = NULL;
}

void deleteAt(DLIST list, int position){
	if(position == 1){
		deleteFront(list);
	} else if(position == list->size){
		deleteBack(list);
	} else {
		DNODE temp = list->head;
		while(--position)
			temp = temp->next;

		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;

		free(temp);
		temp = NULL;
		list->size--;
	}
}

void sort(DLIST list){
	DNODE temp = list->head;
	element arr[list->size];
	for(int i=0;i<list->size;i++){
		arr[i] = temp->data;
		temp = temp->next;
	}
	for(int i=0;i<list->size-1;i++){
		int hold = i;
		for(int j=i+1;j<list->size;j++){
			if(arr[j]<arr[hold]){
				hold = j;
			}
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

void deleteElement(DLIST list, element data){
	DNODE temp = list->head;
	int pos = 1;
	while(temp != NULL){
		if(temp->data == data){
			DNODE nextNode = temp->next;
			deleteAt(list,pos);
			temp = nextNode;
		} else {
 			temp = temp->next;
 		}
		pos++;
	}
}

void removeConsecutiveDuplicates(DLIST list) {
    DNODE current = list->head;

    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            
            DNODE duplicate = current->next;

            current->next = duplicate->next;
            if (duplicate->next != NULL){
                duplicate->next->prev = current;
            } else {
                list->tail = current;
            }

            free(duplicate);
            list->size--;
        } else {            
            current = current->next;
        }
    }
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