#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define vb vector<bool>
#define pib pair<int, bool>
#define mii map<int, int>
#define mil map<int, ll>
#define mli map<ll, int>
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define yn yes else no

const int INF = 1e9 + 7;

void solve()
{
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (int &x : a) cin >> x;
    sort(a.begin(), a.end());

    int res = INF;
    for (int i=k-1; i<n; i++) {
        res = min(res, a[i] - a[i-k+1]);
    }
    cout << res << '\n';
}

signed main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}