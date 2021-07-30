class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int t) {
        t*=k;
        int n=arr.size(),ans(0),sum(0);
        for(int i=0;i<k;i++){
            sum+=arr[i];
        }
        if(sum>=t)ans++;
        for(int i=k;i<n;i++){
            sum-=arr[i-k];
            sum+=arr[i];
            if(sum>=t)ans++;
        }
        return ans;
        
    }
};