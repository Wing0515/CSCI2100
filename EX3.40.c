// Wing LAW 2/3/2022
#include <stdio.h>
#include <stdlib.h>

int counter = 0;
int T;

typedef struct QNode {
    struct TNode* data;
    struct QNode *next;
} qnode;

typedef struct TNode{
    int data;
    struct TNode* left;
    struct TNode* right; 
} tnode;

typedef struct Queue {
    struct QNode *head;
    struct QNode *tail;
} queue;

tnode *tnode_add(int value){
    tnode *t = (tnode*)malloc(sizeof(tnode));
    t -> left = t -> right = NULL;
    t -> data = value;
    return t;
}

queue *queue_init(){
    queue *q = (queue*)malloc(sizeof(queue));
    q -> head = (qnode*)malloc(sizeof(qnode));
    q -> tail = q -> head;
    return q;
}

void queue_free(queue *q){
    qnode *current = q -> head;
    while(current != NULL){
        qnode *tmp = current -> next;
        free(current);
        current = tmp;
    }
    free(q);
}

tnode* front(queue *q){
    if(q -> head == q -> tail){
        puts("The queue is empty, there is no front.");
        return NULL;
    }
    return q -> head -> next -> data;
}

void enqueue(queue *q, tnode *node){
    qnode *new = (qnode*)malloc(sizeof(qnode));
    new -> data = node;
    new -> next = NULL;
    q -> tail -> next = new;
    q -> tail = new;
}

void dequeue(queue *q){
    qnode *current = q -> head -> next;

    if(q -> head == q -> tail){
        puts("The queue is empty.");
        return;
    }
    if(current == q -> tail)
        q -> tail = q -> head;
    q -> head -> next = current -> next;
    free(current);
}

void tree_free(tnode *root){
    if(root -> left)
        tree_free(root -> left);
    if(root -> right)
        tree_free(root -> right);
    free(root);
}

void printInorder(tnode *t){
    if(t == NULL)
        return;
    printInorder(t -> left);
    if(t -> data == 0) {
        printf("");
    }
    else{
        if(counter == 1){
            printf("%d", t -> data);
            counter--;
        }
        else
            printf(" %d", t -> data);
    }
    printInorder(t -> right);
}

void solve(){
    int n;
    int control = -1;
    scanf("%d", &n);
    queue *q = queue_init();
    tnode *t, *root, *parent;
    for(int i = 0; i < n; i++){
        int a;
        scanf("%d", &a);
        t = tnode_add(a);
        // for root
        if(control == -1){
            root = t;
            enqueue(q, t);
            control = 0;
            continue;
        }
        // left
        if(control == 0){
            parent = front(q);
            dequeue(q);
            enqueue(q, t);
            parent -> left = t;
            control = 1;
            continue;
        }
        // right
        if(control = 1){
            enqueue(q, t);
            parent -> right = t;
            control = 0;
            continue;
        }
    }
    counter = 1;
    printInorder(root);
    tree_free(root);
    queue_free(q);
    printf("\n");
}

int main(){
    scanf("%d\n", &T);
    while(T--){
        solve();
    }
    return 0;
}