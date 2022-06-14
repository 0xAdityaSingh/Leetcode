class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans(0), start(0),end(height.size()-1);
        while(start<end){
            ans=max(ans,min(height[start],height[end])*(end-start));
            if(height[start]>height[end]) end--;
            else start++;
        }
        return ans;
    }
};