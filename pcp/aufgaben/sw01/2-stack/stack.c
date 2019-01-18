#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// returns new empty stack
stack init() {
    stack s;
    s.index = STACK_EMPTY_INDEX;
    return s;
}

// adds element to stack
stack push(element e, stack s) {
    if (s.index + 1 < STACK_SIZE) {
        // there is space for one more element
        s.index++;
        s.stackArray[s.index] = e;
    } else {
        printf("ERROR - push: stack full! Cannot add %i\n", e);
    }
    return s;
}

// returns top element
element top(stack s) {
    if (s.index > STACK_EMPTY_INDEX) {
        return s.stackArray[s.index];
    } else {
        printf("ERROR - top: stack empty!\n");
        return STACK_DUMMY_ELEMENT;
    }
}

// removes top element from stack
stack pop(stack s) {
    if (s.index > STACK_EMPTY_INDEX) {
        s.index--;
    }
    return s;
}

// prints all elements
void print(stack s) {
    if (s.index > STACK_EMPTY_INDEX) {
        printf("print - Stack contains: ");
        int i;
        for (i = 0; i <= s.index; i++) {
            printf("%i, ", s.stackArray[i]);
        }
        printf("top element = %i\n", s.stackArray[s.index]);
    } else {
        printf("print - Stack is empty\n");
    }
}

int isEmpty(stack s) {
    if (s.index == STACK_EMPTY_INDEX) {
        return 1;
    } else {
        return 0;
    }
}

int size(stack s) {
    return s.index + 1;
}
