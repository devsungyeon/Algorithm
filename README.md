# Algorithm

# Sorting
## selection
    
    ```c
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
    ```
    ```java
    import java.util.Arrays;
    
    public class selection {
        public static void selectionsort(Comparable[] arr) {
            int N = arr.length;
            for(int i = 0; i<N ; i++ ) {
                int min = i;
                for(int j = i+1 ; j < N ; j++ )
                    if (less(arr[j], arr[min])) min = j;
                exch(arr, i, min);
            }
            System.out.println(Arrays.toString(arr));
        }
    
        private static boolean less(Comparable v, Comparable w) {
            return v.compareTo(w) < 0;
        }
    
        private static void exch(Comparable[] a, int i, int j) {
            Comparable swap = a[i];
            a[i] = a[j];
            a[j] = swap;
        }
    
        public static void main(String[] args) {
            selectionsort(new Integer[]{10,9,8,7,6,5,4,3,2,1});
        }
    }
    ```
## insertion
    ```c
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
    ```
    ```java
    import java.util.Arrays;
    
    public class insertion {
        public static void insertionsort(Comparable[] arr) {
            int N = arr.length;
            for(int i = 0 ; i < N ; i++ ) {
                for(int j = i ; j > 0 ; j--) {
                    if(less(arr[j], arr[j-1])) exch(arr, j, j-1);
                    else break;
                }
            }
            System.out.println(Arrays.toString(arr));
        }
    
        private static boolean less(Comparable v, Comparable w) {
            return v.compareTo(w) < 0;
        }
    
        private static void exch(Comparable[] a, int i, int j) {
            Comparable swap = a[i];
            a[i] = a[j];
            a[j] = swap;
        }
    
        public static void main(String[] args) {
            insertionsort(new Integer[]{10,9,8,7,6,5,4,3,2,1});
        }
    }
    ```
## bubble
    ```c
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
    ```
    ```java
    import java.util.Arrays;

    public class bubble {
        public static void bubblesort(int[] arr) {
            int temp = 0;
            for(int i = 0 ; i < arr.length ; i++ ) {
                for(int j = 1; j < arr.length-i ;j++) {
                    if(arr[j] < arr[j-1]) {
                        temp = arr[j-1];
                        arr[j-1] = arr[j];
                        arr[j] = temp;
                    }
                }
            }
            System.out.println(Arrays.toString(arr));
        }
        public static void main(String[] args) {
            bubblesort(new int[]{10, 9, 8, 7, 6, 5, 4, 3, 2, 1});
        }
    }
    ```