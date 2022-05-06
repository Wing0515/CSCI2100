#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int T;

typedef struct Heap{
    int *arr;
    int currSize;
    int maxSize;
} heap;

heap *heap_init(int size){
    heap *h = malloc(sizeof(heap));
    h -> arr = (int*)malloc(sizeof(int) * (size + 1));
    h -> arr[0] = INT_MIN;
    h -> currSize = 0;
    h -> maxSize = size;
    return h;
}

void heap_free(heap *h){
    free(h -> arr);
    free(h);
}

void insert(heap *h, int val){
    if(h -> currSize == h-> maxSize)
        return;
    h -> currSize++;

    // Percolate UP
    int index = h -> currSize;
    while(h -> arr[index / 2] > val){
        h -> arr[index] = h -> arr[index / 2];
        index /= 2;
    }
    h -> arr[index] = val;
}

int getMin(heap *h){
    if(h -> currSize == 0)
        return -1;
    return h -> arr[1];
}

void deleteMin(heap *h){
    if(h -> currSize == 0)
        return;
    
    int val = h -> arr[h -> currSize];
    h -> currSize--;
    
    int index = 1, child;
    for(; index * 2 <= h -> currSize; index = child){
        child = index * 2;
        if(child != h -> currSize && h -> arr[child] > h -> arr[child + 1])
            child++;
        if(h -> arr[child] < val)
            h -> arr[index] = h -> arr[child];
        else break;
    }
    h -> arr[index] = val;
}

void solve(){
    int n, k;
    scanf("%d %d\n", &n, &k);
    heap *h = heap_init(n * n);
    int a;
    for(int i = 0; i < n * n; i++){
        scanf("%d", &a);
        insert(h, a);
    }

    for(int i = 0; i < k - 1; i++)
        deleteMin(h);

    printf("%d\n", getMin(h));
    free(h);
}

int main(void){
    scanf("%d\n", &T);
    while(T--)
        solve();
    return 0;
}