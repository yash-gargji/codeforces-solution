#include<bits/stdc++.h>
using namespace std;


void checkWinner(){
    
    string board[3];
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
           cin>> board[i][j];
        }
    }
 char winner;

 // any of the rows is same
 for (int i=0; i<=2; i++)
 {
  if(board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][0]!= '.'  )
  {
    winner = board[i][0];
    cout<<winner<<endl;
    return ;
  }
 }

 // any of the columns is same
 for(int i=0; i<=2; i++)
 {
  if (board[0][i]==board[1][i] && board[1][i]==board[2][i] && board[0][i]!= '.'  )
  {
    winner = board[0][i];
    cout<<winner<<endl;
    return ;
  }
 }

 // 1st diagonal is same
 if(board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[0][0]!= '.' )
 {
  winner = board[0][0];
  cout<<winner<<endl;
  return ;
 }

 // 2nd diagonal is same
 if(board[0][2]==board[1][1] && board[1][1]==board[2][0] && board [0][2]!= '.')
 {
  winner = board[0][2];
  cout<<winner<<endl;
  return ;
 }
 cout<<"DRAW\n";
 return;
}

 int main(){
        int t;
        cin>>t;
        while(t--){
            
                checkWinner();
        }
 }