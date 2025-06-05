              //N-Queens

//Three Rules:
//1.Every row: 1 queen
//2.Every column:1 queen
//3.None of the queen should attack each other.

//A Queen can attack in 8 directions.

class Solution {
    public:
    bool isSafe1(int row, int col,vector<string> board, int n){
        //check upper diagonal
        int duprow=row;
        int dupcol=col;

        //move diagonally upwards
        while(row>=0 && col>=0){             //O(n)
            if(board[row][col]=='Q') return false;
            row--;
            col--;
        }
        //move left
        col=dupcol;
        row=duprow;
        while(col>=0){                       //O(n)
            if(board[row][col]=='Q') return false;
            col--;
        }
        //move diagonally downwards
        row=duprow;
        col=dupcol;
        while(row<n && col>=0){             //O(n)
            if(board[row][col]=='Q') return false;
            row++;
            col--;
        }
        return true;
    }
  public:
  void solve(int col, vector<string>&board, vector<vector<string>>&ans, int n){
    if(col==n){
        ans.push_back(board);
        return;
    }

    for(int row=0;row<n;row++){
        if(isSafe1(row,col,board,n)){
            board[row][col]='Q';
            solve(col+1,board,ans,n);
            board[row][col]='.';      //backtrack
        }
    }
  }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        solve(0,board,ans,n);
        return ans;
    }
};

//but this not optimal approach

//OPTIMAL APPROACH:
//using hashing:
// maintain an array of size (2n-1) and mark every  index as 1 if a queen is placed there.
class Solution {
    public:
    void solve(int col, vector<string>&board, vector<vector<string>> &ans, vector<int>&leftRow,vector<int>&upperDiagonal,vector<int>&lowerDiagonal,int n){
        if(col==n){
            ans.push_back(board);
            return;
        }

        for(int row=0; row<n;row++){
            if(leftRow[row]==0 && lowerDiagonal[row+col]==0 && upperDiagonal[n-1+col-row]==0){
                board[row][col]='Q';
                leftRow[row]=1;
                lowerDiagonal[row+col]=1;
                upperDiagonal[n-1+col-row]=1;
                solve(col+1,board,ans,leftRow,upperDiagonal,lowerDiagonal,n);
                board[row][col]='.';
                leftRow[row]=0;
                lowerDiagonal[row+col]=0;
                upperDiagonal[n-1+col-row]=0;
            }
        }
    }
    

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        vector<int> leftRow(n,0), upperDiagonal(2*n-1,0), lowerDiagonal(2*n-1,0);
        solve(0,board,ans,leftRow,upperDiagonal,lowerDiagonal,n);
        return ans;
    }
};
