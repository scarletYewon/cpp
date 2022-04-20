#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    for (int i=0; i<t; i++){
        int n,value;
        int left,mid,right;
        int cnt=0;
        cin >> n;
        for (int j=0; j<n; j++){
            cin >> value;
            if (j==0) { 
                left = value;
                continue;
            }
            if (j==1) {
                mid = value;
                continue;
            }
            right = value;
            if (mid > left && mid > right) cnt++;
            if (mid==right) continue;
            else {
                left = mid;
                mid = right;
            }
        }
        cout << cnt << endl;
        
    }
}