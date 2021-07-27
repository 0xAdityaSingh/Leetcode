class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& v, int k) {
        unordered_map<int,unordered_set<int>>mp;
        vector<int>ans(k,0);
        for(int i=0;i<v.size();i++){
            int id=v[i][0];
            int time=v[i][1];
            mp[id].insert(time);
        }
        for(auto it=mp.begin();it!=mp.end();it++){
            int temp=it->second.size()-1;
            ans[temp]++;
        }
        return ans;
    }
};