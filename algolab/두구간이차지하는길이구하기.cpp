#include <iostream>
using namespace std;

int main(){
    int t;
    int a,b,c,d;
    int close,len;
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> a >> b >> c >> d;
        if (b<=c || a>=d){
            close = 0;
        }
        else {
            close = min(b,d)-max(a,c);
        }
        len = ((b-a)+(d-c))-close;
        cout << close << ' ' << len << endl;
    }
    return 0;
}