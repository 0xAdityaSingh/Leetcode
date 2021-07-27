class Solution {
public:
    vector<int> dx={-1,1,0,0};
    vector<int> dy={0,0,-1,1};
    bool issafe(int x,int y,int n,int m){
        if(x>=n || x<0 || y>=m || y<0) return false;
        return true;
    }
    void bfs(vector<vector<bool>> &vis,vector<vector<char>> &vec,int n,int m,int x,int y){
        vis[x][y]=true; 
        for(int i=0;i<4;i++){
            if(issafe(x+dx[i],y+dy[i],n,m) && vec[x+dx[i]][y+dy[i]]=='1' &&!vis[x+dx[i]][y+dy[i]]){
                bfs(vis,vec,n,m,x+dx[i],y+dy[i]);
            }
        }
    }
    int numIslands(vector<vector<char>>& vec) {
        int n=vec.size();
        int m=vec[0].size();
        vector<vector<bool> >vis(n,vector<bool>(m,false));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vec[i][j]=='1' && !vis[i][j]){
                    bfs(vis,vec,n,m,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};