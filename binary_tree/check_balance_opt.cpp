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

class node
{
public:
    int data;
    node *l;
    node *r;

    node(int val)
    {
        this->data = val;
        this->l = NULL;
        this->r = NULL;
    }
};

int height(node *root)
{
    // Base case.
    if (root == NULL)
    {
        return 0;
    }

    // Recursive steps
    return max(height(root->l), height(root->r)) + 1;
}

pair<bool, int> Fast_check(node *root) // <<< O(n) >>> //
{
    // pair<int, int> --> pair.first = balance or not , pair.second = height;
    // Base case
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    
    // Recursive steps
    pair<bool, int> left = Fast_check(root->l);
    pair<bool, int> right = Fast_check(root->r);

    bool check_left = left.first;
    bool check_right = right.first;
    bool check_current = abs(left.second - right.second) <= 1 ? true : false;

    pair<bool, int> ans;
    ans.first = (check_current && check_left && check_right) ? true : false;
    ans.second = max(left.second, right.second) + 1;
    return ans;
}

bool opt_check_balance(node *root)
{
    return Fast_check(root).first;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}