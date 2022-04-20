#include <iostream>
using namespace std;

int main(){
    int t;
    int a,b,c,d,e,f,g,h;
    int close_r,close_c;
    int area, round;
    cin >> t;
    for (int i=0; i<t; i++){
        cin >> a >> b >> c >> d;
        cin >> e >> f >> g >> h;

        if (c<=e || a>=g){
            close_r = 0;
        }
        else {
            close_r = min(c,g)-max(a,e);
        }

        if (d<=f || b>=h){
            close_c = 0;
        }
        else {
            close_c = min(d,h)-max(b,f);
        }

        if(close_c==0 || close_r==0){
            close_r = 0;
            close_c = 0;
        }

        area = ((d-b)*(c-a))+((h-f)*(g-e))-(close_r*close_c);
        round = 2*((d-b)+(c-a))+2*((h-f)+(g-e))-(2*(close_r+close_c));
        cout << area << ' ' << round << endl;
    }
    return 0;
}