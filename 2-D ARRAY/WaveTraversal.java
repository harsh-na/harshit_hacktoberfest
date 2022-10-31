import java.io.*;
import java.util.*;

public class Main {

  public static void main(String[] args) throws Exception {
    // write your code here
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int m = sc.nextInt();
    int[][]mon = new int[n][m];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        mon[i][j] = sc.nextInt();
      }
    }

    for (int j = 0; j < mon[0].length; j++) {
      if (j % 2 == 0) {
        for (int i = 0; i < mon.length; i++) {
          System.out.println(mon[i][j]);
        }
      }
      else {
         for (int i =mon.length-1; i>=0;i--) {
          System.out.println(mon[i][j]);
        }
      }
    }
  }

}
