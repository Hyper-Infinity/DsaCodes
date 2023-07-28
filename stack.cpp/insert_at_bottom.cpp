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
    
    
void insert_at_bottom(stack<int> &s, int val)
{
    // Base case
    if (s.empty())
    {
        s.push(val);
        return;
    }
    
    
    // recursive steps.
    int element = s.top();
    s.pop();
    insert_at_bottom(s, val);
    s.push(element);
}
    
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    insert_at_bottom(s, 5);  

    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}