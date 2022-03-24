#include<iostream>
using namespace std;

int main(){
	int t;
	cin >> t;
    int value;
    int n;
    for (int k=0; k<t; k++){
        int sum=0;
        cin >> n;
        for (int i=0; i<n; i++){
            cin >> value;
            sum= sum+value;
        }
        cout << sum << endl;
    }
    return 0;
}