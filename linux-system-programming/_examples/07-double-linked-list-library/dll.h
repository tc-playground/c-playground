#ifndef __DLL__
#define __DLL__

// Double-Linked-List Header --------------------------------------------------

// Types

typedef struct dll_node {
    void *data;
    struct dll_node *left;
    struct dll_node *right;
} dll_node_t;

typedef struct dll_{
    dll_node_t *head;
    int (*key_match)(void *, void *);
} dll_t;


// Public Functions -----------------------------------------------------------

// Create a new empty Double-Linked-List.
// Return a pointer to the new list.
dll_t *get_new_dll();

// Add an element to a Double-Linked-List.
// Return 0 if successful.
int add_data_to_dll(dll_t *dll, void *app_data);


// Generic Functions ----------------------------------------------------------

void* dll_find_by_key(dll_t *dll, void *key);


// Callback Registration Functions --------------------------------------------

void register_key_match_callback(dll_t *dll, int(*keymatch)(void *, void *));


#endif