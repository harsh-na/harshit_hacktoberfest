import java.util.*;
import java.lang.*;
import java.io.*;
class Bidding
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc=new Scanner(System.in);
        int T=sc.nextInt();
        for(int i=0;i<T;i++){
            int num1=sc.nextInt(); //Alice
            int num2=sc.nextInt(); //BOB
            int num3=sc.nextInt(); //Charlie
            if (num1 >= num2 && num1 >= num3)
                    System.out.println("Alice");
            else if (num2 >= num1 && num2 >= num3)
                   System.out.println( "BOB");
            else
                  System.out.println("Charlie");
        }
        
	}
}
