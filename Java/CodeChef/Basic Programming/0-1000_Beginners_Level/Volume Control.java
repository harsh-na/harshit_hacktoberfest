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
		int t=sc.nextInt();
		if(t>=1&&t<=100){
		for(int i=1;i<=t;i++){
		int Vup=sc.nextInt();
		int Vdown=sc.nextInt();
  if(Vup>=1&&Vup<=100&&Vdown>=1&&Vdown<=100){
		if(Vup>Vdown){
		  Vup=Vup- Vdown;
		  System.out.println(Vup);
		}
		else{
		  Vdown=Vdown- Vup;
		  System.out.println(Vdown);
		}
	}
}
}
}
}