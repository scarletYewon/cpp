#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int t;
	cin >> t;
    int value;
    int n;
    for (int k=0; k<t; k++){
        cin >> n;
        int value[n];
        for (int i=0; i<n; i++){
            cin >> value[i];
        }
        cout << *max_element(value,value+n) << " " << *min_element(value,value+n) << endl;
    }
    return 0;
}