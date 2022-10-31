package com.company;
import java.util.*;
public class Game_RPS {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int i=0,u=0,c=0;
        while (i!=5) {
            i++;
            System.out.println("Enter - 0 for Rock ; 1 for Scissor ; 2 for paper");
            int num = sc.nextInt();
            Random rn = new Random();
            int rand = rn.nextInt(3);
            if (rand == 0 && num == 0)
                System.out.println("Rock \n IT'S A TIE");
            if (rand == 0 && num == 1) {
                System.out.println("Rock \n COMPUTER WON");
                c++;
            }
            if (rand == 0 && num == 2) {
                System.out.println("Rock \n YOU WON");
                u++;
            }
            if (rand == 1 && num == 1) {
                System.out.println("Scissor \n IT'S A TIE");
            }
            if (rand == 1 && num == 0) {
                System.out.println("Scissor \n YOU WON");
                u++;
            }
            if (rand == 1 && num == 2) {
                System.out.println("Scissor \n COMPUTER WON");
                c++;
            }
            if (rand == 2 && num == 2) {
                System.out.println("Paper \n IT'S A TIE");
            }
            if (rand == 2 && num == 1) {
                System.out.println("Paper \n YOU WON");
                u++;
            }
            if (rand == 2 && num == 0) {
                System.out.println("Paper \n COMPUTER WON");
                c++;
            }
        }
        if (u>c)
            System.out.println("\n\tCongratulations, You won this game");
        else if (u<c)
            System.out.println("\n\tComputer won, Better luck next time");
        else
            System.out.println("\n\tIt's a tie game");

    }
}
