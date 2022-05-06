#include <stdio.h>
#include <string.h>
int T;

int solve(){
    int size1, size2, size3;
    scanf("%d %d", &size1, &size2);
    size3 =  size1 + size2;
    int num1[size1], num2[size2], o[size3 / 2 + 1];
    memset(num1, 0, size1 * sizeof(int));
    memset(num2, 0, size2 * sizeof(int));
    memset(o, 0, (size3 / 2 + 1) * sizeof(int));
    for(int i = 0; i < size1; i++)
        scanf("%d", &num1[i]);
     for(int i = 0; i < size2; i++)
        scanf("%d", &num2[i]); 

    int j = 0, k = 0;
    if(size3 == 0) return 0;
    else if(size1 == 0 && size2 != 0){
        for(int i = 0; i < size2 / 2 + 1; i++)
            o[i] = num2[i];
    }
    else if(size2 == 0 && size1 != 0){
        for(int i = 0; i < size1 / 2 + 1; i++)
            o[i] = num1[i];
    }
    else{
        for(int i = 0; i < size3 / 2 + 1; i++){
            if(j == size1 && k < size2){
                o[i] = num2[k];
                k++;
            }
            else if(k == size2 && j < size1){
                o[i] = num1[j];
                j++;
            }
            else if(num1[j] <= num2[k]){
                o[i] = num1[j];
                j++;
            }
            else if(num1[j] > num2[k]){
                o[i] = num2[k];
                k++;
            }
        }
    }
    if(size3 == 1)
        printf("%.1f\n", (double) o[0]);
    else if(size3 % 2 == 0)
        printf("%.1f\n", (o[size3 / 2 - 1] + o[size3 / 2]) / (double) 2);
    else
        printf("%.1f\n", (double) o[size3 / 2]);
    return 0;
}

int main(){
    scanf("%d", &T);
    while(T--)
        solve();
    return 0;
}