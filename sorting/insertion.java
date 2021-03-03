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