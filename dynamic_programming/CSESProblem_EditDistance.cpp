#include <bits/stdc++.h>
using namespace std;

const int N = 5003;
int dp[N][N];

int main()
{

    string a, b;
    cin >> a >> b;
    int n = a.size();
    int m = b.size();

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
            dp[i][j] = 1e6;
    }

    dp[0][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        dp[0][i] = i;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int op1 = 0, op2 = 0, op3 = 0;

            op1 = 1 + dp[i - 1][j];
            op2 = 1 + dp[i][j - 1];
            op3 = (dp[i - 1][j - 1]);
            op3 += ((a[i - 1] != b[j - 1]) ? 1 : 0);
            dp[i][j] = min(op1, min(op2, op3));
        }
    }

    cout << dp[n][m];

    return 0;
}
