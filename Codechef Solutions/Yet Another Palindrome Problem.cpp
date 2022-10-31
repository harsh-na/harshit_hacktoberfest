#include <bits/stdc++.h>
using namespace std;

int main(){
   int t;
   cin>>t;
   while(t--){
    int n ;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int flag1=0;
    int flag2=0;
    for(int i=0;i<n/2;i++){
        if(a[i]!=a[n-(i+1)]){
            flag1=1;
            break;
        }
    }
    if(flag1==1){
        for(int i=0;i<n/2-1;i++){
        if(a[i]>a[i+1]){
            flag2=1;
            break;
        }
      }
      for(int i=0;i<n/2-1;i++){
        if((a[n-(i+1)]-a[i])<=(a[n-(i+1+1)]-a[i+1])){
            flag2=1;
            break;
        }
      }

    }
    if(flag1==0) cout<<0<<endl;
    else{
        if(flag2==1) cout<<-1<<endl;
            if(flag2==0) cout<<a[n-1]-a[0]<<endl;
    }
    

   }




return 0;    
}