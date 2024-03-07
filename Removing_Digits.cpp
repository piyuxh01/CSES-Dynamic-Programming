#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
typedef long long ll;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;

const int MAXN = 2e5 + 5;

int dfs(int n,int count,v32& dp) {
    if (n == 0) return count;
    if(dp[n] != -1) return dp[n];
    int x = n;
    int maxi = 0;
    while (x > 0) {
        maxi = max(maxi, x % 10);
        x /= 10;
    }
    return dp[n] = dfs(n - maxi,1+count,dp);
}

void solve() {
    int n;
    cin >> n;
    v32 dp(n+1,-1);
    cout << dfs(n,0,dp) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll test = 1;
    // cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}
