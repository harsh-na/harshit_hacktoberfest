#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 3;
const int M = 103;
int dp[N][M];

int32_t main()
{

    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    int mod = 1e9 + 7;
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= m; j++)
        {
            if (i == 1)
            {
                if (a[i] == 0 || a[i] == j)
                {
                    dp[1][j] = 1;
                }
                else
                {
                    dp[1][j] = 0;
                }
            }

            else if (a[i] == 0 || a[i] == j)
            {
                int o1 = dp[i - 1][j - 1];
                int o2 = dp[i - 1][j];
                int o3 = dp[i - 1][j + 1];
                dp[i][j] = ((o1 + o2) % mod + o3) % mod;
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    ll ans = 0;
    for (int i = 1; i <= m; i++)
    {
        ans = (ans + dp[n][i]) % mod;
    }
    cout << ans << '\n';

    return 0;
}