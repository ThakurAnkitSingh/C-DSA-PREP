#include <iostream>
using namespace std;

int main()
{
    cout << "Enter the number" << endl;
    int n;
    cin >> n;

    int row = 1;

    while (row <= n)
    {
        // space print
        int space = n - row;
        while (space)
        {
            cout << " ";
            space = space - 1;
        }

        // number print
        int j = 1;
        while (j <= row)
        {
            cout << j;
            j = j + 1;
        }
        int start = row - 1;
        while (start)
        {
            cout << start;
            start = start - 1;
        }
        cout << endl;
        row = row + 1;
    }
}