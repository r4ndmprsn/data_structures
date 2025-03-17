#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
    int data;
    struct Node* next;
};
struct Queue{
    struct Node* front;
    struct Node* rear;
};
struct Node* create_node(int data){
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    if(!new_node){
        return NULL;
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
struct Queue* create_queue(){
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    if(!queue){
        return NULL;
    }
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}
//returns if the queue is empty
bool is_empty(struct Queue* queue){
    if(queue->front == NULL){
        return true;
    }
    return false;
}
//adds a node to the queue
void enqueue(struct Queue* queue, int data){
    struct Node* new_node = create_node(data);
    if(queue->front == NULL){
        queue->front = new_node;
        queue->rear = new_node;
    }
    else{
        queue->rear->next = new_node;
        queue->rear = new_node;
    }
}
//removes a node from the queue and returns it
int dequeue(struct Queue* queue){
    if(queue->front == NULL){
        printf("ERROR: queue is already empty");
        return -1;
    }
    struct Node* erase = queue->front;
    int data = queue->front->data;
    queue->front = queue->front->next;
    free(erase);
    erase = NULL;
    return data;
}
//returns a node from the front of the queue
int front(struct Queue* queue){
    if(queue->front == NULL){
        printf("ERROR: queue is empty");
        return -1;
    }
    return queue->front->data;
}
//frees all of the nodes' memory
void free_queue(struct Queue* queue){
    if(queue == NULL){
        return;
    }
    while(queue->front != NULL){
        struct Node* cleanup = queue->front;
        queue->front = queue->front->next;
        free(cleanup);
        cleanup = NULL;
    }
    free(queue);
    queue = NULL;
}
int main(){
    struct Queue* queue = create_queue();
    printf("%d\n", is_empty(queue));
    printf("%d\n",front(queue));
    enqueue(queue, 1);
    printf("%d\n",front(queue));
    enqueue(queue, 2);
    printf("%d\n",dequeue(queue));
    printf("%d\n",dequeue(queue));
    printf("%d\n",dequeue(queue));
    printf("%d\n", is_empty(queue));
    free_queue(queue);
    return 0;
}