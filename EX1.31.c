#include <stdio.h>
#include <string.h>

int main(){
    int n;
    scanf("%d\n", &n);
    while(n--){
        char a[1000];
        gets(a);
        int length = strlen(a);
        int i = 0;
        while(i < length){
            int start = i;
            while(i < length && a[i] != ' ')
                i++;
            
            int left = start, right = i - 1;
            while(left < right){
                char tmp = a[right];
                a[right] = a[left];
                a[left] = tmp;
                left++;
                right--;
            }

            while(i < length && a[i] == ' ')
                i++;
        }
        printf("%s\n", a);
    }
    return 0;
}
