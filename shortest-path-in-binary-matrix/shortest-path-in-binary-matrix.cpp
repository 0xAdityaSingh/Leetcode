class Solution {
public:
    vector<int>dx{-1,1,0,0,-1,-1,1,1};
  vector<int>dy{0,0,-1,1,-1,1,-1,1};
  bool issafe(int x,int y,int N,int M){
      if(x>=N || x<0 || y>=M || y<0) return false;
      return true;
  }
    int bfs(vector<vector<int>>& A,vector<vector<int>>& dist, int N,int M,int X,int Y,vector<vector<bool>>& vis){
        queue<pair<int,int>>q;
        q.push(make_pair(0,0));
        vis[0][0]=true;
        while(!q.empty()){
        auto it=q.front();
        q.pop();
        int x=it.first;
        int y=it.second;
        if(x==X and y==Y) return dist[x][y];
        for(int i=0;i<8;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(issafe(nx,ny,N,M) && !A[nx][ny] && !vis[nx][ny]){
                dist[nx][ny]=min(dist[nx][ny],dist[x][y]+1);
                // cout<<nx<<" "<<ny<<" "<<dist[nx][ny]<<endl;
                A[nx][ny]=1;
                q.push(make_pair(nx,ny));
                vis[x][y]=true;
            }
        }    
        }
        return -1;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int N=grid.size();
        int M=grid[0].size();
        vector<vector<int>>dist(N,vector<int>(M,INT_MAX));
        vector<vector<bool>>vis(N,vector<bool>(M,false));
        dist[0][0]=1;
        if(grid[0][0]==1)return -1;
        return bfs(grid,dist,N,M,N-1,M-1,vis);
        
    }
};