#include <iostream>
using namespace std;


int prt(int n, int val){
    if (n < 0)
        return 0;
    for (int i=0; i<n; i++){
        for (int j =0; j<n; j++){
            if (i == 0 || i == n - 1 || j ==0 || j == n-1){
                cout<<val;
            } 
            else{
                prt(n - 2, (val + 1) % 2);
            }
        }
        cout<<"\n";
    }
    return 0;
}

int main(){
    int n;
    cin>> n;

    int val =1; 
    if (( n - 1) % 4 == 0) {
        val = 0;
    }
    prt(n, val);
}