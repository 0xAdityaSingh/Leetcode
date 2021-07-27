class Solution {
public:
    int c=0;
    vector<int> dx={-1,1,0,0};
    vector<int> dy={0,0,-1,1};
    bool issafe(int x,int y,int n,int m){
        if(x>=n || x<0 || y>=m || y<0) return false;
        return true;
    }
    void ndfs(vector<vector<int>>& vec,vector<vector<int>>& vis,int x,int y,int n,int m){
        vis[x][y]=-1;
        for(int i=0;i<4;i++){
            int newx=x+dx[i];
            int newy=y+dy[i];
            if(issafe(newx,newy,n,m) && vec[newx][newy]==1 && (vis[newx][newy]==0 || vis[newx][newy]==1)){
                ndfs(vec,vis,newx,newy,n,m);
            }
        }
    }
    
    void dfs(vector<vector<int>>& vec1, vector<vector<int>>& vec2,vector<vector<int>>& vis,int x,int y,int n, int m){
        vis[x][y]=1;
        for(int i=0;i<4;i++){
            int newx=x+dx[i];
            int newy=y+dy[i];
            if(issafe(newx,newy,n,m) && vec1[newx][newy]==1 && vec2[newx][newy]==1 && vis[newx][newy]==0){
                dfs(vec1,vec2,vis,newx,newy,n,m);
            }
            else if(issafe(newx,newy,n,m) && vec1[newx][newy]==0 && vec2[newx][newy]==1 && vis[newx][newy]==0){
                c++;
                ndfs(vec2,vis,newx,newy,n,m);
            }
        }
    }
    int countSubIslands(vector<vector<int>>& vec1, vector<vector<int>>& vec2) {
        int n=vec2.size();    
        int m=vec2[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vec2[i][j]==1 && vec1[i][j]==1 && vis[i][j]==0){
                dfs(vec1,vec2,vis,i,j,n,m);
                ans++;    
                }
                
            }
        }
        return ans-c;
    }
};