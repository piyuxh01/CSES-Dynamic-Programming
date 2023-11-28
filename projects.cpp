#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
/*
S.find_by_order(k) => returns iterator to the kth largest element
S.find_by_order(sz) returns end(S)
S.order_of_key(x) => number of items in the set that are strictly smaller than x
*/
#define ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
#define ordered_multiset = tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>;
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
#define forn(i,a,b) for(int i = a; i < b; i++)
#define rforn(i,a,b) for(int i = a; i >= b; i--)
#define nl "\n"
#define dbg(x) cout << x << nl
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define all(x) begin(x), end(x)
#define sz(x) x.size()
const int MOD = 1e9+7;
struct jobs{
    int f,s,t;
};
// bool comp(const jobs& a, const jobs& b) {
//     return a.s < b.s;
// }
// int latestNonConflict(vector<jobs> &arr, int i)
// {
//     for (int j=i-1; j>=0; j--)
//     {
//         if (arr[j].s < arr[i-1].f)
//             return j;
//     }
//     return -1;
// }
// ll dfs(int i,vector<jobs> &arr,v32 &dp){
//     if(i == 1) return arr[i-1].t;
//     if(dp[i] != -1) return dp[i];
//     ll inc = arr[i-1].t;
//     int x = latestNonConflict(arr,i);
//     if(x != -1){
//         inc += dfs(x+1,arr,dp);
//     }
//     ll exc = dfs(i-1,arr,dp);
//     return dp[i] = max(inc,exc);
// }
void solve() {
    int n;cin>>n;
    vector<jobs> arr(n+1);
    forn(i,1,n+1){
        cin>>arr[i].f>>arr[i].s>>arr[i].t;
    }
    sort(arr.begin() + 1, arr.end(), [](const jobs &p1, const jobs &p2) {
		return p1.s < p2.s;
	});

    vector <ll> lastEndDate (n + 1);
	for (int i = 1; i <= n; i++) {
		lastEndDate[i] = arr[i].s;
	}
 
	// (3)
	vector <ll> maxMoney (n + 1, 0);
	for (int i = 1; i <= n; i++) {
		int j = distance(lastEndDate.begin(), lower_bound(lastEndDate.begin(), lastEndDate.end(), arr[i].f)) - 1;
		maxMoney[i] = max(maxMoney[i - 1], maxMoney[j] + arr[i].t);
	}
 

    cout<< maxMoney[n] <<endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

auto start_time = chrono::high_resolution_clock::now();

    ll test = 1;
    // cin >> test;
    while (test--) {
        solve();
    }
auto end_time = chrono::high_resolution_clock::now();
auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
cout << duration.count() << nl;

    return 0;
}