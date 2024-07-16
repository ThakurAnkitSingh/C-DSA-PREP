#include <iostream>
using namespace std;

int main()
{
    // cout << "Enter the number of stars" << endl;
    // int num;
    // cin >> num;

    // int i = 1;
    // while (i <= num)
    // {
    //     int j = 1;
    //     while (j <= num)
    //     {
    //         cout << "*" << endl;
    //         j = j + 1;
    //     }
    //     cout << endl;
    //     i = i + 1;
    // }
    cout << "Enter the number of stars" << endl;
    int num;
    cin >> num;

    int i = 1;
    while (i <= num)
    {
        int j = 1;
        while (j <= num)
        {
            cout << "*" << endl;
            j = j + 1;
        }
        cout << endl;
        i = i + 1;
    }
}