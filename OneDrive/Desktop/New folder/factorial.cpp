#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 100;
    long long int fac = 1;
    for(int i=2; i<=n; i++){
        fac = fac * i;
    }
    cout << "Factorial " << fac << endl;
    return fac;
}