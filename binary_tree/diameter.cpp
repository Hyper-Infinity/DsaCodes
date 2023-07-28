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

int Diameter(node *root)  //  <<< O(n * 2) >>>  //  
{
    // Base case
    if (root == NULL)
    {
        return 0;
    }
    
    // recursive steps

    int option1 = Diameter(root->l); // ans is in left sub tree.
    int option2 = Diameter(root->r); // ans is in right sub tree.
    int option3 = height(root->l) + height(root->r) + 1; // ans is through current root.

    return max(option1, max(option2, option3));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}