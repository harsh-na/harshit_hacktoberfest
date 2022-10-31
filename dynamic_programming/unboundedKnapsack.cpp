#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N + 1, vector<int>(W + 1, -1));
        for (int i = 0; i < N + 1; i++)
        {
            for (int j = 0; j < W + 1; j++)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
                else if (wt[i - 1] <= j)
                {
                    dp[i][j] = max(dp[i - 1][j], val[i - 1] + dp[i][j - wt[i - 1]]);
                }
                else if (wt[i - 1] > j)
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[N][W];
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;
        int val[n], wt[n];
        for (int i = 0; i < n; i++)
        {
            cin >> val[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> wt[i];
        }
        Solution ob;
        cout << ob.knapSack(n, w, val, wt) << endl;
    }
    return 0;
}