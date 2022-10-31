#include <bits/stdc++.h>
using namespace std;
solve(int coin[],int n,int sum){
    int dp[n+1][sum+1];

    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int j=0;j<=sum;j++){
        dp[0][j]=INT_MAX-1;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(i==1){
                if(j%coin[0]==0){
                    dp[i][j]=j%coin[0];
                }
                else
                dp[i][j]=INT_MAX-1;
            }
            if(coin[i-1]<=sum){
                dp[i][j]= min(dp[i-1][j],1+dp[i][j-coin[i-1]]);

            }
            else
            dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][sum];

}



int main(){
    int coin[]={1,2,3,4,5};
    int sum=5;
    int n=sizeof(coin)/sizeof(coin[0]);
    cout<<solve(coin,n,sum);
}