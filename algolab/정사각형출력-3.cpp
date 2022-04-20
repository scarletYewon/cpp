#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int k=0; k<t; k++){
        int n;
        cin >> n;
        int mid = n/2;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==0 || i==mid || i==n-1){
                    if(j==0 || j==mid || j==n-1){
                        if(i==mid && j==mid){
                            cout << '*';
                        }
                        else {
                            cout << '+';
                        }
                    }
                    else {
                        cout << '-';
                    }
                }
                else {
                    if(j==0 || j==mid || j==n-1){
                        cout << '|';
                    }
                    else {
                        if(i<mid && j<mid && i==j){
                            cout << '\\';
                        }
                        else if(i>mid && j<mid && n-1-i==j){
                            cout << '/';
                        }
                        else if(i<mid && j>mid && i==n-1-j){
                            cout << '/';
                        }
                        else if(i>mid && j>mid && i==j){
                            cout << '\\';
                        }
                        else {
                            cout << '.';
                        }
                    }
                }
            }
            cout << endl;
        }
    }
}