#include <iostream>
using namespace std;

// 123321
// 12**21
// 1****1

int main()
{
    int n;
    cout << "Enter number" << endl;
    cin >> n;

    int i = 1;
    while (i <= n)
    {
        int j = 1;
        while (j <= n - i + 1)
        {
            cout << j;
            j = j + 1;
        }

        int start = n - j + 1;
        while (start)
        {
            cout << "*";
            start = start - 1;
        }

        
        start = n - j + 1;
        while (start)
        {
            cout << "*";
            start = start - 1;
        }


        j = n-i+1;
        while (j)
        {
            cout << j;
            j = j-1;
        }

        cout << endl;
        i = i + 1;
    }
}