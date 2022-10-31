package com.company;
import java.util.*;

class game{
    int rn,num,n=1;
    Scanner sc = new Scanner(System.in);
    public game(){
        Random run = new Random();
        rn = run.nextInt(101);
    }
    public int takeUserInput(){
        System.out.printf("  Welcome to Guess the Number Game \n Guess a number between 0 to 100 to start \n");
        num = sc.nextInt();
        return num;
    }
    public void isCorrectNumber(){
        while (num!=rn){
            if(num<rn) {
                System.out.println("Your Number is LESSER than the Computer number, Try Again..");
                num = sc.nextInt();
                n++;
            }
            else if (num>rn) {
                System.out.println("Your Number is GREATER than the Computer number, Try Again..");
                num = sc.nextInt();
                n++;
            }
        }
        System.out.println("Congratulations you guessed the Number right in "+n+" times");
    }
}


public class Guess_The_Number {
    public static void main(String[] args) {
        game guess = new game();
        guess.takeUserInput();
        guess.isCorrectNumber();
    }
}
