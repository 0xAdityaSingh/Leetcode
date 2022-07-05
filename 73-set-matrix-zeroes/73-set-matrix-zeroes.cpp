class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<char>> cmat(m,vector<char>(n,'.'));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    for(int t=0;t<m;t++){
                        if(matrix[t][j]!=0)cmat[t][j]='*';
                    }
                    for(int t=0;t<n;t++){
                        if(matrix[i][t]!=0) cmat[i][t]='*';
                    }
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(cmat[i][j]=='*')matrix[i][j]=0;
            }
        }
        return;
    }
};