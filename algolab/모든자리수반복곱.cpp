#include <iostream>
using namespace std;

int main(){
    int t;
    unsigned int n;
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n;
        unsigned int m;
        while(true){
            m=1;
            int s=n%10;
            if (n<10){
                m=n;
                break;
            }
            while (n>10){
                if (s!=0){
                    m *=s;
                }
                n = n/10;
                s = n%10;
            }

            if (s!=0){
                m *=s;
            }
            n = n/10;
            s = n%10;
            n=m;
        }
        cout << m << endl;
    }
    return 0;
}