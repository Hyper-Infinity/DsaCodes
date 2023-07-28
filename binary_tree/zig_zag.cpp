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

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

vector<int> zigZagTraversal(Node *root)
{
    queue<Node *> q;
    queue<Node *> save;
    vector<int> ans;
    q.push(root);
    save.push(root);
    q.push(NULL);
    save.push(NULL);
    int order = 1;

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            if (order & 1)
            {
                while (save.front() != NULL)
                {
                    ans.push_back(save.front()->data);
                    save.pop();
                }
                if (save.front() == NULL)
                {
                    save.pop();
                }
                order++;
            }
            else
            {
                stack<Node *> s;
                while (save.front() != NULL)
                {
                    s.push(save.front());
                    save.pop();
                }

                if (save.front() == NULL)
                {
                    save.pop();
                }

                while (!s.empty())
                {
                    ans.push_back(s.top()->data);
                    s.pop();
                }
                order++;
            }

            if (!q.empty())
            {
                q.push(NULL);
                save.push(NULL);
            }
        }
        else
        {
            if (temp->left)
            {
                q.push(temp->left);
                save.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
                save.push(temp->right);
            }
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}