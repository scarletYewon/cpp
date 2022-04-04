#include <iostream>
using namespace std;

int main(){
	int t;
	cin >> t;
	for (int i=0; i<t; i++){
		int n,a,b;
		cin >> n >> a >> b;
		cout << n << a << b << endl;
		int array[0][0];
		for (int row=0; row<n; row++){
			for (int col=0; col<n; col++){
				cout << array[row][col] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}