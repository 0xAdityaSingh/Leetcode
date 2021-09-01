class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }
        int mm=mp[0],idx=0;
        for(auto it:mp){
            if(it.second>mm){
                idx=it.first;
                mm=it.second;
            }
        }
        return idx;
    }
};