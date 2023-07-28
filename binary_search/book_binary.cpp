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

bool if_possible(vi &v, int size, int m, int mid)
{
    int count = 1;
    int page_sum = 0;

    for (int i = 0; i < size; i++)
    {
        if ((page_sum + v[i]) <= mid)
        {
            page_sum += v[i];
        }
        else
        {
            count++;
            if ((count > m) || (v[i] > mid))
            {
                return false;
            }
            page_sum = v[i];
        }
    }
    return true;
}

int solve(vi &v, int m)
{
    int f = 0;
    int sum = 0;
    int ans = 0;
    int size = v.size();
    for (int i = 0; i < size; i++)
    {
        sum += v[i];
    }
    int b = sum;
    int mid = 0;

    while (f <= b)
    {
        mid = f + (b - f) / 2;

        if (if_possible(v, size, m, mid))
        {
            ans = mid;
            b = mid - 1;
        }
        else
        {
            f = mid + 1;
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

    cout << "Answer is : " << solve(v, m) << endl;

    return 0;
}