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
} dll_t;


// Public Functions -----------------------------------------------------------

// Create a new empty Double-Linked-List.
// Return a pointer to the new list.
dll_t *get_new_dll();

// Add an element to a Double-Linked-List.
// Return 0 if successful.
int add_data_to_dll (dll_t *dll, void *app_data);

#endif