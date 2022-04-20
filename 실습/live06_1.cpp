#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#define TARGET 'e'

int main(int argc, char *argv[]){
    if (argc<2) {
        cout << "one command line argument needed\n";
        return -1;
    }
    int n = strlen(argv[1]);
    char *a = new char[n*2+3];
    if (!a) {
        cout << "allocation failed.\n";
        return -1;
    }
    a[0] = '!';
    int c = 0;
    for (int i=0; i<n; i++){
        if (argv[1][i]== TARGET){
            a[c+1] = argv[1][i];
            a[c+2] = TARGET;
            c = c+2;
        }
        else{
            a[c+1] = argv[1][i];
            c++;
        }
    }
    a[c+1] = '.';
    cout << a << endl;

    string s = "!";
    s += argv[1];
    s += ".";
    int pos = s.find(TARGET);
    while(1){
        if( pos != string::npos){
            s.insert(pos,1,TARGET);
        }
        else {
            break;
        }
        pos = s.find(TARGET,pos+2);
    }
    cout << s << endl;
}