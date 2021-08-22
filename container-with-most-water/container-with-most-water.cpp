class Solution {
public:
    int maxArea(vector<int>& h) {
        int n=h.size();
        int ans(0),i(0),j(n-1);
        while(i<j){
            ans=max(ans,(j-i)*min(h[i],h[j]));
            if(h[i]>h[j])j--;
            else i++;
        }
        return ans;
    }
};