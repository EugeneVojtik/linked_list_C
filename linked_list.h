//#include <stdio.h>
//#include <stdlib.h>


struct Node {
    int value;
    struct Node* next;
};

struct Node* find_node_by_index(struct Node* head, int index);

int get_node_value(struct Node* node);

void check_index_validity(int index);

void check_index_oor(struct Node* node);

struct Node* create_node(int value);

void insert_first_element(struct Node* new_node, struct Node** head);

void insert_node_at_index(struct Node* previous_node, struct Node* new_node);

void insert_at_index(struct Node** head, int value, int index);

void delete_first_node(struct Node** head);

void delete_node_by_index(struct Node* node);

void delete_at_index(struct Node** head, int index);

void free_memory(struct Node* head);

int get_element_at_index(struct Node* head, int index);

void print_linked_list(struct Node* head);
