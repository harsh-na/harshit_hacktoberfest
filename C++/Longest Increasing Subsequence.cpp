#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int arr[])
    {
       int t[n];
       t[0]=1;
       for(int i=1;i<n;i++){
           int maxi=1;
           for(int j=i-1;j>=0;j--){
               if(arr[j]<arr[i]) maxi=max(maxi,t[j]+1);
           }
           t[i]=maxi;
       }
       int maxi=INT_MIN;
       for(int i=0;i<n;i++) maxi=max(maxi,t[i]);
       return maxi;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends
