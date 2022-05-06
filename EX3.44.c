// Wing LAW 3/3/2022
#include <stdio.h>
#include <stdlib.h>


int T;
int head = 0;

typedef struct TNode{
    int data;
    struct TNode* left;
    struct TNode* right; 
} tnode;

tnode *tnode_add(int value){
    tnode *t = (tnode*)malloc(sizeof(tnode));
    t -> data = value;
    t -> left = t -> right = NULL;
    return t;
}

void printInorder(tnode *t){
    if(t == NULL)
        return;
    printInorder(t -> left);
    //(t -> data == 0) ? printf("") : printf("%d ", t -> data);
    if(head == 1){
        printf("%d", t -> data);
        head--;
    }
    else
        printf(" %d", t -> data);
    printInorder(t -> right);
}

tnode *construct(int pre[], int post[], int size){
    if(size <= 0)
        return NULL;
    tnode *root = tnode_add(pre[0]);
    if(size == 1)
        return root;

    int i;
    for(i = 0; i < size; i++){
        if(post[i] == pre[1])
            break;
    }

    int *tmpPre, *tmpPost;
    
    tmpPre = malloc((i + 1) * sizeof(int)), tmpPost = malloc((i + 1) * sizeof(int));
    int preIndex = 1, postIndex = 0;

    for(int j = 0; j < i + 1; j++)
        tmpPre[j] = pre[preIndex++];
    for(int j = 0; j < i + 1; j++)
        tmpPost[j] = post[postIndex++];

    root -> left = construct(tmpPre, tmpPost, i + 1);
    
    free(tmpPre);
    free(tmpPost);
    tmpPre = malloc((size - i - 2) * sizeof(int)), tmpPost = malloc((size - i - 2) * sizeof(int));
    preIndex = i + 2;
    postIndex = i + 1;

    for(int j = 0; j < size - i - 2; j++)
        tmpPre[j] = pre[preIndex++];
    for(int j = 0; j < i; j++)
        tmpPost[j] = post[postIndex++];

    root -> right = construct(tmpPre, tmpPost, size - i - 2);
    
    free(tmpPre);
    free(tmpPost);
    return root;
}

void solve(){
    int n;
    scanf("%d", &n);
    int pre[n], post[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &pre[i]);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &post[i]);
    }
    tnode *root = construct(pre, post, n);
    head = 1;
    printInorder(root);
    free(root);
    printf("\n");
}

int main(){
    scanf("%d\n", &T);
    while(T--){
        solve();
    }
    return 0;
}