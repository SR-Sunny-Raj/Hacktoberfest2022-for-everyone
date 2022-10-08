#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> v;
bool is_safe(vector<string> &board , int row , int col , int n)
{
    for (int i = 0 ; i < n; ++i)
    {
        if (board[row][i] == 'Q' && i != col)
        {
            return false;
        }
        if (board[i][col] == 'Q' && i != row)
        {
            return false;
        }
    }
    int i = row - 1 ;
    int j = col - 1;
    int x = row - 1;
    int y = col + 1;
    while (i >= 0 && j >= 0)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
        i--;
        j--;
    }
    while (x >=0 && y < n)
    {
        if (board[x][y] == 'Q')
        {
            return false;
        }
        x--; y++;
    }
    return true;
}
void NQueens(vector<string> &board , int row , int n)
{
    if (row == n)
    {
        v.push_back(board);
        return ;
    }

    for (int col = 0 ; col < n; ++col)
    {
        if (is_safe(board , row , col  , n))
        {
            board[row][col] = 'Q';
            (NQueens(board, row + 1, n ));
            board[row][col] = '.';
        }
    }

}


vector<vector<string>> solveNQueens(int n) {
    vector<string> board;
    for (int i = 0; i < n; ++i)
    {
        string s = "";
        for (int i = 0; i < n; ++i)
        {
            s += ".";
        }
        board.push_back(s);
    }
    NQueens(board, 0, n );   
    return v;
}

int main(){
  int n;
  cout<<"Enter the size of chess board : ";
  cin>>n;
  cout<<"The possible combos are : \n";
  for(int i=0;i<n;++i){
    for(int j=0;j<n;++j){
      cout<<v[i][j]<<"\n";
    }
    cout<<"\n";
  }
  return 0;
}
