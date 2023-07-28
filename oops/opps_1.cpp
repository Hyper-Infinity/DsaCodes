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

class hero
{
    // There three types of access modifiers --> private, public, protected;

    //      <<<<<<<<<< Properties >>>>>>>>>>       //

private: // By default private j hoy 6e.
    // private eetale khali class ma j excess kari shakay.
    // To access private properties outside the class we have create behaviour like setter and getter.
    int health;

public:
    // Public eetale aakha program ma gametya excess kari shakay.
    char level;
    char *name;


    // static mumber of the class.
    // static mumber belongs to the class eetale ke static mumber ne object ni need(zarurat) hoti nathi.
    // badha object mate aani value same j hoy 6e. and aane object vina pan excess kari sakay 6e.
    // static mumber ne class ni bar Initialise karava ma aave 6e.
    static int TimeToComplete;


    //      <<<<<<<<<< Behaviour(functions) >>>>>>>>>>      //


    // static functions of the class.
    // static functions belongs to the class eetale ke static mumber ne object ni need(zarurat) hoti nathi.
    // static functions pase 'this' key word hoto nathi.
    // static functions khali static variables ne j excess kari shake 6e.
    static void change_time(int n)
    {
        hero :: TimeToComplete = n;
    }


    // setter for health.
    void sethealth(int health) // (int h)
    {
        // 'this' is a key word that stores the address of the current object.
        // this no use tyare j karaVo jyare 2 same name bhega thy aa case na jem.
        this->health = health;
        // health = h;
    }

    // getter for health.
    int gethealth()
    {
        return this->health;
        //    OR    //
        // return health;
    }

    // setter for name
    void setname(char name[])
    {
        strcpy(this->name, name);
    }

    // for printing the properties of the objest.
    void print()
    {
        cout << "Health is : " << (*this).health << endl;
        cout << "level is : " << (*this).level << endl;
        cout << "name is : " << this->name << endl << endl << endl;

        //      OR      //

        /*
        cout << "Health is : " << health << endl;
        cout << "Health is : " << (*this).gethealth() << endl;
        cout << "level is : " << level << endl;
        */
    }

    //   << constructors >>   // When we create constructor manually Default one destroys automatically.

    // [1] simple (default jevu j pan khali call thy 6e ee jova mate print statment lakhyu 6e)
    hero()
    {
        cout << "Simple constructor colled" << endl;
        name = new char[100];
    }

    // [2] Parameterised constructor.
    hero(int health, char level, char  n[])
    {
        name = new char[100];
        cout << "Parameterised constructor called." << endl;
        strcpy(this->name, n);
        this->health = health;
        this->level = level;
    }


    //  << copy constructors are of two types >>  //


    //  ************ 1 time per eek j chale ************  //


    // When we create copy constructor manually Default  one destroys automatically.

    // [1] Shallow copy constructor (default one)
    // jo ahi pass by value kariye to object ni copy create thy and eena mate copy constructor call thy to aam ee Infinite loop ma fasi jay.

    hero(hero &h) 
    {
        cout << "shallow copy constructor called ." << endl;
        this->health = h.health;
        this->level = h.level;
        this->name = h.name;
        // aahi aa shellow eetala mate kahevay 6e karanake -->
        // aahi name ma khali pointer j copy thaya 6e aathi aa bane same memmory ne point are 6e aathi eek ma change karavathi banne ma refect thy.
    }

    // [2] Deep copy constructor

    hero(hero &h)
    {
        cout << "Deep copy constructor called ." << endl;
        char *temp = new char[100];
        strcpy(temp, h.name);

        this->health = h.health;
        this->level = h.level;
        this->name = temp;
    }


    // << Distructor (for  de-allocate memmory) >> //  
    // [1] for staticaly created object Distructor called Automatically.
    // [2] For dynamically created object we have to call destructor manually.
    // Distructor same constructor jevu j hoy 6e.
    // constructor object creation vakhate call thy and distructor object khatam thavano hoy tyare call thy.

    ~hero()
    {
        cout << "simple distructor called." << endl;
        delete name;
    }

};

int hero :: TimeToComplete = 10;
// '::' is Scope resolution operator.

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    char n[8] = "samarth";
    char m[7] = "saloni";
    char c[7] = "prachi";

    cout << endl << hero :: TimeToComplete << endl;

    // Static
    hero s;
    s.level = 'A';
    s.setname(n);
    s.sethealth(100);
    s.print();
    cout << endl << s.TimeToComplete << endl;

    // Dyanmic
    hero *p = new hero;
    p->sethealth(80);
    p->setname(m);
    p->level = 'B';
    p->TimeToComplete = 20;
    p->print();
    cout << endl << hero :: TimeToComplete << endl;
    cout << endl << s.TimeToComplete << endl;

    // colling static function
    hero :: change_time(50);
    cout << endl << p->TimeToComplete << endl;

    hero r(90, 'A', c);
    r.print();

    hero b(s);
    b.print();

    s.setname(m);
    // s.print();

    cout << "After change" << endl;
    b.print();

    // for s, r, and b distructor called Automatically.
    // we have to call distructor for p manually.
    delete p;

    return 0;
}