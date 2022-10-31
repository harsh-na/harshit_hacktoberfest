#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int maxSubArray(vector<int>& a){
    int sum=0,  start = 0, end = 0, index = 0, x = a[0];
    for(int i=0;i<a.size();i++){
        sum += a[i];
        if(x<sum){
            x = sum;
            start = index;      // this is for calculate length of subarray
            end = i;
        }
        if(sum<0){
            sum = 0;
            index++;
        }
    }    return x;
}

// Main Function 
int main()
{
    int n; 
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
       v.push_back(x);
    }
    cout<<maxSubArray(v)<<endl;
    return 0;   
}
