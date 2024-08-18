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
int n, k;
vl fen;

void query(int ind, int x)
{
    while (ind <= n)
    {
        fen[ind] += (ll)x;
        ind += (ind & -ind);
    }
}

ll calc(int ind)
{
    ll sum = 0;
    while (ind > 0)
    {
        sum += (ll)fen[ind];
        ind -= (ind & -ind);
    }
    return sum;
}

void solve()
{
    cin >> n >> k;
    vi a(n + 1), f(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        f[i] = a[i];
    }
    sort(f.begin() + 1, f.end());
    fen.assign(n + 1, 0);

    ll res = 0;
    int right = n;
    int tmp = 0;
    int i = n;
    while (i > 0)
    {
        int ind = lower_bound(f.begin() + 1, f.end(), a[i]) - f.begin();
        query(ind, 1);
        tmp += calc(ind - 1);
        //cout << ind << ' ' << tmp << '\n';
        while (right >= i && tmp >= k)
        {
            // cout << i << ' ';
            res += (ll)i;
            int ind = lower_bound(f.begin() + 1, f.end(), a[right]) - f.begin();
            query(ind, -1);
            tmp -= (calc(n) - calc(ind));
            right--;
        }
        i--;
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