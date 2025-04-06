#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include<math.h>
#define SIZE 50
struct stack
{
    int top;
    char arr[SIZE];
};
struct stack s1;
char pop()
{
    if (s1.top == -1)
    {
        return -1;
    }
    else
    {
        return s1.arr[s1.top--];
    }
}
void push(char c)
{
    s1.arr[++s1.top] = c;
}

int evaluatePostfix(char* exp)
{
    s1.top = -1;
    int i = 0;
    while (exp[i] != '\0')
    {
        if (isdigit(exp[i]))
        {
            push(exp[i] - '0');
        }
        else
        {
            int val1 = pop();
            int val2 = pop();
            switch (exp[i])
            {
            case '+':
                push(val2 + val1);
                break;
            case '-':
                push(val2 - val1);
                break;
            case '*':
                push(val2 * val1);
                break;
            case '/':
                push(val2 / val1);
                break;
            case'^':
            	push(pow(val2,val1));
            	break;
            }
        }i++;
    }return pop();
}

int main()
{
    char exp[SIZE];
    printf("Enter the postfix expression: ");
    scanf("%s",exp);
    printf("The result of the postfix expression is: %d", evaluatePostfix(exp));
    return 0;
}
