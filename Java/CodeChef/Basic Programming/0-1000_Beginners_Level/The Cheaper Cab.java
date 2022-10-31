/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		Scanner sc=new Scanner(System.in);
		int T=sc.nextInt();
		if(T>=1&&T<=100){
		for (int i=1;i<=T;i++){
		int X=sc.nextInt();
		int Y=sc.nextInt();
		 if(X>=1&&X<=100&&Y>=1&&Y<=100){
		    if(X>Y)
		    System.out.println("SECOND");
		    else if(X==Y)
		    System.out.println("ANY");
		else
		    System.out.println("FIRST");
		 }
		
		} 
		}
	}
}
