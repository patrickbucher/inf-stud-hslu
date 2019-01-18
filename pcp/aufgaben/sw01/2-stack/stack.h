#ifndef STACK_H
#define	STACK_H

#define STACK_SIZE 3
#define STACK_EMPTY_INDEX -1
#define STACK_DUMMY_ELEMENT -1234 // attention: arbitrary number used as dummy :-(

typedef int element;

typedef struct {
    element stackArray[STACK_SIZE];
    int index;
} stack;

stack init();
stack push(element e, stack s);
element top(stack s);
stack pop(stack s);
void print(stack s);
int isEmpty(stack s);
int size(stack s);

#endif	/* STACK_H */
