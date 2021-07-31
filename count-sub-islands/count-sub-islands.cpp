class Solution {
public:
    vector<int> dx{-1,1,0,0};
    vector<int> dy {0,0,-1,1};
    int c=0;
    
    bool issafe(int x,int y,int n,int m){
        if(x<0 || x>=n || y<0 || y>=m) return false;
        return true;
    }
    
    void bfs(vector<vector<int>> &g,vector<vector<int>> &vis,int x,int y,int n,int m){
        vis[x][y]=-1;
        for(int i=0;i<4;i++){
            int nx=x+dx[i],ny=y+dy[i];
            if(issafe(nx,ny,n,m) && g[nx][ny]==1 && (vis[nx][ny]==0||vis[nx][ny]==1)){
                bfs(g,vis,nx,ny,n,m);
            }
        }
    }
    
    void nbfs(vector<vector<int>> &g1,vector<vector<int>> &g2,vector<vector<int>> &vis,int x,int y,int n,int m){
        vis[x][y]=1;
        for(int i=0;i<4;i++){
            int nx=x+dx[i],ny=y+dy[i];
            if(issafe(nx,ny,n,m) && g1[nx][ny]==1 && g2[nx][ny]==1 && vis[nx][ny]==0){
                nbfs(g1,g2,vis,nx,ny,n,m);
            }
            else if(issafe(nx,ny,n,m) && g1[nx][ny]==0 && g2[nx][ny]==1 && vis[nx][ny]==0){
                c++;
                bfs(g2,vis,nx,ny,n,m);
            }
        }
    }
    
    int countSubIslands(vector<vector<int>>& g1, vector<vector<int>>& g2) {
        int n=g2.size(),m=g2[0].size(),ans(0);
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g1[i][j]==1 && g2[i][j]==1 && vis[i][j]==0){
                    ans++;
                    nbfs(g1,g2,vis,i,j,n,m);
                }
            }
        }
        return ans-c;
    }
};