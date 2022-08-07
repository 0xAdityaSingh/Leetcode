class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
       int verStart=0,verEnd=matrix.size()-1,horStart=0,horEnd=matrix[0].size()-1;
        vector<int>ansArr;
        while(horStart<=horEnd and verStart<=verEnd){
            for(int i=horStart;i<=horEnd;i++){
                ansArr.push_back(matrix[verStart][i]);
            }
            verStart++;
            if (verStart > verEnd) {
                break;
            }
            for(int i=verStart;i<=verEnd;i++){
                ansArr.push_back(matrix[i][horEnd]);
            }
            horEnd--;
            if (horStart > horEnd) {
                break;
            }
            for(int i=horEnd;i>=horStart;i--){
                ansArr.push_back(matrix[verEnd][i]);
            }
            verEnd--;
            if (verStart > verEnd) {
                break;
            }
            for(int i=verEnd;i>=verStart;i--){
                ansArr.push_back(matrix[i][horStart]);
            }
            horStart++;
        }
        
        return ansArr;
    }
};