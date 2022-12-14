//https://leetcode.com/problems/distinct-subsequences-ii/

class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.length();
        vector<int> last(26, -1); /* last position given character is seen */
        vector<long> dp(n + 1); /* #unique subsequences in s[0 ... i - 1] */
        dp[0] = 1; /* empty subsequence */
        
        int i = 0;
        for (char c : s) {
            dp[i + 1] = 2 * dp[i]; /* subseuqnces : excluding + including ith character */
            
			/* To reject duplicates, find the last occurance of 
                same character, and subtract all the subsequences
			    before last occurances 

                For example, current character is 'a', and last occurance of 'a' was at 
                position 2, adding 'a' to any subsequence till position 1 will be
				redundant. Those subsequences would have been counted when
                considering 'a' at index 2 */
            if (last[c - 'a'] > -1) {
                dp[i + 1] -= dp[last[c - 'a']];
            }
            
            dp[i + 1] %= 1000000007;
            dp[i + 1] += 1000000007; /* if dp[i + 1] < 0 */
            dp[i + 1] %= 1000000007;
            last[c - 'a'] = i++;
        }
        
        long res = dp[n] - 1; /* reject the empty subsequence */
        res %= 1000000007;
        res += 1000000007; /* if res < 0 */
        return res % 1000000007;
    }
};