#include <stdio.h>
#include <stdlib.h>
#include "linked_list.c"

int main() {
    struct Node* head = NULL;


    for (int i = 1; i < 6; i++) {
        insert_at_index(&head, i, 0);
    }

    printf("Linked List: ");
    print_linked_list(head);


    printf("Element with index 0: %d\n", get_element_at_index(head, 0));
    printf("Element with index 2: %d\n", get_element_at_index(head, 2));
    printf("Element with index 4: %d\n", get_element_at_index(head, 4));

    int index_to_insert = 2;
    int value_to_insert = 10;

    printf("Inserting value: %d at index: %d\n.", value_to_insert, index_to_insert);
    insert_at_index(&head, value_to_insert, index_to_insert);

    printf("After insertion %d at index %d: ", value_to_insert, index_to_insert);
    print_linked_list(head);
    printf("Element with index 2: %d\n", get_element_at_index(head, 2));

    delete_at_index(&head, index_to_insert);
    printf("After deletion element with index %d: ", index_to_insert);
    print_linked_list(head);

    //check out of the range error
    insert_at_index(&head, value_to_insert, 6);

    free_memory(head);

    return 0;
}
