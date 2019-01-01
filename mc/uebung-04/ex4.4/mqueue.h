/*
 * Author: Patrick Bucher <patrick.bucher@stud.hslu.ch>
 */

typedef struct qnode {
    int message;
    struct qnode *next;
    struct qnode *prev;
} qnode;

void initialize();
void enqueue(int message);
int dequeue();
