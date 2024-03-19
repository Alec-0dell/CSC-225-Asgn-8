/*
 * Defines functions for linked lists
 * CSC 225, Assignment 8
 * Given code, Winter '24
 */

#include <stdlib.h>
#include "list.h"

/* lstcreate: Creates an empty linked list. */
List *lstcreate() {
    /* TODO: Complete this function, given no arguments:
     * ...return a pointer to a new, dynamically allocated List structure. */
}

/* lstdestroy: Destroys an existing linked list. */
void lstdestroy(List *lst) {
    /* TODO: Complete this function, given:
     *  lst - A pointer to a List structure
     * ...deallocate all memory associated with "lst". */
}

/* lstsize: Computes the size of a linked list. */
unsigned int lstsize(List *lst) {
    /* TODO: Complete this function, given:
     *  lst - A pointer to a List structure
     * ...return the number of nodes in "lst". */
}

/* lstget: Gets an element in a linked list at an index. */
void *lstget(List *lst, unsigned int idx) {
    /* TODO: Complete this function, given:
     *  lst - A pointer to a List structure
     *  idx - A non-negative index
     * ...return a pointer to element "idx" of "lst", NULL if "idx" outside
     * bounds [0, size - 1] */
}

/* lstset: Sets an element in a linked list at an index. */
int lstset(List *lst, unsigned int idx, void *data) {
    /* TODO: Complete this function, given:
     *  lst  - A pointer to a List structure
     *  idx  - A non-negative index
     *  data - A pointer to a desired element
     * ...set element "idx" of "lst" to "data"; return 0 on success, 1 if "idx"
     * outside bounds [0, size - 1]. */
}

/* lstadd: Adds an element to a linked list at an index. */
int lstadd(List *lst, unsigned int idx, void *data) {
    /* TODO: Complete this function, given:
     *  lst  - A pointer to a List structure
     *  idx  - A non-negative index
     *  data - A pointer to a desired element
     * ...add "data" as element "idx" of "lst", shifting existing elements as
     * necessary; return 0 on success, 1 if "idx" outside bounds [0, size]. */
}

/* lstremove: Removes an element from a linked list at an index. */
void *lstremove(List *lst, unsigned int idx) {
    /* TODO: Complete this function, given:
     *  lst  - A pointer to a List structure
     *  idx  - A non-negative index
     * ...remove element "idx" of "lst", shifting remaining elements as
     * necessary; return a pointer to the removed element, NULL if "idx"
     * outside bounds [0, size - 1]. */
}

/* lstreverse: Creates a new linked list in reverse order. */
List *lstreverse(List *lst) {
    /* TODO: Complete this function, given:
     *  lst  - A pointer to a List structure
     * ...return a pointer to a new, dynamically allocated List structure
     * containing the elements of "lst" in reverse order. */
}
