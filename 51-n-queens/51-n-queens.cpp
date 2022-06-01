class Solution {
public:
    bool issafe(vector<string>& board, int row, int col, int n){
        int nrow=row;
        int ncol=col;
        while(ncol>=0 and nrow>=0){
            if(board[nrow][ncol]=='Q') return false;
            nrow--;
            ncol--;
        }
        nrow=row;
        ncol=col;
        while(ncol>=0){
            if(board[nrow][ncol]=='Q') return false;
            ncol--;
        }
        nrow=row;
        ncol=col;
        while(ncol>=0 and nrow<n){
            if(board[nrow][ncol]=='Q') return false;
            nrow++;
            ncol--;
        }
        return true;
    }
    void solve(vector<string> &board, vector<vector<string>>& ans, int col, int n){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(issafe(board,row,col,n)){
                board[row][col]='Q';
                solve(board,ans,col+1,n);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board;
        string s(n,'.');
        for(int i=0;i<n;i++){
            board.push_back(s);
        }
        solve(board,ans,0,n);
        return ans;
    }
};