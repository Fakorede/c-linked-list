/** 
 * File name: list_test.c
 * Description: Contains the test cases for the linked list implementation.
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
    // Test: create list
    list *myList = create_list();
    if (myList != NULL) {
        printf("list created successfully\n");
    }

    // Test: add items to list
    int returnValue;
    
    returnValue = add_to_list(myList, "hello");
    if (returnValue == 0) {
        printf("item added to list successfully\n");
    }

    returnValue = add_to_list(myList, "Burrow");
     if (returnValue == 0) {
        printf("item added to list successfully\n");
    }

    returnValue =  add_to_list(myList, "Chase");
     if (returnValue == 0) {
        printf("item added to list successfully\n");
    }

    returnValue = add_to_list(myList, "Jefferson");
     if (returnValue == 0) {
        printf("item added to list successfully\n");
    }

    // Test: print list items
    print_list(myList);

    // Test: remove items from list
    char *removedItem = remove_from_list(myList);
    if (removedItem != NULL) {
        printf("removed item: %s\n", removedItem);
        free(removedItem);
        removedItem = NULL;
    }
    print_list(myList);

    // Test: flush list items
    int count = flush_list(myList);
    printf("flushed %d items from the list.\n", count);
    print_list(myList);

    returnValue = add_to_list(myList, "try now");
    if (returnValue == 0) {
        printf("item added to list successfully\n");
    }

    free_list(myList);

    return 0;
}

