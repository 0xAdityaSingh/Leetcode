class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& v) {
        unordered_map<int,vector<int>> mp;
        int n=v.size();
        vector<vector<int>> vec;
        for(int i=0;i<n;i++){
            if(mp.count(v[i])>0)
                mp[v[i]].push_back(i);
            else
                mp[v[i]]=vector<int>{i};
            if(mp[v[i]].size()==v[i]){
                vec.push_back(mp[v[i]]);
                mp.erase(v[i]);
            }   
        }
        return vec;
    }
};