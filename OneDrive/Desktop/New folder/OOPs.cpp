#include <bits/stdc++.h>
using namespace std;

class Demo
{
    // default constructor
public:
    int health;
    int level;

public:
    void print()
    {
        cout << "Health : " << this->health << endl;
        cout << "Level : " << this->level << endl;
    }
};

class car : public Demo
{
    public:
    int height;
};

int main()
{

    Demo a;
    a.health = 70;
    a.level = 5;
    a.print();
    car b;
    b.print();

    return 0;
}