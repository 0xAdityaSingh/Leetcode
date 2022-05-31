class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int l(0),r(0),ans(0);
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])==mp.end()){
                mp[s[i]]=i;
                r=i;
                ans=max(ans,r-l+1);
            }
            else{
                l=max(l,mp[s[i]]+1);
                mp[s[i]]=i;
                r=i;
                ans=max(ans,r-l+1);
            }
        }
        return ans;
    }
};