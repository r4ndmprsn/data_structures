#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
    int data;
    struct Node* next;
};
struct Stack{
    struct Node* top;
};
//creates a stack
struct Stack* create_stack(){
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if(!stack){
        return NULL;
    }
    stack->top = NULL;
    return stack;
}
//creates a node
struct Node* create_node(int data){
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    if(!new_node){
        return NULL;
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
bool is_empty(struct Stack* stack){
    if(stack->top == NULL){
        return true;
    }
    return false;
}
//adds a new node to the stack
void push(struct Stack* stack, int data){
    if(stack->top == NULL){
        stack->top = create_node(data);
    }
    else{
        struct Node* new_top = create_node(data);
        new_top->next = stack->top;
        stack->top = new_top;
    }
}
//removes a node from the top of the stack and returns its value
int pop(struct Stack* stack){
    if(stack->top == NULL){
        printf("ERROR: stack is already empty");
        return -1;
    }
    else{
        struct Node* erase = stack->top;
        int data = erase->data;
        stack->top = stack->top->next;
        free(erase);
        erase = NULL;
        return data;
    }
}
//returns the data from a node from the top of the stack
int peak(struct Stack* stack){
    if(stack->top == NULL){
        printf("ERROR: stack is empty");
        return -1;
    }
    return stack->top->data; 
}
//frees all of the nodes' memory
void free_stack(struct Stack* stack){
    if(stack == NULL){
        return;
    }
    while(stack->top != NULL){
        struct Node* cleanup = stack->top;
        stack->top = stack->top->next;
        free(cleanup);
        cleanup = NULL;
    }
    free(stack);
    stack = NULL;
}
int main(){
    struct Stack* stack = create_stack();
    printf("%d\n", is_empty(stack));
    push(stack, 1);
    printf("%d\n",peak(stack));
    push(stack, 2);
    printf("%d\n",peak(stack));
    push(stack, 3);
    printf("%d\n", is_empty(stack));
    printf("%d\n",peak(stack));
    printf("%d\n",pop(stack));
    printf("%d\n",pop(stack));
    printf("%d\n",pop(stack));
    printf("%d\n",pop(stack));
    
    free_stack(stack);
    return 0;
}
