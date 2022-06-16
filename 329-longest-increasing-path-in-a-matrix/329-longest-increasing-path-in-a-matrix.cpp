class Solution {
public:
    vector<int> dx={0,0,1,-1};
    vector<int> dy={1,-1,0,0};
    bool issafe(int x,int y,int n,int m){
        if(x>=n || x<0 || y<0 || y>=m) return false;
        return true;
    }
    int func(vector<vector<int>> &arr,int x,int y,int n,int m,vector<vector<int>> &dp){
        if(dp[x][y]) return dp[x][y];
	    dp[x][y] = 1;
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];            
            if(issafe(nx,ny,n,m) && arr[nx][ny]>arr[x][y]){
                dp[x][y]=max(dp[x][y],1+func(arr,nx,ny,n,m,dp));
            }
        }
        return dp[x][y];
    }
    int longestIncreasingPath(vector<vector<int>>& arr) {
       int n=arr.size();
        int m=arr[0].size();
        vector<vector<int>>dp(n,vector<int>(m));
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans,func(arr,i,j,n,m,dp));
            }
        }
        return ans;
    }
};