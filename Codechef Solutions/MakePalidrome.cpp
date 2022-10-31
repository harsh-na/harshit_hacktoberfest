#include <bits/stdc++.h>
using namespace std;

int main() {
    int tt; cin>>tt;
    while(tt--){
        int N; cin>>N;
        string S1; cin>>S1;
        int x=0,y=0;
        for(auto z:S1){
            if(z=='0'){
                x++;
            }
            else{
                y++;
            }
            
        }
        string S2;
        if(y>x){
            for(int i=0; i<y;i++){
                S2+='1';
            }
        }
        else{
            for(int i=0; i<x; i++){
                S2+='0';
            }
        }
        cout<<S2<<endl;
    }
	
	return 0;
}