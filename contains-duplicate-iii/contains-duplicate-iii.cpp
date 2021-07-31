class Solution {
public:
    #define ll long long 
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n=nums.size();
        vector<pair<ll,ll>>v;
        for(int i=0;i<n;i++) v.push_back({nums[i],i});
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((v[j].first-v[i].first)>t) break;
                if(abs(v[j].second-v[i].second)<=k) return 1;
            }
        }
        return 0;
    }
};