#include <iostream>
#include <cmath>
#include <sstream>
using namespace std;

int main(){
    int t;
    cin >> t;
    for (int i=0; i<t; i++){
        int n;
        int l=0;
        cin >> n;
        string strn = to_string(n);
        l = strn.length();
        int arr[l];
        int s=1;
        int m = n;
        for (int j=0; j<l; j++){
            s = n%10;
            arr[j] = s;
            n = n/10;
        }
        long long sum=0;
        for(int k=0; k<l; k++){
            sum += pow(arr[k],l);
        }
        if (m==sum){
            cout << 1 << endl;
        }
        else {
            cout << 0 << endl;
        }
    }
}