#include"queue.h"

#include<stdio.h>
#include<stdlib.h>

typedef struct node_ NODE;

struct node_{
    NODE *next;
    CARTA carta;
};

struct queue_{
    NODE *front;
    NODE *back;
    int size;
};

QUEUE *queue_generate(){
    QUEUE *q = (QUEUE*) malloc(sizeof(QUEUE));
    if(q != NULL){
        q->front = NULL;
        q->back = NULL;
        q->size = 0;
    }
    return(q);
}

void queue_push(QUEUE *queue, CARTA carta){
    if(!queue_full(queue)){
        NODE *node = (NODE*) malloc(sizeof(NODE));
        node->next = NULL;
        if(queue->front == NULL){
            queue->front = node;
            queue->back = node; 
        }
        else{
            queue->back->next = node;
            queue->back = node;
        }
        node->carta = carta;
        queue->size++;
    }
}   

CARTA queue_pop(QUEUE *queue){
    CARTA carta;
    if(!queue_empty(queue)){
        NODE *erase_node;
        
        erase_node = queue->front;
        carta = erase_node->carta;
        queue->front = erase_node->next;

        free(erase_node);
        erase_node = NULL;
        queue->size--;

        if(queue->front == NULL)
            queue->back = NULL;
        
    }
    return carta;
}

bool queue_empty(QUEUE *queue){
    if(queue != NULL){
        return(queue->size == 0);
    }
    return true;
}

bool queue_full(QUEUE *queue){
    if(queue != NULL){
        NODE *node = (NODE*) malloc(sizeof(NODE));

        if(node == NULL) return true;

        free(node);
        node = NULL;

        return false;
    }
    return true;
}

void queue_erase(QUEUE **queue){
    if(!queue_empty(*queue)){
        NODE *queue_erase = (*queue)->front;
        while(queue_erase != NULL){
            (*queue)->front = (*queue)->front->next;
            free(queue_erase);
            queue_erase = (*queue)->front;
        }
        free(*queue);
        *queue = NULL;
    }
}

int queue_size(QUEUE *queue){
    if(queue != NULL){
        return(queue->size);
    }
    return(-1);
}

void queue_print(QUEUE *queue){
    if(!queue_empty(queue)){
        NODE *node = queue->front;
        printf("Queue: \n");
        while(node != NULL){
            printf("%s %s\n", node->carta.naipe, node->carta.valor);
            node = node->next;
        }
        printf("\n");
    }
}

    