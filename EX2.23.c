#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct Node{
    int data;
    struct Node *next;
}node;

typedef struct Stack{
    node *top;
}stack;

typedef enum Operator{
    ADD, SUB, MUL, DIV, FACT, NONE
}operator;

node *node_init(int value){
    node *n = (node*)malloc(sizeof(node));
    n -> data = value;
    n -> next = NULL;
    return n;
}

stack *stack_init(){
    stack *s = (stack*)malloc(sizeof(stack));
    s -> top = node_init(-1);
    return s;
}

void stack_free(stack *s){
    node *current = s -> top;
    while(current != NULL){
        node *tmp = current -> next;
        free(current);
        current = tmp;
    }
    free(s);
}

void push(stack *s, int value){
    node *current = node_init(value);
    current -> next = s -> top -> next;
    s -> top -> next = current;
}

int is_empty(stack *s){
    return !(s -> top -> next);
}

void pop(stack *s){
    if(is_empty(s)) return;
    node *current = s -> top -> next;
    s -> top -> next = s -> top -> next -> next;
    free(current);
}

int peek(stack *s){
    if(is_empty(s)) return -1;
    return s -> top -> next -> data;
}

int fact(int n){
    if (n < 0) return -1;
    if (n == 0) 
        return 1;
    else 
        return (n * fact(n - 1));
}

int read(char *str){
    char ch;
    int i = 0;
    while((ch = getchar()) != ' '){
        if(ch == '\n' || ch == EOF){
            str[i] = '\0';
            return 0;
        }
        str[i++] = ch;
    }
    str[i] = '\0';
    return 1;
}

operator readOperator(char *str){

    if(strcmp(str, "+") == 0)
        return ADD;
    if(strcmp(str, "-") == 0)
        return SUB;
    if(strcmp(str, "*") == 0)
        return MUL;
    if(strcmp(str, "/") == 0)
        return DIV;
    if(strcmp(str, "!") == 0)
        return FACT;

    return NONE;
}
int main(){
    int m;
    scanf("%d\n", &m);
    while(m--){
        char x[255];
        int num1, num2, control, result;
        int error = 0;
        stack *s = stack_init();
        do{
            control = read(x);
            operator op = readOperator(x);

            if(op == NONE)
                result = atoi(x);

            else if(op == FACT){
                int n = peek(s);
                pop(s);
                result = fact(n);
                if(result == -1){
                    printf("factorial of an negative number\n");
                    error = 1;
                    break;
                }
            }
            else {
                int num1, num2;
                num2 = peek(s);
                pop(s);
                num1 = peek(s);
                pop(s);

                if(op == ADD) result = num1 + num2;
                else if(op == SUB) result = num1 - num2;
                else if(op == DIV){
                    if(num2 == 0){
                        printf("division by zero\n");
                        error = 1;
                        break;
                    }
                    result = num1 / num2;
                }
                else if(op == MUL) result = num1 * num2;
            }
            push(s, result);
        }while (control);

        if(!error)
            printf("%d\n", peek(s));
        stack_free(s);
    }
    return 0;
}