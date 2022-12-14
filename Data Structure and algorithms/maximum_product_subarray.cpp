//Maximum Product Subarray
#include <bits/stdc++.h>

using namespace std;


class Solution{
public:

	long long maxProduct(vector<int> a, int n) {
	   long long ma=a[0],mi=a[0],ans=a[0];
	   for(int i=1;i<n;i++)
	   {   if(a[i]<0)
	       swap(ma,mi);
	       long long p=a[i];
	       ma=max(p,ma*a[i]);
	       mi=min(p,mi*a[i]);
	       ans=max(ans,ma);
	   }
	   return ans;
	}
};



int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
} 
