# Algorithm_c

# Sorting

    
```c
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
```



- MST Minimnum Spanning Tree
    - 그래프에 모든 정점을 연결하는 트리.
    - 스패팅 트리 중, 트리를 구성하는 간선들의 가중치의 합이 최소가 되는 스패닝 트리가 최소 스패닝 트리.
    - 정점 개수 V인 그래프의 최소 스패팅 트리는 V-1개의 간선
    - 스패팅 트리 구하는 알고리즘 ; 크루스칼, 프림
- Kruskal
    - 시간복잡도
        - O(ElogE) ; 간선 정렬 
        - O(1) * E = O(E) ; 정렬된 간선을 순회, UnionFind연산을 한번씩 수행
        - 결과적으로 O(ElogE + E)
        - O(ElogE + E) = O(ElogE) = O(ElogV^2) = O(2*ElogV) = O(ElogV)
        - 최종 시간복잡도 ; O(ElogV)
    1. 그래프의 간선 리스트 구성.
    2. 간선 리스트를 간선의 가중치를 기준으로 오름차순 정렬
    3. 가중치가 가장 작은 간선부터 스패닝 트리에 해당하는 간선에 추가.
    4. 사이클이 발생하는 간선은 추가하지 않고 무시.
    (사이클의 여부는 UnionFind DisjointSet 유니온 파인드 상호배타적 집합을 이용하여 O(1)에 확인 )
- Prim
    - 시간복잡도
        - 각 간선이 한번씩 pq에 삽입되고 제거.
        - O(ElogE) = O(ElogV)
    1. 첫 번째 임의의 시작점 선택
    2. 시작점으로부터 인접한 정점을 Priority Queue(pq)에 저장. 이때 해당 정점과 가중치 함께 저장.
    pq에는 vector<ii>가 저장
    (typedef pair<int, int> ii;) // 간선의 가중치, 인접한 정점번호
    3. pq에 저장된 정점과 가중치 쌍은 가중치의 오름차순으로 정렬. pq에 저장되는 정점은 아직 스패닝 트리를 구성하는데 있어서 포함되지 않은 정점. 이는 스패닝 트리에 사이클이 생기는 것을 방지.
    4. 시작점과 인접한 정점을 pq에 삽입하는 작업이 끝나면 pq가 빌때까지 아래 작업을 반복
        1) pq.top()의 값을 추출하고 pq에서 제거
        2) 추출된 것은 정점번호와 가중치. 즉 가중치가 가장 작으면서 정점번호가 가장 빠른 정점이 추출.
        3) 해당 정점이 구성중인 스패닝 트리에 포함되어 있지 않다면 해당 정점의 가중치를 결과값에 더하고 해당 정점에 방문했다고 표시.(사이클 방지 위해)
        4) 해당 정점과 인접한 정점 중 아직 스패닝 트리에 고려되지 않은 정점들을 pq에 삽입(사이클 방지)


# Kruskal


'''c



'''



# Prim

'''c



'''