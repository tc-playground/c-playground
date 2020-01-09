#include "dll.h"

int length(dll_t *list) {
    int count = 0;
    dll_node_t *head = list->head;
    while (head) {
        count++;
        head = head->right;
    }
    return count;
}