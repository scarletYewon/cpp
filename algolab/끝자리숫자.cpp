#include <iostream>
using namespace std;

int main() {
    int t;
	cin >> t;
    int n;
    int cnt;
    for(int i=0; i<t; i++){
        int f=1;
        cin >> cnt;
        for (int j=0; j<cnt; j++){
            cin >> n;
            f = (f%10)*(n%10);
        }
        int L = f%10;
        cout << L << endl;
    }
    return 0;
}