#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int T;

int cmp(int a, int b){
    char AB[10], BA[10];
    char A[5], B[5];
    sprintf(A, "%d", a);
    sprintf(B, "%d", b);
    strcpy(AB, A);
    strcat(AB, B);
    strcpy(BA, B);
    strcat(BA, A);
    int oa = atoi(AB);
    int ob = atoi(BA);
    return (oa >= ob);
}

void solve(){
    int a;
    scanf("%d", &a);
    int arr[a];
    for(int i = 0; i < a; i++)
        scanf("%d", &arr[i]);
    for(int i = 0; i < a; i++){
        for(int j = i + 1; j < a; j++){
            if(cmp(arr[i],arr[j])){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for(int i = 0; i < a; i++)
        printf("%d", arr[i]);
    printf("\n");
}

int main(){
    scanf("%d", &T);
    while(T--)
        solve();
    return 0;
}