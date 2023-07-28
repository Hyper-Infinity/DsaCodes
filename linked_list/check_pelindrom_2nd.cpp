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
    char data;
    node *next;

    node(char data = 's')
    {
        this->data = data;
        this->next = NULL;
    }

    ~node()
    {
        char val = this->data;
        cout << "Deleting..." << val << endl;
    }
};

void Insert_At_Head(node *&head, char data)
{
    node *temp = new node(data);
    temp->next = head;
    head = temp;
}

void Insert_At_Tail(node *&tail, char data)
{
    node *temp = new node(data);
    tail->next = temp;
    tail = temp;
}

void Insert_At_Possition(node *&head, node *&tail, char p, char data)
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

void delete_node(node *&head, node *&tail, char val)
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

node *getMid(node *head)
{
    node *slow = head;
    node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

node *reverse(node *head)
{

    node *curr = head;
    node *prev = NULL;
    node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool check(node *head)
{
    if (head->next == NULL)
    {
        return true;
    }

    // step 1 -> find Middle
    node *middle = getMid(head);
    // cout << "Middle " << middle->data << endl;

    // step2 -> reverse List after Middle
    node *temp = middle->next;
    middle->next = reverse(temp);

    // step3 - Compare both halves
    node *head1 = head;
    node *head2 = middle->next;

    while (head2 != NULL)
    {
        if (head2->data != head1->data)
        {
            return 0;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    // step4 - repeat step 2
    temp = middle->next;
    middle->next = reverse(temp);

    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    node *node1 = new node('s');
    node *head = node1;
    node *tail = node1;

    Insert_At_Tail(tail, 'a');
    Insert_At_Tail(tail, 'm');
    Insert_At_Tail(tail, 'm');
    Insert_At_Tail(tail, 'a');
    Insert_At_Tail(tail, 's');

    if (check(head))
    {
        cout << "Given word is palindrome" << endl;
    }
    else
    {
        cout << "Given word is not a palindrome" << endl;
    }

    return 0;
}