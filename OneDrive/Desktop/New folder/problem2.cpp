#include <iostream>
using namespace std;

int main()
{

    int Totalproduct = 1;
    int Totalsum = 0;

    int num;
    cout << "Enter the number" << endl;
    cin >> num;
    int n = num;
    while (n != 0)
    {
        int digit;
        digit = n % 10;
        Totalproduct = Totalproduct * digit;
        Totalsum += digit;
        n = n / 10;
    }

    cout << "Total Product : " << Totalproduct << endl;
    cout << "Total Sum : " << Totalsum << endl;
    cout << "Subtract : " << Totalproduct - Totalsum << endl;
}