class Solution {
public:
    int dp[501][501];
    int editdist(string s1,string s2,int m,int n){
        if(n==0) return m;
        if(m==0) return n;
        if(dp[m][n]!=-1) return dp[m][n];
        if(s1[m-1]==s2[n-1]){
            dp[m][n]=editdist(s1,s2,m-1,n-1);
            return dp[m][n];
        }
        else{
            dp[m][n]=1+min({editdist(s1,s2,m-1,n-1),editdist(s1,s2,m,n-1),editdist(s1,s2,m-1,n)});
            return dp[m][n];
        }
    }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        return editdist(word1,word2,word1.size(),word2.size());
    }
};