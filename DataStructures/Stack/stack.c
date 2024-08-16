#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_SIZE 6

typedef struct{

    bool success;
    int value;

} StackPopResult;

typedef struct {

    unsigned int pointer;
    int data[STACK_SIZE];
    
} Stack;

bool stack_is_full(Stack *stack){

    return stack->pointer == STACK_SIZE;

}

bool stack_is_empty(Stack *stack){

    return stack->pointer == 0;
}

bool stack_push(Stack *stack, int value){

    if(stack_is_full(stack)){

        return false;
    }

    stack->data[stack->pointer++] = value;

    return true;
}

StackPopResult stack_pop(Stack *stack){

    if(stack_is_empty(stack)){

        return (StackPopResult){.success=false, .value=0};
    }

    return (StackPopResult){.success=true, .value=stack->data[--stack->pointer]};
}

int main(int argc, char ** argv){

    int array[] = {1,2,3,4,5,6,7,8,9,10};
    Stack stack = {.pointer=0};

    for(int i = 0; i < (int)(sizeof(array)/sizeof(int)); i++){

        if(!stack_push(&stack, array[i])){

            puts("Stack is Full!");
            break;
        }

        printf("Push -> %d\n",i);
    }

    while(true){

        StackPopResult result = stack_pop(&stack);
        
        if(!result.success){

            puts("Stack is Empty!");
            break;
        }

        printf("Pop -> %d\n", result.value);

    }

    return 0;
}