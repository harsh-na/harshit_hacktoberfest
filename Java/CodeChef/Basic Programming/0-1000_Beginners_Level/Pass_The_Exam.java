import java.util.*;
import java.lang.*;
import java.io.*;

class Pass_The_Exam
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc=new Scanner(System.in);
        int T=sc.nextInt();
        for(int i=0;i<T;i++){
            int A=sc.nextInt();
            int B=sc.nextInt();
            int C=sc.nextInt();
            int sum=A+B+C;
            if(sum>=100 && A>=10 && B>=10 && C>=10){
                System.out.println("pass");
            }
            else{
                System.out.println("fail");
            }
        }
	}
}
