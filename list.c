/*
 * Defines functions for linked lists
 * CSC 225, Assignment 8
 * Given code, Winter '24
 */

#include <stdlib.h>
#include "list.h"

/* lstcreate: Creates an empty linked list. */
List *lstcreate(void)
{
    /* TODO: Complete this function, given no arguments:
     * ...return a pointer to a new, dynamically allocated List structure. */
    List *lst = (List *)malloc(sizeof(List));
    lst->head = NULL;
    lst->size = 0;
    return lst;
}

/* lstdestroy: Destroys an existing linked list. */
void lstdestroy(List *lst)
{
    /* TODO: Complete this function, given:
     *  lst - A pointer to a List structure
     * ...deallocate all memory associated with "lst". */
    Node *curNode;
    while (lst->head != NULL)
    {
        curNode = lst->head;
        lst->head = lst->head->next;
        free(curNode);
    }
}

/* lstsize: Computes the size of a linked list. */
unsigned int lstsize(List *lst)
{
    /* TODO: Complete this function, given:
     *  lst - A pointer to a List structure
     * ...return the number of nodes in "lst". */
    return lst->size;
}

/* lstget: Gets an element in a linked list at an index. */
void *lstget(List *lst, unsigned int idx)
{
    /* TODO: Complete this function, given:
     *  lst - A pointer to a List structure
     *  idx - A non-negative index
     * ...return a pointer to element "idx" of "lst", NULL if "idx" outside
     * bounds [0, size - 1] */
    Node *curNode = lst->head;
    if (curNode == NULL)
    {
        return NULL;
    }
    while (curNode != NULL)
    {
        if (idx == 0)
        {
            return curNode->data;
        }
        curNode = curNode->next;
        idx--;
    }
    return NULL;
}

/* lstset: Sets an element in a linked list at an index. */
int lstset(List *lst, unsigned int idx, void *data)
{
    /* TODO: Complete this function, given:
     *  lst  - A pointer to a List structure
     *  idx  - A non-negative index
     *  data - A pointer to a desired element
     * ...set element "idx" of "lst" to "data"; return 0 on success, 1 if "idx"
     * outside bounds [0, size - 1]. */
    Node *curNode = lst->head;
    if (curNode == NULL)
    {
        return 1;
    }
    while (curNode != NULL)
    {
        if (idx == 0)
        {
            curNode->data = data;
            return 0;
        }
        curNode = curNode->next;
        idx--;
    }
    return 1;
}

/* lstadd: Adds an element to a linked list at an index. */
int lstadd(List *lst, unsigned int idx, void *data)
{
    /* TODO: Complete this function, given:
     *  lst  - A pointer to a List structure
     *  idx  - A non-negative index
     *  data - A pointer to a desired element
     * ...add "data" as element "idx" of "lst", shifting existing elements as
     * necessary; return 0 on success, 1 if "idx" outside bounds [0, size]. */
    Node *curNode = lst->head;
    Node *prevNode = NULL;
    if (idx > lst->size)
    {
        return 1;
    }
    if (idx == 0)
    {
        Node *nd = (Node *)malloc(sizeof(Node));
        nd->data = data;
        nd->next = lst->head;
        lst->head = nd;
        lst->size++;
        return 0;
    }
    while (curNode != NULL && idx > 0)
    {
        prevNode = curNode;
        curNode = curNode->next;
        idx--;
    }
    if (idx == 0)
    {
        Node *nd = (Node *)malloc(sizeof(Node));
        nd->data = data;
        nd->next = curNode;
        prevNode->next = nd;
        lst->size++;
        return 0;
    }
    return 1;
}

/* lstremove: Removes an element from a linked list at an index. */
void *lstremove(List *lst, unsigned int idx)
{
    /* TODO: Complete this function, given:
     *  lst  - A pointer to a List structure
     *  idx  - A non-negative index
     * ...remove element "idx" of "lst", shifting remaining elements as
     * necessary; return a pointer to the removed element, NULL if "idx"
     * outside bounds [0, size - 1]. */
    Node *curNode = lst->head;
    Node *temp, *ret;
    if (lst->head == NULL || idx >= lst->size)
    {
        return NULL;
    }
    if (idx == 0)
    {
        ret = lst->head;
        lst->head = lst->head->next;
        lst->size--;
        return ret;
    }
    while (curNode->next != NULL && idx > 1)
    {
        curNode = curNode->next;
        idx--;
    }
    if (curNode->next != NULL)
    {
        temp = curNode->next->next;
        ret = curNode->next;
        curNode->next = temp;
        lst->size--;
        return ret;
    }
    return NULL;
}

/* lstreverse: Creates a new linked list in reverse order. */
List *lstreverse(List *lst)
{
    /* TODO: Complete this function, given:
     *  lst  - A pointer to a List structure
     * ...return a pointer to a new, dynamically allocated List structure
     * containing the elements of "lst" in reverse order. */
    Node *prevNode = lst->head;
    Node *curNode, *nextNode;
    if (prevNode == NULL)
    {
        return NULL;
    }
    if (prevNode->next == NULL)
    {
        return lst;
    }
    curNode = prevNode->next;
    nextNode = curNode->next;
    prevNode->next = NULL;
    while (1)
    {
        curNode->next = prevNode;
        if (nextNode == NULL)
        {
            lst->head = curNode;
            return lst;
        }
        else
        {
            prevNode = curNode;
            curNode = nextNode;
            nextNode = nextNode->next;
        }
    }
}
