import java.util.Arrays;

public class sorting {
    public static void main(String[] args) {
        int max_size = 10;
        int list[] = new int[max_size];
        
        Sort s = new Sort();

        for(int i=0; i<max_size;i++ ) list[i] = i;
        System.out.println("Before Selection : " + Arrays.toString(list));
        s.Selection(list);
        System.out.println(" After Selection : " + Arrays.toString(list));

        for(int i=0; i<max_size;i++ ) list[i] = i;
        System.out.println("Before Insertion : " + Arrays.toString(list));
        s.Insertion(list);
        System.out.println(" After Insertion : " + Arrays.toString(list));

        for(int i=0; i<max_size;i++ ) list[i] = i;
        System.out.println("Before Bubble : " + Arrays.toString(list));
        s.Bubble(list);
        System.out.println(" After Bubble : " + Arrays.toString(list));
    }
}

class Sort {
    public void Selection(int[] arr) {
        int N = arr.length;
        for(int i = 0 ; i < N ; i++) {
            int min = i;
            for(int j = i+1 ; j < N ;j++ ) {
                if(less(arr[j], arr[min])) {
                    min = j;
                }
            }
            exch(arr, i, min);
        }
    }
    public void Insertion(int[] arr) {

    }
    public void Bubble(int[] arr) {

    }
    private boolean less(Comparable v, Comparable w) {
        return v.compareTo(w) < 0;
    }
    private void exch(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}