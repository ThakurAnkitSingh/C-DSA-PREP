#include <iostream>
using namespace std;

int main()
{
    cout << "Enter the number" << endl;
    int n;
    int hundreads = 0;
    int fiftys = 0;
    int tens = 0;
    cin >> n;
    // while (n > 0)
    // {
        switch (true)
        {
        case n >= 100:
            hundreads = n / 100;
        case n >= 50:
            fiftys = n / 50;
        case n >= 10:
            tens = n / 10;
        case n >= 1:
            tens = n / 1;
        }
    // }
}