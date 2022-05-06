#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int m;
    scanf("%d", &m);
    while(m--){
        unsigned int a, b, c;

        scanf("%u %u", &a, &b);

        int lenB = log2(b) + 1;
        c = a << lenB;
        printf("%u\n", c | b);
    }
    return 0;
}