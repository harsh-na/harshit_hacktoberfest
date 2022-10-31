import java.util.*;
import java.lang.*;
import java.io.*;
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc=new Scanner(System.in);
            int N=sc.nextInt();
            int mid=N/2;
            if(N==1){
                System.out.println(0);
            }
            else(N%2==0){
                System.out.println(N-1);
            }          
	}
}
