class Solution {
public:
    int trap(vector<int>& v) {
        
        int ans=0,n=v.size();
        if(n==0)return 0;
        vector<int> suf(n),pre(n);
        pre[0]=v[0];
        suf[n-1]=v[n-1];
        for(int i=1;i<n;i++)pre[i]=max(pre[i-1],v[i]);
        for(int i=n-2;i>=0;i--)suf[i]=max(suf[i+1],v[i]);
        for(int i=0;i<n;i++)ans+=min(pre[i],suf[i])-v[i];
        return ans;
    }
};