class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(auto it:nums1){
            ans.push_back(it);
        }
        for(auto it:nums2){
            ans.push_back(it);
        }
        sort(ans.begin(),ans.end());
        if(ans.size()%2==1){
            return ans[(ans.size()/2)];
        }
        int idx1=ans.size()/2;
        int idx2=(ans.size()-1)/2;
        return (ans[idx2]+ans[idx1])/2.0;
    }
};