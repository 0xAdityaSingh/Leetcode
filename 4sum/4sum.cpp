class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& vec, int t) {
        vector<vector<int>>ans;
        if (vec.empty())
            return ans;
        sort(vec.begin(),vec.end());
        int n=vec.size();
        for(int i=0;i<n;i++){
            int target2=t-vec[i];
            for(int j=i+1;j<n;j++){
                int target3=target2-vec[j];
                int front =j+1,end=n-1;
                vector<int> temp;
                while(front<end){
                    if(vec[front]+vec[end]>target3)
                        end--;
                    else if(vec[front]+vec[end]<target3)
                        front++;
                    else{
                        temp={vec[i],vec[j],vec[front],vec[end]};
                        ans.push_back(temp);
                        while (front < end && vec[front] == temp[2]) ++front;
                        while (front < end && vec[end] == temp[3]) --end;
                    }
                }
                while(j + 1 < n && vec[j + 1] == vec[j]) ++j;
            }
            while(i + 1 < n && vec[i + 1] == vec[i]) ++i;
        }
        return ans;
    }
};