#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(int argc, char** argv) {
   stack myStack = init();
    /*
       print(myStack);
       top(myStack);
       myStack = push(42, myStack);
       myStack = push(77, myStack);
       myStack = push(1, myStack);
       print(myStack);
       myStack = push(33, myStack);
       myStack = pop(myStack);
       myStack = push(33, myStack);
       print(myStack);
       element e = top(myStack);
       printf("top element is %i\n", e);
       print(myStack);
   */
    
    printf("size(myStack) = %i\n", size(myStack));
    printf("isEmpty(myStack) = %i\n", isEmpty(myStack));
    print(myStack);
    top(myStack);
    myStack = push(42, myStack);
    myStack = push(77, myStack);
    myStack = push(1, myStack);
    printf("size(myStack) = %i\n", size(myStack));
    printf("isEmpty(myStack) = %i\n", isEmpty(myStack));
    print(myStack);

    return (EXIT_SUCCESS);
}
