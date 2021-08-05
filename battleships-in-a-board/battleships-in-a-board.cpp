class Solution {
public:
    int countBattleships(vector<vector<char>>& vec) {
        if(vec.empty() || vec[0].empty())return 0;
        int n=vec.size(),m=vec[0].size(),ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans+=vec[i][j]=='X' && (i==0 || vec[i-1][j]!='X') && (j==0 || vec[i][j-1]!='X');
            }
        }
        return ans;
    }
};