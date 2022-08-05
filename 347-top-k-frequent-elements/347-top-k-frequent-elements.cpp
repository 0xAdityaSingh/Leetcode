class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        vector<pair<int,int>>vec;
        for(auto it:mp){
            vec.push_back(make_pair(it.second,it.first));
        }
        sort(vec.rbegin(),vec.rend());
        
        int i=0;
        while(k>0){
            ans.push_back(vec[i].second);
            i++;
            k--;
        }
        return ans;
    }
};