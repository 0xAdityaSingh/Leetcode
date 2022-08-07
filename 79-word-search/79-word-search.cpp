class Solution {
public:
    bool dfs(vector<vector<char>>& board,string word,int i,int j){
        if(word.size()==0)return true;
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]!=word[0]) return false;
        char c=board[i][j];
        board[i][j]='*';
        string s=word.substr(1);
        bool ans=dfs(board,s,i-1,j) || dfs(board,s,i+1,j) || dfs(board,s,i,j-1) || dfs(board,s,i,j+1);
        board[i][j]=c;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(),m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dfs(board,word,i,j)) return true;
            }
        }
        return false;
    }
};