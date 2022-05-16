#include <iostream>
using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    int t;
    cin >> t;
    for (int k=0; k<t; k++){
        int n;
        cin >> n;
        int arr[n][n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                arr[i][j] = -1;
            }
        }
        int i = 0;
        int j = n/2;
        int num = 1;
        
        while(true){
            arr[i][j] = num;
            if(num==n*n){
                break;
            }
            int new_i = (i-1 + n) % n;
            int new_j = (j+1 + n) % n;
            if(arr[new_i][new_j] >0){
                i = (i+1 + n) % n;
                num++;
                continue;
            }
            i = new_i;
            j = new_j;
            num++;
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
}