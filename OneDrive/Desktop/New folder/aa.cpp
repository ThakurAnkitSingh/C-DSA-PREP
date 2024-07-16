#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x = 2010;
    string str = "K";
    int cnt = 0;
    string temp;
    while(cnt < 2){
        temp += to_string(x%10);
        x = x/10;
        cnt++;
    }
    reverse(temp.begin(), temp.end());
    str = str + temp[0] + temp[1];
    cout << "TEMP: " << str << endl;
    // str += to_string(x%100);
    // cout << " STring : " << str << endl;
}