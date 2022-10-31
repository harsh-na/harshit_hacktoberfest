import java.util.*;
import java.lang.*;
import java.io.*;
class BinaryToDecimal{
	public static void main(String[] args){
		Scanner scn = new Scanner(System.in);
		System.out.println("Enter the Binary Number : ");
		int bin = scn.nextInt();
		deci(bin);
	}
	public static void deci(int bin){
		int res = 0;
		int i = 0;
		while(bin!=0){
			int r = bin%10;
			res = res + (r*(int)Math.pow(2,i));
			i++;
			bin = bin/10;
		}
		System.out.println(res);
	}
}
