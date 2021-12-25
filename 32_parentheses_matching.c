#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow! Your value %d can't be added.\n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow! Nothing to be popped!.\n");
        return -1;
    }
    else
    {
        char var = ptr->arr[ptr->top];
        ptr->top--;
        return var;
    }
}

int checkValidity(char *exp)
{

    struct stack *sp;

    sp->size = 20;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    for (int i = 0; i < sp->size; i++)
    {
        if (exp[i] == '(')
        {
            push(sp, exp[i]);
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            pop(sp);
        }
    }

    if (isEmpty(sp))
    {
        return 1;
    }
    return 0;
}

int main()
{

    // char array[20] = {'(', 1, '*', '(', 8, '-', '(', 3, '+', ')', ')'};
    char *exp = "(()))";

    // '(' = value = 41
    // ')' = value = 40

    // printf("Popped %d from the stack.\n", pop(sp));

    if (checkValidity(exp))
    {
        printf("You parenthsis is valid");
    }
    else
    {
        printf("You parenthsis is Invalid");
    }

    return 0;
}