/*
Given two strings str1 and str2 and below operations 
that can be performed on str1. Find minimum number of edits 
(operations) required to convert ‘str1’ into ‘str2’.  

1.Insert
2.Remove
3.Replace
*/
#include <bits/stdc++.h>
using namespace std;

int editDistance(string s, string t) {
       int n=s.size();
       int m=t.size();
       int dp[n+1][m+1];
       for(int i=0;i<n+1;i++)
       dp[i][0]=i;
       for(int i=0;i<m+1;i++)
       dp[0][i]=i;
       
       for(int i=1;i<n+1;i++)
       {
           for(int j=1;j<m+1;j++)
           {
               if(s[i-1]==t[j-1])
               dp[i][j]=dp[i-1][j-1];
               else
               dp[i][j]=min(1+dp[i-1][j-1],1+dp[i-1][j]);
               dp[i][j]=min(dp[i][j],1+dp[i][j-1]);
           }
       }
       return dp[n][m];
}
int main()
{ 
    string str1 = "sunday";
    string str2 = "saturd";
    cout << editDistance(str1, str2);
    return 0;
}
