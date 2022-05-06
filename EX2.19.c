#include <stdio.h>
#include <string.h>

//consider the elements in the stack, there is no 2 elements can enter to the same stack
//this question can be consider as a bipartite question
#define MAXN 1005
int const NEINF = -1000;

int scan[MAXN];
int compare[MAXN];
int bi[MAXN];
int adj[MAXN][MAXN];
int n;
int noSolution = 0;

//checking the graph is bipartite or not, if it is then there is the solution.
//if the graph is not bipartite, then there is no solution.
void colouringAndCheckConflict(int i, int c) {
    bi[i] = c;
    for (int j = 0; j < n; j++) {
        if (adj[i][j]) {
            if (bi[j] == c)
            {
                noSolution = 1;
                return;
            }
            if (!bi[j]) {
                colouringAndCheckConflict(j, 3 - c);
            }
        }
    }
}

//dye the graph with 1
void checkAdjacencyAndDye() {
    compare[0] = NEINF;
    for (int i = 0; i < n; i++) {
        compare[i] = scan[i];
        if (compare[i - 1] > compare[i])
            compare[i] = compare[i - 1];
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (scan[i] < scan[j] && compare[i - 1] > scan[j]) {
                adj[i][j] = adj[j][i] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (!bi[i] && !noSolution) {
            colouringAndCheckConflict(i, 1);
        }
    }
}
//reset all the array, since the array is global var
void reset() {
    memset(adj, 0, sizeof(adj));
    memset(bi, 0, sizeof(bi));
    memset(scan, 0, sizeof(scan));
    memset(compare, 0, sizeof(compare));
    n = 0;
    noSolution = 0;
}

int main() {

    int m;
    scanf("%d", &m);
    while(m--){
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &scan[i]);
        }
        checkAdjacencyAndDye();
        if (!noSolution) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
        reset();
    }

    return 0;
}