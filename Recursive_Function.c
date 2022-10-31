#include <stdio.h>

// Sum of natural numbers using Recursive Function

int add(int num);

int main() 
{
  int n;
  printf("Enter any positive integer: ");
  scanf("%d", &n);

  printf("The sum is: %d", add(n));
  return 0;
}

int add(int num) 
{
  if (num != 0){
    return num + add(num - 1);
    }

  else{
    return num;
    }
}
