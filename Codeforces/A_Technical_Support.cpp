// --------------------------------------------------------------------------------------------
#ifndef LOCAL
    #pragma GCC optimize("Ofast")
    #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
    #pragma GCC optimize("unroll-loops")
#endif

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
ll const MOD = 998244353;
double eps = 1e-12;
#define ln '\n'
#define sp ' '
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define fi first
#define se second
#define FOR(a, b, c) for (int a = (b); a < (c); ++a)
#define f(a, b) for (int i = (a); i < (b); ++i)
#define frev(n) for (int i = n; i--;)
#define all(arr) arr.begin(), arr.end()
#define forEachEin(arr) for(auto &e: arr)
typedef vector<int> vint;
typedef vector<vector<int>> mat;
#ifdef LOCAL
	#define dbg(x) cout << #x << ":" << x << ln
#else
	#define dbg(x)
#endif
// ============================================================================================

bool solve(vector<char> const &arr){
	int n = arr.size();
    stack<char> S;
    f(0, n){
        if(arr[i]=='Q') S.push(arr[i]);
        else if(!S.empty()) S.pop();
    }
	return S.empty();
}

int main(){
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#else
		fast_cin();
	#endif
	ll t;   cin >> t;
	for(int T=1; T<=t; T++){
		int n = 0; cin>>n;
		vector<char> arr(n);
		f(0, n)  cin>>arr[i];
		// cout << "Case #" << t << ": ";
		cout << (solve(arr)?"Yes":"No");
		cout << ln;
	}
	return 0;
}