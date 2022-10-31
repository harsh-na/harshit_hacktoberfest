#include<stdio.h>
int main()
{ int a;
  int m,d;
  printf("enter the no. of days");
  scanf("%d" ,&a);
  m=a/30;
  d=a%30;
  printf("no. of months=%d",m);
  printf("no. of days=%d", d);
}
