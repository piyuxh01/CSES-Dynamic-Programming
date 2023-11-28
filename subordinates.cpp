#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
// n = 10^5  n,nlogn,nrootn
// n = 10^6  n,nlogn
// n >= 10^9 1,logn
// n = 10^3  n,n^2,n^2logn
// n = 10^2  n,n^2,n^3,n^3logn
// n <= 20   2^n bitmasking
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
typedef unordered_map<int,int> um;
typedef map<int,int> m;
ll MOD = 998244353;
#define forn(i,a,b) for(ll i = a; i < b; i++)
#define rforn(i,a,b) for(ll i = a; i >= b; i--)
#define nl "\n"
#define dbg(x) cout << x << nl
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define INF 2e18
#define all(x) (x).begin(), (x).end()
void swap(int &a, int &b) { a = a ^ b; b = a ^ b; a = a ^ b; }
const int MAXN = 2e5 + 5;
v32 adj[MAXN];
int ans[MAXN];
void dfs(int src){
    ans[src] = 1;
    for(auto i:adj[src]){
        dfs(i);
        ans[src] += ans[i]; 
    }
}
void solve() {
    int n;
    cin>>n;
    int x = 0;
    forn(i,2,n+1){
        cin>>x;
        adj[x].pb(i);
    }
    dfs(1);
    for(int i=1;i<=n;i++){
        cout<<ans[i]-1<<" ";
    }
    cout<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    auto start_time = chrono::high_resolution_clock::now();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll test = 1;
    // cin >> test;
    while (test--) {
        solve();
    }
    auto end_time = chrono::high_resolution_clock::now();
    chrono::duration<float> elapsed_seconds = end_time - start_time;
    float time_taken = elapsed_seconds.count();
    //dbg(time_taken);
    return 0;
}