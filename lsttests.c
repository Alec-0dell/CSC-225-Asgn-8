/*
 * Tests functions for linked lists
 * CSC 225, Assignment 8
 * Given tests, Winter '24
 */

#include <stddef.h>
#include <assert.h>
#include <stdio.h>
#include "list.h"

void test01empty(void);
void test02add(void);
void test03remove(void);
void test04get(void);
void test05set(void);
void test06reverse(void);
void test07reverse(void);

/* test01empty: Tests empty lists. */
void test01empty(void)
{
    List *lst = lstcreate();

    assert(lst != NULL);
    assert(lst->head == NULL);
    assert(lst->size == 0);

    lstdestroy(lst);
}

/* test02add: Tests adding to lists. */
void test02add(void)
{
    List *lst = lstcreate();
    int data1 = 1, data2 = 2;

    lstadd(lst, 0, &data1);
    lstadd(lst, 1, &data2);

    assert(lst->head != NULL);
    assert(lst->head->data == &data1);
    assert(lst->head->next->data == &data2);
    assert(lst->head->next->next == NULL);
    assert(lst->size == 2);

    lstdestroy(lst);
}

/* test03remove: Tests removing from lists. */
void test03remove(void)
{
    List *lst = lstcreate();
    int data1 = 1, data2 = 2;

    lstadd(lst, 0, &data1);
    lstadd(lst, 1, &data2);
    lstremove(lst, 0);

    assert(lst->head != NULL);
    assert(lst->head->data == &data2);
    assert(lst->head->next == NULL);
    assert(lst->size == 1);

    lstdestroy(lst);
}

/* test04get: Tests getting elements from lists. */
void test04get(void)
{
    List *lst = lstcreate();
    int data1 = 1, data2 = 2;

    lstadd(lst, 0, &data1);
    lstadd(lst, 1, &data2);

    assert(*(int *)lstget(lst, 0) == data1);
    assert(*(int *)lstget(lst, 1) == data2);
    assert(lstget(lst, 2) == NULL);

    lstdestroy(lst);
}

/* test05set: Tests setting elements in lists. */
void test05set(void)
{
    List *lst = lstcreate();
    int data1 = 1, data2 = 2, newData = 3;

    lstadd(lst, 0, &data1);
    lstadd(lst, 1, &data2);

    assert(lstset(lst, 1, &newData) == 0);
    assert(*(int *)lstget(lst, 1) == newData);
    assert(lstset(lst, 2, &newData) == 1);

    lstdestroy(lst);
}

/* test06reverse: Tests reversing the list. */
void test06reverse(void)
{
    List *lst = lstcreate();
    List *reversed;
    int data1 = 1, data2 = 2, data3 = 3, data4 = 4, data5 = 5;

    lstadd(lst, 0, &data1);
    lstadd(lst, 1, &data2);
    lstadd(lst, 2, &data3);
    lstadd(lst, 3, &data4);
    lstadd(lst, 4, &data5);

    reversed = lstreverse(lst);

    assert(reversed != NULL);
    assert(*(int *)lstget(reversed, 0) == data5);
    assert(*(int *)lstget(reversed, 1) == data4);
    assert(*(int *)lstget(reversed, 2) == data3);
    assert(*(int *)lstget(reversed, 3) == data2);
    assert(*(int *)lstget(reversed, 4) == data1);
    assert(lstsize(reversed) == 5);

    lstdestroy(lst);
    lstdestroy(reversed);
}

void test07reverse(void)
{
    List *lst = lstcreate();
    List *reversed;
    int data1 = 1;

    lstadd(lst, 0, &data1);

    reversed = lstreverse(lst);

    assert(reversed != NULL);
    assert(*(int *)lstget(reversed, 0) == data1);
    assert(lstsize(reversed) == 1);

    lstdestroy(lst);
    lstdestroy(reversed);
}

int main(void)
{
    test01empty();
    test02add();
    test03remove();
    test04get();
    test05set();
    test06reverse();
    test07reverse();

    return 0;
}
