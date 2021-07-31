class Solution {    
public:
    vector<int> dx{-1,1,0,0};
    vector<int> dy{0,0,-1,1};
    bool issafe(int x,int y,int n,int m){
        if(x<0 || x>=n || y<0 || y>=m)return false;
            return true;
        }
    
    void bfs(vector<vector<char>> &v, vector<vector<bool>> &vis, int x,int y,int n,int m){
        vis[x][y]=true;
        for(int i=0;i<4;i++){
            int nx=x+dx[i],ny=y+dy[i];
            if(issafe(nx,ny,n,m) && !vis[nx][ny] && v[nx][ny]=='1'){
                bfs(v,vis,nx,ny,n,m);
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& v) {
        int n=v.size(), m=v[0].size(),ans(0);
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]=='1' && !vis[i][j]){
                    ans++;
                    bfs(v,vis,i,j,n,m);
                }
            }
        }
        return ans;
    }
};