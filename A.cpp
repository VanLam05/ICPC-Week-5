#include <bits/stdc++.h>
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
#define yes cout << "Yes";
#define no cout << "No";
#define yn yes else no

const int INF = 1e9 + 7;

void solve()
{
    string s, t;
    cin >> s >> t;

    vi f(26, -1), g(26, -1);
    for (int i = 0; i < s.length(); i++)
    {
        int si = s[i] - 'a';
        int ti = t[i] - 'a';
        if (f[si] == -1 && g[ti] == -1)
        {
            f[si] = ti;
            g[ti] = si;
        }
        else if (f[si] != ti || g[ti] != si)
        {
            no return;
        }
    }
    yes
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}