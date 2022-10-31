/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;

class BinarySearch {
  public static void main (String[] args) {
	    int arr[]={1, 3, 4, 5, 6};
	    int target = 1;
	    binarySearch(arr, target);
  }

  static void binarySearch(int arr[], int k)
  {
	  int lo = 0, hi = arr.length - 1;
	  // for mid=lo-(hi-lo)/2
	  while (hi - lo > 1) {
		  int mid = (hi + lo) / 2;
		  if (arr[mid] < k) {
			  lo = mid + 1;
		  }
		  else {
			  hi = mid;
		  }
	  }
	  if (arr[lo] == k) {
	    System.out.println("Found At Index " + lo );
	  }
	  else if (arr[hi] == k) {
		  System.out.println("Found At Index " + hi );
	  }
	  else {
		  System.out.println("Not Found" );
	  }
  }
}
