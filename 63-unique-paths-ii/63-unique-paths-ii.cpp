class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0 && !mat[i][j]){
                    dp[i][j]=1;
                }
                else if(!mat[i][j] && i>0 && j>0){
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
                else if(!mat[i][j] && j>0){
                    dp[i][j]=dp[i][j-1];
                }
                else if(!mat[i][j] && i>0){
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
       return dp[n-1][m-1];
    }
};