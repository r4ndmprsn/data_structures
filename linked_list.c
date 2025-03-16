#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct Node{
    int data;
    struct Node* next;
};
//returns true if the list is empty and false if it is not
bool is_empty(struct Node* head){
    if(head == NULL){
        return true;
    }
    return false;
}
//returns the length of the list
int list_length(struct Node* head){
    struct Node* current = head;
    int length = 0;
    while(current != NULL){
        current = current->next;
        length++;
    }
    return length;
}
//prints all of the nodes in the list
void print_list(struct Node* head){
    if(head == NULL){
        return;
    }    
    else{
        struct Node* current = head;
        while(current != NULL){
            printf("%d ",current->data);
            current = current->next;
        }
    }
}
//frees all of the nodes' memory
void free_list(struct Node* head){
    if(head == NULL)    return;
    struct Node* current = head;
    while(current != NULL){
        struct Node* cleanup = current;
        current = current->next;
        free(cleanup);
    }
    free(current);
}
//creates a new node
struct Node* create_node(int data){
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    if(!new_node){
        return NULL;
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
//adds a node at the beginning
struct Node* add_at_beggining(struct Node* head, int data){
    if(head == NULL){
        head = create_node(data);
        return head;
    }
    else{
        struct Node* new_head =  create_node(data);
        new_head->next = head;
        return new_head;
    }
}
//adds a node at the end
struct Node* add_at_end(struct Node* head, int data){
    if(head == NULL){
        head = create_node(data);
    }
    else{
        struct Node* new_node = create_node(data);
        struct Node* current = head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = new_node;
    }
    return head;
}
//adds a node at a specific position
struct Node* add_at_specific_position(struct Node* head, int data, int position){
    if(position == 0){
        head = add_at_beggining(head, data);
    }
    else if(position == list_length(head)){
        head = add_at_end(head, data);
    }
    else if(position >= list_length(head)){
        return NULL;
    }
    else{
        struct Node* new_node = create_node(data);
        struct Node* current = head;
        for(int i = 0; i<position-1; i++){
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
    return head;
}
//updates the value of the node at a specific position
struct Node* update_node(struct Node* head, int data, int position){
    if(position >= list_length(head)){
        return NULL;
    }
    else{
        struct Node* current = head;
        for(int i = 0; i<position; i++){
            current = current->next;
        }
        current->data = data;
    }
    return head;
}
//deletes a node at the beginning
struct Node* delete_at_beginning(struct Node* head){
    if(head == NULL){
        return NULL;
    }
    else if(head->next == NULL){
        free(head);
        head = NULL;
    }
    else{
        struct Node* erase = head;
        head = head->next;
        free(erase);
        erase = NULL;
    }
    return head;
}
//deletes a node at the end
struct Node* delete_at_end(struct Node* head){
    if(head == NULL){
        return NULL;
    }
    if(head->next == NULL){
        free(head);
        head = NULL;
    }
    else{
        struct Node* current = head;
        while(current->next->next != NULL){
            current = current->next;
        }
        struct Node* erase = current->next;
        current->next = NULL;
        free(erase);
        erase = NULL;
    }
    return head;
}
//deletes a node at a specific position
struct Node* delete_at_specific_position(struct Node* head, int position){
    if(head == NULL){
        return NULL;
    }
    else if(position >= list_length(head)){
        printf("ERROR: this position is out of bound, no changes made\n");
    }
    else if(position == 0){
        head = delete_at_beginning(head);
    }
    else if(position == list_length(head)-1){
        head = delete_at_end(head);
    }
    else{
        struct Node* current = head;
        for(int i = 0; i<position-1; i++){
            current = current->next;
        }
        struct Node* erase = current->next;
        current->next = current->next->next;
        free(erase);
        erase = NULL;
    }
    return head;
}
// returns the zero-based position of the node containing the first occurrence of the target value
// returns -1 if the value is not found
int search_list(struct Node* head, int target_value){
    if(head != NULL){
        struct Node* current = head;
        int position = 0;
        while(current != NULL){
            if(current->data == target_value){
                return position;
            }
            current = current->next;
            position++;
        }
    }
    return -1;
}
//returns the biggest value in the list
int list_max(struct Node* head){
    if(head == NULL){
        return -1;
    }
    else{
        struct Node* current = head;
        int max = INT_MIN, position = 0, max_position = 0;
        while(current != NULL){
            if(current->data > max){
                max = current->data;
                max_position = position;
            }
            position++;
        current = current->next;
        }
        return max_position;
    }
}
//returns the smallest value in the list
int list_min(struct Node* head){
    if(head == NULL){
        return -1;
    }
    else{
        struct Node* current = head;
        int min = INT_MAX, position = 0, min_position = 0;
        while(current != NULL){
            if(current->data < min){
                min = current->data;
                min_position = position;
            }
            position++;
        current = current->next;
        }
        return min_position;
    }
}
//reverses the order of the list
struct Node* reverse_list(struct Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    else{
        struct Node* prev = NULL;
        struct Node* current = head;
        struct Node* next = NULL;
        while(current != NULL){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
}
int main(){
    struct Node* head = NULL;
    print_list(head);
    printf("length of the list: %d\n", list_length(head));
    printf("%d\n", is_empty(head));
    head = add_at_beggining(head, 1);
    head = add_at_beggining(head, 2);
    print_list(head);
    printf("length of the list: %d\n", list_length(head));
    printf("%d\n", is_empty(head));
    head = add_at_end(head, 3);
    print_list(head);
    printf("length of the list: %d\n", list_length(head));
    head = add_at_specific_position(head, 4, 2);
    print_list(head);
    printf("length of the list: %d\n", list_length(head));
    head = update_node(head, 5, 3);
    head = update_node(head, 6, 2);
    print_list(head);
    printf("length of the list: %d\n", list_length(head));
    head = delete_at_beginning(head);
    print_list(head);
    printf("length of the list: %d\n", list_length(head));
    head = delete_at_end(head);
    print_list(head);
    printf("length of the list: %d\n", list_length(head));
    head = add_at_beggining(head, 7);
    head = add_at_beggining(head, 8);
    print_list(head);
    printf("length of the list: %d\n", list_length(head));
    head = delete_at_specific_position(head, 2);
    print_list(head);
    printf("length of the list: %d\n", list_length(head));
    int found = search_list(head, 7);
    if(found == -1){
        printf("target value not found\n");
    }
    else{
        printf("target value at %d\n", found);
    }   
    printf("position of the biggest value: %d\n",list_max(head));
    printf("position of the smallest value: %d\n",list_min(head));
    head = reverse_list(head);
    print_list(head);
    printf("length of the list: %d\n", list_length(head));
    free_list(head);
    return 0;
}
