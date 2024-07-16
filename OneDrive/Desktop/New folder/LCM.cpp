#include<iostream>
using namespace std;

int gcd(int x, int y){
    if(x==0) return y;
    if(y==0) return x;

    while(x!=y){
        if(x>y){
            x = x-y;
        }else{
            y = y-x;
        }
    }
    return x;
}

int main(){
    int a = 10;
    int b = 2;

    // Formula of LCM(a, b);-  LCM(a,b) = a*b/GCD(a,b);

    // First find GCD of a and b;

    int result = a*b/gcd(a, b);
    cout << "LCM of a and b is " << result << endl;
}