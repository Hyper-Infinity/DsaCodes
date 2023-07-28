/* <<<<< CODE BY SRP >>>>> */
/* <<<<< SAMARTH >>>>> */
/* <<<<< JAY HIND >>>>> */

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef vector<long long int> vli;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int, int> pi;
typedef map<int, int> mi;
typedef multimap<int, int> mmi;
typedef unordered_map<int, int> umi;
typedef set<int> si;
typedef multiset<int> msi;
typedef unordered_set<int> usi;

bool if_possible(vi &v, int n, int m, int mid)
{
    int count = 1;
    int curr_dis = 0;
    int s1 = 0;
    int s2 = 1;

    while (s2 < n)
    {
        if ((v[s2] - v[s1]) < mid)
        {
            s2++;
        }
        else
        {
            s1 = s2;
            s2++;
            count++;
            if (count >= m)
            {
                return true;
            }
        }
    }
    if (count < m)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int solve(vi &v, int n, int m)
{
    auto min = min_element(all(v));
    auto max = max_element(all(v));
    int f = 0;
    int ans = 0;
    int b = (*max) - (*min);
    int mid = 0;

    while (f <= b)
    {
        mid = f + (b - f) / 2;

        if (if_possible(v, n, m, mid))
        {
            ans = mid;
            f = mid + 1;
        }
        else
        {
            b = mid - 1;
        }
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    // t = 1;

    vi v;

    for (int i = 0; i < n; i++)
    {
        int in;
        cin >> in;
        v.push_back(in);
    }
    sort(all(v));

    cout << "Answer is : " << solve(v, n, m) << endl;

    return 0;
}