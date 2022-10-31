#include<stdio.h>    
#include<stdlib.h>  
int main(){  
int b[10],p,i;    
system ("class");  
printf("Enter the number: ");    
scanf("%d",&p);    
for(i=0;p>0;i++)    
{    
b[i]=p%2;    
p=p/2;    
}    
printf("\nIn Binary;");    
for(i=i-1;i>=0;i--)    
{    
printf("%d",b[i]);    
}    
return 0;  
}  
