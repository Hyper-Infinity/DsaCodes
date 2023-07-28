// /* <<<<< CODE BY SRP >>>>> */
// /* <<<<< SAMARTH >>>>> */
// /* <<<<< JAY HIND >>>>> */

// #include <bits/stdc++.h>
// using namespace std;

// typedef long long int ll;
// typedef unsigned long long int ull;
// #define all(x) (x).begin(), (x).end()
// #define F first
// #define S second
// #define PB push_back
// #define MP make_pair
// typedef vector<long long int> vli;
// typedef vector<int> vi;
// typedef vector<double> vd;
// typedef vector<string> vs;
// typedef pair<int, int> pi;
// typedef map<int, int> mi;
// typedef multimap<int, int> mmi;
// typedef unordered_map<int, int> umi;
// typedef set<int> si;
// typedef multiset<int> msi;
// typedef unordered_set<int> usi;

// class node
// {
// public:
//     int data;
//     node *next;

//     node(int data = 0)
//     {
//         this->data = data;
//         this->next = NULL;
//     }

//     ~node()
//     {
//         int val = this->data;
//         cout << "Deleting..." << val << endl;
//     }

//     void Insert_At_Head(node *&head, int data)
//     {
//         node *temp = new node(data);
//         temp->next = head;
//         head = temp;
//     }

//     void Insert_At_Tail(node *&tail, int data)
//     {
//         node *temp = new node(data);
//         tail->next = temp;
//         tail = temp;
//     }

//     void Insert_At_Possition(node *&head, node *&tail, int p, int data)
//     {
//         if (p == 1) // insert at head so we have to up date head
//         {
//             head->Insert_At_Head(head, data);
//             return;
//         }
//         node *t = head;
//         node *ins = new node(data);
//         p--;
//         p--;
//         while (p--)
//         {
//             t = t->next;
//         }
//         if (t->next == NULL) // insert at last so we have to update tail
//         {
//             tail->Insert_At_Tail(tail, data);
//             return;
//         }

//         ins->next = t->next;
//         t->next = ins;
//     }

//     // << OR >> // --> when tail pointer is note given

//     // node *Insert_At_Last_using_head(node* &head, int data)
//     // {
//     //     node* t = head;
//     //     node* n = new node(data);

//     //     while (t->next != NULL)
//     //     {
//     //         t = t->next;
//     //     }
//     //     t->next = n;
//     //     return head;
//     // }

//     void delete_node(node *&head, node *&tail, int val)
//     {
//         node *t = head;

//         if (t->data == val)
//         {
//             head = t->next;
//             t->next = NULL;
//             delete t;
//             return;
//         }

//         while ((t->next->data != val))
//         {
//             t = t->next;
//             if (t->next == NULL)
//             {
//                 cout << "Element not found" << endl;
//                 return;
//             }
//         }
//         node *temp = t->next;

//         if (temp->next == NULL)
//         {
//             t->next = NULL;
//             tail = t;
//             temp->next = NULL;
//             delete temp;
//             return;
//         }

//         t->next = temp->next;
//         temp->next = NULL;
//         delete temp;
//     }

//     void print(node *&head)
//     {
//         node *t = head;
//         while (t != NULL)
//         {
//             cout << t->data << " ";
//             t = t->next;
//         }
//         cout << endl;
//     }
// };

// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     node *node1 = new node;
//     node1->data = 26;
//     node1->next = NULL;
//     //  << OR >>  //
//     // node *node1 = new node(26);

//     node *head = node1;
//     node *tail = node1;
//     head->print(head);

//     cout << endl
//          << "Inserting at head" << endl;
//     head->Insert_At_Head(head, 31); // 31-->26
//     head->Insert_At_Head(head, 14); // 14-->31-->26
//     head->print(head);

//     // head->Insert_At_Last(head, 38); // 14-->31-->26-->38
//     // head->Insert_At_Last(head, 43); // 14-->31-->26-->38-->43
//     // head->print(head);

//     cout << endl
//          << "Inserting at tail" << endl;
//     tail->Insert_At_Tail(tail, 38); // 14-->31-->26-->38
//     tail->Insert_At_Tail(tail, 43); // 14-->31-->26-->38-->43
//     head->print(head);

