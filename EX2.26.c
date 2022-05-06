#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} node;

typedef struct Queue {
    node *head;
    node *tail;
} queue;

queue *queue_init(){
    queue *q = malloc(sizeof(queue));
    q -> head = malloc(sizeof(node));
    q -> tail = q -> head;
    return q;
}

void queue_free(queue *q){
    node *current = q -> head;
    while(current != NULL){
        node *tmp = current -> next;
        free(current);
        current = tmp;
    }
    free(q);
}

int front(queue *q){
    if(q -> head == q -> tail){
        puts("The queue is empty, there is no front.");
        return -1;
    }
    return q -> head -> next -> data;
}

void enqueue(queue *q, int value){
    node *new = malloc(sizeof(node));
    new -> data = value;
    new -> next = NULL;
    q -> tail -> next = new;
    q -> tail = new;
}

void dequeue(queue *q){
    node *current = q -> head -> next;

    if(current == NULL){
        puts("The queue is empty.");
        return;
    }
    if(current == q -> tail)
        q -> tail = q -> head;
    q -> head -> next = current -> next;
    free(current);
}

void print(queue *q){
    node *current = q -> head -> next;
    while(current != NULL){
        printf("%d", (current -> data) - 48);
        current = current -> next;
    }
}

int main(void){
    int n;
    char control;
    scanf("%d\n", &n);
    while(n--){
        queue *q = queue_init();
        while(control = getchar()){
            if(control == 'S') continue;
            if(control == 'E'){
                int throw = getchar();
                int a = getchar();
                enqueue(q,a);
            }
            if(control == 'D')
                dequeue(q);
            if(control == 'X') break;
        }
        print(q);
        printf("\n");
        queue_free(q);
    }
    return 0;
}