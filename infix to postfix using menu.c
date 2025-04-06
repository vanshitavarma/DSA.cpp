#include <stdio.h>
#include <ctype.h>
#define SIZE 50

char s[SIZE];
int top = -1;

void push(char elem);
char pop();
int pr(char elem);
void infixToPostfix();

void push(char elem)
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
        case '#': return 0;
        case '(': return 1;
        case '+':
        case '-': return 2;
        case '*':
        case '/': return 3;
        default: return -1;
    }
}

void infixToPostfix() {
    char infix[SIZE], postfix[SIZE], ch, elem;
    int i = 0, k = 0;

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    push('#');

    while ((ch = infix[i++]) != '\0') {
        if (isalnum(ch))
        {
            postfix[k++] = ch;
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while (s[top] != '(')
                postfix[k++] = pop();
            pop();
        }
        else
        {
            while (pr(s[top]) >= pr(ch))
                postfix[k++] = pop();
            push(ch);
        }
    }
    while (s[top] != '#')
    {
        postfix[k++] = pop();
    postfix[k] = '\0';
    }

    printf("\nGiven Infix Expression: %s\nPostfix Expression: %s\n", infix, postfix);
}

int main()
{
    int choice;

    while (1)
        {
        printf("\nMenu:\n");
        printf("1. Convert Infix to Postfix\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                infixToPostfix();
                break;
            case 2:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
