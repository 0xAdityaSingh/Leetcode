class Solution {
public:
    vector<int> findDuplicates(vector<int>& vec) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(auto it:vec){
            if(mp.find(it)!=mp.end()){
                ans.push_back(it);
                }
            else mp[it]++;
        }
        return ans;
    }
};