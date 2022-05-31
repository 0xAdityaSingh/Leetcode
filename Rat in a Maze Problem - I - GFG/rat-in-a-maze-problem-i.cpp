// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<int> dx={0,0,1,-1};
    vector<int> dy={1,-1,0,0};
    vector<char> dc={'R','L','D','U'};
    bool issafe(int x,int y,int m,int n){
        if(x>=0 and x<m and y>=0 and y<n) return true;
        else return false;
    }
    void bfs(vector<vector<int>> &vec, vector<vector<int>> &vis,int x,int y,int m,int n,string s,vector<string>&ans){
        if(x==m-1 and y==n-1){
            ans.push_back(s);
            return;
        }
        else{
            for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            vis[x][y]=1;
            if(issafe(nx,ny,m,n) and vis[nx][ny]==0 and vec[nx][ny]==1){
                bfs(vec,vis,nx,ny,m,n,s+dc[i],ans);
            }
            vis[x][y]=0;
            
        }    
        }
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<int>>vis(n,vector<int>(n,0));
        if(m[0][0]==0 || m[n-1][n-1]==0) return ans;
        bfs(m,vis,0,0,n,n,"",ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends