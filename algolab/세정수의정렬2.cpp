#include<iostream>
using namespace std;

int main(){
	int t;
	cin >> t;
    int n[3];
    int f[3];
    for(int i=0; i<t; i++){
        for(int i=0; i<3; i++){
            cin >> n[i];
        }
        if (n[0]<=n[1]) {
            if (n[1]<=n[2]){
                f[0] = n[0];
                f[1] = n[1];
                f[2] = n[2];
            }
            else if (n[0]<=n[2]){
                f[0] = n[0];
                f[1] = n[2];
                f[2] = n[1];
            }
            else {
                f[0] = n[2];
                f[1] = n[0];
                f[2] = n[1];
            }
        }
        else {
            if (n[2]<=n[1]){
                f[0] = n[2];
                f[1] = n[1];
                f[2] = n[0];
            }
            else if (n[0]<=n[2]){
                f[0] = n[1];
                f[1] = n[0];
                f[2] = n[2];
            }
            else {
                f[0] = n[1];
                f[1] = n[2];
                f[2] = n[0];
            }
        }
        cout << f[0] << " " << f[1] << " " << f[2] << endl;
    }
    return 0;
}