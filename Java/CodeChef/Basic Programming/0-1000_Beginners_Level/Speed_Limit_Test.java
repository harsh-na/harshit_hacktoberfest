import java.util.*;
import java.lang.*;
import java.io.*;
class Speed_Limit_Test
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc=new Scanner(System.in);
        int T=sc.nextInt();
        for(int i=0;i<T;i++){
            int A =sc.nextInt();
            int B=sc.nextInt();
            int X=sc.nextInt();
            int Y=sc.nextInt();
            
            float a=A/X;
            float b=B/Y;
            if(a>b){
                System.out.println("Alice");
            }
            else if(a<b){
                System.out.println("Bob");
            }
            else{
                System.out.println("equal");
            }
        }
	}
}
