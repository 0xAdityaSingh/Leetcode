class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& num) {
        int n=num.size(),ans(INT_MIN);
        sort(num.begin(),num.end());
        vector<int>dp(n,1);
        for(int i=1;i<n;i++){
            int j=i-1;
            while(j>=0){
                if(num[i]%num[j]==0 && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                }
                j--;
            }
        }
        int idx=0;
        for(int i=0;i<n;i++){
            if(ans<dp[i]){
                ans=dp[i];
                idx=i;
            }
        }
        int prev=num[idx];
        vector<int> vec;
        ans--;
        vec.push_back(num[idx]);
        for(int i=idx-1;i>=0;i--){
            if(ans==dp[i] && prev%num[i]==0){
                vec.push_back(num[i]);
                ans--;
                prev=num[i];
            }
        }
        return vec;
    }
};