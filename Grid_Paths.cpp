#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
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
const int MOD = 1e9+7;

int dfs(int i,int j,vector<vector<char>>& arr,vv32& dp){
    int n = arr.size();
    if(i >= n or j>= n or i<0 or j<0 or arr[i][j] == '*') return 0;
    if(i == n-1 and j == n-1) return 1;
    if(dp[i][j] != -1) return dp[i][j];
    int down = dfs(i+1,j,arr,dp);
    int right = dfs(i,j+1,arr,dp);
    return dp[i][j] = (right + down)%MOD;
}
void solve() {
    int n;
    cin>>n;
    vector<vector<char>>arr(n,vector<char>(n));
    vv32 dp(n+1,v32(n+1,-1));
    forn(i,0,n){
        forn(j,0,n) cin>>arr[i][j];
    }
    cout<<dfs(0,0,arr,dp)<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
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