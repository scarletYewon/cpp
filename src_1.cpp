#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


void init_array(int a[], int n){
    for (int i=0; i<n; i++){
        srand(n+i);
        int num = rand()%999+1;
        a[i] = num;
    }
}

int sum_array1(int a[], int n){
    int Sum=0;
    for (int i=0; i<n; i++){
        Sum += a[i];
    }
    return Sum;
}

int main(int argc, char *argv[]){
    if(argc < 2) {
        cout << "one command line argument needed\n";
        return -1;
    }

    int n = atoi(argv[1]);
    n = (n<1)? 1:n;
    n = (n>10)? 10:n;

    int arr[n];

    int *a = arr;
    if (!a) {
        cout << "allocation failed. \n";
        return -1;
    }
    int s;

    init_array(a,n);

    for (int i=0; i<n; i++){
        cout << a[i] << " ";
    }

    s = sum_array1(a,n);
    cout << endl << s << endl;
}