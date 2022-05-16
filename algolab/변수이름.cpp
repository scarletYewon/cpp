#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
    int t,answer;
    cin >> t;
    for (int i=0; i<t; i++){
        string s;
        cin >> s;
        int n = s.length();
        for (int i=0; i<n; i++){
            if (i == 0 && s[0] >= 48 && s[0] <= 57) {
                answer = 0;
                break;
            }
            if(s[i]>=48 && s[i] <=57){answer = 1;}
            else if(s[i]>=65 && s[i] <=90){answer = 1;}
            else if(s[i]>=97 && s[i] <=122){answer = 1;}
            else if(s[i]==95){answer = 1;}
            else{
                answer = 0;
                break;
            }
        }
        cout << answer << endl;
    }
}