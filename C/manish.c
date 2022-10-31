// STONE PAPER SCSSIORS Game
// Creater : Manish Kumar

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(){
    int p = 1;
    do{
        int num; char a[10] = "STONE"; char b[10] = "PAPER"; char c[10] = "SCSSIOR";
            srand(time(0));
            num = rand() % 3 + 1;

        // printf("The number is: %d\n", num);  //Check variable

// Code for Computer's choice
        char sps[20];
        if(num == 1){strcpy(sps, a);}
        else if(num == 2){strcpy(sps, b);}
        else if(num == 3){strcpy(sps, c);}


// Code for player's choice 
        int pnum; char abc[10];
    do{
            printf("\nEnter your choice i.e. STONE(1), PAPER(2), or SCSSIOR(3):\n==");
            scanf("%d", &pnum);
        } while (pnum<1 || pnum>3);

        if(pnum == 1){strcpy(abc, a);}
        else if(pnum == 2){strcpy(abc, b);}
        else if(pnum == 3){strcpy(abc, c);}
        printf("Your choice is: ");
        puts(abc);  //Check Function

   
// Here code for game starts
        printf("Computer's choice was: ");
        puts(sps);      // Compter's choice:
        if(pnum==1 && num ==3)      {printf("\n Congratulations! YOU WON\n");}
        else if(pnum==2 && num ==1)      {printf("\n Congratulations! YOU WON\n");}
        else if(pnum==3 && num ==2)      {printf("\n Congratulations! YOU WON\n");}
        else if(pnum == num)      {printf("\n Match TIE\n");}
        else{printf("\nSorry! YOU LOST\n");}
        

    } while (p == 1);

    return 0;
}