//     cout << endl
//          << "Inserting at position" << endl;
//     head->Insert_At_Possition(head, tail, 3, 50); // 14-->31-->50-->26-->38-->43
//     head->Insert_At_Possition(head, tail, 2, 10); // 14-->10-->31-->50-->26-->38-->43
//     head->print(head);
//     head->Insert_At_Possition(head, tail, 8, 100); // 14-->10-->31-->50-->26-->38-->43-->100
//     head->Insert_At_Possition(head, tail, 1, 1);   // 1-->14-->10-->31-->50-->26-->38-->43-->100
//     head->print(head);

//     cout << endl
//          << "deletion.." << endl;
//     head->delete_node(head, tail, 50);
//     head->delete_node(head, tail, 1);
//     head->print(head);
//     head->delete_node(head, tail, 100);
//     head->delete_node(head, tail, 80);
//     head->print(head);

//     cout << "head = " << head->data << endl;
//     cout << "tail = " << tail->data << endl;

//     return 0;
// }

/* <<<<< JAY HIND >>>>> */

// << singly linked list

#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
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
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        cout << "Deleting Node with value : " << this->data << endl;
    }
};

void insertAtHead(Node *&tail, Node *&head, int d)
{
    Node *temp = new Node(d);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
}

void insertAtTail(Node *&tail, Node *&head, int d)
{
    Node *temp = new Node(d);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

void insertAtPosition(Node *&tail, Node *&head, int position, int d)
{
    if (head == NULL || position == 1)
    {
        insertAtHead(tail, head, d);
        return;
    }

    int count = 1;
    Node *curr = head;

    while (curr != NULL && count < position - 1)
    {
        curr = curr->next;
        count++;
    }

    if (curr == NULL)
    {
        cout << "Given position does not exist !" << endl;
        return;
    }

    if (curr->next == NULL)
    {
        insertAtTail(tail, head, d);
        return;
    }

    Node *temp = new Node(d);

    temp->next = curr->next;
    curr->next = temp;
}

void insertAtValue(Node *&tail, Node *&head, int value, int d)
{
    if (head == NULL || value == -1)
    {
        insertAtHead(tail, head, d);
        return;
    }

    Node *curr = head;

    while (curr != NULL && curr->data != value)
    {
        curr = curr->next;
    }

    if (curr == NULL)
    {
        cout << "Given value : " << value << " not found in linked list" << endl;
        return;
    }

    if (curr->next == NULL)
    {
        insertAtTail(tail, head, d);
        return;
    }

    Node *temp = new Node(d);

    temp->next = curr->next;
    curr->next = temp;
}

void printLinkedList(Node *&tail, Node *&head)
{
    if (head == NULL)
    {
        cout << "Linked list is empty !!!" << endl;
        return;
    }

    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
    cout << "Head : " << head->data << "  Tail : " << tail->data << endl
         << endl;
}

void deleteValue(Node *&tail, Node *&head, int value)
{
    if (head == NULL)
    {
        cout << "Linklisted list is Empty !!!" << endl;
        return;
    }

    Node *prev = NULL;
    Node *curr = head;

    while (curr->data != value)
    {
        prev = curr;
        curr = curr->next;
    }

    // Case 1 : deleting 1st element
    if (curr == head)
    {
        head = head->next;
        if (head == NULL)
        {
            tail = NULL;
        }
        curr->next = NULL;
        delete curr;
        return;
    }

    // Case 2 : deleting last element
    if (curr->next == NULL)
    {
        tail = prev;
        prev->next = NULL;
        delete curr;
        return;
    }

    // Case 3 : Middle element
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
}

int main()
{
    // #ifndef ONLINE_JUDGE
    /* freopen(input.txt, r, stdin); */
    /* freopen(output.txt, w, stdout); */
    // #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Node *head = NULL;
    Node *tail = NULL;

    insertAtPosition(tail, head, 5, 10);
    printLinkedList(tail, head);

    insertAtPosition(tail, head, 2, 20);
    printLinkedList(tail, head);

    insertAtPosition(tail, head, 1, 30);
    printLinkedList(tail, head);

    insertAtPosition(tail, head, 3, 40);
    printLinkedList(tail, head);

    insertAtPosition(tail, head, 7, 40);
    printLinkedList(tail, head);

    insertAtValue(tail, head, 20, 26);
    printLinkedList(tail, head);

    insertAtValue(tail, head, 25, 26);
    printLinkedList(tail, head);

    deleteValue(tail, head, 30);
    printLinkedList(tail, head);

    return 0;
}