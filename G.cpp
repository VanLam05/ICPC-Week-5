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

int n, k, cnt;
vi heights, a;
ll res;

void calculateWater()
{
    vector<int> left_max(n, 0), right_max(n, 0);

    left_max[0] = heights[0];
    for (int i = 1; i < n; ++i)
        left_max[i] = max(left_max[i - 1], heights[i]);

    right_max[n - 1] = heights[n - 1];
    for (int i = n - 2; i >= 0; --i)
        right_max[i] = max(right_max[i + 1], heights[i]);

    ll water = 0;
    for (int i = 0; i < n; ++i)
        water += (ll)min(left_max[i], right_max[i]) - heights[i];

    res = max(res, water);
}

void update()
{
    int tmp = k;
    vi ind;
    for (int i = 0; i < n; i++)
    {
        if (a[i])
            ind.push_back(i);
    }

    if (ind.size() == 0)
    {
        calculateWater;
        return;
    }
    if (ind.size() == 1)
    {
        heights[ind[0]] += tmp;
        calculateWater;
        heights[ind[0]] -= tmp;
        return;
    }

    int h1 = heights[ind[0]], h2 = heights[ind[1]];
    if (heights[ind[0]] < heights[ind[1]])
    {
        if (tmp >= heights[ind[1]] - heights[ind[0]])
        {
            tmp -= heights[ind[1]] - heights[ind[0]];
            heights[ind[0]] = heights[ind[1]];
        }
        else
        {
            heights[ind[0]] += tmp;
            tmp = 0;
        }
    }
    else
    {
        if (tmp >= heights[ind[0]] - heights[ind[1]])
        {
            tmp -= heights[ind[0]] - heights[ind[1]];
            heights[ind[1]] = heights[ind[0]];
        }
        else
        {
            heights[ind[1]] += tmp;
            tmp = 0;
        }
    }

    if (tmp > 0)
    {
        heights[ind[0]] += tmp / 2;
        heights[ind[1]] += tmp / 2;
    }

    calculateWater();
    heights[ind[0]] = h1;
    heights[ind[1]] = h2;
}

void backTrack(int x)
{
    if (x == n)
    {
        update();
        return;
    }
    for (int i = 0; i < 2; i++)
    {
        a[x] = i;
        cnt += i;
        if (cnt <= 2)
            backTrack(x + 1);
        cnt -= i;
    }
}

int main()
{
    cin >> n >> k;
    heights.resize(n);
    a.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> heights[i];
    res = 0;
    backTrack(0);
    cout << res;
    return 0;
}