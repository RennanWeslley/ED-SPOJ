#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
}tNode;

typedef struct {
    tNode *back;
    tNode *front;
    int reverse;
    int size;
}tQueue;

int size(tQueue);
int empty(tQueue);
int getReverse(tQueue);
int pushEmpty(tQueue *, int);
int pushBack(tQueue *, int);
int pushFront(tQueue *, int);
int popBack(tQueue *);
int popFront(tQueue *);
int toFront(tQueue *, int);
int push_back(tQueue *, int);
int front(tQueue *);
int back(tQueue *);
int reverse(tQueue *, int);

int main() {
    tQueue queue;
    
    queue.back = NULL;
    queue.front = NULL;
    queue.reverse = 0;
    queue.size = 0;
    
    long long bounds;
    int i = 2;
    int data;
    char op[25];
    
    scanf(" %Ld", &bounds);
    
    do{
        scanf(" %s", op);
        
        if(!strcmp(op, "back"))
            back(&queue);
        else if(!strcmp(op, "front"))
            front(&queue);
        else if(!strcmp(op, "reverse")) {
            i++;
            reverse(&queue, i);
        }
        else if(!strcmp(op, "push_back")) {
            scanf(" %d", &data);
            push_back(&queue, data);
        }
        else if(!strcmp(op, "toFront")) {
            scanf(" %d", &data);
            toFront(&queue, data);
        }
        
        bounds--;
    }while(bounds > 0);
}

int size(tQueue queue) {
    return queue.size;
}

int empty(tQueue queue) {
    return queue.size == 0;
}

int getReverse(tQueue queue) {
    return queue.reverse;
}

int pushEmpty(tQueue *queue, int data) {
    tNode *new = (tNode *) malloc(sizeof(tNode));
    
    new->data = data;
    new->next = NULL;
    new->prev = NULL;
    queue->back = new;
    queue->front = new;
    
    queue->size++;
    
    return 1;
}

int pushBack(tQueue *queue, int data) {
    if(empty(*queue))
        return pushEmpty(queue, data);
    
    tNode *new = (tNode *) malloc(sizeof(tNode));
    tNode *p = queue->back;
    
    new->data = data;
    new->prev = NULL;
    new->next = p;
    p->prev = new;
    queue->back = new;

    queue->size++;
    
    return 1;
}

int pushFront(tQueue *queue, int data) {
    if(empty(*queue))
        return pushEmpty(queue, data);
    
	tNode *new = (tNode *) malloc(sizeof(tNode));
	tNode *p = queue->front;
    
	new->data = data;
	new->next = NULL;
	new->prev = p;
	p->next = new;
	queue->front = new;
    
    queue->size++;
}

int popBack(tQueue *queue) {
    if(empty(*queue)) {
        printf("No job for Ada?\n");
        return 0;
    }
    
    tNode *p = queue->back;
	
	printf("%d\n", p->data);
	queue->back = p->next;
	
	if(size(*queue) > 1)
		queue->back->prev = NULL;
	
	free(p);
	
	queue->size--;
	
	return 1;
}

int popFront(tQueue *queue) {
    if(empty(*queue)){
        printf("No job for Ada?\n");
        return 0;
    }
    
    tNode *p = queue->front;
	
	printf("%d\n", p->data);
	queue->front = p->prev;
	
	if(size(*queue) > 1)
		queue->front->next = NULL;
		
	free(p);
	
	queue->size--;
	
	return 1;
}

int toFront(tQueue *queue, int data) {
    if(getReverse(*queue))
        return pushBack(queue, data);
    else
        return pushFront(queue, data);
}

int push_back(tQueue *queue, int data) {
    if(getReverse(*queue))
        return pushFront(queue, data);
    else
        return pushBack(queue, data);
}

int front(tQueue *queue) {
    if(getReverse(*queue))
        return popBack(queue);
    else
        return popFront(queue);
}

int back(tQueue *queue) {
    if(getReverse(*queue))
        return popFront(queue);
    else
        return popBack(queue);
}

int reverse(tQueue *queue, int i) {
    queue->reverse = i%2;
    return 1;
}