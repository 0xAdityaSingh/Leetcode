class Solution {
public:
    int maxProfit(vector<int>& pr) {
        int ans(0);
        for(int i=1;i<pr.size();i++){
            ans+=max(0,pr[i]-pr[i-1]);
        }
        return ans;
    }
};