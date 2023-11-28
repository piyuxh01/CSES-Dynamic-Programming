#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
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
#define forn(i, a, b) for (int i = a; i < b; i++)
#define rforn(i, a, b) for (int i = a; i >= b; i--)
#define nl "\n"
#define dbg(x) cout << x << nl
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
const int MAXN = 2e5 + 5;

void dfs(int src, int par, v32 adj[], vector<bool> &vis, int col) {
    vis[src] = true;
    for (auto i : adj[src]) {
        if (!vis[i]) {
            dfs(i, src, adj, vis, !col);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    v32 adj[n + 1]; // Changed to n+1 instead of m+1
    v32 ans; // Removed m+1 size since you're using push_back
    vector<bool> vis(n + 1, false); // Changed to n+1
    int x, y;
    forn(i, 0, m) {
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    int col = 0;
    for (int i = 1; i <= n; i++) { // Loop from 1 to n
        if (!vis[i]) {
            dfs(i, -1, adj, vis, col); // Start with 0 as color
            ans.pb(col); // Push i to the answer since you need vertices
        }
    }
    for (auto i : ans) {
        cout << i << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int test = 1; // Changed to int
    // cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}
