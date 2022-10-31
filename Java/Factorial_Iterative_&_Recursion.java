import java.util.Scanner;

public class Factorial {
    public static void main(String[] args) {
      
        //Iterative
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a number");
        int n = sc.nextInt();
      
        int fact=1;
        for(int i=1;i<=n;i++){
            fact = fact * i ;
        }
        System.out.println("Factorial using Iterative : " + fact);

        //Recursive
        factorial(n);
        System.out.println("Factorial using Recursive : " + factorial(n));
    }

    public static int factorial(int n) {
        int facto;
        if(n==0){
            facto=1;
        }else {
            facto = n * factorial(n - 1);
        }
        return facto;
    }
}
