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

bool knows(int a, int b, vector<vi> v)
{
    if (v[a][b] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
    
int detect_celebrity(vector<vi> &v, int n)
{
    stack<int> s;

    // push all the element in the stack
    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }

    // get 2 element and compair them.
    while (s.size() > 1)
    {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();

        if (knows(a, b, v))
        {
            s.push(b);
        }
        else
        {
            s.push(a);
        }
    }

    // now stack has only one element that is Tentative celebrity.
    // so now we only have to check Whether it is celebrity or not.

    int one_count = 0;
    int zero_count = 0;
    int ans = s.top();

    for (int i = 0; i < n; i++)
    {
        if (v[ans][i] == 0)
        {
            zero_count++;
        }
        if (v[i][ans] == 1)
        {
            one_count++;
        }
    }
    
    if ((one_count ==  n - 1) && (zero_count == n))
    {
        return ans;
    }
    else
    {
        return -1;
    }
}
    
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<vi> v;

    for (int i = 0; i < n; i++)
    {
        vi in;
        for (int j = 0; j < n; j++)
        {
            int inp;
            cin >> inp;
            in.push_back(inp);
        }
        v.push_back(in);
    }
    
    int celebrity = detect_celebrity(v, n);

    if (celebrity)
    {
        cout << "celebrity person is --> " << celebrity << endl;
    }
    else
    {
        cout << "No one is celebrity." << endl;
    }

    return 0;
}