#include<bits/stdc++.h>
using namespace std;

class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        long long m=0;
        int a[n];
        int b[n];
        a[0]=arr[0];
        for(int i = 1 ;i<n;i++){
            a[i]=max(a[i-1],arr[i]);
        }
        b[n-1]=arr[n-1];
        for(int i = n - 2; i >= 0; i--){
            b[i]=max(b[i+1],arr[i]);
        }
        for(int i=1;i<n-1;i++){
            int v=min(a[i-1],b[i+1]);
            if(v>arr[i]){
                m+=v-arr[i];
            }
        }
        return m;
    }
    int a[n];
    inr b[n];
    a[0]=arr[0];
    for(int i=1;i<n;i++){
        a[i]=max(arr[i],a[i-1]);
    }
    b[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--){
        b[i]=max(arr[i-1],b[i+1]);
    }
    for(int i=0;i<n;i++){
        
    }
};

int main(){
  int t;
  cin>>t;
  while(t--){
  int n;
  cin>>n;
  int a[n];
  while(n--){
    cin>>a[n-1];
  }
  Solution m;
  cout<<m.trappingWater(a,sizeof(a)/sizeof(a[0]);
  retunr 0;
}
