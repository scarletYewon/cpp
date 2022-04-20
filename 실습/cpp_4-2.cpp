#include <iostream>
using namespace std;
int main ()
{
    int arr[2][3] = {
        {10, -1, 3},
        {2, 5, 6}
    };
    int i, s;

    for(i = 0; i < 2; i++) {
        for (s = 0; s < 3; s++)
            cout << "arr[" << i << "][" << s << "] value : " << arr[i][s] << " address: " << &arr[i][s] << "\n";
    }
    
    return 0;
}