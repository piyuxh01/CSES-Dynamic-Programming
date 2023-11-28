#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
// Policy based data structures
/*
S.find_by_order(k) => returns iterator to the kth largest element
S.find_by_order(sz) returns end(S)
S.order_of_key(x) => number of items in the set that are strictly smaller than x
*/
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
typedef long long ll;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
#define forn(i,a,b) for(ll i = a; i < b; i++)
#define rforn(i,a,b) for(ll i = a; i >= b; i--)
#define nl "\n"
#define dbg(x) cout << x << nl
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define all(x) begin(x), end(x)
#define sz(x) ((ll)(x).size())
const ll MOD = 1000000007; // Updated MOD value
const int MAXN = 1e5;

int dfs(int x, int i, v32& coins, set<vector<int>>& combo, vector<int>& curr, vv32& dp) {
    if (x == 0) {
        combo.insert(curr);
        return 1;
    }
    if (x < 0 || i < 0) {
        return 0;
    }
    if (dp[x][i] != -1) return dp[x][i];
    curr.pb(coins[i]);
    int a = dfs(x - coins[i], i, coins, combo, curr, dp) % MOD;
    curr.pop_back();
    int b = dfs(x, i - 1, coins, combo, curr, dp) % MOD;
    return dp[x][i] = (a + b) % MOD;
}

void solve() {
    int n, m;
    cin >> n >> m;
    v32 coins(n);
    forn(i, 0, n) cin >> coins[i];
    set<vector<int>> combo;
    vector<int> curr;
    vv32 dp(m + 1, v32(n + 1, -1));
    int x = dfs(m, n - 1, coins, combo, curr, dp);
    cout << combo.size() << nl;
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
