#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

struct Node* find_node_by_index(struct Node* head, int index) {
    int counter = 0;
    while (head != NULL && counter < index) {
        head = head->next;
        counter++;
    }
    return head;
}


int get_node_value(struct Node* node){
   return node->value;
}


void check_index_validity(int index){
    if (index < 0) {
        printf("Invalid index.\n");
        return;
    }
}



struct Node* create_node(int value) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}


void insert_first_element(struct Node* new_node, struct Node** head){
    new_node->next = *head;
    *head = new_node;
}


void insert_node_at_index(struct Node* previous_node, struct Node* new_node){
    if (previous_node == NULL){
        printf("Index out of range.\n");
        return;
    }
    new_node->next = previous_node->next;
    previous_node->next = new_node;
}


void insert_at_index(struct Node** head, int value, int index) {
    struct Node* new_node = create_node(value);
    check_index_validity(index);

    if (index == 0) {
        insert_first_element(new_node, head);
        return;
    }

    struct Node* previous_node = find_node_by_index(*head, index - 1);
    insert_node_at_index(previous_node, new_node);
}


void delete_first_node(struct Node** head){
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
    return;
}

void delete_node_by_index(struct Node* node){
    if (node == NULL || node->next == NULL) {
        printf("Index out of range.\n");
        return;
    }
    struct Node* tmp = node->next;
    node->next = node->next->next;
    free(tmp);
}


void delete_at_index(struct Node** head, int index) {
    check_index_validity(index);

    if (index == 0) {
        delete_first_node(head);
        return;
    }

    struct Node* previous_node = find_node_by_index(*head, index - 1);
    delete_node_by_index(previous_node);
}


void free_memory(struct Node* head){
    while(head != NULL) {
        delete_at_index(&head, 0);
    }
}


int get_element_at_index(struct Node* head, int index) {
    struct Node* node = find_node_by_index(head, index);
    if (node == NULL) {
        printf("Index out of range.\n");
        return -1;
    }
    return get_node_value(node);
}


void print_linked_list(struct Node* head) {
    while (head != NULL) {
        printf("%d, ", head->value);
        head = head->next;
    }
    printf("\n");
}
