#include<bits/stdc++.h>
using namespace std;
int main()

{
	int n,x=0,c=1,i,t,r,s=0;
	
	cout<<"enter n";
	cin>>n;
	
	while(c<=n)
	{
	 t=x;
	 s=0;
		while(t!=0)
		{
			r=t%10;
			s=(s*10)+r;
			t=(t/10);
			
		}
		
		if(s==x)
		{
			cout<<" "<<x;
			++c;
		}
		x=x+1;
		
	}
	return 0;
}
