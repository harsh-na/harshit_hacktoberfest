#include<iostream>
#include<math.h>
int main()

{
	int n,x=1,c=1,i,r,t,s=0,d,o;
	
	printf("enter n ");
	scanf("%d",&n);
	
	while(c<=n)
	{
	 t=x;
	 o=x;
	 s=0;
	 d=0;
		while(t!=0)
		{
			++d;
			t=(t/10);
			
		}
		
		while(o!=0)
		{
			r=(o%10);
			s=s+pow(r,d);
			o=(o/10);
		}
		
		if(s==x)
		{
			printf(" %d",x);
			++c;
		}
		x=x+1;
		
	}
	return 0;
}
