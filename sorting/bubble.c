//gcc bubble.c -c; gcc bubble.o -o bubble; ./bubble
#include <stdio.h>
#define MAX_SIZE 10

void bubblesort(int list[], int n) {
    int i, j, temp;

    for(i=0;i<n;i++) {
        for(j=1;j<n-i;j++){
            if(list[j] < list[j-1]) {
                temp = list[j];
                list[j] = list[j-1];
                list[j-1] = temp;
            }
        }
    }
}

int main() {
    int n = MAX_SIZE;
    int li[n];
    
    for(int i=0; i<n; i++) li[i]=n-i;

    bubblesort(li, n);

    for(int i=0; i<n; i++) {
        printf("%d", li[i]);
    }
    return 0;
}