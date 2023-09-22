/**
 * File name: list.h
 * Description: Contains the type definitions and function protoypes used in the program.
*/

struct Node {
    char *data;
    struct Node *next;
};

typedef struct Node NodeItem;

typedef struct {
    struct Node *head;
} list;

/* Allocates and initializes a new list. */
list* create_list();

/* 
* Adds item to end of the list. This function allocates a
* new buffer and copies the string from item (use malloc,
* strlen, and strncpy; or try strdup).
* Returns 0 if successful, non-zero otherwise. 
*/
int add_to_list(list* ll, char* item);

/* 
* Removes the string from the front of the list and
* returns a pointer to it. The caller is expected to free
* the string returned when finished with it. Returns NULL
* if the list is empty.
*/
char* remove_from_list(list* ll);

/* 
* Prints every string in the list, with a new line
* character at the end of each string. 
*/
void print_list(list *ll);

/* 
* Flushes (clears) the entire list and re-initializes the
* list. The passed pointer ll should still point to a
* valid, empty list when this function returns. Any memory
* allocated to store items in the list should be freed.
* Returns the number of items flushed from the list. 
*/
int flush_list(list* ll);

/* 
* De-allocates all data for the list. Ensure all memory
* allocated for this list is freed, including any
* allocated strings and the list itself. 
*/
void free_list(list *ll);