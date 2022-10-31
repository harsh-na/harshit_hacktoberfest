#include<iostream>
#include<climits>
using namespace std;

int main(){
    int arr[]={2,3,1,4,3};
    int n=5;
    int k=7;
    int sum=0,ans=INT_MAX;
    int l=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        while(sum>=k){
            ans=min(i-l+1,ans);
            sum-=arr[l];
            l+=1;
        }
    }
    cout<<ans;
    return 0;
}