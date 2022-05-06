#include <stdio.h>

int main(void){
    int n;
    scanf("%d", &n);
    while(n--){
        int m , a, out = 0;
        scanf("%d", &m);
        while(m--){
            scanf("%d", &a);
            if(a > out && a % 2 == 0)
                out = a;
        }
        printf("%d\n", out);
    }
}