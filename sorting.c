#include <stdio.h>
#define MAX_SIZE 10
#define parent(x) (x-1)/2
int sorted[MAX_SIZE];

void selection(int arr[], int n);
void insertion(int arr[], int n);
void bubble(int arr[], int n);
void merge(int arr[], int left, int right);
void quick(int arr[], int start, int end);
void heap_sort(int arr[], int n);

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
    
    for(i = 0 ; i < n ; i++ ) list[i] = n-i;
    printf("merge before : ");
    for(i = 0 ; i < n ; i++ ) printf("%d ", list[i]);
    printf("\n");
    merge(list, 0, n-1);
    printf("merge after : ");
    for(i = 0 ; i < n ; i++ ) printf("%d ", list[i]);
    printf("\n");

    for(i = 0 ; i < n ; i++ ) list[i] = n-i;
    printf("quick before : ");
    for(i = 0 ; i < n ; i++ ) printf("%d ", list[i]);
    printf("\n");
    quick(list, 0, n-1);
    printf("quick after : ");
    for(i = 0 ; i < n ; i++ ) printf("%d ", list[i]);
    printf("\n");

    for(i = 0 ; i < n ; i++ ) list[i] = n-i;
    printf("heap before : ");
    for(i = 0 ; i < n ; i++ ) printf("%d ", list[i]);
    printf("\n");
    heap_sort(list, n);
    printf("heap after : ");
    for(i = 0 ; i < n ; i++ ) printf("%d ", list[i]);
    printf("\n");

    return 0;
}

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

void merge_list(int arr[], int left, int mid, int right) {
    int i, j, k, l;
    i = left;
    j = mid+1;
    k = left;

    while(i<=mid && j<=right) {
        if(arr[i] <= arr[j])
            sorted[k++] = arr[i++];
        else
            sorted[k++] = arr[j++];
    }

    int tmp = i>mid ? j : i;

    while(k<=right) sorted[k++] = arr[tmp++];

    for(l=left; l<=right; l++) arr[l] = sorted[l];
}

void merge(int arr[], int left, int right) {
    int mid;
    if(left < right) {
        mid  = (left+right) / 2;
        merge(arr, left, mid);
        merge(arr, mid+1, right);
        merge_list(arr, left, mid, right);
    }
}

void quick(int arr[], int start, int end) {
    if(start >= end) {
        return;
    }
    
    int pivot = start ;
    int i = pivot + 1;
    int j = end;
    int temp;

    while(i <= j) {
        while(i <= end && arr[i] <= arr[pivot]) {
            i++;
        }
        while(j > start && arr[j] >= arr[pivot]) {
            j--;
        }

        if(i > j) { // cross
            temp = arr[j];
            arr[j] = arr[pivot];
            arr[pivot] = temp;
        }
        else {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    quick(arr, start, j-1);
    quick(arr, j+1, end);
}

void heapify(int arr[], int n) {
    for(int i=1; i<n; i++) {
        int child = i;
        while(child > 0){
            int root = parent(child);
            if(arr[root] < arr[child]){
                int temp = arr[root];
                arr[root] = arr[child];
                arr[child] = temp;
            }
            child = root;
        }
    }
}

void heap(int arr[], int *size) {
    int temp = arr[0];
	arr[0] = arr[*size-1];
	arr[*size-1] = temp;
	--(*size);
}

void heap_sort(int arr[], int n) {
    int size = n;
    for(int i = 0;i<n;i++){
        heapify(arr, size);
        heap(arr, &size);
    }
}