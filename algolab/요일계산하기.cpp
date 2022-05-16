#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    for (int i=0; i<t; i++){
        int y,m,d;
        int answer=0;
        int sum=0;
        int month[] = {31,28,31,30,31,30,31,31,30,31,30,31};
        int day[] = {0,1,2,3,4,5,6};
        cin >> y >> m >> d;
        for(int i=0; i<y; i++){
            if ((i%400==0) || ((i%100!=0) && (i%4==0))){
                sum+=366;
            }
            else{
                sum+=365;
            }
        }
        if ((y % 400) == 0 || ((y % 100) != 0 && (y % 4) == 0)){
                month[1] = 29;
            }
        for(int i=0;i<m-1;i++){
            sum+=month[i];
        }
        answer=day[(sum+d+5)%7];
        cout << answer << endl;
    }
    return 0;
}