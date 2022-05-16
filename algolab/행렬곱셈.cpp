#include <iostream>
using namespace std;

int main(){
    int test;
    cin >> test;
    for (int i=0; i<test; i++){
        int r,s,t;
        cin >> r >> s >> t;
        int A[r][s];
        int B[s][t];
        int result[r][t];
        for(int i=0; i<r; i++){
            for(int j=0; j<s; j++){
    	        cin >> A[i][j];
            }
        }
        for(int i=0; i<s; i++){
            for(int j=0; j<t; j++){
    	        cin >> B[i][j];
            }
        }
        int A_col = sizeof(A[0]) / sizeof(int);
        int A_row = sizeof(A) / sizeof(A[0]);
        int B_col = sizeof(B[0]) / sizeof(int);
        int B_row = sizeof(B) / sizeof(B[0]);

        int sum;
        for (int r=0; r<A_row; r++){
            for (int c=0; c < B_col; c++){
                sum = 0;
                for (int k=0; k<A_col; k++){
                    sum += A[r][k] * B[k][c];
                }
                result[r][c] = sum;
            }
        }
        for (int r = 0; r < A_row; r++) {
		    for (int c = 0; c < B_col; c++) {
			    cout << result[r][c] << ' ';
		    }
            cout << endl;
        }
	}
    return 0;
}