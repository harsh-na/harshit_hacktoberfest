#include<bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>& prices)
{
	int n=prices.size();
	int curr_diff=prices[1]-prices[0];
	int profit=curr_diff;
	for(int i=1;i<n;i++)
	{
		int diff=prices[i+1]-prices[i];
		if(curr_diff>0)
         curr_diff+=diff;
         else
         curr_diff=diff;
         profit=max(profit,curr_diff);
	}
	return profit;
}
int main()
{
	int n;
	cin>>n;
	vector<int> prices;
	while(n--)
	{
		int x;
		cin>>x;
		prices.push_back(x);
	}
	int ans=maxProfit(prices);
	cout<<ans<<endl;
	return 0;
}
