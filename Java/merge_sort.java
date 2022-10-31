import java.util.Scanner;

public class merge_sort {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("enter the size of the array:");
        int length = sc.nextInt();
        int[] array = new int[length];
        System.out.println("enter array elements:");
        for (int i = 0; i < length; i++) {
            array[i] = sc.nextInt();
        }

        mergeSort(array, array.length);
        System.out.println("after sorting:");
        for (int i = 0; i < array.length; ++i) {
            System.out.print(array[i] + " ");
        }
        sc.close();
    }

    public static void merge(int[] left_arr, int[] right_arr, int[] arr, int left_size, int right_size) {

        int i = 0, l = 0, r = 0;
        while (l < left_size && r < right_size) {

            if (left_arr[l] < right_arr[r]) {
                arr[i++] = left_arr[l++];
            } else {
                arr[i++] = right_arr[r++];
            }
        }
        while (l < left_size) {
            arr[i++] = left_arr[l++];
        }
        while (r < right_size) {
            arr[i++] = right_arr[r++];
        }
    }

    public static void mergeSort(int[] arr, int len) {
        if (len < 2) {
            return;
        }

        int mid = len / 2;
        int[] left_arr = new int[mid];
        int[] right_arr = new int[len - mid];

        // Dividing array into two and copying into two separate arrays
        int k = 0;
        for (int i = 0; i < len; ++i) {
            if (i < mid) {
                left_arr[i] = arr[i];
            } else {
                right_arr[k] = arr[i];
                k = k + 1;
            }
        }
        // Recursively calling the function to divide the subarrays further
        mergeSort(left_arr, mid);
        mergeSort(right_arr, len - mid);
        // Calling the merge method on each subdivision
        merge(left_arr, right_arr, arr, mid, len - mid);
    }
}
