/**
 * File name: list.c
 * Description: Contains the implementation of the functions defined in the header file.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

list* create_list() {
    // printf("size of list struct: %lu\n", sizeof(list));
    list *new_list = (list*)malloc(sizeof(list));

    if (!new_list)
        printf("something went wrong: error while creating new list\n");
    else
        (*new_list).head = NULL;

    return new_list;
}

int add_to_list(list* ll, char* item) {
    if (ll == NULL || item == NULL) {
        printf("something went wrong: provided arguments are not valid\n");
        return 1;
    }

    // create a node for the item (every NodeItem has a pointer to data and next item)
    NodeItem *newNode = (NodeItem*)malloc(sizeof(NodeItem));
    if (!newNode) {
        printf("something went wrong: error while creating new node item\n");
        return 1;
    }

    (*newNode).data = strdup(item);
    if ((*newNode).data == NULL) {
        printf("something went wrong: failed to add item to list\n");
        return 1;
    }

    (*newNode).next = NULL;

    // check if the list does not have a head node and assign the NodeItem as the head
    // else point the last NodeItem to the address of the new NodeItem
    if ((*ll).head == NULL) {
        (*ll).head = newNode;
    } else {
        NodeItem *current = (*ll).head;

        // fast track to the end of the node items
        while ((*current).next) {
            current = (*current).next;
        }

        // next is currently NULL, so set it to the new NodeItem
        (*current).next = newNode;
    }

    return 0;
}

void print_list(list *ll) {
    if (ll == NULL || (*ll).head == NULL) {
        printf("provided list is empty\n");
        return;
    }

    printf("printing list items...\n");

    NodeItem *current = (*ll).head;

    // iterate through all the NodeItem and print their data
    while (current != NULL) {
        printf("%s\n", (*current).data);
        current = (*current).next;
    }
}

char* remove_from_list(list* ll) {
    if (ll == NULL || (*ll).head == NULL) {
        printf("something went wrong: provided list is empty\n");
        return NULL;
    }

    // get the list's head node and make it's head attribute point to the next node
    NodeItem *current = (*ll).head;
    (*ll).head = (*current).next;

    // free the memory of the removed node
    char *data = (*current).data;
    free(current);

    return data;
}

int flush_list(list* ll) {
    if (ll == NULL) {
        printf("something went wrong: provided list is empty\n");
        return 1;
    }

    int count = 0;

    while ((*ll).head != NULL) {
        // get the current node and free the memory allocated to the data stored and the NodeItem
        NodeItem *current = (*ll).head;
        (*ll).head = (*current).next;

        free((*current).data);
        free((current));

        count++;
    }

    return count;
}

void free_list(list *ll) {
    if (ll == NULL) {
        printf("something went wrong: provided list is empty\n");
        return;
    }

    // free memory allocated to the NodeItems and the list itself
    flush_list(ll);
    free(ll);
    ll = NULL;

    printf("memory freed and list is no longer usable\n");
}

