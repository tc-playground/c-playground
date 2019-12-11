#include "dll.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct node {    
    int id;
    char name[32];
    char data[256];
} node_t;

static void
print_node(node_t *node) {
    printf("id   = %d\n", node->id);
    printf("name = %s\n", node->name);
    printf("data = %s\n", node->data);
}

static void
print_node_db(dll_t *node_db) {

    if (!node_db || !node_db->head) {
        return;
    }

    dll_node_t *head = node_db->head;
    node_t *data = NULL;

    while (head) {
        data = head->data;
        print_node(data);
        head = head->right;    
    }
}

int 
main(int argc, char **argv) {

    node_t * node_00 = calloc(1, sizeof(node_t));
    node_00->id = 0;
    strncpy(node_00->name, "name_00", strlen("name_00"));
    strncpy(node_00->data, "data_00", strlen("data_00"));

    node_t * node_01 = calloc(1, sizeof(node_t));
    node_01->id = 1;
    strncpy(node_01->name, "name_01", strlen("name_01"));
    strncpy(node_01->data, "data_01", strlen("data_01"));

    node_t * node_02 = calloc(1, sizeof(node_t));
    node_02->id = 2;
    strncpy(node_02->name, "name_02", strlen("name_02"));
    strncpy(node_02->data, "data_02", strlen("data_02"));

    // Create a new Linked List

    dll_t *node_db = get_new_dll();
    add_data_to_dll(node_db, node_00);
    add_data_to_dll(node_db, node_01);
    add_data_to_dll(node_db, node_02);

    print_node_db(node_db);
    
    return 0;
}