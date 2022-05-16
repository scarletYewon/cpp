#include <iostream>
using namespace std;

char board[9][9];
int direction[8][2] = {
    {-1,-1},
    {0,-1},
    {1,-1},
    {1,0},
    {1,1},
    {0,1},
    {-1,1},
    {-1,0},
};

int main(){
    int size = 8;
    int t;
    cin>> t;

    while(t--){
        for(int x=1; x<=size; x++){
            for(int y=1; y<=size; y++){
                board[x][y] = '+';
            }
        }   
        board[4][4] = 'O';
        board[5][5] = 'O';
        board[4][5] = 'X';
        board[5][4] = 'X';

        int cnt;
        cin>> cnt;
        int white_cnt =0, black_cnt = 0;
        
        char seq;
        seq = 'X';
        while(cnt--){
            int i,j;

            cin>> i;
            cin>> j;
            board[i][j] = seq;
            
            for(int d=0; d<8; d++){
                int change_cnt = 0;
                int move_i = i;
                int move_j = j;
                while(true){
                    move_i += direction[d][0];
                    move_j += direction[d][1];
                    
                    if(move_i >= 9 || move_j>=9 || move_i<=0 || move_j<=0) {
                        change_cnt = 0;
                        break;   
                    }
                    else if(board[move_i][move_j] == '+'){
                        change_cnt = 0;
                        break;
                    }

                    else if(board[move_i][move_j] == seq){
                        break;
                    } 

                    else{
                        change_cnt++;
                    }
                }
                for(int c =1; c<=change_cnt; c++){
                    int update_i = i + direction[d][0] * c;
                    int update_j = j + direction[d][1] * c;
                     
                    if(update_i >= 9 || update_j>=9 || update_i<=0 || update_j<=0) {
                        change_cnt = 0;
                        break;   
                    }
                    board[update_i][update_j] = seq;
                }
            }
            if(seq == 'X') seq = 'O';
             
            else if(seq == 'O') seq = 'X';   
        }
        for(int x=1; x<=size; x++){
            for(int y=1; y<=size; y++){
                if(board[x][y] == 'X') black_cnt++;
                if(board[x][y] == 'O') white_cnt++;       
            }
        }
        cout<<black_cnt<<" "<<white_cnt<<"\n";
        for(int x=1; x<=size; x++){
            for(int y=1; y<=size; y++){
                cout<<board[x][y];
            }
            cout<<"\n";
        }
    }
}