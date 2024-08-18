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
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define yn yes else no

const int INF = 1e9 + 7;

bool isValid(int a, int b, int c)
{
    return a + b > c && b + c > a && c + a > b;
}

void solve()
{
    int n;
    cin >> n;
    vi a(n);
    for (int &x : a)
        cin >> x;
    multiset<int> s;
    int res = 0;
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (s.size() < 2)
        {
            s.insert(a[i]);
        }
        else
        {
            while (s.size() > 1 && (!isValid(*s.begin(), *s.rbegin(), a[i]) || !isValid(*s.begin(), *next(s.begin()), a[i]) || !isValid(*s.rbegin(), *next(s.rbegin()), a[i])))
            {
                s.erase(s.find(a[j++]));
            }
            s.insert(a[i]);
            if (i - j + 1 > 2) res = max(res, i - j + 1);
        }
    }
    cout << res;
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