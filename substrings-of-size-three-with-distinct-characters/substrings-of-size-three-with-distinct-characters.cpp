class Solution {
public:
    int countGoodSubstrings(string s) {
        int ans=0;
        int n=s.size();
        for(int i=0;i<n-2;i++){
            if(s[i]!=s[i+1] && s[i+1]!=s[i+2] && s[i]!=s[i+2]){
                ans++;
            }
        }
        return ans;
    }
};