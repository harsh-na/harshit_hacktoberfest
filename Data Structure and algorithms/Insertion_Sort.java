// Java program for implementation of Insertion Sort
public class Main {
	public static void main(String args[])
	{
		int arr[] = { 31,12, 71, 83, 51, 16 };
        sort(arr);
        int n = arr.length;
		for (int i = 0; i < n; ++i){
            System.out.print(arr[i] + " ");
        }
	}
    public static void sort(int arr[])
	{
		int n = arr.length;
		for (int i = 1; i < n; ++i) {
			int key = arr[i];
			int j = i - 1;

			while (j >= 0 && arr[j] > key) {
				arr[j + 1] = arr[j];
				j = j - 1;
			}
			arr[j + 1] = key;
		}
	}
}
