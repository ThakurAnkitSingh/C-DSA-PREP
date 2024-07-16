#include <iostream>
using namespace std;

int sqrt(int x, int start, int end)
{
    int mid = start + (end - start) / 2;
    int ans = -1;
    while (start <= end)
    {
        int sqrt = mid * mid;
        if (sqrt == x)
        {
            return mid;
        }
        else if (sqrt > x)
        {
            end = mid - 1;
        }
        else
        {
            ans = mid;
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}

double morePrecision(int n, int precision, int x)
{
    double factor = 1;
    double ans = n;

    for (int i = 0; i < precision; i++)
    {
        factor = factor / 10;
        for (double j = ans; j * j < x; j = j + factor)
        {
            ans = j;
        }
    }
    return ans;
}

int main()
{
    int x;
    cout << "Please enter the number" << endl;
    cin >> x;
    // First find the nearest integer
    int start = 0;
    int end = x;
    int sqrtNumber = sqrt(x, start, end);
    double result = morePrecision(sqrtNumber, 3, x);
    cout << "Sqrt of " << x << " " << result << endl;
}