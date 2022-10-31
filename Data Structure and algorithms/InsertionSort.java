package sortingalgos;

import java.util.Arrays;

/*
 Insertion sort is a sorting algorithm that places an unsorted element at its suitable place in each iteration.
 time complexities 
  best O(n)
  Worst O(n*2)
 */
public class InsertionSort {

    static void insertionSort(int[] arr) {
        int n = arr.length;
        for (int i = 0; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
            /* Compare each element to left until the key smaller that it founds */
            while (j >= 0 && key < arr[j]) {
                arr[j + 1] = arr[j];
                --j;
            }
            // place the key after the smalller element than it
            arr[j + 1] = key;
        }
    }

    public static void main(String args[]) {
        int[] arr = { 6, 5, 9, 1 };
        insertionSort(arr);
        System.out.println(Arrays.toString(arr));
    }
}