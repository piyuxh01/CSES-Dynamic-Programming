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
const int MAXN = 2e5+5;
void dfs(int i,int j,vector<vector<char>>& matrix,vector<vector<bool>>& vis){
    int n = matrix.size();
    int m = matrix[0].size();
    if(i<0 or j<0 or i>=n or j>=m or vis[i][j] or matrix[i][j] == '#')
        return;
    matrix[i][j] = '#';
    dfs(i-1,j,matrix,vis);
    dfs(i+1,j,matrix,vis);
    dfs(i,j-1,matrix,vis);
    dfs(i,j+1,matrix,vis);
}
void solve() {
    int n,m;
    cin>>n>>m;
    int count = 0;
    vector<vector<char>> matrix(n,vector<char>(m));
    vector<vector<bool>> vis(n,vector<bool>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if (matrix[i][j] == '.'){
                dfs(i,j,matrix,vis);
                count++;
            }
        }
    }
    cout<<count<<endl;
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