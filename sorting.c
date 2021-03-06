#include <stdio.h>
#define MAX_SIZE 10

void selection(int arr[], int n) {
    int i, j, temp;
    for(i = 0;i<n;i++) {
        int min = i;
        for(j = i+1 ; j < n ;j++) {
            if(arr[j] < arr[min]) {
                min = j;
            }
        }
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

void insertion(int arr[], int n) {
    int i, j, temp;
    for(i =0;i<n;i++) {
        for(j = i;j>0;j--){
            if(arr[j-1] > arr[j]) {
                temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
            }
            else {
                break;
            }
        }
    }
}

void bubble(int arr[], int n) {
    int i, j, temp;
    for(i = 0; i <n;i++) {
        for(j = 1;j<n-i;j++){
            if(arr[j-1] > arr[j]) {
                temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int n = MAX_SIZE;
    int list[MAX_SIZE];
    int i;

    for(i = 0 ; i < n ; i++ ) list[i] = n-i;
    printf("selection before : ");
    for(i = 0 ; i < n ; i++ ) printf("%d ", list[i]);
    printf("\n");
    selection(list, n);
    printf("selection after : ");
    for(i = 0 ; i < n ; i++ ) printf("%d ", list[i]);
    printf("\n");

    for(i = 0 ; i < n ; i++ ) list[i] = n-i;
    printf("insertion before : ");
    for(i = 0 ; i < n ; i++ ) printf("%d ", list[i]);
    printf("\n");
    insertion(list, n);
    printf("insertion after : ");
    for(i = 0 ; i < n ; i++ ) printf("%d ", list[i]);
    printf("\n");

    for(i = 0 ; i < n ; i++ ) list[i] = n-i;
    printf("bubble before : ");
    for(i = 0 ; i < n ; i++ ) printf("%d ", list[i]);
    printf("\n");
    bubble(list, n);
    printf("bubble after : ");
    for(i = 0 ; i < n ; i++ ) printf("%d ", list[i]);
    printf("\n");

    return 0;
}