//gcc selection.c -c; gcc selection.o -o selection; ./selection
#include <stdio.h>
#define MAX_SIZE 10

void selectionsort(int list[], int n) {
    int i, j, temp;

    for(i=0;i<n;i++) {
        int min = i;
        for(j=i+1;j<n;j++){
            if(list[min] > list[j]) {
                min = j;
            }
        }
        temp = list[i];
        list[i] = list[min];
        list[min] = temp;
    }

}

int main() {
    int n = MAX_SIZE;
    int li[n];
    
    for(int i=0; i<n; i++) li[i]=n-i;

    selectionsort(li, n);

    for(int i=0; i<n; i++) {
        printf("%d", li[i]);
    }
    return 0;
}