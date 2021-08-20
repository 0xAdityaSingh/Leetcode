class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int k) {
        vector<pair<int,int>> v;
        int n=arr.size();
        for(int i=0;i<n;i++){
            v.push_back(make_pair(arr[i],i));
        }
        sort(v.begin(),v.end());
        int i(0),j=n-1;
        vector<int> ans;
        while(i<j){
            if(v[i].first+v[j].first==k){
                ans.push_back(v[i].second);
                ans.push_back(v[j].second);
                // {v[i].second,v[j].second};
                return ans;
            }
            else if(v[i].first+v[j].first>k){
                j--;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};