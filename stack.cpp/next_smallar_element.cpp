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

void next_smallar(int arr[], int ans[], int n)
{
    stack<int> s;
    s.push(-1);

    for (int i = n - 1; i >= 0; i--)
    {
        while (s.top() >= arr[i])
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(arr[i]);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int *arr = new int[n];
    int *ans = new int[n];

    for (int i = 0; i < n; i++)
    {
        int in;
        cin >> in;
        arr[i] = in;
    }
    next_smallar(arr, ans, n);

    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    delete []ans;
    delete []arr;

    return 0;
}