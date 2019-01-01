/*
 * Author: Patrick Bucher <patrick.bucher@stud.hslu.ch>
 */

#include <stdio.h>
#include <stdlib.h>
#include "mqueue.h"

static qnode *head = NULL;
static qnode *tail = NULL;

void enqueue(int message)
{
    qnode *node = (qnode *)malloc(sizeof(qnode));
    node->message = message;
    if (tail == NULL) {
        head = node;
    }
    if (tail != NULL) {
        tail->prev = node;
        node->next = tail;
    }
    tail = node;
}

int dequeue()
{
    int message;
    qnode *tmp;

    if (head == NULL) {
        fprintf(stderr, "cannot read from empty queue\n");
        return -1;
    }
    message = head->message;
    tmp = head;
    if (head->prev != NULL) {
        head->prev->next = NULL;
        head = tmp->prev;
    } else {
        head = NULL;
    }
    free(tmp);

    return message;
}
