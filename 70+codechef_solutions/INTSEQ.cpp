/*
    (https://www.codechef.com/submit/INTSEQ?tab=statement)
*/

#include <iostream>
using namespace std;

int main() {
	int T=0;
	cin>>T;
	while(T--){
	    int K;
	    cin>>K;
	    int ans=0;
	    if(K%2) ans=0;
	    else{
	        ans++;
	        for(int A=K/2;A%2==0;A/=2){
                ans++;
	        }
	    }
	    cout<<ans<<'\n';
	}
	return 0;
}