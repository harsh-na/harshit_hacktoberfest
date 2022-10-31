package sortingalgos;

import java.util.Arrays;

/*
 * Selection sort is a sorting algorithm that selects the smallest 
 * element from an unsorted list in each iteration and places that 
 * element at the beginning of the unsorted list.
 * time complexity O(n*2)
 */
class SelectionSort {
    static void selectionSort(int array[]) {
        int size = array.length;

        for (int step = 0; step < size - 1; step++) {
            int min_idx = step;

            for (int i = step + 1; i < size; i++) {

                if (array[i] < array[min_idx]) {
                    min_idx = i;
                }
            }

            // put min at the correct position
            int temp = array[step];
            array[step] = array[min_idx];
            array[min_idx] = temp;
        }
    }

    public static void main(String args[]) {
        int[] data = { 20, 12, 10, 15, 2 };
        selectionSort(data);
        System.out.println(Arrays.toString(data));
    }
}