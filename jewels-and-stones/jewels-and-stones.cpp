class Solution {
public:
    int numJewelsInStones(string jj, string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<jj.size();i++){
            mp[jj[i]]++;
        }
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])!=mp.end())ans++;
        }
        return ans;
    }
};