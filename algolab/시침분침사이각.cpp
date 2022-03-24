#include <iostream>
using namespace std;

int angleClock(int h, int m);

int main(void){
    int t;
    int h,m;
    cin >> t;
    for (int i=0; i<t; i++){
        cin >> h >> m;
        cout << (int)angleClock(h, m) << endl;
    }
    return 0;
}

int angleClock(int h, int m){
    double d;
    d = 6*m - (30*h + 0.5*m);
    if (d<0) {
        d *= -1;
    }
    if (d>180){
        d = 360 - d;
    }
    return d;
}