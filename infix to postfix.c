#include <stdio.h>
#include <ctype.h>

#define SIZE 50

char s[SIZE];
int top = -1;

push(char elem)
{
    s[++top] = elem;
}

char pop()
{
    return (s[top--]);
}

int pr(char elem)
{
    switch (elem)
    {
    case '#':
        return 0;
    case '(':
        return 1;
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 3;
    }
}

void main()
{
    char infix[SIZE], postfix[SIZE], ch, elem;
    int i = 0, k = 0;

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    push('#');

    while ((ch = infix[i++]) != '\0')
    {
        if (isalnum(ch))
            postfix[k++] = ch;
        else if (ch == '(')
            push(ch);
        else if (ch == ')')
        {
            while (s[top] != '(')
                postfix[k++] = pop();
            elem = pop();
        }
        else
        {
            while (pr(s[top]) >= pr(ch))
                postfix[k++] = pop();
            push(ch);
        }
    }

    while (s[top] != '#')
        postfix[k++] = pop();
    postfix[k] = '\0';
    printf("\n\nGiven Infix Expn: %s Postfix Expn: %s\n", infix, postfix);
}
