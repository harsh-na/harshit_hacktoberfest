import java.util.*;
import java.lang.*;
import java.io.*;
class Bob_at_the_Bank
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc=new Scanner(System.in);
        int T=sc.nextInt();
        for(int i=0;i<T;i++){
            int W =sc.nextInt();
            int X=sc.nextInt();
            int Y=sc.nextInt();
            int Z=sc.nextInt();
            int a=W+(X-Y)*Z;
            System.out.println(a);
        }
	}
}
