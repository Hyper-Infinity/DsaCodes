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
    
    
void power_set(vi &v, vi out, int ind, vector<vi> &ans)
{
    // Base case
    if (ind >= v.size())
    {
        ans.push_back(out);
        return;
    }

    // exclude
    power_set(v, out, ind + 1, ans);

    //include
    out.push_back(v[ind]);
    power_set(v, out, ind + 1, ans);
}
    
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vi v;

    for (int i = 0; i < n; i++)
    {
        int in;
        cin >> in;
        v.push_back(in);
    }

    vi out;
    vector<vi> ans;
    cout << endl;
    cout << "{" << endl;

    power_set(v, out, 0, ans);

    for (auto it : ans)
    {
        cout << "{"; 
        for (auto num : it)
        {
            cout << num << ",";
        }
        cout << "}";
        cout << endl;
    }
    
    cout << "}" << endl;
    
    return 0;
}