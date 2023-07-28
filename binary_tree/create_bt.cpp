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

node *buildTree(node *root)
{
    cout << "Enter the data : ";
    int val1;
    cin >> val1;

    if (val1 == -1)
    {
        return NULL;
    }

    root = new node(val1);

    cout << "Enter data for inserting in left of " << val1 << endl;
    root->l = buildTree(root->l);

    cout << "Enter data for inserting in right of " << val1 << endl;
    root->r = buildTree(root->r);

    return root;
}

void LevelOrder(node *root) // Breath first search
{
    queue<node *> q;
    q.push(root);
    q.push(NULL); // Separator.

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            // purana level complete traverse ho chuka hai
            cout << endl;

            if (!q.empty())
            {
                // queue still has some child ndoes
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->l)
            {
                q.push(temp->l);
            }
            if (temp->r)
            {
                q.push(temp->r);
            }
        }
    }
}

void BuildFromLevelOrder(node* &root)
{
    queue<node *> q;

    cout << "Enter the data for root node" << endl;
    int val1;
    cin >> val1;
    if (val1 == -1)
    {
        return;
    }
    
    root = new node(val1);
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        cout << "Enter left node for : " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if(leftData != -1) {
            temp -> l = new node(leftData);
            q.push(temp->l);
        }

        cout << "Enter right node for : " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if(rightData != -1) {
            temp -> r = new node(rightData);
            q.push(temp->r);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    node *root = NULL;

    BuildFromLevelOrder(root);

    return 0;
}