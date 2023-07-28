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

    node(int data = 0)
    {
        this->data = data;
        this->next = NULL;
    }

    ~node()
    {
        int val = this->data;
        cout << "Deleting..." << val << endl;
    }
};

void Insert_At_Head(node *&head, int data)
{
    node *temp = new node(data);
    temp->next = head;
    head = temp;
}

void Insert_At_Tail(node *&tail, int data)
{
    node *temp = new node(data);
    tail->next = temp;
    tail = temp;
}

void Insert_At_Possition(node *&head, node *&tail, int p, int data)
{
    if (p == 1) // insert at head so we have to up date head
    {
        Insert_At_Head(head, data);
        return;
    }
    node *t = head;
    node *ins = new node(data);
    p--;
    p--;
    while (p--)
    {
        t = t->next;
    }
    if (t->next == NULL) // insert at last so we have to update tail
    {
        Insert_At_Tail(tail, data);
        return;
    }

    ins->next = t->next;
    t->next = ins;
}

void delete_node(node *&head, node *&tail, int val)
{
    node *t = head;

    if (t->data == val)
    {
        head = t->next;
        t->next = NULL;
        delete t;
        return;
    }

    while ((t->next->data != val))
    {
        t = t->next;
        if (t->next == NULL)
        {
            cout << "Element not found" << endl;
            return;
        }
    }
    node *temp = t->next;

    if (temp->next == NULL)
    {
        t->next = NULL;
        tail = t;
        temp->next = NULL;
        delete temp;
        return;
    }

    t->next = temp->next;
    temp->next = NULL;
    delete temp;
}

void print(node *&head)
{
    node *t = head;
    while (t != NULL)
    {
        cout << t->data << " ";
        t = t->next;
    }
    cout << endl;
}

bool detect_loop(node *head)
{
    map<node *, bool> visited;
    node *t = head;

    while (t != NULL)
    {
        if (visited[t])
        {
            cout << "Loop is present at : " << t->data << endl;
            return true;
        }
        visited[t] = true;
        t = t->next;
    }
    cout << "NO loop is present in linked list" << endl;
    return false;
}

bool floyd_cycle_detection(node *head)
{
    if (head == NULL)
    {
        cout << "NO loop is present in linked list" << endl;
        return false;
    }

    node *slow = head;       // 1 - 1 karine aagal vadhe
    node *fast = head; // 2 - 2 karine aagal vadhe
    int check = 0;
    // infinit var loop chalavava no jo loop hashe to fast and slow kyak to bhega thay j.

    while (true)
    {
        
        if (slow == fast && check)
        {
            // for finding starting element of the loop;
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            cout << "Loop is present at : " << slow->data << endl;
            return true;
        }

        if (fast == NULL)
        {
            cout << "NO loop is present in linked list" << endl;
            return false;
        }
        else
        {
            fast = fast->next;
            slow = slow->next;
        }

        if (fast == NULL)
        {
            cout << "NO loop is present in linked list" << endl;
            return false;
        }
        else
        {
            fast = fast->next;
        }
        check++;
    }
}

void remove_loop(node *&head)
{
    map<node *, bool> visited;
    node *curr = head;
    node *prev = NULL;
    int check = 0;

    while (curr != NULL)
    {
        if (visited[curr])
        {
            check = 1;
            break;
        }
        visited[curr] = true;
        prev = curr;
        curr = curr->next;
    }
    if (check)
    {
        prev->next = NULL;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    node *node1 = new node(10);
    node *head = node1;
    node *tail = node1;

    Insert_At_Tail(tail, 20);
    Insert_At_Tail(tail, 30);
    Insert_At_Tail(tail, 40);
    Insert_At_Tail(tail, 50);
    Insert_At_Tail(tail, 60);

    tail->next = head;
    // print(head);

    if (floyd_cycle_detection(head))
    {
        remove_loop(head);
        cout << "linked list after removing loop : ";
        print(head);
    }
    else
    {
        print(head);
    }

    return 0;
}