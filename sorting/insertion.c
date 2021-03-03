//gcc insertion.c -c; gcc insertion.o -o insertion; ./insertion
#include <stdio.h>
#define MAX_SIZE 10

void insertionsort(int list[], int n) {
    int i, j, temp;

    for(i=0;i<n;i++){
        for(j=i;j>0;j--){
            if(list[j] < list[j-1]) {
                temp = list[j];
                list[j] = list[j-1];
                list[j-1] = temp;
            }
            else {
                break;
            }
        }
    }
}

int main() {
    int n = MAX_SIZE;
    int li[n];
    
    for(int i=0; i<n; i++) li[i]=n-i;

    insertionsort(li, n);

    for(int i=0; i<n; i++) {
        printf("%d", li[i]);
    }
    return 0;
}