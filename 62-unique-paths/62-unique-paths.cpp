class Solution {
public:
    int func(int x,int y,int m,int n,vector<vector<int>> &dp){
        if(x==m-1 && y==n-1) return 1;
        if(x>=m || y>=n) return 0;
        if(dp[x][y]!=-1) return dp[x][y];
        return dp[x][y]=func(x+1,y,m,n,dp)+func(x,y+1,m,n,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return func(0,0,m,n,dp);
    }
};