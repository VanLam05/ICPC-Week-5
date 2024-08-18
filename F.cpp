#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define fi first
#define se second

ll distance(pll a, pll b)
{
    return sqrt(pow(a.fi - b.fi, 2) + pow(a.se - b.se, 2));
}

bool checkCircle(pll a, pll b, pll c, vector<pll> &plls, int K)
{
    int d = 2 * (a.fi * (b.se - c.se) + b.fi * (c.se - a.se) + c.fi * (a.se - b.se));
    if (d == 0)
        return false;

    ll ux = ((pow(a.fi, 2) + pow(a.se, 2)) * (b.se - c.se) +
             (pow(b.fi, 2) + pow(b.se, 2)) * (c.se - a.se) +
             (pow(c.fi, 2) + pow(c.se, 2)) * (a.se - b.se));

    ll uy = ((pow(a.fi, 2) + pow(a.se, 2)) * (c.fi - b.fi) +
             (pow(b.fi, 2) + pow(b.se, 2)) * (a.fi - c.fi) +
             (pow(c.fi, 2) + pow(c.se, 2)) * (b.fi - a.fi));

    pll center = {ux, uy};
    pll tmp = {a.fi * d, a.se * d};
    double radius = distance(center, tmp);

    int count = 0;
    for (auto &p : plls)
    {
        pll tmp = {p.fi * d, p.se * d};
        double d = distance(center, tmp);
        if (d < radius)
            count++;
    }

    return count == K;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N, K;
        cin >> N >> K;
        vector<pll> plls(N);

        for (int i = 0; i < N; i++)
        {
            cin >> plls[i].fi >> plls[i].se;
        }

        bool found = false;
        for (int i = 0; i < N && !found; i++)
        {
            for (int j = i + 1; j < N && !found; j++)
            {
                for (int k = j + 1; k < N && !found; k++)
                {
                    if (checkCircle(plls[i], plls[j], plls[k], plls, K))
                    {
                        found = true;
                        break;
                    }
                }
            }
        }

        if (found)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
