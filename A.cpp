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
#define yes cout << "Yes";
#define no cout << "No";
#define yn yes else no

const int INF = 1e9 + 7;

void solve()
{
    string s, t;
    cin >> s >> t;

    vi f(26, -1);
    for (int i=0; i<s.length(); i++) {
        if ((f[s[i] - 'a'] == -1 && f[t[i] - 'a'] == -1) || (f[s[i] - 'a'] == t[i] - 'a' && f[t[i] - 'a'] == s[i] - 'a')) {
            f[s[i] - 'a'] = t[i] - 'a';
            f[t[i] - 'a'] = s[i] - 'a';
        } else {
            no
            return;
        }
    }
    yes
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