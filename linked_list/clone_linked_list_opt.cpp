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
    node *next;
    node *random;

    node(int data = 0)
    {
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }

    ~node()
    {
        int val = this->data;
        cout << "Deleting..." << val << endl;
    }
};

void insertAtTail(node *&head, node *&tail, int d)
{
    node *newNode = new node(d);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

void print(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void printRandom(node *head)
{
    while (head != NULL)
    {
        cout << " head data: " << head->data << " ";
        if (head->random != NULL)
        {
            cout << " head random data" << head->random->data;
        }
        else
        {
            cout << " head random data: NULL";
        }
        head = head->next;
        cout << endl;
    }
}

node *copyList(node *head)
{
    // step 1: Create a Clone List
    node *cloneHead = NULL;
    node *cloneTail = NULL;

    node *temp = head;
    while (temp != NULL)
    {
        insertAtTail(cloneHead, cloneTail, temp->data);
        temp = temp->next;
    }

    // step 2: insert nodes of Clone List in between originalList

    node *originalNode = head;
    node *cloneNode = cloneHead;

    while (originalNode != NULL && cloneNode != NULL)
    {
        node *next = originalNode->next;
        originalNode->next = cloneNode;
        originalNode = next;

        next = cloneNode->next;
        cloneNode->next = originalNode;
        cloneNode = next;
    }

    // step 3: Random pointer copy
    originalNode = head;
    cloneNode = cloneHead;

    while (originalNode != NULL && cloneNode != NULL)
    {

        if (originalNode->random != NULL)
        {
            cloneNode->random = originalNode->random->next;
        }
        else
        {
            cloneNode->random = NULL;
        }

        cloneNode = cloneNode->next;
        originalNode = originalNode->next;
    }

    // step 4: revert step 2 changes
    node *original = head;
    node *copy = cloneHead;

    while (original && copy)
    {
        original->next =
            original->next ? original->next->next : original->next;

        copy->next = copy->next ? copy->next->next : copy->next;
        original = original->next;
        copy = copy->next;
    }

    // step 5 answer return
    return cloneHead;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a = 10;

    node *node1 = new node(10);
    node *head = node1;
    node *tail = node1;

    return 0;
}