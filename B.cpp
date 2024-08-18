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
    int n, m;
    cin >> n >> m;
    vi tmp;
    for (int i=1; i*i<=m; i++) {
        if (m % i == 0) {
            tmp.push_back(i);
            tmp.push_back(m / i);
        }
    }
    sort(tmp.begin(), tmp.end());
    int ind = upper_bound(tmp.begin(), tmp.end(), m / n) - tmp.begin();
    cout << tmp[ind - 1];
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