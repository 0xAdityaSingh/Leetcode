class Solution {
public:
    int maxSubArray(vector<int>& v) {
        //kadane's algo
        int s=0;
        int ans=INT_MIN;
        for(int i=0;i<v.size();i++){
            s+=v[i];
            ans=max(ans,s);
            if(s<0) s=0;
        }
        return ans;
    }
};