// Wing LAW 2/3/2022
#include <stdio.h>
#include <stdlib.h>

typedef struct QNode {
    struct TNode* data;
    struct QNode *next;
} qnode;

typedef struct TNode{
    int data;
    int painted;
    struct TNode* parent;
    struct TNode* left;
    struct TNode* right; 
} tnode;

typedef struct Queue {
    struct QNode *head;
    struct QNode *tail;
} queue;

tnode *tnode_add(int value){
    tnode *t = (tnode*)malloc(sizeof(tnode));
    t -> data = value;
    t -> painted = 0;
    t -> left = t -> right  = t -> parent = NULL;
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

int notNull(tnode * t){
    return t != NULL && t -> data != 0;
}

int T;
int count = 0;

void paint(tnode *root){
    count ++;
    root -> painted = 1;
    if(notNull(root -> parent))
        root -> parent -> painted = 1;
    if(notNull(root -> left))
        root -> left -> painted = 1;
    if(notNull(root -> right))
        root -> right -> painted = 1;
}

void painter(tnode *root){
    int hasLeft = notNull(root -> left); 
    int hasRight = notNull(root -> right);

    if(hasLeft)
        painter(root -> left);
    if(hasRight)
        painter(root -> right);
    if(hasLeft && !(root -> left -> painted))
        paint(root);
    else if(hasRight && !(root -> right -> painted))
        paint(root);
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
            t -> parent = parent;
            parent -> left = t;
            control = 1;
            continue;
        }
        // right
        if(control = 1){
            enqueue(q, t);
            t -> parent = parent;
            parent -> right = t;
            control = 0;
            continue;
        }
    }
    queue_free(q);
    count = 0;
    painter(root);
    if(!(root -> painted)) count++;
    tree_free(root);
    printf("%d\n", count);
}

int main(){
    scanf("%d\n", &T);
    while(T--){
        solve();
    }
    return 0;
}