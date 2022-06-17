class Solution {
public:
    
    bool issafe(vector<vector<char>>& board,int i,int j,char val){
        int row=i/3*3, col=j/3*3;
        for(int x=0; x<9; x++) if(board[x][j] == val) return false;
        for(int y=0; y<9; y++) if(board[i][y] == val) return false;
        for(int x=0; x<3; x++)
            for(int y=0; y<3; y++)
                if(board[row+x][col+y] == val) return false;
        return true;
    }
    bool dfs(vector<vector<char>>& board, int x,int y){
        if(x==9) return true;
        if(y==9) return dfs(board,x+1,0);
        if(board[x][y]!='.') return dfs(board,x,y+1);
        for(char i='1';i<='9';i++){
            if(issafe(board,x,y,i)){
                board[x][y]=i;
                if(dfs(board,x,y+1)) return true;
                board[x][y]='.';
            }
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board,0,0);
        return;
    }
};