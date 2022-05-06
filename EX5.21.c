#include <stdio.h>
#include <stdlib.h>

int T;

typedef struct pair{
    int first;
    int second;
}pair;

void solve(){
    int n, m;
    int count = 0;
    scanf("%d %d\n", &n, &m);
    int input[n];
    pair map[50000];

    for(int i = 0; i< 50000; i++){
        map[i].first = -1;
    }

    for(int i = 0; i < n; i++){
        scanf("%d", &input[i]);
        map[input[i]].first = input[i];
        map[input[i]].second = i;
    }


    if(m == 0){
        for(int i = 0; i < n; i++){
            if(input[i] == 0){
                count += (n - 1) * (n - 2) / 2;
                printf("%d\n", count);
                return;
            }
        }
    }

    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            int a = input[i] * input[j];
            if((a <= m && a != 0) && (m % a == 0)){
                    int b = m / a;
                    int first = map[b].first;
                    if(first == -1) continue;
                    int second = map[b].second;
                    if((b != input[i] && b != input[j]) && (second > i && second > j))
                            count++;   
                }
        }
    }
    printf("%d\n", count);
}

int main(void){
    scanf("%d\n", &T);
    while(T--){
        solve();
    }
    return 0;
}